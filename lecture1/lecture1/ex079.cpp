#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ��������(Prim MST �˰��� (�ּҽ��д�Ʈ��): priority_queue Ȱ��)
// �ּҺ�����Ʈ�� 
static vector<int> ch(30);
struct Edge2 {
    int e, val;
    Edge2(int a, int b) {
        e = a;
        val = b;
    }
    bool operator<(const Edge2 &b) const {
        return val > b.val; // ��������(�ּ������� ����)
    }
};

int ex079() {
    int n = 9; // ����
    int m = 12; // ����
    vector<vector<int>> inputs{ {1, 2, 12},
                                {1, 9, 25},
                                {2, 3, 10},
                                {2, 8, 17},
                                {2, 9, 8 },
                                {3, 4, 18},
                                {3, 7, 55},
                                {4, 5, 44},
                                {5, 6, 60},
                                {5, 7, 38},
                                {7, 8, 35},
                                {8, 9, 15} };
    priority_queue<Edge2> Q;
    vector<pair<int, int>> map[30]; // ����ġ ��������Ʈ
    for (int i = 0; i < m; i++) { // ������
        map[inputs[i][0]].push_back(make_pair(inputs[i][1], inputs[i][2]));
        map[inputs[i][1]].push_back(make_pair(inputs[i][0], inputs[i][2]));
    }
    int res = 0;
    Q.push(Edge2(1, 0));
    while (!Q.empty()) {
        Edge2 tmp = Q.top();
        Q.pop();
        int v = tmp.e;
        int cost = tmp.val;
        if (ch[v] == 0) {
            res += cost;
            ch[v] = 1;
            for (int i = 0; i < map[v].size(); i++) {
                Q.push(Edge2(map[v][i].first, map[v][i].second));
            }
        }
    }
    cout << res << endl;
    return 0;
}

//int main() {
//    ex079();
//    cout << endl << "done!" << endl;
//}
// 196