//못생긴 수 
//못생긴수 * 못생긴수 = 못생긴수
//3개의 deque 이용해서 각각의 수들 구하면서 그 중 가장작은거부터 넣어준다.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int dp[1002]={1,};
    deque<int> two, three, five;

    cin >> N;
    for(int i = 1; i < N; i++){
        two.push_back(dp[i-1]*2);
        three.push_back(dp[i-1]*3);
        five.push_back(dp[i-1]*5);

        int minval = min(two.front(), min(three.front(),five.front()));
        dp[i] = minval;
        if(two.front() == minval) two.pop_front();
        if(three.front() == minval) three.pop_front();
        if(five.front() == minval) five.pop_front();
    }
    cout << dp[N-1] << "\n";
}