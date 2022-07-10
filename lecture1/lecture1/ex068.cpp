#include <iostream>
#include <vector>

using namespace std;

// 최소 비용 탐색(DFS : 인접리스트 방법, 가중치 방향 그래프)
static int cost = 2147000000;
static const int n = 5;
static vector<int> check(n + 1);
static vector<vector<pair<int, int> >> map(n + 1);

static void dfs(int v, int sum /* 비용값 */) {
    if (v == 5) {
        if (cost > sum) // 지금까지 구한 비용중 최소 비용이면 
            cost = sum; // 현재 구한 최소비용으로 업데이트
    }
    else {
        for (int i = 0; i < map[v].size(); i++) {
            int next_node = map[v][i].first;
            int weight = map[v][i].second;
            if (check[next_node] == 0) {
                check[next_node] = 1;
                dfs(next_node, sum + weight);
                check[next_node] = 0;
            }
        }
    }
}

void ex068() {
    vector<vector<int>> inputs{ {1, 2, 12},
                                {1, 3, 6},
                                {1, 4, 10},
                                {2, 3, 2},
                                {2, 5, 2},
                                {3, 4, 3},
                                {4, 2, 2},
                                {4, 5, 5} };

    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0]].push_back(make_pair(inputs[i][1], inputs[i][2]));
    }

    check[1] = 1;
    dfs(1, 0);
    cout << cost << endl;
}

//int main() {
//    ex068();
//    cout << endl << "done!" << endl;
//}
// 13