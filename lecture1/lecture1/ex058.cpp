#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 이진트리 깊이우선탐색 (DFS: Depth First Search)
// dfs : 연결된 하나의 노드를 선택해서 계속 방문하고 막히면 다시 돌아가서 방문 안한 노드 방문
// 전위 순회 : 부모 노드 -> 왼쪽 자식 노드 -> 오른쪽 자식 노드
// 중위 순회 : 왼쪽 자식 노드 -> 부모 노드 -> 오늘쪽 자식 노드
// 후위 순회 : 왼쪽 자식 노드 -> 오른쪽 자식 노드 -> 부모 노드

void dfs_pre(int v) {
    if (v > 7) return;
    else {
        cout << v << " ";
        dfs_pre(v * 2); // 왼쪽
        dfs_pre(v * 2 + 1); // 오른쪽
    }
}

void dfs_mid(int v) {
    if (v > 7) return;
    else {
        dfs_mid(v * 2); // 왼쪽
        cout << v << " ";
        dfs_mid(v * 2 + 1); // 오른쪽
    }
}

void dfs_post(int v) {
    if (v > 7) return;
    else {
        dfs_post(v * 2); // 왼쪽
        dfs_post(v * 2 + 1); // 오른쪽
        cout << v << " ";
    }
}

void ex058() {
    dfs_pre(1);
    cout << endl;
    dfs_mid(1);
    cout << endl;
    dfs_post(1);

}

//int main() {
//    ex058();
//    cout << endl << "done!" << endl;
//}
//1 2 4 5 3 6 7
//4 2 5 1 6 3 7
//4 5 2 6 7 3 1
