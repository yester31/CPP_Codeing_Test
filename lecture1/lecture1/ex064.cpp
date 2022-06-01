#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// °æ·Î Å½»ö(DFS)

static vector<int> ch(30);
static int cnt = 0;

static void dfs(int v, int n, vector<vector<int>>& map) {
    if (v == n - 1) {
        cnt++;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (map[v][i] == 1 && ch[i] == 0) {
                ch[i] = 1;
                dfs(i, n, map);
                ch[i] = 0;
            }
        }
    }
}

void ex064() {
    int n = 5;
    int v = 9;
    vector<vector<int>> inputs{ {1, 2}, {1, 3}, {1, 4}, {2, 1}, {2, 3}, {2, 5}, {3, 4}, {4, 2}, {4, 5} };
    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0] - 1][inputs[i][1] - 1] = 1;
    }

    ch[0] = 1;
    dfs(0, n, map);
    cout << cnt << endl;
}

//int main() {
//    ex064();
//    cout << endl << "done!" << endl;
//}
//6