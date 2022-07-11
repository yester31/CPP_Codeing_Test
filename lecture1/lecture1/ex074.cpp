#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 최소힙 (priority_queue : 우선순위 큐)

//최소힙은 완전이진트리로 구현된 자료구조입니다.그 구성은 부모 노드값이 왼쪽자식과 오른
//쪽 자식노드의 값보다 작게 트리를 구성하는 것입니다.그렇게 하면 트리의 루트(root)노드는
//입력된 값들 중 가장 작은 값이 저장되어 있습니다.

void ex074() {

    priority_queue<int> pQ;
    vector<int> input = { 5,3,6,0,5,0,2,4,0,-1 };
    int a;
    int pos = 0;
    while (true) {
        a = input[pos]; // 맨 앞 값 참조
        pos++;
        if (a == -1) break;
        if (a == 0) {
            if (pQ.empty()) {
                cout << "-1" << endl;
            }
            else {
                cout << -pQ.top() << endl; //root 값
                pQ.pop();
            }
        }
        else {
            pQ.push(-a);
        }
    }
}

//int main() {
//    ex074();
//    cout << endl << "done!" << endl;
//}
//3
//5
//2
