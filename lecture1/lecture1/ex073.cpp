#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �ִ��� (priority_queue : �켱���� ť)

//�ִ����� ��������Ʈ���� ������ �ڷᱸ���Դϴ�.�� ������ �θ� ��尪�� �����ڽİ� ����
//�� �ڽĳ���� ������ ũ�� Ʈ���� �����ϴ� ���Դϴ�.�׷��� �ϸ� Ʈ���� ��Ʈ(root)����
//�Էµ� ���� �� ���� ū ���� ����Ǿ� �ֽ��ϴ�.

void ex073() {

    priority_queue<int> pQ;
    vector<int> input = { 5,3,6,0,5,0,2,4,0,-1 };
    int a;
    int pos = 0;
    while (true) {
        a = input[pos]; // �� �� �� ����
        pos++;
        if (a == -1) break;
        if (a == 0) {
            if (pQ.empty()) {
                cout << "-1" << endl;
            }
            else {
                cout << pQ.top() << endl; //root ��
                pQ.pop();
            }
        }
        else {
            pQ.push(a);
        }
    }
}

//int main() {
//    ex073();
//    cout << endl << "done!" << endl;
//}
//6
//5
//5