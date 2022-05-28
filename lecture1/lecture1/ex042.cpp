#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 이분검색

void sort_insert(vector<int> & vec) {
    int i, j, tmp;
    for (i = 1; i < vec.size(); i++) {
        tmp = vec[i];
        for (j = i - 1; j >= 0; j--) {
            if (tmp < vec[j]) vec[j + 1] = vec[j];
            else break;
        }
        vec[j + 1] = tmp;
    }
}

void ex042() {
    int M = 32;
    vector<int> a{ 23, 87, 65, 12, 57, 32, 99, 81 };
    sort_insert(a);



}

int main() {
    ex042();
    std::cout << "done!" << std::endl;
}
//7 + 8 = 15
//4 + 5 + 6 = 15
//1 + 2 + 3 + 4 + 5 = 15