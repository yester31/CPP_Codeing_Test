#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// Jolly Jumpers

void ex024() {
    bool flag = true;
    int N = 5;
    vector<int> numbers{ 1,4,2,3,7 };
    vector<int> check(N, 0);
    int diff = 0;
    for (int idx = 0; idx < N - 1; idx++) {
        diff = abs(numbers[idx] - numbers[idx + 1]);
        if (check[diff] == 1 || diff > N) {
            flag = false;
            break;
        }
        else {
            check[diff] = 1;
        }
    }
    if (flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

//int main() {
//    ex024();
//    std::cout << "done!" << std::endl;
//}
//YES