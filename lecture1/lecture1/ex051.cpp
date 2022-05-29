//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//using namespace std;
//using namespace chrono;
//
//// 영지(territory) 선택 : (large)
//
//void ex051() {
//    vector<vector<int>> map{ {3, 5, 1, 3, 1, 3, 2},
//                            {1, 2, 1, 3, 1, 1, 2},
//                            {1, 3, 1, 5, 1, 3, 4},
//                            {5, 1, 1, 3, 1, 3, 2},
//                            {3, 1, 1, 3, 1, 1, 2},
//                            {1, 3, 1, 3, 1, 2, 2} };
//    int h = 2, w = 3;
//    int max = 0;
//    int loc_h, loc_w;
//    for (int i = 0; i <= map.size() - h; i++) { // h
//        for (int j = 0; j <= map[0].size() - w; j++) { // w
//            int sum = 0;
//            for (int h_idx = i; h_idx < h + i; h_idx++) { // h
//                for (int w_idx = j; w_idx < w + j; w_idx++) { // w
//                    sum += map[h_idx][w_idx];
//                }
//            }
//            if (sum > max) {
//                max = sum;
//                loc_h = i;
//                loc_w = j;
//            }
//        }
//    }
//
//    cout << "max :: " << max << endl;
//    for (int h_idx = loc_h; h_idx < h + loc_h; h_idx++) { // h
//        for (int w_idx = loc_w; w_idx < w + loc_w; w_idx++) { // w
//            cout << map[h_idx][w_idx] << " ";
//        }cout << endl;
//    }
//}
//
//int main() {
//    ex051();
//    std::cout << "done!" << std::endl;
//}
