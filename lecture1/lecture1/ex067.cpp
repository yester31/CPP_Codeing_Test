#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 경로 탐색(DFS : 인접리스트 방법)
static int cost = 2147000000;
static const int n = 5;
static vector<int> ch(n+1);
static vector<vector<int>> map(n+1 , vector<int>(n+1, 0));

static void dfs(int v, int sum) {
    if (v == 5) {
        if (cost > sum)
            cost = sum;
    }
    else {
        for (int i = 1; i < map[v].size(); i++) {
            if (ch[i] == 0 && map[v][i] != 0) {
                ch[i] = 1;
                dfs(i, sum + map[v][i]);
                ch[i] = 0;
            }
        }
    }
}

void ex067() {
    vector<vector<int>> inputs{ {1, 2, 12}, {1, 3, 6}, {1, 4, 10}, {2, 3, 2}, {2, 5, 2}, {3, 4, 3}, {4, 2, 2}, {4, 5, 5} };
    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0]][inputs[i][1]] = inputs[i][2];
    }
    ch[1] = 1;
    dfs(1, 0);
    cout << cost << endl;
}

//int main() {
//    ex067();
//    cout << endl << "done!" << endl;
//}
// 13