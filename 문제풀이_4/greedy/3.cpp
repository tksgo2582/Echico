/* 
    그리디, 모든 상황마다 최적선택(그게 최종 답이 되게 생각)
    0,1 별로 숫자 바뀔때마다 카운트
    최종, 둘 중 작은게 최적해
 */
#include <bits/stdc++.h>
using namespace std;

string S;
int cnt0 = 0, cnt1 = 0;

int main() {
    cin >> S;

    if (S[0] == '1') {
        cnt0 += 1;
    } else {
        cnt1 += 1;
    }

    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] != S[i + 1]) {
            if (S[i] == '1') {
                cnt1 += 1;
            } else {
                cnt0 += 1;
            }
        }
    }

    cout << min(cnt0, cnt1) << '\n';
}