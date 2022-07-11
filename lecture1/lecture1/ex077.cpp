#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ģ���ΰ�? (Disjoint-set(���μ� ����) : Union&Find �ڷᱸ��)
// ���� �ٸ� ���տ��� ���� ���Ұ� ������ ���μ� ����.

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
    int n = 9; // �л� ��
    int m = 7; // ���� ���� ����
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