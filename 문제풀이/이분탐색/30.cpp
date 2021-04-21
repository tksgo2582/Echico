#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
//인덱스 구해서 몇개가 있는지 확인.. 
int countByRange(vector<string> &v, string left, string right){
    int rightIndex = upper_bound(v.begin(), v.end(), right) - v.begin();
    int leftIndex = lower_bound(v.begin(), v.end(), left) - v.begin();
    return rightIndex - leftIndex;
}
// 특정한 문자열을 to로 치환 ( 여기선 ? -> a)
string replaceAll(string str, string from, string to){
    string res = str;
    int pos = 0;
    while((pos = res.find(from,pos)) != string::npos){
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

vector<string> arr[10001];
vector<string> reversed_arr[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i =0; i < words.size(); i++){
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        reversed_arr[word.size()].push_back(word);
    }
    
    for(int i =0; i < 10001; i++){  //길이별 벡터배열 정렬
        sort(arr[i].begin(), arr[i].end());
        sort(reversed_arr[i].begin(), reversed_arr[i].end());
    }
    
    for(int i =0; i < queries.size(); i++){
        string q = queries[i];
        int res = 0;
        if(q[0] != '?'){
            res = countByRange(arr[q.size()], replaceAll(q,"?","a"), replaceAll(q, "?", "z"));
        }else{
            reverse(q.begin(), q.end());
            res = countByRange(reversed_arr[q.size()], replaceAll(q,"?","a"), replaceAll(q, "?", "z"));
        }
        answer.push_back(res);
    }
    
    return answer;
}