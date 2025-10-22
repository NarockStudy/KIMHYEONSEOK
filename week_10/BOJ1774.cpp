// [BOJ1774] 우주신과의 교감 / 골드 3 / MST / 40 ms / 14464 KB
/*
    문제 입, 출력

    문제 방향

        1. 크루스칼 알고리즘 이용 

        2. n개를 좌표를 입력받아서 point struct에 저장
            1-index 인것을 조심

        3. m개 번호들과 미리 연결하고 cnt 증가 

        4. 모든 좌표들의 거리를 계산하여 edges에 저장
                4-1. 먼저 sqrt 한 것을 저장해도 됨.
                4-2. a^2 + b^2 값을 저장하고 최종 답에 넣을때, sqrt 해도 됨.
        
        5. 크루스칼 알고리즘을 이용하여 순회
            5-1 오름차순 정렬을 함.
            5-2 선택한 간선이 이미 같은 그룹이면 넘어감.
                다른 그룹이면 같은 그룹으로 합치고 cnt 증가, ans 계산
            5-3. 정점의 수 - 1 이 될 때까지 5-2 반복 

*/

#include<bits/stdc++.h>
using namespace std;

struct Point{    int x,y;};

int n,m;
int cnt = 0 ;
double ans;

Point points[1'010];
vector<int> p(1010,-1);
vector<tuple<long long,int,int>> edges;

int find(int x){
    if(p[x] < 0 ) return x;
    return p[x] = find(p[x]);
}
bool uni(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;
    
    if(p[v] < p[u]) swap(u,v);
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n >> m ;

    for(int i = 1; i <= n ; i ++){
        int x,y;
        cin >> x >> y;
        points[i] = {x,y};
    }

    for(int i = 0 ; i < m ; i ++){
        int a,b;
        cin >> a >> b;
        if(!uni(a,b)) continue;;
        cnt ++ ;
    }

    for(int i = 1 ; i <= n ; i ++){
        for(int j = i +1; j <= n ;j ++){
            Point a = points[i];
            Point b = points[j];
            // long long x_d = (a.x-b.x) * (a.x-b.x);
            // long long y_d = (a.y - b.y) * (a.y-b.y);
            // double sq = sqrt( x_d + y_d );
            long long dx = 1LL * a.x - b.x;
            long long dy = 1LL * a.y - b.y;
            long long dist2 = dx*dx + dy*dy;
            edges.push_back({dist2,i,j});
        }
    }

    sort(edges.begin(),edges.end());
    
    for(int i = 0 ; i < edges.size(); i ++){
        long long cost;
        int a,b;
        tie(cost,a,b) = edges[i];

        if(!uni(a,b)) continue;

        ans += sqrt(cost);
        cnt ++;
        if(cnt == n - 1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}