#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 숫자의 총 개수 (small)

void ex011() {
    auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    int N = 15;
    int cnt = 0;
    for (int i = 1; i < N + 1; i++)
    {
        int target = i;
        while (target)
        {
            cnt++;
            target /= 10;
        }
    }

    cout << cnt << endl;

    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
    std::cout << std::endl << "ex011 1 Dur time :: " << dur << " milliseconds" << std::endl;
}


int main() {
    ex011();
    std::cout << "done!" << std::endl;
}
// 21