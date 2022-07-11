#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Loc {
    int x, y, z;
    Loc(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
    bool operator<(const Loc &b) const {
        if (x!= b.x) return x < b.x;
        if (y!= b.y) return y < b.y;
        if (z!= b.z) return z < b.z;

        //return x < b.x; // 오른차순 
        //return x > b.x; // 내림차순 
    }
};   

//int main() {
//    vector<Loc> XY;
//    XY.push_back(Loc(2, 3, 5));
//    XY.push_back(Loc(3, 6, 7));
//    XY.push_back(Loc(2, 3, 1));
//    XY.push_back(Loc(5, 2, 3));
//    XY.push_back(Loc(3, 1, 6));
//
//    for (auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;
//
//    sort(XY.begin(), XY.end());
//    cout << "after sort" << endl;
//    for (auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;
//
//    return 0;
//}