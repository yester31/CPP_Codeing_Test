#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 친구인가? (Disjoint-set(서로수 집합) : Union&Find 자료구조)
// 서로 다른 집합에서 공통 원소가 없으면 서로수 집합.

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

int ex077() {
    int n = 9; // 학생 수
    int m = 7; // 숫자 쌍의 개수
    vector<vector<int>> inputs{ {1, 2},
                                {2, 3},
                                {3, 4},
                                {1, 5},
                                {6, 7},
                                {7, 8}, 
                                {8, 9}};

    for (int i = 1; i <= n; i++) {
        unf[i] = i;
    }

    for (int i = 0; i < m; i++){
        Union(inputs[i][0], inputs[i][1]);
    }

    if (Find(3) == Find (8)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

//int main() {
//    ex077();
//    cout << endl << "done!" << endl;
//}
////NO