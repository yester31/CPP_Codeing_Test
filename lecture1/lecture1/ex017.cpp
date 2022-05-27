#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 1부터 주어진 숫자 까지 합을 구하고 정답과 비교하기

void ex017() {
    int n = 3;
    int sum;
    vector<int> m = { 10, 20, 100 };
    vector<int> ans = { 55, 350, 5050 };

    for (int i = 0; i < n; i++) {
        sum = 0;

        for (int j = 0; j <= m[i]; j++) {
            sum += j;
        }

        if (ans[i] == sum) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

//int main() {
//    ex017();
//    std::cout << "done!" << std::endl;
//}
//YES
//NO
//YES