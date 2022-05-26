#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

// 가장 많이 사용된 자릿수

int reverse(int x) {
    int ans = 0;
    string s = to_string(x);
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += (int(s[i]) - 48) * pow(10, i);
    }
    //cout << ans << endl;;
    return ans;
}

int reverse2(int x) {
    int ans = 0;
    while (x > 0) {
        int tmp = x % 10;
        ans = ans * 10 + tmp;
        x /= 10;
    }
    //cout << ans << endl;;
    return ans;
}

bool isPrime(int x) {
    if (x == 1) return false;
    bool flag = true;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

void ex014() {
    vector<int> vec = { 12, 123, 42, 123, 17, 71 };
    for (int i = 0; i < vec.size(); i++) {
        //int reverse_num = reverse(vec[i]);
        int reverse_num = reverse2(vec[i]);
        if (isPrime(reverse_num)) {
            cout << reverse_num << "<Prime Number>" << endl;
        }
        else {
            cout << vec[i] << endl;;
        }
    }
}


//int main() {
//    ex014();
//    std::cout << "done!" << std::endl;
//}
//12
//123
//42
//123
//71 < Prime Number >
//17 < Prime Number >