#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// ¹Ì·ÎÅ½»ö(DFS)
static int n = 7;
static vector<vector<int>> ch(n, vector<int>(n, 0));
static int cnt = 0;

static void dfs(int h, int w, vector<vector<int>>& map) {
    if (n == h + 1 && n == w + 1) {
        cnt++;
    }
    else {
        if (w + 1 < n) {// µ¿
            if (map[h][w + 1] == 0 && ch[h][w + 1] == 0) {
                ch[h][w + 1] = 1;
                dfs(h, w + 1, map);
                ch[h][w + 1] = 0;
            }
        }
        if (w - 1 >= 0) {// ¼­
            if (map[h][w - 1] == 0 && ch[h][w - 1] == 0) {
                ch[h][w - 1] = 1;
                dfs(h, w - 1, map);
                ch[h][w - 1] = 0;
            }
        }
        if (h + 1 < n) {// ³²
            if (map[h + 1][w] == 0 && ch[h + 1][w] == 0) {
                ch[h + 1][w] = 1;
                dfs(h + 1, w, map);
                ch[h + 1][w] = 0;
            }
        }
        if (h - 1 >= 0) {// ºÏ
            if (map[h - 1][w] == 0 && ch[h - 1][w] == 0) {
                ch[h - 1][w] = 1;
                dfs(h - 1, w, map);
                ch[h - 1][w] = 0;
            }
        }
    }
}

void ex065() {
    vector<vector<int>> map{ {0, 0, 0, 0, 0, 0, 0},
                            {0, 1, 1, 1, 1, 1, 0},
                            {0, 0, 0, 1, 0, 0, 0},
                            {1, 1, 0, 1, 0, 1, 1},
                            {1, 1, 0, 0, 0, 0, 1},
                            {1, 1, 0, 1, 1, 0, 0},
                            {1, 0, 0, 0, 0, 0, 0} };
    ch[0][0] = 1;
    dfs(0, 0, map);
    cout << cnt << endl;
}

//int main() {
//    ex065();
//    cout << endl << "done!" << endl;
//}
// 8