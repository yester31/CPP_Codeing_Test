#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// N!에서 0의 개수(소인수분해 응용)

void ex028() {
    int N = 12;
    int tmp, div;
    vector<int> ch(N + 1);

    for (int idx = 2; idx <= N; idx++) {
        tmp = idx;
        div = 2;
        while (tmp > 1) {
            if (tmp % div == 0) {
                tmp /= div;
                ch[div]++;
            }
            else {
                div++;
            }
        }
    }
    cout << min(ch[2], ch[5]) << endl;
}

//int main() {
//    ex028();
//    std::cout << "done!" << std::endl;
//}
//2