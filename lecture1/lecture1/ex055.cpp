#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
using namespace chrono;

// 기차운행 (스택 자료구조 응용)

void ex055() {

    vector<int> trains{ 2, 1, 3, 4 };
    stack<int> st;
    vector<string> res;
    int pos = 0;
    int order = 1;
    bool possible = true;
    while (order != trains.size()+1) {
        if (!st.empty()) {
            if (st.top() != order) {
                if (pos == trains.size()) {
                    possible = false;
                    break;
                }
                st.push(trains[pos]);
                res.push_back("P");
                pos++;
            }
            else {
                res.push_back("O");
                order++;
                st.pop();
            }
        }
        else {
            res.push_back("P");
            st.push(trains[pos]);
            pos++;
        }
    }
    if (possible) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
    }
    else
        cout << "impossible";

}

//int main() {
//    ex055();
//    cout << endl << "done!" << endl;
//}
//PPOOPOPO
