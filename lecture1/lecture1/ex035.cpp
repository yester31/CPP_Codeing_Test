#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// Special Sort (버블정렬 응용: 구글 인터뷰)

void ex035() {
    vector<int> a{ 1, 2, 3, -3, -2, 5, 6, -6 };

    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (0 < a[j] && a[j + 1] < 0) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}

//int main() {
//    ex035();
//    std::cout << "done!" << std::endl;
//}
//