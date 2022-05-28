#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 삽입정렬

void ex036() {
    vector<int> a{ 7, 11, 5, 6, 10, 9 };
    int j;
    for (int i = 1; i < a.size(); i++) {
        int tmp = a[i];
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > tmp) {
                a[j + 1] = a[j]; // 뒤로 이동
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp; // 현재까지 정렬된 숫자들 바로 뒤에 삽입
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}

//int main() {
//    ex036();
//    std::cout << "done!" << std::endl;
//}
// 5 6 7 9 10 11