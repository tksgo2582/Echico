#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    //int answer = 0;
    int length = weak.size();
    for(int i =0; i < length; i++){   //원형이므로 취약점 벡터를 2배로 늘린다.
        weak.push_back(weak[i] + n);   // 1357 -> 1,3,5,7,++ 13,15,17,19
    }
    int answer = dist.size() + 1; // 최소 인원 구하기위해서 처음엔 (최대 +1)
    for(int start = 0; start < length; start++){
        do{
            int cnt = 1;        //투입할 친구 수
            int position = weak[start] + dist[cnt - 1];  //해당인원이 점검할 마지막 위치 
            for(int index = start; index < start + length; index++){
                if(position < weak[index]){ //마지막 위치를 벗어나는 취약점이 있다면
                    cnt +=1;                // 사람 수 증가
                    if(cnt > dist.size())   // 최대 친구수 초과시 종료
                        break;
                position = weak[index] + dist[cnt - 1]; //마지막 점검위치 업데이트
                }
            }
            answer = min(answer, cnt);
        }while(next_permutation(dist.begin(), dist.end())); //뽑는 경우의 수 업데이트
    }
    if(answer > dist.size())
        return -1;
    return answer;
}