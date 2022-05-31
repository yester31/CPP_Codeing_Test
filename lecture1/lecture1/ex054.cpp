#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
using namespace chrono;

// ¿Ã¹Ù¸¥ °ýÈ£(stack)

void ex054() {
    string n = "(()(()))(()";
    //string n = "()()(()())";
    int pos = 1;
    stack<int> st;
    if (n[0] == ')') cout << "NO" << endl;
    else {
        st.push(1);
        while (pos < n.size()) {
            if (n[pos] == '(') st.push(1);
            else st.pop();
            pos++;
        }
        if (st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

//int main() {
//    ex054();
//    std::cout << "done!" << std::endl;
//}
//NO
//YES