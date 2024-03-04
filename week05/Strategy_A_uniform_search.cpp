#include <iostream>
#include <chrono>
#include <random>

#define N 80000

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
    unsigned seed = N;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0,N-1);
    for (int i = 0; i < N; ++i){
        arr[i] = dstr(rng);
    }
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i != 100000; ++i){
        func(arr, arr[dstr(rng)]);
    }  
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << std::endl << time_span.count() << std::endl;
    return 0;
}