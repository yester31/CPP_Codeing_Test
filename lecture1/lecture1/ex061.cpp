#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 병합정렬

static vector<int> nums{ 2, 4, 6, 8 };
static int cnt = 0;

static void dfs(int L, int sum, int m) {
    if (L == nums.size()) {
        if (sum == m) {
            cnt++;
        }
    }
    else {
        dfs(L + 1, sum + nums[L], m);
        dfs(L + 1, sum - nums[L], m);
        dfs(L + 1, sum, m);
    }
}

void ex061() {
    int m = 12;
    dfs(0, 0, m);
    if (cnt > 0) cout << cnt;
    else cout << "-1";
    cout << endl;
}

//int main() {
//    ex061();
//    cout << endl << "done!" << endl;
//}
// 4