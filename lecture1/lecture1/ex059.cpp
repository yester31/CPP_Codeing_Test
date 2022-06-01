#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// �κ����� (MS ���ͺ� ���� : DFS ����Ž��)

static int n = 3;
static vector<int> ch(n);

static void dfs(int L) {
    if (L == n) {
        for (int i = 0; i < ch.size(); i++) {
            if (ch[i] == 1) cout << i + 1;
        }cout << endl;
        return;
    }
    else {
        ch[L] = 1;
        dfs(L + 1);
        ch[L] = 0;
        dfs(L + 1);
    }
}

void ex059() {
    dfs(0);
    cout << endl;
}

//int main() {
//    ex059();
//    cout << endl << "done!" << endl;
//}
//123
//12
//13
//1
//23
//2
//3