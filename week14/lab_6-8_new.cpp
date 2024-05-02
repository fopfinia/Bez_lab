#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
#define int long long

const vector<int> ns = {10,   100,  1000, 2000, 4000, 6000, 8000, 10000, 15000,
                        20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 
                        65000, 70000};
const vector<int> k = {100000, 10000, 10000, 10000, 10000, 10000,
                        10000, 10000, 5000, 5000, 5000, 1000, 1000, 1000,
                        1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
                        1000};

void queue_new(int*& dst, int& write_idx, int& read_idx, size_t& size) {
    int* tmp = new int[size*2];
    read_idx += size;
    size = size*2;
    for (int i = 0; i < size-1; i++) tmp[i] = 0;
    for (int i = 0; i < write_idx; i++) tmp[i] = dst[i];
    for (int i = read_idx; i < size-1; i++) tmp[i] = dst[i - size];
    delete[] dst;
    dst = tmp;
}

bool queue_write(int*& dst, int &write_idx, int &read_idx, size_t size){
    if (write_idx < read_idx){
        write_idx++;
        return true;
    }
    return false;
}

bool queue_read(int*& dst, int &write_idx, int &read_idx, size_t size){
    if (read_idx < size-1){
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
            int write_idx = 0, read_idx = 1;
            int* dst = new int[2];
            dst[0] = 1; dst[1] = 0;
            size_t size = 2;
            auto begin = std::chrono::steady_clock::now();
            while (size < n){
                if(queue_write(dst, write_idx, read_idx, size) == false){
                    queue_new(dst, write_idx, read_idx, size); 
                } 
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            dp[0][i] += time_span.count();
        }
        for (int j = 0; j < k[i]; ++j) {  
            int write_idx = 0, read_idx = 1;
            int* dst = new int[2];
            dst[0] = 1; dst[1] = 0;
            size_t size = 2;
            auto begin = std::chrono::steady_clock::now();
            while (size < n){
                if(queue_read(dst, write_idx, read_idx, size) == false){
                    queue_new(dst, write_idx, read_idx, size); 
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