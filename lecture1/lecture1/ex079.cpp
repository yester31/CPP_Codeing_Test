#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 원더랜드(Prim MST 알고리즘 : priority_queue 활용)
// 최소비용신장트리 

int ex079() {
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
                                {8, 9, 15} };

    //cout << res << endl;

    return 0;
}

int main() {
    ex079();
    cout << endl << "done!" << endl;
}
// 196