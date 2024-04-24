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
            int write_idx = 0, read_idx = 0;
            vector<int> mass(1);
            auto begin = std::chrono::steady_clock::now();
            if(queue_write(mass, write_idx, read_idx) == false){
                read_idx = write_idx + size(mass);
                mass = queue_new(mass); 
            } 
            auto end = std::chrono::steady_clock::now();
            auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            dp[0][i] += time_span.count();
        }
        for (int j = 0; j < k[i]; ++j) {  
            int write_idx = 0, read_idx = 0;
            vector<int> mass(1);
            auto begin = std::chrono::steady_clock::now();
            if(queue_read(mass, write_idx, read_idx) == false){
                write_idx = read_idx + size(mass);
                mass = queue_new(mass); 
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