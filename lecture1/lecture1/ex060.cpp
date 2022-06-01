#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 합이 같은 부분 집합 (아마존 인터뷰 문제 : DFS 완전탐색)

static vector<int> nums{ 1, 3, 5, 6, 7, 10 };
static bool flag = false;

static void dfs(int L, int sum, int tot) {
    if (flag) return;
    if (L == nums.size()) {
        if (sum == (tot - sum)) flag = true;
    }
    else {
        dfs(L + 1, sum + nums[L], tot);
        dfs(L + 1, sum, tot);
    }
}

void ex060() {
    int tot = 0;
    for (int i = 0; i < nums.size(); i++) {
        tot += nums[i];
    }
    dfs(0, 0, tot);
    if (flag) cout << "YES";
    else cout << "NO";

    cout << endl;
}

//int main() {
//    ex060();
//    cout << endl << "done!" << endl;
//}
// YES