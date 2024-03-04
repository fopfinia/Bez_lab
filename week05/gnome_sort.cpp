#include <iostream>
#include <random>

#define N 10

void gnome_sort(int (&array)[N]){
    int index = 0;
    while (index <= N){
        if (array[index] > array[index+1]){
            int x = array[index];
            array[index] = array[index + 1];
            array[index + 1] = x;
            index--;
        }
        else if(array[index] <= array[index+1]){
            index++;
        }
    }
    for (int i = 0; i != N; ++i){
        std::cout <<  array[i] << ' ';
    }
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
    std::cout << std::endl;
    gnome_sort(array);
    return 0;
}