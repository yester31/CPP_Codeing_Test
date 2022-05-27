#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 3의 개수는? (small : 구글 인터뷰)

void ex029() {
    int N = 15;
    int cnt = 0;
    int tmp;
    vector<int> ch(N + 1);

    for (int idx = 1; idx <= N; idx++) {
        tmp = idx;
        while (tmp > 2) {
            if (tmp % 10 == 3) cnt++;
            tmp /= 10;
        }
    }
    cout << cnt << endl;
}

//int main() {
//    ex029();
//    std::cout << "done!" << std::endl;
//}
//2