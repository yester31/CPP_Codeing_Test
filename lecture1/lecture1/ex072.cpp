#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� ���ϱ� (ť �ڷᱸ���� �ذ�)

void ex072() {
    int n = 8; // ���ڼ�
    int c = 3;
    queue<int> Q;

    for (int i = 1; i <= n; i++) {
        Q.push(i); // 1 �湮
    }

    int x;
    int count = 1;
    while (Q.size() != 1) {// Q�� ��� ������ ����
        x = Q.front(); // �� �� �� ����
        Q.pop(); // �� �� ������(�����)
        if (count == c) {
            count = 1;
        }
        else {
            Q.push(x);
            count++;
        }
    }
    x = Q.front();
    cout << x << endl;
}

//int main() {
//    ex072();
//    cout << endl << "done!" << endl;
//}
//// 7