#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 3등의 성적은? (정렬 응용)

void ex033() {
    vector<int> a{ 80, 96, 75, 82, 96, 92, 100 };

    for (int i = 0; i < a.size(); i++) {
        int min = a[i];
        for (int j = 0; j < a.size(); j++) {
            if (a[j] < min) {
                a[i] = a[j];
                a[j] = min;
                min = a[i];
            }
        }
    }
    int rank = 1;
    for (int i = 0; i < a.size() - 1; i++) {
        if (rank == 3) {
            std::cout << a[i] << std::endl;
            break;
        }
        if (a[i] != a[i + 1]) rank++;
    }
}

//int main() {
//    ex033();
//    std::cout << "done!" << std::endl;
//}
//92