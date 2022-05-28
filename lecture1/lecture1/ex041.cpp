#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 연속된 자연수의 합

void ex041() {
    int N = 15;
    for (int i = 2; i < N; i++) {
        int tmp = 1;
        int sum = 0;
        while (tmp <= i) {
            sum += tmp;
            tmp++;
        }
        if (N - sum < 0) break;
        if ((N - sum) % i == 0) {
            int j;
            for (j = 0; j < i - 1; j++) {
                cout << (N - sum) / i + j + 1 << " + ";
            }
            cout << (N - sum) / i + j + 1 << " = " << N << endl;
        }
    }
}

//int main() {
//    ex041();
//    std::cout << "done!" << std::endl;
//}
//7 + 8 = 15
//4 + 5 + 6 = 15
//1 + 2 + 3 + 4 + 5 = 15