#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Prime Number 소수 개수 구하기
// 소수란 자신을 제외한 자연수로는 나누어 떨어지지 않는 자연수

// 1) 모든 수에 대해 약수가 있는지 확인
void ex015_1(int N) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int count = 0;
    for (int j = 2; j < N; j++) {
        bool flag = true;
        for (int i = 2; i < j; i++) {
            if (j % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }

    auto dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "(1) 1 부터 " << N << " 까지 사이에 존재하는 소수 개수 : " << count << " ex015_1 Dur time :: " << dur << " milliseconds" << endl;
}

// 2) 모든 약수가 가운데 약수를 기준으로 대칭을 갖는 성질 이용 (제곱근까지만 확인 하면 됨)
void ex015_2(int N) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int count = 0;
    for (int j = 2; j < N; j++) {
        bool flag = true;
        for (int i = 2; i * i <= j; i++) {
            if (j % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }

    auto dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "(2) 1 부터 " << N << " 까지 사이에 존재하는 소수 개수 : " << count << " ex015_2 Dur time :: " << dur << " milliseconds" << endl;
}

// 3) 에라토스테네스의 체 알고리즘 이용
// 1. 2부터 N까지 모든 자연수 나열
// 2. 남은 자연수 중 처리되지 않은 가장 작은 수 찾기
// 3. 2번 에서 찾은 가장 작은 수의 배수를 모두 제거 (해당 작은 수는 제거하지 않는다.)
// 4. 끝까지 2번과 3번을 반복
void ex015_3(int N) {
    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    int count = 0;
    vector<int> container(N);
    for (int i = 2; i < N; i++) {
        container[i] = i;   // 2부터 N까지 모든 자연수 나열
    }

    for (int i = 2; i < N; i++) {
        if (container[i] == 0) continue;    // 이미 처리 됬다면 통과
        for (int j = i + i; j < N; j += i) {// 해당 작은 수를 제거하지 않도록 i+i에서 시작 
            container[j] = 0;               // 해당 가장 작은 수의 배수를 모두 제거
        }
    }

    for (int i = 2; i < N; i++) {
        if (container[i] != 0) count++; // 소수 카운트
    }

    auto dur = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "(3) 1 부터 " << N << " 까지 사이에 존재하는 소수 개수 : " << count << " ex015_3 Dur time :: " << dur << " milliseconds" << endl;
}


//int main() {
//    int max = 399999;
//    ex015_1(max);
//    ex015_2(max);
//    ex015_3(max);
//    return 0;
//}
//(1) 1 부터 399999 까지 사이에 존재하는 소수 개수 : 33860 ex015_1 Dur time :: 10670 milliseconds
//(2) 1 부터 399999 까지 사이에 존재하는 소수 개수 : 33860 ex015_2 Dur time :: 37 milliseconds
//(3) 1 부터 399999 까지 사이에 존재하는 소수 개수 : 33860 ex015_3 Dur time :: 335 milliseconds