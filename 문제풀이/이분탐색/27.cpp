//정렬된 배열에서 특정 수의 개수 구하기
//정렬 후 upper_bound, lowwer_bound 활용하기 , 이 함수들은 주소값을 출력.... v.begin 을 빼주면 몇번재 인덱스인지 확인 가능
// upper 는 찾는 val 가 끝나는 지점 반환... (다음 원소의 시작주소값)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, tmp;
    vector<int> v;
    cin >> n >> x;
    for(int i =0 ; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    int low = lower_bound(v.begin(), v.end(), x)- v.begin();
    int up = upper_bound(v.begin(), v.end(), x) - v.begin();
    
    int result = up - low;
    if(result == 0)
        result = -1;
    cout << result;
}