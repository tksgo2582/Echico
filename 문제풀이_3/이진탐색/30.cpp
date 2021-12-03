#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define MAX_W 10010

vector<string> arr[MAX_W], re_arr[MAX_W];

// faaaa~ fzzzz 사이에 있는 갯수 구하기
int countByRange(vector<string> v, string left, string right ){
    int leftIndex = lower_bound(v.begin(), v.end(), left) - v.begin();
    int rightIndex = upper_bound(v.begin(), v.end(), right) - v.begin();
    return rightIndex - leftIndex;
}
//??로 되어있는 문자열 to 문자로 바꿔준다. faaaa, fzzzz
string replaceAll(string str, string from, string to){
    string res = str;
    int pos = 0;
    while((pos = res.find(from, pos)) != string::npos){
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i = 0 ; i < words.size(); i++){
        string w = words[i];
        arr[w.size()].push_back(w); // a??? 검사
        reverse(w.begin(), w.end());
        re_arr[w.size()].push_back(w);  //???a 검사 위해서 reverse 한 후 저장 
    }
    for(int i = 2; i < MAX_W; i++){ // 각 길이별 정렬
        sort(arr[i].begin(), arr[i].end());
        sort(re_arr[i].begin(), re_arr[i].end());
    }

    for(int i = 0 ; i < queries.size(); i++){
        string q = queries[i];
        int res = 0;
        if(q[0] != '?'){
            res = countByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }else{
            reverse(q.begin(),q.end());
            res = countByRange(re_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
    }

    return answer;
}