#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// ���� ����

void ex018() {
    int N = 10; // 10�ʴ����� ����
    int M = 90; // �溸�� thre
    vector<int> values = { 23, 17, 120, 34, 112, 136, 123, 23, 25, 113 };
    int cnt = 0;
    int max = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] > M) {
            cnt++;
            if (cnt > max) {
                max = cnt;
            }
        }
        else {
            cnt = 0;
        }
    }

    if (max == 0) {
        cout << -1 << endl;
    }
    else {
        cout << max << endl;
    }
}

//int main() {
//    ex018();
//    std::cout << "done!" << std::endl;
//}
//3