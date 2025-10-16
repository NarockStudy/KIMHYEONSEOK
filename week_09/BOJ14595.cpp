// [BOJ14595] 동방 프로젝트 (Large) / 골드 4 / Union-Find / 0 ms / 6068 KB
/*
    문제 입, 출력

    문제 방향

        1. 입력받기

        2. a,b 사이 간격 모두 같은 집합으로 만들기 -> O(N * M) == 5 * 10^9 == 5초 이내  == x
        2. sort 하여 스위핑 기법으로 처리
            cur = 0 으로 두어 시작
            시작 방은 cur,s 중 큰 값으로 설정 ==> 왜? 
                ex) cur = 3 , s = 5 일때 5부터 시작되어 이전 cur 값을 버림 == 전과 같은 집합 아님
                    cur = 5 , s = 3 일때 5부터 시작됨. 하지만 이어져 있어서 전과 같은 집합임.
            끝은 e 로 설정하여 같은 집합으로 만드는 작업 실행
            
            cur 을 cur, e 중 큰 값으로 설정 ==> 왜?
                ex) cur = 3, e = 5 일때 5로 cur 갱신, 의미 s ~5까지는  이미 같은 집합이므로 cur를 갱신
                    cur = 5, e = 3 일때 5로 cur 유지, 의미는 위와 똑같음.
                    안하면 사고임. 왜냐면 cur = 1 , e = 1'000'000 일때 이미 같은 집합인데 또 uni 함. == O(N * M)
        3. p 배열 - 값들 갯수 저장 및 출력


*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
int a,b;
int ans;
vector<int> p(1'000'001,-1);
vector<pair<int,int>> room;
int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}


bool uni(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    if(p[u] == p[v]) p[u] --;
    p[v] = u;
    return true;

}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0 ; i < m; i ++){
        cin >> a >> b;
        room.push_back({a,b});
    }
    sort(room.begin(),room.end());

    int cur = 0;
    for(int i = 0 ; i < (int)room.size(); i ++){
        int s,e;
        tie(s,e) = room[i];
        s = max(s,cur);
        for(int j = s + 1 ; j <= e; j ++ ) uni(s,j);
        cur = max(cur,e);
    }


    for(int i = 1 ; i <=n ; i++) 
        if(p[i] < 0) ans ++;

    // for(int i = 1 ; i <=n ; i++) cout << p[i] << ' ';
    // cout << '\n';
    cout << ans;
    
}