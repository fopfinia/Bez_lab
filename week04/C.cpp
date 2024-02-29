#include <iostream>
using namespace std;

int main(){
    int *ptr = new int[1];
    int index = 0;
    cin >> ptr[index];
    while (ptr[index] != 0){
        ++index;
        void *realloc(
            void *memblock,
            size_t index
        );
        cin >> ptr[index];   
    }
    for (int i = 0; i < index; ++i){
        cout << ptr[i] << ' ' << &(ptr[i]) << endl;
    }
    for (int i = 0; i < index - 1; ++i){
        cout << ptr[i] - ptr[i+1] << ' ';
    }
    return 0;
}