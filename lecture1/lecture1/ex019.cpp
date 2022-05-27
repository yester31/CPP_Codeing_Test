#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 분노 유발자(1차원 배열의 필요성)

void ex019() {
    int N = 10; //
    vector<int> values = { 56, 46, 55, 76, 65, 53, 52, 53, 55, 50 };
    int cnt = 0;
    int max = values[values.size() - 1];
    for (int i = values.size() - 2; i >= 0; i--) {
        if (values[i] > max) {
            max = values[i];
            cnt++;
        }
    }
    cout << cnt << endl;
}

//int main() {
//    ex019();
//    std::cout << "done!" << std::endl;
//}
//3