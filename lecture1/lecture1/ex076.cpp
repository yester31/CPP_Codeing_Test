#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 이항계수(메모이제이션)
// ex 5C3 = 4C2 + 4C3
int dy[21][21];
static int DFS(int n, int r) {
    if (dy[n][r] > 0) return dy[n][r];
    if (n == r || r==0) {
        return 1;
    }
    else {
        return dy[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r);
    }
}

int ex076() {
    int n = 5;
    int r = 3;

    cout << DFS(n, r) << endl;
    return 0;
}

//int main() {
//    ex076();
//    cout << endl << "done!" << endl;
//}
////10