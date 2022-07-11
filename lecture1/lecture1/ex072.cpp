#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 공주 구하기 (큐 자료구조로 해결)

void ex072() {
    int n = 8; // 왕자수
    int c = 3;
    queue<int> Q;

    for (int i = 1; i <= n; i++) {
        Q.push(i); // 1 방문
    }

    int x;
    int count = 1;
    while (Q.size() != 1) {// Q가 비어 있으면 종료
        x = Q.front(); // 맨 앞 값 참조
        Q.pop(); // 맨 앞 꺼내기(지우기)
        if (count == c) {
            count = 1;
        }
        else {
            Q.push(x);
            count++;
        }
    }
    x = Q.front();
    cout << x << endl;
}

//int main() {
//    ex072();
//    cout << endl << "done!" << endl;
//}
//// 7