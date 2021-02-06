#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> v;

int parametric(int start, int end, int target){
    int mid;
    int sum, result;
    while(start <= end){
         mid = (start+end)/2;
        sum = 0;

        for(const auto& i : v ){ // v에 있는 길이들 하나씩 대입
            if(i > mid)
                sum += i-mid;     // 잘린 떡의길이 합
        }
        if(sum == target)       //딱 맞으면 
            return mid;
        else if(sum < target)      // 부족하면
            end = mid -1;
        else{                   // 넘치면
            result = mid;       //일단 제일 가까운걸로 저장
            start = mid +1;
        }
    }
    return result;
}


int main(){
    cin >> N>> M;
    int tmp;
    for(int i =0 ; i<N; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }
    int result = parametric(0, *max_element(v.begin(), v.end()) , M);
    cout << result;
}