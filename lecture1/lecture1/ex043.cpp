#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 뮤직비디오 (이분검색 응용 : 결정 알고리즘)

int Count(int s, vector<int>& a) {
    int i, cnt = 1, sum = 0;
    for (i = 0; i < a.size(); i++) {
        if (sum + a[i] > s) { // 새로운 누적 시작
            cnt++;
            sum = a[i];
        }
        else {
            sum += a[i]; // 누적
        }
    }
    return cnt;
}

void ex043() {
    int M = 3;
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int lt = 1;
    int rt = 0;
    int max = -214700000;
    for (int i = 0; i < a.size(); i++) {
        rt += i;
        if (a[i] > max) max = a[i];
    }
    int mid, res;
    while (lt <= rt) { // 엇갈리면 끝
        mid = (lt + rt) / 2; // 예상 답(확인할 값)
        if (mid >= max && Count(mid, a) <= M) {
            res = mid;
            rt = mid - 1;
        }
        else {
            lt = mid + 1;
        }
    }
    cout << res << endl;
}

//int main() {
//    ex043();
//    std::cout << "done!" << std::endl;
//}
//17