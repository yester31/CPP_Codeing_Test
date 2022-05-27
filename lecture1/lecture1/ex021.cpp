#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// 카드게임(기본코딩설계)

void ex021() {
    int N = 10;
    vector<int> a = { 9,1,7,2,6,3,0,4,8,5 };
    vector<int> b = { 6,3,9,2,1,0,7,4,8,5 };
    int a_v = 0;
    int b_v = 0;
    string last;
    for (int i = 0; i < N; i++) {
        if (a[i] > b[i]) {
            a_v += 3;
            last = "A";
        }
        else if (a[i] < b[i]) {
            b_v += 3;
            last = "B";
        }
        else {
            a_v += 1;
            b_v += 1;
        }
    }

    if (a_v > b_v) {
        cout << "A" << endl;
    }
    else if (a_v < b_v) {
        cout << "B" << endl;
    }
    else {
        cout << last << endl;
    }
}

//int main() {
//    ex021();
//    std::cout << "done!" << std::endl;
//}
//B