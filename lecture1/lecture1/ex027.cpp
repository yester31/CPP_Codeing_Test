#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// N!의 표현법

void ex027() {
    int N = 53;
    int tmp, div;
    vector<int> ch(N+1);

    for (int idx = 2; idx <=N; idx++) {
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

    for (int idx = 0; idx <= N; idx++) {
        if (ch[idx]) 
            cout << ch[idx] << " ";
    }
}

//int main() {
//    ex027();
//    std::cout << "done!" << std::endl;
//}
//49 23 12 8 4 4 3 2 2 1 1 1 1 1 1 1