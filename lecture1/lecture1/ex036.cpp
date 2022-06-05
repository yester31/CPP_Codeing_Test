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
    
    for (int i = 1; i < a.size(); i++) {
        int tmp = a[i];
        int j;
        for (j = i - 1; j >= 0; j--) { // 역순회
            if (a[j] > tmp) {
                a[j + 1] = a[j]; // 뒤로 이동
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp; // 현재까지 정렬된 숫자들 앞에 삽입
    }
    // 결과 출력
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}

//int main() {
//    ex036();
//    std::cout << "done!" << std::endl;
//}
// 5 6 7 9 10 11