#include <iostream>
#include <vector>
using namespace std;

// 영어 단어 복구(문자열 컨트롤)
// char 문자 배열에서 마지막 값에 '\0'이 들어감.
// 아스키 코드에서 문자 'a' -> 97, 문자 'A' -> 65
// 대문자 범위 65 <= 대문자 <= 90
// 소문자 범위 97 <= 소문자 <= 122

void ex007() {
    char a[] = "bE    au T I fu    L";
    char b[101];
    int pos = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ') //공백이 아니면
        {
            if (a[i] > 65 && a[i] <= 90) // 대문자
            {
                b[pos++] = a[i] + 32;// 소문자 + 32 = 대문자
            }
            else { // 소문자 (a : 97, A : 65)
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