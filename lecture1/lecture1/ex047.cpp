#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// ºÀ¿ì¸®

void ex047() {
    int N = 5;
    vector<vector<int>> map{ {0, 0, 0, 0, 0, 0, 0},
                            {0, 5, 3, 7, 2, 3, 0},
                            {0, 3, 7, 1, 6, 1, 0},
                            {0, 7, 2, 5, 3, 4, 0},
                            {0, 4, 3, 6, 4, 1, 0},
                            {0, 8, 7, 3, 5, 2, 0},
                            {0, 0, 0, 0, 0, 0, 0} };
    int cnt = 0;
    for (int i = 1; i < map[0].size() - 1; i++) {
        for (int j = 1; j < map[0].size() - 1; j++) {
            int tar = map[i][j];
            if (tar > map[i - 1][j] && tar > map[i][j - 1] && tar > map[i + 1][j] && tar > map[i][j + 1]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

//int main() {
//    ex047();
//    std::cout << "done!" << std::endl;
//}
// 10