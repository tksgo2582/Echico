//행성터널
#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int N;
vector <pair<int,int>> x, y, z;
int parent[MAX]={0,};

int findf(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = findf(parent[a]);
}
void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    if(a < b)           // 이부분 중요....!
        parent[b] = a;
    else {
        parent[a] = b;
    }
}

int main(){
    cin >> N;
    int a, b, c;
    for(int i = 1 ; i <= N; i++){
        parent[i] = i;
        cin >> a >> b >> c;
        x.push_back({a,i});
        y.push_back({b,i});
        z.push_back({c,i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    vector<pair<int,pair<int, int>>> edge;

    for(int i = 1; i < N; i++){
        edge.push_back({x[i].first - x[i-1].first, {x[i-1].second, x[i].second}});
        edge.push_back({y[i].first - y[i-1].first, {y[i-1].second, y[i].second}});
        edge.push_back({z[i].first - z[i-1].first, {z[i-1].second, z[i].second}});
    }
    sort(edge.begin(), edge.end());
    int result = 0;
    for(int i = 0 ; i < edge.size(); i++){
        int a, b, cost;
        cost = edge[i].first;
        a = edge[i].second.first;
        b = edge[i].second.second;

        if(parent[a] != parent[b]){
            unionf(a,b);
            result += cost;
        }
    }
    cout << result << "\n";
}