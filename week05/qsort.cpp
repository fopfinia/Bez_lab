#include <iostream>
#include <random>

#define N 10

void qsort(int (&array)[N], int ind_left_base, int ind_right_base){
    
}

int main(){
    int array[N] = {0};
    unsigned seed = N;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0,N-1);
    for (int i = 0; i != N; ++i){
        array[i] = dstr(rng);
    }
    for (int i = 0; i != N; ++i){
        std::cout << array[i] << ' ';
    }
    int ind_left_base = 0;
    int ind_right_base = N-1;
    std::cout << std::endl;
    qsort(array, ind_left_base, ind_right_base);
    for (int i = 0; i != N; ++i){
        std::cout <<  array[i] << ' ';
    }
    return 0;
}