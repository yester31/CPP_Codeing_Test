#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 모두의 약수(제한시간 1초)

void ex009_1(int N) {
    auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    vector<int> cnt_v;
    for (int i = 1; i < N + 1; i++)
    {
        int cnt = 0;
        for (int j = 1; j < i + 1; j++)
        {
            if (i % j == 0)
                cnt++;
        }
        cnt_v.push_back(cnt);
    }

    for (int i = 0; i < N; i++)
    {
        cout << cnt_v[i] << " ";
    }

    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
    std::cout << std::endl << "ex009_1 Dur time :: " << dur << " milliseconds" << std::endl;
}

void ex009_2(int N) {
    auto start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    vector<int> cnt_v(N);
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = i; j < N + 1; j += i) // 각 i 마다 i의 배수에 해당되는 수에 약수 개수 추가
        {
            cnt_v[j - 1]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << cnt_v[i] << " ";
    }

    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
    std::cout << std::endl << "ex009_2 Dur time :: " << dur << " milliseconds" << std::endl;
}

//int main() {
//    int N = 8;
//    ex009_1(N);
//    ex009_2(N);
//    std::cout << "done!" << std::endl;
//}
// 1 2 2 3 2 4 2 4
//ex009_1 Dur time :: 1 milliseconds
//1 2 2 3 2 4 2 4
//ex009_2 Dur time :: 1 milliseconds