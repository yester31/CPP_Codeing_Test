#include <iostream>
#include <vector>
using namespace std;

// 나이 차이

void ex004() {
    vector<int> tt{ 30, 23, 26, 50, 17, 34, 35, 50 };

    int min = 2147000000;
    int max = -2147000000;
    int target;
    for (int i = 0; i < tt.size(); i++)
    {
        target = tt[i];
        if (target > max) max = target;
        if (target < min) min = target;
    }

    cout << "max : " << max << " min : " << min << " diff : " << max - min << endl;
}

//int main() {
//    ex004();
//    std::cout << "done!" << std::endl;
//}
// max : 50 min : 17 diff : 33