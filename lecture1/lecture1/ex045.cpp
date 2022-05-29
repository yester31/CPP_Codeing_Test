#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 공주 구하기

void ex045() {
    int K = 3;
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> b(a.size());
    int pos = K - 1;
    b[pos] = 1;
    int cnt = 1;
    while (cnt < 7) {
        for (int i = 0; i < K; i++) { // 3 칸 씩 이동
            if (pos == a.size() - 1) pos = 0;
            else pos++;

            while (b[pos] == 1) {
                if (pos == a.size() - 1) pos = 0;
                else pos++;
            }
        }
        b[pos] = 1;
        cnt++;
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == 0) cout << i + 1 << endl;
    }
}

//int main() {
//    ex045();
//    std::cout << "done!" << std::endl;
//}
//3