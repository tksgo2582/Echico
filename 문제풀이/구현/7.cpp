#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    cin >> s;
    int sum =0;
    for(int i = 0; i < s.size()/2; i++){ //절반까지 더하고
        sum += s[i]-'0';
    }
    for(int i = s.size()/2; i < s.size(); i++){ // 절반까지 빼고
        sum -= s[i]-'0';
    }
    if(sum==0)
        cout << "LUCKY" << "\n";
    else
    {
        cout << "READY";
    }
    
}