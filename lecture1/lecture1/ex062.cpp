#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 병합정렬 (dfg 후위 순회)

static vector<int> tmp(8);

static void divide(int lt, int rt, vector<int>& data) {
    int mid;
    int p1, p2, p3;
    if (lt < rt) {
        mid = (lt + rt) / 2;
        divide(lt, mid, data);
        divide(mid + 1, rt, data);
        p1 = lt;
        p2 = mid + 1;
        p3 = lt;
        while (p1 <= mid && p2 <= rt) {
            if (data[p1] < data[p2]) tmp[p3++] = data[p1++];
            else tmp[p3++] = data[p2++];
        }
        while (p1 <= mid) tmp[p3++] = data[p1++];
        while (p2 <= rt) tmp[p3++] = data[p2++];
        for (int i = lt; i <= rt; i++) {
            data[i] = tmp[i];
        }
    }
}

void ex062() {
    vector<int> data = { 7, 6, 3, 1, 5, 2, 4, 8 };
    divide(0, data.size() - 1, data);
    for (int i = 0; i < data.size(); i++) {
        cout << data[i];
    }
}

//int main() {
//    ex062();
//    cout << endl << "done!" << endl;
//}
// 12345678