#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 두 배열 합치기

void ex039_1() {
    vector<int> a{ 1, 3, 5 };
    vector<int> b{ 2, 3, 6, 7, 9 };
    b.resize(a.size() + b.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] < b[j]) {
                for (int k = b.size() - 2; k >= j; k--) {
                    b[k + 1] = b[k];
                }
                b[j] = a[i];
                break;
            }
        }
    }
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << ' ';
    }
}

void ex039_2() {
    vector<int> a{ 1, 3, 5 };
    vector<int> b{ 2, 3, 6, 7, 9 };
    vector<int> c;
    int pt1 = 0;
    int pt2 = 0;

    while (pt1 < a.size() && pt2 < b.size()) {
        if (a[pt1] <= b[pt2]) {
            c.push_back(a[pt1++]);
        }
        else {
            c.push_back(b[pt2++]);
        }
    }

    if (pt1 != a.size()) {
        while (pt1 < a.size()) {
            c.push_back(a[pt1++]);
        }
    }

    if (pt2 != b.size()) {
        while (pt2 < b.size()) {
            c.push_back(b[pt2++]);
        }
    }

    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << ' ';
    }
}

//int main() {
//    ex039_1();
//    std::cout << "done!" << std::endl;
//
//    ex039_2();
//    std::cout << "done!" << std::endl;
//}
//1 2 3 3 5 6 7 9