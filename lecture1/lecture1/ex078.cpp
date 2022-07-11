#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 원더랜드(Kruskal MST 알고리즘 : Union&Find 활용)

struct Edge {
    int v1, v2, val;
    Edge(int a, int b, int c) {
        v1 = a;
        v2 = b;
        val = c;
    }
    bool operator<(const Edge &b) const {
        return val < b.val; // 오른차순 
    }
};

static int unf[1001];

static int Find(int v) {
    if (v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

static void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) unf[a] = b;
}

int ex078() {
    int n = 9; // 도시
    int m = 12; // 간선
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
                                {8, 9, 15}};

    for (int i = 1; i <= n; i++) {
        unf[i] = i;
    }
    vector<Edge> Ed;
    for (int i = 0; i < m; i++) {
        Ed.push_back(Edge(inputs[i][0], inputs[i][1], inputs[i][2]));
    }
    sort(Ed.begin(), Ed.end());
    int res = 0;
    for (int i = 0; i < m; i++) {
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if (fa != fb) {
            res += Ed[i].val;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    cout << res << endl;

    return 0;
}

//int main() {
//    ex078();
//    cout << endl << "done!" << endl;
//}
//// 196