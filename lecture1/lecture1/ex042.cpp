#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 이분검색

void sort_insert2(vector<int> & vec) {
    int i, j, tmp;
    for (i = 1; i < vec.size(); i++) {
        tmp = vec[i];
        for (j = i - 1; j >= 0; j--) {
            if (tmp < vec[j]) vec[j + 1] = vec[j];
            else break;
        }
        vec[j + 1] = tmp;
    }
}

void ex042() {
    int M = 32;
    vector<int> a{ 23, 87, 65, 12, 57, 32, 99, 81 };
    sort_insert2(a); // 오른차순 정렬
    int lt = 0;
    int rt = a.size() - 1;
    int mid = (lt + rt) / 2;
    int loc = 0;

    while (a[mid] != M) {
        if (a[mid] > M) {
            rt = mid - 1;
        }
        else {
            lt = mid + 1;
        }
        mid = (lt + rt) / 2;
    }
    loc = mid + 1;
    cout << loc << endl;
}

//int main() {
//    ex042();
//    std::cout << "done!" << std::endl;
//}
//3