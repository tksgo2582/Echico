#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    vector <int> v;

    int cnt0 =0, cnt1=0;

    if(s[0] == '1')  // 전부 0으로 바꾸는 경우
        cnt0++;
    else{               // 전부 1로 바꾸는 경우
        cnt1++;
    }

    for(int i = 0; i < s.size()-1; i++){
        if(s[i]!=s[i+1]){
            if(s[i+1] == '1')
                cnt0++;
            else
                cnt1++;
        }
    }
    cout << min(cnt0, cnt1)<< "\n";
}