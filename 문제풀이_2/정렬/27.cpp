//정렬된~~~

/* 
    lowwer, upper 바운드 함수 사용하기
 */
#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> v;

int main() {
    cin >> N >> X;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    int up = upper_bound(v.begin(), v.end(), X) - v.begin();
    int low = lower_bound(v.begin(), v.end(), X) - v.begin();

    int result = up - low;
    if (result > 0)
        cout << result << '\n';
    else {
        cout << -1 << '\n';
    }
}