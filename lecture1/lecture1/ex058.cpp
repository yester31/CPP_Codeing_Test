#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// ����Ʈ�� ���̿켱Ž�� (DFS: Depth First Search)
// dfs : ����� �ϳ��� ��带 �����ؼ� ��� �湮�ϰ� ������ �ٽ� ���ư��� �湮 ���� ��� �湮
// ���� ��ȸ : �θ� ��� -> ���� �ڽ� ��� -> ������ �ڽ� ���
// ���� ��ȸ : ���� �ڽ� ��� -> �θ� ��� -> ������ �ڽ� ���
// ���� ��ȸ : ���� �ڽ� ��� -> ������ �ڽ� ��� -> �θ� ���

void dfs_pre(int v) {
    if (v > 7) return;
    else {
        cout << v << " ";
        dfs_pre(v * 2); // ����
        dfs_pre(v * 2 + 1); // ������
    }
}

void dfs_mid(int v) {
    if (v > 7) return;
    else {
        dfs_mid(v * 2); // ����
        cout << v << " ";
        dfs_mid(v * 2 + 1); // ������
    }
}

void dfs_post(int v) {
    if (v > 7) return;
    else {
        dfs_post(v * 2); // ����
        dfs_post(v * 2 + 1); // ������
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
