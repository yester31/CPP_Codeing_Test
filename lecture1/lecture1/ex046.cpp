#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// ��Ƽ�½�ŷ(īī�� �Թ� ���� ����)

void ex046() {
    int n = 3;
    vector<int> a{ 1, 2, 3 };
    int k = 5;
    int pos = 0;
    int cnt = 0;
    int tot;

    while (1) {
        pos++;
        if (pos > n) pos = 1;
        if (a[pos - 1] == 0) continue;
        a[pos - 1]--;
        cnt++;
        if (cnt == k) break;
    }
    while (1) {
        pos++;
        if (pos > n) pos = 1;
        if (a[pos - 1] != 0) break;
    }
    cout << pos << endl;
}

//int main() {
//    ex046();
//    std::cout << "done!" << std::endl;
//}
//3