#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Prime Number �Ҽ� ���� ���ϱ�
// �Ҽ��� �ڽ��� ������ �ڿ����δ� ������ �������� �ʴ� �ڿ���

// 1) ��� ���� ���� ����� �ִ��� Ȯ��
void ex015_1(int N) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int count = 0;
    for (int j = 2; j < N; j++) {
        bool flag = true;
        for (int i = 2; i < j; i++) {
            if (j % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }

    auto dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "(1) 1 ���� " << N << " ���� ���̿� �����ϴ� �Ҽ� ���� : " << count << " ex015_1 Dur time :: " << dur << " milliseconds" << endl;
}

// 2) ��� ����� ��� ����� �������� ��Ī�� ���� ���� �̿� (�����ٱ����� Ȯ�� �ϸ� ��)
void ex015_2(int N) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int count = 0;
    for (int j = 2; j < N; j++) {
        bool flag = true;
        for (int i = 2; i * i <= j; i++) {
            if (j % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }

    auto dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "(2) 1 ���� " << N << " ���� ���̿� �����ϴ� �Ҽ� ���� : " << count << " ex015_2 Dur time :: " << dur << " milliseconds" << endl;
}

// 3) �����佺�׳׽��� ü �˰��� �̿�
// 1. 2���� N���� ��� �ڿ��� ����
// 2. ���� �ڿ��� �� ó������ ���� ���� ���� �� ã��
// 3. 2�� ���� ã�� ���� ���� ���� ����� ��� ���� (�ش� ���� ���� �������� �ʴ´�.)
// 4. ������ 2���� 3���� �ݺ�
void ex015_3(int N) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int count = 0;
    vector<int> container(N);
    for (int i = 2; i < N; i++) {
        container[i] = i;   // 2���� N���� ��� �ڿ��� ����
    }

    for (int i = 2; i < N; i++) {
        if (container[i] == 0) continue;    // �̹� ó�� ��ٸ� ���
        for (int j = i + i; j < N; j += i) {// �ش� ���� ���� �������� �ʵ��� i+i���� ���� 
            container[j] = 0;               // �ش� ���� ���� ���� ����� ��� ����
        }
    }

    for (int i = 2; i < N; i++) {
        if (container[i] != 0) count++; // �Ҽ� ī��Ʈ
    }

    auto dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "(3) 1 ���� " << N << " ���� ���̿� �����ϴ� �Ҽ� ���� : " << count << " ex015_3 Dur time :: " << dur << " milliseconds" << endl;
}


//int main() {
//    int max = 399999;
//    ex015_1(max);
//    ex015_2(max);
//    ex015_3(max);
//    return 0;
//}
//(1) 1 ���� 399999 ���� ���̿� �����ϴ� �Ҽ� ���� : 33860 ex015_1 Dur time :: 10670 milliseconds
//(2) 1 ���� 399999 ���� ���̿� �����ϴ� �Ҽ� ���� : 33860 ex015_2 Dur time :: 37 milliseconds
//(3) 1 ���� 399999 ���� ���̿� �����ϴ� �Ҽ� ���� : 33860 ex015_3 Dur time :: 335 milliseconds