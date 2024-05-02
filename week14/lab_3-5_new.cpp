#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;

// ns - в каких n замеряем время
const vector<int> ns = {10,   100,  1000, 2000, 3000, 4000,
                        5000, 6000, 7000, 8000, 9000, 10000};
const vector<int> k = {10000, 1000, 100, 100, 100, 100,
                        100, 100, 100, 50, 50, 50};  // количество замеров времени для одной точки

// пытаемся добавить элементы 0 ... n в массив a,
// динамически изменяя его размер тремя способами

void solve1(int*& dst, size_t& size) {
  int *tmp  = new int[size + 1];
  for (int i = 0; i < size; i++){
    tmp[i] = dst[i];
  }
  tmp[size] = size - 1;
  delete[] dst;
  dst = tmp;
  size++;
}

const int m = 100;  // на сколько элементов увеличиваем размер массива
void solve2(int*& dst, size_t& size) {
  int *tmp = new int[size + m];
  for (int i = 0; i < size; i++){
    tmp[i] = dst[i];
  }
  for (int i = size; i < size + m; i++){
    tmp[i] = i;
  }
  delete[] dst;
  dst = tmp;
  size += m;
}

void solve3(int*& dst, size_t& size) {
  int *tmp = new int[2*size];
  for (int i = 0; i < size; i++){
    tmp[i] = dst[i];
  }
  for (int i = size; i < 2*size; i++){
    tmp[i] = i;
  }
  delete[] dst;
  dst = tmp;
  size = size * 2;
}

signed main() {
  vector<vector<int>> dp(3, vector<int>(ns.size(), 0));
  for (int i = 0; i < ns.size(); ++i) {
    int n = ns[i];
    for (int j = 0; j < k[i]; ++j) { 
      int* dst = new int[1];
      dst[0] = 0;
      size_t size = 1;
      auto begin = std::chrono::steady_clock::now();
      while (size < n){
        solve1(dst, size);
      }
      auto end = std::chrono::steady_clock::now();
      auto time_span =
          std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
      dp[0][i] += time_span.count();
    }
    for (int j = 0; j < k[i]; ++j) {  
      int* dst = new int[1];
      dst[0] = 0;
      size_t size = 1;
      auto begin = std::chrono::steady_clock::now();
      while (size < n){
        solve2(dst, size);
      }
      auto end = std::chrono::steady_clock::now();
      auto time_span =
          std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
      dp[1][i] += time_span.count();
    }
    for (int j = 0; j < k[i]; ++j) { 
      int* dst = new int[1];
      dst[0] = 0;
      size_t size = 1;
      auto begin = std::chrono::steady_clock::now();
      while (size < n){
        solve3(dst, size);
      }
      auto end = std::chrono::steady_clock::now();
      auto time_span =
          std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
      dp[2][i] += time_span.count();
    }
  }
  ofstream f1;
  f1.open("01.txt");
  for (int j = 0; j < ns.size(); ++j) {
    f1 << ns[j] << ' ' << dp[0][j] / k[j] << '\n';
  }
  f1.close();
  f1.open("02.txt");
  for (int j = 0; j < ns.size(); ++j) {
    f1 << ns[j] << ' ' << dp[1][j] / k[j] << '\n';
  }
  f1.close();
  f1.open("03.txt");
  for (int j = 0; j < ns.size(); ++j) {
    f1 << ns[j] << ' ' << dp[2][j] / k[j] << '\n';
  }
  f1.close();
}