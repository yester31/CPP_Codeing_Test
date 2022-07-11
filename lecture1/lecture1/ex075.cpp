#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

// 최대 수입 스케쥴(priority_queue 응용문제)

struct Data {
    int money, when;
    Data(int a, int b) {
        money = a;
        when = b;
    }
    bool operator<(const Data &b) const {
        //return x < b.x; // 오른차순 
        return when > b.when; // 내림차순 
    }
};

void ex075() {
    int n = 6;
    vector<vector<int>> inputs{ {50, 2},
                                {20, 1},
                                {40, 2},
                                {60, 3},
                                {30, 3},
                                {30, 1}};
    vector<Data> T;
    priority_queue<int> pQ;
    int max= 0;
    for (int i = 0; i < inputs.size(); i++) {
        T.push_back(Data(inputs[i][0], inputs[i][1]));
        if (inputs[i][1] > max) {
            max = inputs[i][1];
        }
    }

    sort(T.begin(), T.end());
    int res = 0;
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < inputs.size(); j++){
            if (T[j].when < i) break;
            if (T[j].when > i) continue;
            pQ.push(T[j].money);
        }
        if (!pQ.empty()) {
            res += pQ.top();
            pQ.pop();
        }
    }

    cout << res << endl;
}

//int main() {
//    ex075();
//    cout << endl << "done!" << endl;
//}
// 150
