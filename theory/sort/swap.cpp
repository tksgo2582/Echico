#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int N, K;
    int tmp;
    vector<int> A, B;
    cin >> N >> K;
    for (int j = 0; j < N; j++) {
        cin >> tmp;
        A.emplace_back(tmp);
    }
    for (int j = 0; j < N; j++) {
        cin >> tmp;
        B.emplace_back(tmp);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    //cout<< A[0] << B[0];

    for (int i = 0; i < K;i++) {
        if (A[i] < B[i]) {
            tmp = A[i];
            A[i] = B[i];
        } else {
            break;
        }
    }

    int sum = 0;
    for (int i : A ){
        sum += i;
    }
    cout << sum;
}