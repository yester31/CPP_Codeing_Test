#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// 석차 구하기(브루트포스)

void ex025() {
    int N = 5;
    vector<int> socres{ 90, 85, 92, 95, 90 };
    vector<int> orders(5, 1);
    for (int idx = 0; idx < N; idx++) {
        int score = socres[idx];
        for (int idx2 = idx; idx2 < N; idx2++) {
            if (score < socres[idx2]) {
                orders[idx]++;
            }
            else if (score == socres[idx2]) {
            }
            else {
                orders[idx2]++;
            }
        }
    }

    for (int idx = 0; idx < N; idx++) {
        cout << orders[idx] << " ";
    }
}

//int main() {
//    ex025();
//    std::cout << "done!" << std::endl;
//}
//3 5 2 1 3