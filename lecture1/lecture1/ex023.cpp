#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// ���� �κ� ��������

void ex023() {
    int n = 9;
    vector<int> values = { 5,7,3,3,12,12,13,10,11 };

    int cnt = 1; // ���� Ƚ��
    int pre = values[0];
    int max = 0;
    for (int i = 1; i < values.size(); i++) {
        if (pre <= values[i]) {
            cnt++;
        }
        else {
            if (cnt > max) {
                max = cnt;
            }
            cnt = 1;
        }
        pre = values[i];
    }
    cout << max << endl;
}

//int main() {
//    ex023();
//    std::cout << "done!" << std::endl;
//}
//5