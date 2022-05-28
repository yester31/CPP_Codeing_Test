#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// Least Recently Used (삽입정렬 코드 스타일 : 카카오)

void ex037() {
    int cash_size = 5;
    vector<int> a{ 1, 2, 3, 2, 6, 2, 3, 5, 7 };
    vector<int> cash(cash_size);

    for (int i = 0; i < a.size(); i++) {
        int task = a[i];
        bool hit = false; // init hit
        int loc = 0;
        for (int j = 0; j < cash.size(); j++) {
            if (task == cash[j]) {// hit
                loc = j;
                hit = true;
                break;
            }
        }

        int tt = hit ? loc : cash.size() - 1;
        for (int j = tt; j > 0; j--) { // 뒤로 밀기
            cash[j] = cash[j - 1];
        }
        cash[0] = task;
    }
    for (int i = 0; i < cash.size(); i++) {
        cout << cash[i] << ' ';
    }
}

//int main() {
//    ex037();
//    std::cout << "done!" << std::endl;
//}
//7 5 3 2 6