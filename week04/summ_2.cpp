#include <iostream>
#include <chrono>
#include <random>

#define N 30000

void func(int (&arr)[N], int meaning, int left, int right){
    if(right == 0 or left == N-1){
        std::cout << "нету" << std::endl;
    }
    else if(arr[left] + arr[right] > meaning){
        func(arr, meaning, left, right-1);
    } 
    else if(arr[left] + arr[right] < meaning){
        func(arr, meaning, left+1, right);
    } 
    else if(arr[left] + arr[right] == meaning){
        std::cout << "отл" << std::endl;
    } 
}

int main(){
    int arr[N] = {0};
    unsigned seed = 2*N-1;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0,N-1);
    for (int i = 0; i < N; ++i){
        arr[i] = i+1;
    }
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i != 10000; ++i){
        int left = 0, right = N-1;
        func(arr, dstr(rng), left, right);
    }  
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << std::endl << time_span.count() << std::endl;
    return 0;
}