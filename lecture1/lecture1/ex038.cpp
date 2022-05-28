#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// Inversion Sequence (삽입정렬 코드스타일)

void ex038() {
    int cash_size = 8;
    vector<int> is{ 5, 3, 4, 0, 2, 1, 1, 0 };
    vector<int> os(cash_size);

    for (int i = is.size() - 1; i >= 0; i--) {
        int tt = i + 1;
        int j = 0;
        for (; j < is[i]; j++) {
            os[i + j] = os[i + j + 1];
        }
        os[i + j] = tt;
    }
    for (int i = 0; i < os.size(); i++) {
        cout << os[i] << ' ';
    }
}
//
//int main() {
//    ex038();
//    std::cout << "done!" << std::endl;
//}
//4 8 6 2 5 1 3 7