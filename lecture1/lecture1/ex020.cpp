#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// ���� ���� ��(�⺻�ڵ�����)

void ex020() {
    int N = 5;
    vector<int> a = { 2, 3, 3, 1, 3 };
    vector<int> b = { 1, 1, 2, 2, 3 };
    // ���� : 1 , ���� : 2, �� : 3
    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            cout << "D" << endl;
        }
        else if (a[i] == 1 && b[i] == 3) {
            cout << "A" << endl;
        }
        else if (a[i] == 2 && b[i] == 1) {
            cout << "A" << endl;
        }
        else if (a[i] == 3 && b[i] == 2) {
            cout << "A" << endl;
        }
        else {
            cout << "B" << endl;
        }
    }
}

//int main() {
//    ex020();
//    std::cout << "done!" << std::endl;
//}
//A
//B
//A
//B
//D