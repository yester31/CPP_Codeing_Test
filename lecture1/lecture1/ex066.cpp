#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 경로 탐색(DFS : 인접리스트 방법)
// 인접 행렬에 비해 메모리 사용량이 적다
static int cnt = 0;
static const int n = 5;
static vector<int> ch(n + 1);
static vector<vector<int>> map(n + 1);

void dfs(int v) {
    if (v == n) {
        cnt++;
    }
    else {
        for (int i = 0; i < map[v].size(); i++) {
            if (ch[map[v][i]] == 0) {
                ch[map[v][i]] = 1;
                dfs(map[v][i]);
                ch[map[v][i]] = 0;
            }
        }
    }
}

void ex066() {
    int v = 9;
    vector<vector<int>> inputs{ {1, 2},
                                {1, 3},
                                {1, 4},
                                {2, 1},
                                {2, 3},
                                {2, 5},
                                {3, 4},
                                {4, 2},
                                {4, 5} };
    for (auto itr = inputs.begin(); itr != inputs.end(); ++itr) {
        map[((*itr)[0])].push_back((*itr)[1]);
    }
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            cout << map[i][j] << " ";
        }cout << endl;
    }

    ch[1] = 1;
    dfs(1);
    cout << cnt << endl;

}

//int main() {
//    ex066();
//    cout << endl << "done!" << endl;
//}
// 6