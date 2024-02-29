#include <iostream>
#include <chrono>
#include <random>

#define N 300000

void func(int (&arr)[N], int meaning, int left, int right){
    auto mid = (left + right)/2;
    if (arr[mid] > meaning){
        return func(arr, meaning, left, mid);
    } 
    else if (arr[mid] < meaning){
        return func(arr, meaning, mid + 1, right);
    } 
}

int main(){
    int arr[N] = {0};
    unsigned seed = N;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0,N-1);
    for (int i = 0; i < N; ++i){
        arr[i] = i;
    }
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i != 100000; ++i){
        int left = 0;
        int right = N-1;
        func(arr, arr[dstr(rng)], left, right);
    }  
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << std::endl << time_span.count() << std::endl;
    return 0;
}