#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 그래프 최단거리(BFS)

void ex070() {
    int n = 6;
    vector<vector<int>> map(n + 1);
    vector<vector<int>> inputs{ {1, 3},
                                {1, 4},
                                {2, 1},
                                {2, 5},
                                {3, 4},
                                {4, 5},
                                {4, 6},
                                {6, 2},
                                {6, 5} };

    for (int i = 0; i < inputs.size(); i++) {
        map[inputs[i][0]].push_back(inputs[i][1]);
    }

    vector<int> ch(n + 1);
    vector<int> dis(n + 1);
    queue<int> Q;

    Q.push(1); // 1 방문
    ch[1] = 1; // 1 방문 처리
    int x;
    while (!Q.empty()) {// Q가 비어 있으면 종료
        x = Q.front(); // 맨 앞 값 참조
        Q.pop(); // 맨 앞 꺼내기(지우기)
        for (int i = 0; i < map[x].size(); i++) { // x 와 연결된 노드들을 순회
            if (ch[map[x][i]] == 0) { // 방문 했는지 확인
                ch[map[x][i]] = 1; // 방문 처리
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x] + 1; // 시작점에서 부터 x 정점까지 거리 값 + 1 
            }
        }
    }

    for (int i = 2; i < n + 1; i++) {
        cout << i << " : " << dis[i] << endl;
    }
}

//int main() {
//    ex070();
//    cout << endl << "done!" << endl;
//}
//2 : 3
//3 : 1
//4 : 1
//5 : 2
//6 : 2