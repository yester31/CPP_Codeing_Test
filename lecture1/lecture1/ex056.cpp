#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 재귀함수 분석 (스택을 이용하는 재귀)

void recur(int x) {
    if (x == 0) return;
    recur(x - 1);
    cout << "x : " << x << endl;
}

void ex056() {
    int n = 3;
    recur(n);
}

//int main() {
//    ex056();
//    cout << endl << "done!" << endl;
//}
//x : 1
//x : 2
//x : 3
