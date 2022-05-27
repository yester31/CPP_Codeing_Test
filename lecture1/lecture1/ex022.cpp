#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// 온도의 최댓값 (1차원 배열 구간합 : 제한시간 1초)

void ex022() {
    int n = 10;
    int k = 2;
    vector<int> values = { 3, -2, -4, -9, 0, 3, 7, 13, 8, -3 };

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += values[i];
    }
    //cout << sum << endl;
    int max = 0;
    for (int i = 1; i < values.size() - k + 1; i++) {
        sum += values[i + k - 1];
        sum -= values[i - 1];
        if (max < sum) {
            max = sum;
        }
    }
    cout << max << endl;

}

//int main() {
//    ex022();
//    std::cout << "done!" << std::endl;
//}
//21