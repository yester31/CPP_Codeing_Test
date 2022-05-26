#include <iostream>
using namespace std;

// 진약수의 합

void ex003(int n) {
    int sum = 1;

    cout << "1";
    for (int i = 2; i < n; i++) {

        if (n % i == 0) {
            sum += i;
            cout << " + " << i;
        }
    }
    cout << " = " << sum << endl;
}

//int main() {
//    ex003(20);
//    std::cout << "done!" << std::endl;
//}
// 1 + 2 + 4 + 5 + 10 = 22