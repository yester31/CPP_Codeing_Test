#include <iostream>
#include <vector>
using namespace std;

// ���� �ܾ� ����(���ڿ� ��Ʈ��)
// char ���� �迭���� ������ ���� '\0'�� ��.
// �ƽ�Ű �ڵ忡�� ���� 'a' -> 97, ���� 'A' -> 65
// �빮�� ���� 65 <= �빮�� <= 90
// �ҹ��� ���� 97 <= �ҹ��� <= 122

void ex007() {
    char a[] = "bE    au T I fu    L";
    char b[101];
    int pos = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ') //������ �ƴϸ�
        {
            if (a[i] > 65 && a[i] <= 90) // �빮��
            {
                b[pos++] = a[i] + 32;// �ҹ��� + 32 = �빮��
            }
            else { // �ҹ��� (a : 97, A : 65)
                b[pos++] = a[i];
            }
        }
    }
    b[pos] = '\0';
    cout << "result : " << b << endl; // beautiful
}

//int main() {
//    ex007();
//    std::cout << "done!" << std::endl;
//}
// result : beautiful