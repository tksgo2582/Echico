#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> v;

int main(){
    cin >> N;
    int tmp;
    for(int i =0; i<N;i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin(),v.end());
    
    int target = 1;         //1부터 만들 수 있는지 검사

    for(const auto & x : v){
        if(target < x)      // target 을 만들수 없다면 
            break;
        target += x;        // 다음 target 설정
    }
    
    cout << target << '\n';
}