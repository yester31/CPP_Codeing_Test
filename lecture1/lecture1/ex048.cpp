#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 각 행의 평균과 가장 가까운 값

void ex048() {
    int N = 9;
    vector<vector<int>> map{{ 3, 23, 85, 34, 17, 74, 25, 52, 65},
                            {10,  7, 39, 42, 88, 52, 14, 72, 63},
                            {87, 42, 18, 78, 53, 45, 18, 84, 53},
                            {34, 28, 64, 85, 12, 16, 75, 36, 55},
                            {21, 77, 45, 35, 28, 75, 90, 76,  1},
                            {25, 87, 65, 15, 28, 11, 37, 28, 74},
                            {65, 27, 75, 41,  7, 89, 78, 64, 39},
                            {47, 47, 70, 45, 23, 65,  3, 41, 44},
                            {87, 13, 82, 38, 50, 12, 48, 29, 80}};
    int cnt = 0;
    for (int i = 0; i < map[0].size(); i++) {
        int sum = 0;
        for (int j = 0; j < map[0].size(); j++) {
            sum += map[i][j];
        }
        int avg = (int)((float)sum / map[0].size() + 0.5);
        cout << avg;
        int near;
        int diff = 99;
        for (int j = 0; j < map[0].size(); j++) {
            if (abs(map[i][j] - avg) < diff) {
                near = map[i][j];
                diff = abs(map[i][j] - avg);
            }
            else if (abs(map[i][j] - avg) == diff) {
                if (near < map[i][j]) {
                    near = map[i][j];
                }
            }
        }
        cout << " " << near << endl;
    }
}

//int main() {
//    ex048();
//    std::cout << "done!" << std::endl;
//}
//42 34
//43 42
//53 53
//45 36
//50 45
//41 37
//54 64
//43 44
//49 50