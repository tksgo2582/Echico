#include <bits/stdc++.h>
using namespace std;

string s;
vector <int> v;

int main(){
    string c;
    cin >> c;
    for(const auto& a : c){
        if(a>='0' && a<='9'){
            v.emplace_back(a-'0');
        }
        else 
            s.push_back(a);
    }
    sort(s.begin(), s.end());
    int sum=0;
    for(const auto& a : v){
        sum+=a;
    }
    cout << s;
    cout << sum;
}