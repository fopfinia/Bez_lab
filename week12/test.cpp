#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
#define int long long

vector<int> queue_new(vector<int>& old_mass, int& write_idx, int& read_idx) {
    vector<int> new_mass(size(old_mass) * 2);
    for (int i = 0; i < size(old_mass) * 2 - 1; i++) new_mass[i] = 0;
    for (int i = 0; i < write_idx; i++) new_mass[i] = old_mass[i];
    for (int i = read_idx; i < size(old_mass); i++) new_mass[i + size(old_mass)] = old_mass[i];
    read_idx += size(old_mass);
    return new_mass;
}

bool queue_write(vector<int>& mass, int& write_idx, int& read_idx) {
    int n = size(mass);
    if (write_idx < n - 1) {
        if (write_idx != read_idx) {
            mass[write_idx] = 1;
            write_idx++;
            return true;
        }
    }
    else {
        mass[write_idx] = 1;
        write_idx = 0;
        return true;
    }
    return false;
}
bool queue_read(vector<int>& mass, int& write_idx, int& read_idx) {
    int n = size(mass);
    if (read_idx < n - 1) {
        read_idx++;
        return true;
    }
    return false;
}

signed main() {
    std::chrono::microseconds arr[100];
    for (int k = 1; k < 1000; k++)
    {
        vector<int> mass(2);
        int write_idx = 1, read_idx = 0;
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 1000 * k; i++)
        {
            if (queue_write(mass, write_idx, read_idx) == false) {
                mass = queue_new(mass, write_idx, read_idx);
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        cout << time_span.count() << ", ";
    }
    return 0;
}