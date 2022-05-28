#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 두 배열 합치기

void sort_insert(vector<int> &vec) {
    int j, tmp;
    for (int i = 1; i < vec.size(); i++) {
        tmp = vec[i];
        for (j = i - 1; j >= 0; j--) {
            if (tmp < vec[j]) vec[j + 1] = vec[j];
            else break;
        }
        vec[j + 1] = tmp;
    }
}

void ex040() {
    vector<int> a{ 2, 7, 10, 5, 3 };
    vector<int> b{ 3, 10, 5, 17, 12 };
    sort_insert(a);
    sort_insert(b);
    vector<int> c;
    int pt1 = 0;
    int pt2 = 0;

    while (pt1 < a.size() && pt2 < b.size()) {
        if (a[pt1] < b[pt2]) {
            pt1++;
        }
        else if (a[pt1] == b[pt2]) {
            c.push_back(a[pt1]);
            pt1++;
            pt2++;
        }
        else {
            pt2++;
        }
    }
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << ' ';
    }
}

//int main() {
//    ex040();
//    std::cout << "done!" << std::endl;
//}
//3 5 10