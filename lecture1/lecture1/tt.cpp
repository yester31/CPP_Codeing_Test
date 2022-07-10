#include <vector>
#include <algorithm>
#include <iostream>

void dfs(int d, int c, std::vector<std::vector<float>>& map, std::vector<float>& candi, std::vector<int>& check, std::vector<std::vector<float>>& out) {
    if (d == c) {
        out.push_back(candi);
    }
    else {
        for (int i = 0; i < map[c].size(); i++) {
            if (check[map[c][i]] == 0) {
                check[map[c][i]] = 1;
                candi.push_back(map[c][i]);
                c++;
                dfs(d, c, map, candi, check, out);
                candi.pop_back();
                c--;
                check[map[c][i]] = 0;
            }
        }
    }
}

int tt() {
    int H = 3;
    int W = 4;
    std::vector<float> tt = { 0, 3, 2, 8, 
                              2, 0, 3, 0, 
                              5, 8, 0, 0 };

    std::vector<std::vector<float>> map(H);

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (tt[h*W + w] == 0) {
                map[h].push_back(w);
            }
        }
    }
    std::vector<int> check(W);
    std::vector<float> candi;
    std::vector<std::vector<float>> out;

    dfs(H, 0, map, candi, check, out);

    std::vector<std::vector<float>> costMatrix{ {3, 7, 5, 11},
                                                {5, 4, 6, 3},
                                                {6, 10, 1, 1} };
    //std::vector<float> candi_cost;
    //for (int i = 0; i < out.size(); i++) { // candidates
    //    float sum = 0;
    //    for (int h = 0; h < H; h++) {
    //        sum += costMatrix[h][out[i][h]];
    //    }
    //    candi_cost.push_back(sum);
    //}

    std::vector<float> candi_cost{1,2,1,3,1};

    float min = *min_element(candi_cost.begin(), candi_cost.end());
    std::cout << "min value : " << min << "\n";

    int min_index = min_element(candi_cost.begin(), candi_cost.end()) - candi_cost.begin();
    std::cout << "min value index : " << min_index << std::endl;

    for (int h = 0; h < H; h++) {
        std::cout << out[min_index][h] << "\n";
    }

    return 0;
}

//int main() {
//    tt();
//    return 0;
//}