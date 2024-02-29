#include <iostream>
using namespace std;

int main(){
    double *ptr = nullptr;
    double var = 0;
    ptr = &var;
    cout << ptr << ' ' << *ptr << endl;
    ptr = ptr - 3;
    cout << ptr << ' ' << *ptr << endl;
    ptr = ptr + 5;
    cout << ptr << ' ' << *ptr << endl;
    return 0;
}