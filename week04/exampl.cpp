#include <iostream>
using namespace std;

int main(){
    int *point = nullptr; // указатель
    int var0 = 342;
    point = &var0;
    cout << point << ' ' << *point << endl;
    cout << &var0 << ' ' << var0 << endl;
    double *ptr = new double[200000000]; // выделяем память в оперативке
    delete[] ptr; // удаляем память
    return 0;
}