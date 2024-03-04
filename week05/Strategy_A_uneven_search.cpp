#include <iostream>
#include <chrono>
#include <random>

#define N 1000

void func(int (&arr)[N], int meaning){
    for (int j = 0; j != N; ++j){
        if (arr[j] == meaning){
            int x = arr[j];
            arr[j] = arr[0];
            arr[0] = x;
            break;
        }
    }
}

int main(){
    int arr[N] = {0};
    int help_arr[N] = {0};
    unsigned seed = N;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(1,N-1);
    for (int i = 0; i < 5; ++i){
        for (int i = 0; i < N; ++i){
            help_arr[i] = dstr(rng)/(N/10);
        }
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < help_arr[i]; j++){
                int x = dstr(rng);
                int y = x-1;
                bool yes = false;
                while (yes == false){
                    if (arr[x] == 0){
                        arr[x] = i;
                        yes = true;
                    } 
                    else if (x < N-1) x++;
                    else if (x == N-1) x = 0;
                    if (x == y){
                        i = N;
                        yes = true;
                    }
                }             
            }
        }
        std::cout << std::endl;
        for (int i = 0; i < N; ++i){
            std:: cout << help_arr[i] << ' ';
        }
        std::cout << std::endl << std::endl;
        for (int i = 0; i < N; ++i){
            std::cout << arr[i] << ' ';
        }
        int max = 0;
        for (int i = 0; i != N; ++i){
            if (arr[i] > max) max = arr[i];
        }
        std::cout << std::endl << max << std::endl;
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i != 100000000; ++i){
            func(arr, dstr(max));
        }  
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << std::endl << time_span.count() << std::endl;
    }
    return 0;
}