#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �۾��� ã��(BFS : ����Ʈ��Ž��)

void ex071() {
    int max = 10000;
    vector<int> jump{1, -1, 5};
    vector<int> ch(max + 1);
    queue<int> Q;
    int start = 5;
    int end = 14;

    Q.push(start); // 1 �湮
    ch[start] = 1; // 1 �湮 ó��
    int x, pos;
    while (!Q.empty()) {// Q�� ��� ������ ����
        x = Q.front(); // �� �� �� ����
        Q.pop(); // �� �� ������(�����)
        for (int i = 0; i < jump.size(); i++) { 
            pos = x + jump[i];
            if (pos <= 0|| pos > 10000) {
                continue;
            }
            if (end == pos) { // ����
                cout << ch[x] << endl;
                while (!Q.empty()) Q.pop();
                break;
            }
            if (ch[pos] == 0) { // ���� �湮�� ���� ��������
                ch[pos] = ch[x] + 1; // �湮 ó�� �� �Ÿ� ����
                Q.push(pos);
            }
        }
    }
}

//int main() {
//    ex071();
//    cout << endl << "done!" << endl;
//}
// 3