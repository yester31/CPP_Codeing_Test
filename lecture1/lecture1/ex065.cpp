#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// ¹Ì·ÎÅ½»ö(DFS)

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

void ex065() {
    vector<vector<int>> map{{0, 0, 0, 0, 0, 0, 0},
                            {0, 1, 1, 1, 1, 1, 0},
                            {0, 0, 0, 1, 0, 0, 0},
                            {1, 1, 0, 1, 0, 1, 1},
                            {1, 1, 0, 0, 0, 0, 1},
                            {1, 1, 0, 1, 1, 0, 0},
                            {1, 0, 0, 0, 0, 0, 0} };

    cout << cnt << endl;
}

int main() {
    ex065();
    cout << endl << "done!" << endl;
}
//6