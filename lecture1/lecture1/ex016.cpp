#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Anagram (구글 인터뷰 문제)
// 나열 순서는 다르지만 구성이 일치하면 아나그램이라 함.

void ex016() {
    string a = "AbaAeCe";
    string b = "baeeACA";
    //string b = "baeeACs";
    vector <int> chars1(52); // 26(소문자 97 - 122) + 26 (대문자 65 - 90)
    vector <int> chars2(52); // 26(소문자 97 - 122) + 26 (대문자 65 - 90)
    for (int i = 0; i < a.size(); i++) {
        int aski1 = int(a[i]);
        if (65 <= aski1 && 90 >= aski1) {   //대문자
            chars1[aski1 - 39]++;
        }
        else {                              //소문자
            chars1[aski1 - 97]++;
        }

        int aski2 = int(b[i]);
        if (65 <= aski2 && 90 >= aski2) {   // 대문자
            chars2[aski2 - 39]++;
        }
        else {                              //소문자
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