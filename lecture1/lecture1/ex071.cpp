#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 송아지 찾기(BFS : 상태트리탐색)

void ex071() {
    int max = 10000;
    vector<int> jump{1, -1, 5};
    vector<int> ch(max + 1);
    queue<int> Q;
    int start = 5;
    int end = 14;

    Q.push(start); // 1 방문
    ch[start] = 1; // 1 방문 처리
    int x, pos;
    while (!Q.empty()) {// Q가 비어 있으면 종료
        x = Q.front(); // 맨 앞 값 참조
        Q.pop(); // 맨 앞 꺼내기(지우기)
        for (int i = 0; i < jump.size(); i++) { 
            pos = x + jump[i];
            if (pos <= 0|| pos > 10000) {
                continue;
            }
            if (end == pos) { // 종료
                cout << ch[x] << endl;
                while (!Q.empty()) Q.pop();
                break;
            }
            if (ch[pos] == 0) { // 아직 방문을 하지 안했으면
                ch[pos] = ch[x] + 1; // 방문 처리 및 거리 저장
                Q.push(pos);
            }
        }
    }
}

//int main() {
//    ex071();
//    cout << endl << "done!" << endl;
//}
// 3