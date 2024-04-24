#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
#define int long long

const vector<int> ns = {10,   100,  1000, 2000, 4000, 6000, 8000, 10000, 15000,
                        20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 
                        65000, 70000, 75000, 80000, 85000, 90000, 95000, 100000};
const vector<int> k = {100000, 10000, 10000, 10000, 10000, 10000,
                        10000, 10000, 5000, 5000, 5000, 1000, 1000, 1000,
                        1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
                        1000, 1000, 1000, 1000, 1000, 1000, 1000};

vector<int> queue_new(vector<int>& old_mass, int& write_idx, int& read_idx) {
    vector<int> new_mass(size(old_mass) * 2);
    for (int i = 0; i < size(old_mass) * 2 - 1; i++) new_mass[i] = 0;
    for (int i = 0; i < write_idx; i++) new_mass[i] = old_mass[i];
    for (int i = read_idx; i < size(old_mass); i++) new_mass[i + size(old_mass)] = old_mass[i];
    read_idx += size(old_mass);
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

bool queue_read(vector<int> &mass, int &write_idx, int &read_idx){
    int n = size(mass);
    if (read_idx < n-1){
        read_idx ++;
        return true;
    }
    return false;
}

signed main(){
    vector<vector<int>> dp(2, vector<int>(ns.size(), 0));
    for (int i = 0; i < ns.size(); ++i) {
        int n = ns[i];
        for (int j = 0; j < k[i]; ++j) {  
            int write_idx = 1, read_idx = 0;
            vector<int> mass(2);
            auto begin = std::chrono::steady_clock::now();
            while (size(mass) < n){
                if(queue_write(mass, write_idx, read_idx) == false){
                    mass = queue_new(mass, write_idx, read_idx); 
                } 
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            dp[0][i] += time_span.count();
        }
        for (int j = 0; j < k[i]; ++j) {  
            int write_idx = 1, read_idx = 0;
            vector<int> mass(2);
            auto begin = std::chrono::steady_clock::now();
            while (size(mass) < n){
                if(queue_read(mass, write_idx, read_idx) == false){
                    mass = queue_new(mass, write_idx, read_idx); 
                }
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            dp[1][i] += time_span.count();
        }
    }
    ofstream f1;
    f1.open("11.txt");
    for (int j = 0; j < ns.size(); ++j) {
        f1 << ns[j] << ' ' << dp[0][j] / k[j] << '\n';
    }
    f1.close();
    f1.open("12.txt");
    for (int j = 0; j < ns.size(); ++j) {
        f1 << ns[j] << ' ' << dp[1][j] / k[j] << '\n';
    }
    f1.close();
}