// [BOJ13418] 학교 탐방하기 / 골드 3 / MST / 168 ms / 11376 KB
/*
    문제 입, 출력

    문제 방향

     0(오르막길) 또는 1(내리막길)

     1. 최악의 경우의 수 , 최선의 경우의 수 둘 다 구하기 

     2. 최악의 수는 오르막길(0) 이 많아야 하므로 오름차순 정렬
     3. 선택된 두 정점이 같은 그룹이면 패스
        다른 그룹이라면 같은 그룹으로 만들고, ans,cnt 갱신
     4. cnt == n-1 일떄 까지 3 반복 

     5. 최선의 수는 내리막길(1)이 많아야 하므로 내림차순 정렬.
     6. 3,4 같은 행위 반복 



     ==> 답을 보니깐 함수화 하여 재활용할 수 있음 .

*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<tuple<int,int,int>> edges;
vector<int> p(1010,-1);
int cnt, ans;
int mx,mn;
int find(int x){
    if(p[x] < 0 )  return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v )return false;
    
    if(p[v] < p[u]) swap(u,v);
    if(p[u] == p[v]) p[u] --;
    p[v] =u;
    return true;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0 ; i <= m ; i ++){
        int cost,a,b;
        cin >> a >> b >> cost;
        edges.push_back({cost,a,b});
    }

    // 0번쨰 입구 연결
    int cost,a,b;
    tie(cost,a,b) = edges[0];
    uni(a,b);
    if(cost == 0) mx += 1;
    // 최악의 수 == 오르막이 많은 경우의 수 
    sort(edges.begin()+1,edges.end());
    for(int i = 1; i < m ; i++){
        int cost,a,b;
        tie(cost,a,b) = edges[i];
        
        if(!uni(a,b)) continue;
        // cout << cost << ' ' << a << ' ' << b << '\n';
        
        if(cost == 0) mx += 1; // 오르막이면 
        cnt ++;

        if(cnt == n - 1) break;
    }

    fill(p.begin(),p.begin()+n+1,-1);
    cnt = 0;
    // cout <<a << ' ' << b << '\n';
    uni(a,b);
    if(cost == 0) mn += 1;

    // 최선의 수 == 내리막(1) 이 많은 경우의 수 
    sort(edges.begin() + 1, edges.end(), greater<>());
    
    
    for(int i = 1 ; i < m ; i ++){
        int cost,a,b;
        tie(cost,a,b) = edges[i];
        if(!uni(a,b)) continue;
        if(cost == 0) mn += 1; // 오르막이면 
         
        // cout << cost << ' ' << a << ' ' << b << '\n';

        cnt ++;
        if(cnt == n - 1) break;
    }
    ans =  mx * mx - mn * mn ;
    cout << ans ;
    
}