#include <iostream>
using namespace std;

int main(){
    short int *ptr = new short int[10];
    for (int i = 0; i <= 9; ++i){
        ptr[i] = i;
    }
    for (int i = 0; i <= 9; ++i){
        cout << &(ptr[i]) << ' ';
    }
    cout << endl;
    for (int i = 0; i <= 9; ++i){
        cout << ptr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i <= 9; i = i + 2){
        ptr[i] = ptr[i]^2;
    }
    for (int i = 0; i <= 9; ++i){
        cout << &(ptr[i]) << ' ';
    }
    delete[] ptr;
    return 0;
}