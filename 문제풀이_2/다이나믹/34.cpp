//병사 배치하기
/* 
    하나 잡고 맨 앞부터 거기까지 검사... 
    검사하면서 기준이 더 크면 검사하는애의 dp + 1
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int dp[2010];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    fill(dp, dp + 2010, 1);
    reverse(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    cout << N - *max_element(dp, dp + N) << '\n';
}