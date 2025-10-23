// [BOJ10423] 전기가 부족해 / 골드 3 / MST / 32 ms / 3196 KB
/*
    문제 입, 출력

    문제 방향
        0. 크루스칼 알고리즘
        
        1. k 개의 발전소 들을 미리 가상의 0과 연결  
            문제 모델링을 통해 해결
        
        2. 간선들을  오름차순 정렬

        3. 두 정점이 같은 그룹이면 넘어감. 
            다른 그룹이면 같은 그룹으로 만들고 ans, cnt 갱신

        4. 0을 추가했으므로 cnt == n 일때 까지 3번 반복

        0. 프림 알고리즘

        1. k 개의 발전소 들을 저장
        2. 시작할 pq에 k개의 발전소 먼저 넣고 시작 
        3. 이미 방문했으면 넘어가고 아니라면 ans,cnt 갱신 
        4. n - k 개 일때까지 3 반복 
*/

#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int ans,cnt;
tuple<int,int,int> edges[100'010];
vector<int> p (1010,-1);
int find (int x){
    if(p[x] < 0 ) return x;
    return p[x] = find(p[x]);
}
bool uni(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;
    
    if(p[v] < p[u]) swap(u,v);
    if(p[u] == p[v]) p[u] --;
    p[v] = u ;
    return true;
}

void solve(){
    cin >> n >> m >> k ;

    for(int i = 0 ; i < k ; i ++){
        int a;
        cin >> a;
        if(!uni(0,a))continue;
        cnt ++;
    }

    for(int i = 0 ; i < m ; i ++){
        int cost,a,b;
        cin >> a >> b >> cost;
        edges[i] = {cost,a,b};
    }

    sort(edges,edges+m);

    for(int i = 0 ; i < m ;i ++){
        int cost,a,b;
        tie(cost,a,b) = edges[i];
        
        if(!uni(a,b)) continue;
        ans+= cost;
        cnt ++;
        
        if(cnt == n) break;
    }

    cout << ans;

}

#define X first
#define Y second
int yny[1'010];
vector<pair<int,int>> adj[1'010];
priority_queue<tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;
bool chk[1'010];
void solve2(){
    cin >> n >> m >> k ;

    for(int i = 0 ; i < k ; i ++)
        cin >> yny[i];

    for(int i = 0 ; i < m ; i ++){
        int cost,a,b;
        cin >> a >> b >> cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }

    for(int i = 0 ; i < k ; i ++){
        chk[yny[i]] = 1;
        for(auto nxt : adj[yny[i]]){
            pq.push({nxt.first,yny[i],nxt.second});
        }
    }


    while(cnt < n - k){
        int cost,a,b;
        tie(cost,a,b) = pq.top(); pq.pop();

        if(chk[b]) continue;
        chk[b] = 1;
        ans += cost;
        cnt ++ ;
        for(auto nxt : adj[b]){
            if(chk[nxt.second]) continue;
            pq.push({nxt.first,b,nxt.second});
        }
    }

    cout << ans;

}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    // solve();    // 크루스칼 알고리즘

    solve2(); // 프림 알고리즘

    
}