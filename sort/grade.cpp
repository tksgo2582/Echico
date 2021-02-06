#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    int N, tmp;
    string s;
    vector <pair<int, string>> v;

    cin >> N;
    for(int i =0 ;i <N; i++){
        cin >> s >> tmp;
        v.emplace_back(make_pair(tmp, s));
        //cout << v[i].second;
    }
    sort(v.begin(), v.end());

    for(int i =v.size()-1 ; i >=0; i--){
        cout << v[i].second<<"\n";
    }

}