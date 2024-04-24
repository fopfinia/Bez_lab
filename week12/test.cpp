#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
#define int long long

const vector<int> ns = {10,   100,  1000, 2000, 3000, 4000,
                        5000, 6000, 7000, 8000, 9000, 10000};
const vector<int> k = {10000, 1000, 100, 100, 100, 100,
                        100, 100, 100, 50, 50, 50};

vector<int> queue_new(vector<int> &old_mass) {
    vector<int> new_mass(size(old_mass)*2);
    for (int i = 0; i < size(old_mass)*2 - 1; i++) new_mass[i] = 0;
    return new_mass;
} 

bool queue_write(vector<int> &mass, int &write_idx, int &read_idx){
    int n = size(mass);
    if (write_idx < n-1){
        if(write_idx != read_idx){
            write_idx++;
            return true;
        }
    }
    else{
        write_idx = 0;
        return true;
    }
    return false;
}

int main(){
    vector<int> mass(1);
    int write_idx = 0, read_idx = 0;
    if(queue_write(mass, write_idx, read_idx) == false){
        read_idx = write_idx + size(mass);
        mass = queue_new(mass); 
    } 
    cout << size(mass) << ' ' << read_idx;
    return 0;
}