#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
using namespace chrono;

// K���� ��� (���� �ڷᱸ�� ���� ����)

void ex053() {
    int n = 11;
    int k = 2;
    stack<int> st;
    while (n > 0) {
        st.push(n%k);
        n /= k;
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

//int main() {
//    ex053();
//    std::cout << "done!" << std::endl;
//}
//1 0 1 1