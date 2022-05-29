#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 마구간 정하기(이분검색 응용)

static void sort_insert(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int tmp = a[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > tmp) {
                a[j + 1] = a[j];
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp;
    }
}

static int Count(int mid, vector<int>& vec) {
    int loc = 0;
    int cnt = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] - vec[loc] >= mid) {
            loc = i;
            cnt++;
        }
    }
    return cnt;
}

void ex044() {
    int C = 3;
    vector<int> a{ 1, 2, 8, 4, 9 };
    sort_insert(a); // 오른 차순 삽입 정렬
    int lt = a[0];
    int rt = a[a.size() - 1];
    int res, mid;
    while (lt <= rt) {
        mid = (lt + rt) / 2;
        if (Count(mid, a) >= C) {
            res = mid;
            lt = mid + 1;
        }
        else {
            rt = mid - 1;
        }
    }

    cout << res << endl;
}

//int main() {
//    ex044();
//    std::cout << "done!" << std::endl;
//}
//3