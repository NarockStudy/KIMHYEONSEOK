// [BOJ2637] 장난감 조립 / 골드 2 / 위상정렬 / 0 ms / 2028 KB
/*
    문제 입, 출력

    문제 방향

        1. dp + 위상정렬 은 유명한 dp 심화

        2. 기본 부품만 출력이므로 is_default bool 배열을 활용
        3. 탑 다운 방식으로 완제품인 n을 queue에 삽입
            dp[n] = 1 (완제품 1개 만들었을 때 )
        4. n 부터 위상 indegree == 0 인 노드들 queue 삽입
            하위 제품들 dp 값 채워짐


*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,m;
vector<pair<int,int>> adj[110];
queue<int> q;
int deg[110];
bool is_default[110];   // 기본 부품만 출력이므로 is_default bool 배열을 활용

int dp[110];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    
    cin >> n >> m;
    fill(is_default,is_default+n+1,1);
    for(int i = 0 ; i < m ; i ++){
        int x,y,k;
        cin >> x >> y >> k;
        adj[x].push_back({y,k});
        deg[y] ++;
        is_default[x] = false;
    }

    dp[n] = 1; // dp[n] = 1 (완제품 1개 만들었을 때 )
    q.push(n);
    
    //n 부터 위상 indegree == 0 인 노드들 queue 삽입
    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto nxt : adj[cur]){
            deg[nxt.X] --;
            //  하위 제품들 dp 값 채워짐
            dp[nxt.X] += dp[cur] * nxt.Y;
            if(deg[nxt.X]) continue;
            q.push(nxt.X);

        }
    }

    for(int i = 1 ; i <=n ; i++) 
        if(is_default[i]) cout << i << ' ' << dp[i] << '\n';
    
}