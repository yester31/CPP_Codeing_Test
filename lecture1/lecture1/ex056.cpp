#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// ����Լ� �м� (������ �̿��ϴ� ���)

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
