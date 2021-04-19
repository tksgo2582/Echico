//국영수
#include <bits/stdc++.h>
using namespace std;

struct score{
    string name;
    int kor, eng, math;
};
vector<score> v;
bool comp(score s1, score s2){
    if(s1.kor > s2.kor){
        return 1;
    }else if(s1.kor == s2.kor){
        if(s1.eng < s2.eng){
            return 1;
        }else if(s1.eng == s2.eng){
            if(s1.math > s2.math){
                return 1;
            }
            else if (s1.math == s2.math){
                return s1.name < s2.name;
            }
        }
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    score s;
    for(int i =0; i < n; i++){
        cin >> s.name >> s.kor >> s.eng >> s.math;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), comp);
    for(auto a : v){
        cout << a.name << "\n";
    }

}