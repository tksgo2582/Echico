#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector <int> v1,v2;

int binary_search( int start, int end, int target){
    int mid;
    while(start <= end){ // end 가 더 클 경우만
        mid = (start + end)/2; // mid 설정

        if(v1[mid] == target){ // 찾은경우
            return 1;
        }
        else if(v1[mid] > target){ // mid가 더 크면 end를 mid 앞으로
            end = mid -1;
        }
        else{                       // mid 보다 크면 start를 mid 뒤로
            start = mid + 1;
        }
    }
    return 0;
}

int main(){
    int tmp;
    cin >> N;
    for(int i =0; i <N; i++){
        cin >> tmp;
        v1.emplace_back(tmp);
    }
    sort(v1.begin(), v1.end());

    cin >> M;
    for(int i =0; i <M; i++){
        cin >> tmp;
        v2.emplace_back(tmp);
    }
int answer;
    for(int i =0; i<M;i++){
        answer = binary_search(0, N-1, v2[i]);
        if(answer == 1)
        cout << "yes ";
        else
        {
            cout<< "no ";
        }
        
    }
}