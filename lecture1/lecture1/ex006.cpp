#include <iostream>
#include <vector>
using namespace std;

// 숫자만 추출
// char 문자 배열에서 마지막 값에 '\0'이 들어감.
// 아스키 코드에서 문자 '0' -> 48, 문자 '9' -> 57
void ex006() {
    char a[] = "g0en2Ts8eSoft";
    int res = 0;
    int cnt = 0;
    //int length = sizeof(a) / sizeof(a[0]);
    //cout << "length of a array : " << length << endl;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 48 && a[i] <= 57)
        {
            res = res * 10 + (a[i] - 48);
        }
    }

    cout << "number : " << res;

    for (int i = 1; i <= res; i++)
    {
        if (res%i == 0) { cnt++; }
    }

    cout << ", cnt : " << cnt << endl;

}

//int main() {
//    ex006();
//    std::cout << "done!" << std::endl;
//}
// number : 28, cnt : 6