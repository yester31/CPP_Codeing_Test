#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �׷��� �ִܰŸ�(BFS)

void ex070() {
    int n = 6;
    vector<vector<int>> map(n + 1);
    vector<vector<int>> inputs{ {1, 3},
                                {1, 4},
                                {2, 1},
                                {2, 5},
                                {3, 4},
                                {4, 5},
                                {4, 6},
                                {6, 2},
                                {6, 5} };

    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0]].push_back(inputs[i][1]);
    }

    vector<int> ch(n + 1);
    vector<int> dis(n + 1);
    queue<int> Q;

    Q.push(1); // 1 �湮
    ch[1] = 1; // 1 �湮 ó��
    int x;
    while (!Q.empty()) {// Q�� ��� ������ ����
        x = Q.front(); // �� �� �� ����
        Q.pop(); // �� �� ������(�����)
        for (int i = 0; i < map[x].size(); i++) { // x �� ����� ������ ��ȸ
            if (ch[map[x][i]] == 0) { // �湮 �ߴ��� Ȯ��
                ch[map[x][i]] = 1; // �湮 ó��
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x] + 1; // ���������� ���� x �������� �Ÿ� �� + 1 
            }
        }
    }

    for (int i = 2; i < n + 1; i++) {
        cout << i << " : " << dis[i] << endl;
    }
}

//int main() {
//    ex070();
//    cout << endl << "done!" << endl;
//}
//2 : 3
//3 : 1
//4 : 1
//5 : 2
//6 : 2