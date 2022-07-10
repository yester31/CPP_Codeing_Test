#include <iostream>
#include <vector>

using namespace std;

// 이진트리 넓이 우선 탐색 (큐 자료구조 직접구현 : BFS)

int Q[100], front = -1, back = -1, ch[10];
int n = 7;
static vector<vector<int>> map(n + 1);

void ex069() {

    vector<vector<int>> inputs{ {1, 2},
                                {1, 3},
                                {2, 4},
                                {2, 5},
                                {3, 6},
                                {3, 7}};

    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0]].push_back(inputs[i][1]);
        map[inputs[i][1]].push_back(inputs[i][0]);
    }
    Q[++back] = 1;
    ch[1] = 1;
    int x;
    while (front < back) {
        x = Q[++front];
        printf("%d ", x);
        for (int i = 0; i < map[x].size(); i++) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;
                Q[++back] = map[x][i];
            }
        }
    }
}

//int main() {
//    ex069();
//    cout << endl << "done!" << endl;
//}
//// 1 2 3 4 5 6 7