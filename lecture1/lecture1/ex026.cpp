#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// ∏∂∂Û≈Ê

void ex026() {
    int N = 8;
    vector<int> players{ 2, 8, 10, 7, 1, 9, 4, 15 };
    vector<int> ranks(8, 1);

    for (int idx = N - 1; idx >= 0; idx--) {
        for (int idx2 = idx - 1; idx2 >= 0; idx2--) {
            if (players[idx2] > players[idx]) {
                ranks[idx]++;
            }
        }
    }

    for (int idx = 0; idx < N; idx++) {
        cout << ranks[idx] << " ";
    }
}

//int main() {
//    ex026();
//    std::cout << "done!" << std::endl;
//}
//1 1 1 3 5 2 5 1