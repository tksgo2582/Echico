#include <bits/stdc++.h>
using namespace std;

string s;
vector <int> v;

int main(){
    cin >> s;
    for(int i =0 ;i <s.size(); i++){
        v.emplace_back(s[i]-'0');
    }
    int result = 0;
    sort(v.begin(),v.end(), greater<int>());
    for(int i =0 ;i < v.size(); i++){
        if(i == 0)
            result = v[i];
        else if(v[i] != 0){
            result *= v[i];
        }
        if(v[i] == 0){
            result += v[i];
        }
    }
    cout << result << "\n"; 
}