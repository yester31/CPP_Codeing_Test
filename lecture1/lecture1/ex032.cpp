#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 선택 정렬

void ex032() {
    vector<int> a{ 13, 5, 11, 7, 23, 15 };

    for (int i = 0; i < a.size(); i++) {
        int max = a[i];
        for (int j = i; j < a.size(); j++) {
            if (a[j] < max) {
                a[i] = a[j];
                a[j] = max;
                max = a[i];
            }
        }
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}

//int main() {
//    ex032();
//    std::cout << "done!" << std::endl;
//}
//5 7 11 13 15 23