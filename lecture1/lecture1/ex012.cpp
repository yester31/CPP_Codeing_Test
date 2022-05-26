#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 숫자의 총 개수 (large)

void ex011_1(int N) {
    auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    int cnt = 9;
    int num = 1;
    int count = 0;
    int answer = 0;

    while (N > cnt) {// 1 * 9 + 2 * 90 + 3 * 900 ...
        count += cnt;
        answer += cnt * num;
        cnt *= 10;
        num++;
    }
    answer += (N - count) * num;
    cout << answer << endl;
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
    std::cout << "ex011_1 Dur time :: " << dur << " milliseconds" << std::endl;
}

void ex011_2(int N) {
    auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    int cnt = 0;
    for (int i = 1; i < N + 1; i++) {
        int target = i;
        while (target) {
            cnt++;
            target /= 10;
        }
    }
    cout << cnt << endl;
    auto dur1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
    std::cout << "ex011_2 Dur time :: " << dur1 << " milliseconds" << std::endl;
}


//int main() {
//    int N = 131320121;
//    ex011_1(N);
//    ex011_2(N);
//    std::cout << "done!" << std::endl;
//}
// 1070769987
// ex011_1 Dur time :: 2 milliseconds
// 1070769987
// ex011_2 Dur time :: 2197 milliseconds