#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int step = 1; step < s.size() / 2 + 1; step++) {
        string compressed = "";
        string prev = s.substr(0, step);
        int cnt = 1;

        for (int j = step; j < s.size(); j += step) {
            if (prev == s.substr(j, step)) //압축가능
                cnt += 1;
            else {                         //더 이상 압축불가
                compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
                prev = s.substr(j, step);   
                cnt = 1;
            }
        }
        compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
        answer = min(answer, (int)compressed.size());
    }
    return answer;
}