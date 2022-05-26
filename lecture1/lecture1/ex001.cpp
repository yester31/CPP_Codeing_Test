#include <iostream>

// 1부터 n까지 m의 배수합

void ex001(int n, int m) {

    int sum = 0;

    for (int i = 0; i <= n; i++) {
        if (i%m == 0)
            sum += i;
    }

    std::cout << "sum : " << sum << std::endl;
}

//int main() {
//    ex001(15, 3); 
//    std::cout << "done!" << std::endl;
//}
// 45