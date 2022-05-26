#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 가장 많이 사용된 자릿수

void ex013(string N) {
    vector<int> vec(10);
    for (int i = 0; i < N.size(); i++){
        vec[int(N[i]) - 48]++;
    }

    int max = 0;
    int max_idx;
    for (int i = 0; i < 10; i++){
        if (max <= vec[i]){
            max = vec[i];
            max_idx = i;
        }
    }

    cout << "max_number : " << max_idx << ", max count: " << max << endl;
}

//int main() {
//    string N = "12301156516215";
//    ex013(N);
//    std::cout << "done!" << std::endl;
//}
// max_number : 1, max count: 5