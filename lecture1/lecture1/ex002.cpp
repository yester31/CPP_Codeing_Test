#include <iostream>

// 자연수의 합

void ex002(int n, int m) {

    int sum = 0;

    for (int i = n; i < m; i++) {
        sum += i;
        std::cout << i << " + ";
    }
    sum += m;
    std::cout << m << " = " << sum << std::endl;

}

//int main() {
//    ex002(3, 7); 
//    std::cout << "done!" << std::endl;
//}
// 3 + 4 + 5 + 6 + 7 = 25