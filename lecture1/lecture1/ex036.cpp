#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// ��������

void ex036() {
    vector<int> a{ 7, 11, 5, 6, 10, 9 };
    int j;
    for (int i = 1; i < a.size(); i++) {
        int tmp = a[i];
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > tmp) {
                a[j + 1] = a[j]; // �ڷ� �̵�
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp; // ������� ���ĵ� ���ڵ� �ٷ� �ڿ� ����
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}

//int main() {
//    ex036();
//    std::cout << "done!" << std::endl;
//}
// 5 6 7 9 10 11