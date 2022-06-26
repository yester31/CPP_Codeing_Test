#include <iostream>
#include <vector>
using namespace std;

// 경로 탐색(DFS), 완전 탐색

static vector<int> check(30);
static int cnt = 0;

static void dfs(int v, int n, vector<vector<int>>& map) {
    if (v == n - 1) {// 도착 지점에 왔느냐?
        cnt++;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (map[v][i] == 1 && check[i] == 0) {
                check[i] = 1;
                dfs(i, n, map);
                check[i] = 0;
            }
        }
    }
}

void ex064() {
    int n = 5;
    vector<vector<int>> inputs{ {1, 2}, 
                                {1, 3},
                                {1, 4},
                                {2, 1},
                                {2, 3},
                                {2, 5},
                                {3, 4},
                                {4, 2},
                                {4, 5} };
    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0] - 1][inputs[i][1] - 1] = 1;
    }

    check[0] = 1;
    dfs(0, n, map);
    cout << cnt << endl;
}

//int main() {
//    ex064();
//    cout << endl << "done!" << endl;
//}
//6