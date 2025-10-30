// [BOJ1005] ACM Craft / 골드 3 / 위상정렬 / 120 ms / 2724 KB
/*
    문제 입, 출력

    문제 방향

        1. 작업 문제와  완전 똑같은 위상 정렬

        2. dp 테이블 자기 작업시간으로 초기화 

        3. in degree == 0 인 건물 queue 삽입 
            dp 테이블에서 nxt 값과 선후관계에서 선관계에 있는 시간 + nxt 작업시간 중 큰 값으로 갱신 

        4. 목표 w의 최소 시간으므로 == dp[w]
*/

#include<bits/stdc++.h>
using namespace std;

int t;
int n,k;

vector<int> adj[1'010];
int deg[1'010];
queue<int> q;

int ti[1'010];
long long dp[1'010];


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> t;
    while(t--){
        
        cin >> n >> k;
        for(int i = 1 ; i <=n ; i++ ) adj[i].clear();
        for(int i = 1 ; i <= n ; i++ ) cin >> ti[i];
        for(int i = 0 ; i < k ; i ++){
            //  1. 작업 문제와  완전 똑같은 위상 정렬
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            deg[b]++;
        }
        // 2. dp 테이블 자기 작업시간으로 초기화 
        for(int i = 1 ; i <=n ; i++ ) dp[i] =ti[i];

        for(int i = 1 ; i <=n ; i++)
            // in degree == 0 인 건물 queue 삽입 
            if(deg[i] == 0) q.push(i);

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nxt: adj[cur]){
                deg[nxt] --;
                // dp 테이블에서 nxt 값과 선후관계에서 선관계에 있는 시간 + nxt 작업시간 중 큰 값으로 갱신 
                dp[nxt] = max(dp[nxt], dp[cur]+ti[nxt]);
                if(deg[nxt]) continue;
                q.push(nxt);
            }
        }

        int w;
        cin >> w;
        // 목표 w의 최소 시간으므로 == dp[w]
        cout << dp[w] << '\n';
    }
    
}