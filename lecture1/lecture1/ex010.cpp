#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 자릿수의 합

void ex010() {
    vector<int> number{ 125, 15232, 79, 1325, 97 };
    int max = 0;
    int max_idx;
    for (int i = 0; i < number.size(); i++)
    {
        int target = number[i];
        int sum = 0;
        while (target)
        {
            sum += target % 10;
            target /= 10;
        }

        if (max < sum)
        {
            max = sum;
            max_idx = i;
        }
        else if (max == sum)
        {
            if (number[max_idx] < number[i])
            {
                max = sum;
                max_idx = i;
            }
        }
    }

    cout << "max number : " << number[max_idx] << ", sum max :: " << max << endl;
}


//int main() {
//    ex010();
//    std::cout << "done!" << std::endl;
//}
// max number : 97, sum max :: 16