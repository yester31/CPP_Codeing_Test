#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Anagram (���� ���ͺ� ����)
// ���� ������ �ٸ����� ������ ��ġ�ϸ� �Ƴ��׷��̶� ��.

void ex016() {
    string a = "AbaAeCe";
    string b = "baeeACA";
    //string b = "baeeACs";
    vector <int> chars1(52); // 26(�ҹ��� 97 - 122) + 26 (�빮�� 65 - 90)
    vector <int> chars2(52); // 26(�ҹ��� 97 - 122) + 26 (�빮�� 65 - 90)
    for (int i = 0; i < a.size(); i++) {
        int aski1 = int(a[i]);
        if (65 <= aski1 && 90 >= aski1) {   //�빮��
            chars1[aski1 - 39]++;
        }
        else {                              //�ҹ���
            chars1[aski1 - 97]++;
        }

        int aski2 = int(b[i]);
        if (65 <= aski2 && 90 >= aski2) {   // �빮��
            chars2[aski2 - 39]++;
        }
        else {                              //�ҹ���
            chars2[aski2 - 97]++;
        }
    }
    int flag = 0;
    for (int i = 0; i < chars1.size(); i++) {
        if (chars1[i] != chars2[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << "diff" << endl;
    }
    else {
        cout << "same" << endl;
    }
}

//int main() {
//    ex016();
//    std::cout << "done!" << std::endl;
//}
// same