#include <iostream>
#include <chrono>
#include <random>

#define N 100000

void func(int (&arr)[N], int meaning, int (&counter)[N]){
    for (int j = 0; j != N; ++j){
        if (arr[j] == meaning){
            if(j > 0){
                counter[j]++;
                for (int k = j-1; k >= 0; --k){
                    if (counter[k] < counter[k+1]){
                        int x = arr[k];
                        arr[k] = arr[k+1];
                        arr[k+1] = x;
                        counter[k]++;
                        counter[k+1]--;
                    }
                    else break;
                }
                break; 
            }
            else {
                counter[j]++;
                break;
            }
        }
    }
}

int main(){
    int arr[N] = {0};
    int help_arr[N] = {0};
    unsigned seed = N;
    std::default_random_engine rng1(seed);
    std::uniform_int_distribution<unsigned> dstr1(1,N/10);
    for (int i = 0; i < 5; ++i){
        for (int i = 0; i < N; ++i){
            help_arr[i] = dstr1(rng1);
        }
        unsigned seed2 = N;
        std::default_random_engine rng2(seed);
        std::uniform_int_distribution<unsigned> dstr2(1,N-1);
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < help_arr[i]; j++){
                int x = dstr2(rng2);
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
        int max = 0;
        for (int i = 0; i != N; ++i){
            if (arr[i] > max) max = arr[i];
        }
        /*for (int i = 0; i != N; ++i){
            std::cout << help_arr[i] << ' ';
        }
        std::cout << std::endl;
        for (int i = 0; i != N; ++i){
            std::cout << arr[i] << ' ';
        }*/
        std::cout << std::endl;
        int counter[N] = {0};
        std::default_random_engine rng3(seed);
        std::uniform_int_distribution<unsigned> dstr3(0,max);
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i != 100000; ++i){
            func(arr, dstr3(rng3), counter);
        }  
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << std::endl << time_span.count() << std::endl;
    }
    return 0;
}