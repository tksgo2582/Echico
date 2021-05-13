//퇴사
/* 
    dp 를 거꾸로 생각해서 적용, 마지막 날부터 얼마 벌 수 있는지...
 */
#include <bits/stdc++.h>
using namespace std;

int T, n, m;
int dp[20] = {
    0,
};
vector<pair<int, int>> v;
int max_value = 0;

int main() {
    cin >> n;
    int time, pay;
    for (int i = 0; i < n; i++) {
        cin >> time >> pay;
        v.push_back({time, pay});
    }
    int time;
    for (int i = n - 1; i < 0; i--) {
        time = v[i].first + i;  //일처리 시간 + 현재 날짜
        if (time <= n) {    // 기한 안에 일 처리 가능
            dp[i] = max(v[i].second + dp[time], max_value);
        } else {
            dp[i] = max_value;
        }
    }

    cout << max_value;
}