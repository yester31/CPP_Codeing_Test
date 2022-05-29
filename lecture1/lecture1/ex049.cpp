#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace chrono;

// 쌓기 블록의 최댓값 (2차원 배열 응용)

void ex049() {
    vector<int> map1{ 2, 0, 3, 1 }; // bottom
    vector<int> map2{ 1, 1, 2, 3 }; // right
    vector<vector<int>> map(map2.size(), vector<int>(map1.size(), 0));
    for (int i = 0; i < map1.size(); i++) {
        for (int j = 0; j < map2.size(); j++) {
            map[j][i] = map1[i];
        }
    }

    for (int j = map2.size() - 1; j >= 0; j--) {
        for (int i = 0; i < map2.size(); i++) {
            if (map[3 - j][i] > map2[j]) {
                map[3 - j][i] = map2[j];
            }
        }
    }

    for (int i = 0; i < map2.size(); i++) {
        for (int j = 0; j < map1.size(); j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

//int main() {
//    ex049();
//    std::cout << "done!" << std::endl;
//}
//2 0 3 1
//2 0 2 1
//1 0 1 1
//1 0 1 1