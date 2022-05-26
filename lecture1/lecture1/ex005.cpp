#include <iostream>
#include <vector>
using namespace std;

// 나이 계산
// *아스키코드에서 문자 '0'은 10진수로 48
void ex005() {
    char input[] = "900316-1376152";
    char input2[] = "060316-3576152";
    int year, age;

    if (input[7] == '1' || input[7] == '2')
        year = 1900 + ((input[0] - 48) * 10 + (input[1] - 48));
    else
        year = 2000 + ((input[0] - 48) * 10 + (input[1] - 48));

    age = 2021 - year + 1;
    printf("%d ", age);

    if (input[7] == '1' || input[7] == '3')
        printf("M\n");
    else
        printf("W\n");
}

//int main() {
//    ex005();
//    std::cout << "done!" << std::endl;
//}
// 32 M