#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// Ugly Numbers (투포인트 알고리즘 응용)

void ex052() {
    int N = 1500;
    vector<int> a(N);
    int pt2 = 0;
    int pt3 = 0;
    int pt5 = 0;
    a[0] = 1;
    int min = 9999;
    for (int i = 1; i < a.size(); i++) {
        if (a[pt2] * 2 < a[pt3] * 3) min = a[pt2] * 2;
        else min = a[pt3] * 3;
        if (a[pt5] * 5 < min) min = a[pt5] * 5;
        if (a[pt2] * 2 == min) pt2++;
        if (a[pt3] * 3 == min) pt3++;
        if (a[pt5] * 5 == min) pt5++;
        a[i] = min;
    }

    cout << a[a.size() - 1] << endl;
}

//int main() {
//    ex052();
//    std::cout << "done!" << std::endl;
//}
//859963392