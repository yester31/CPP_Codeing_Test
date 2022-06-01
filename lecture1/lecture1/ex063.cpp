#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 인접행렬(가중치 방향그래프)

void ex063() {
    int n = 6;
    int v = 9;
    vector<vector<int>> inputs{ {1, 2, 7},
                        {1, 3, 4},
                        {2, 1, 2},
                        {2, 3, 5},
                        {2, 5, 5},
                        {3, 4, 5},
                        {4, 2, 2},
                        {4, 5, 5},
                        {6, 4, 5} };
    vector<vector<int>> outputs(n, vector<int>(n, 0));

    for (int i = 0; i < inputs.size(); i++) {
        outputs[inputs[i][0] - 1][inputs[i][1] - 1] = inputs[i][2];
    }

    for (int i = 0; i < outputs.size(); i++) {
        for (int j = 0; j < outputs[0].size(); j++) {
            cout << outputs[i][j] << " ";
        }cout << endl;
    }
}

//int main() {
//    ex063();
//    cout << endl << "done!" << endl;
//}
//0 7 4 0 0 0
//2 0 5 0 5 0
//0 0 0 5 0 0
//0 2 0 0 5 0
//0 0 0 0 0 0
//0 0 0 5 0 0