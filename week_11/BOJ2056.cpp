// [BOJ2056] 작업 / 골드 4 / 위상정렬 / 72 ms / 5940 KB
/*
    문제 입, 출력

    문제 방향

        1. 선후 관계가 있으므로 위상 정렬 

        2. dp를 이용하여 각자의 작업 시간으로 초기화 

        3. queue 에 넣어서 in degree == 0 일떄, queue에 삽입
            이 떄, cur이 이전, nxt가 다음 작업이므로 
            cur 시간을 더해 dp[nxt] 갱신
            max를 하는 이유는, 선 후 관계가 여러 개 있으면, 
            맨 마지막 것만갱신되는걸 방지
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;

vector<int> adj[10'001];
queue<int> q;
int deg[10'001];

int dp[10'001];
int t[10'001];

int ans;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;

    for(int i = 1 ; i <=n ; i ++){
        cin >> t[i] >> cnt;
        for(int j = 0 ; j < cnt ; j ++){
            int c;
            cin >> c;
            adj[c].push_back(i);
            deg[i]++; 
        }
    }

    //  dp를 이용하여 각자의 작업 시간으로 초기화 
    for(int i = 1 ; i <=n ; i++ ) dp[i] = t[i];

    for(int i =1 ; i <=n ; i++){
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(int nxt : adj[cur]){
            deg[nxt] --;
            // 이 떄, cur이 이전, nxt가 다음 작업이므로 cur 시간을 더해 dp[nxt] 갱신
            // max를 하는 이유는, 선 후 관계가 여러 개 있으면,  맨 마지막 것만갱신되는걸 방지
            dp[nxt] = max(dp[nxt],dp[cur]+t[nxt]);
            // queue 에 넣어서 in degree == 0 일떄, queue에 삽입
            if(deg[nxt]) continue;
            q.push(nxt);
        }
    }
    // for(int i = 1 ; i <= n ; i++ )cout << dp[i] << ' ';
    cout << *max_element(dp+1,dp+n+1);
    
}