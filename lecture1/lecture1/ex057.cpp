#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 재귀함수(스택)를 이용한 2진수 출력

void binary(int x) {
    if (x == 0) return;
    binary(x / 2);
    cout << x % 2;
}

void ex057() {
    int n = 11;
    binary(n);
}

//int main() {
//    ex057();
//    cout << endl << "done!" << endl;
//}
//1011
