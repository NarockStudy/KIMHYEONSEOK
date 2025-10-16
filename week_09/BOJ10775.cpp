// [BOJ10775] 공항 / 골드 2 / Union-Find / 12 ms / 2412 KB
/*
    문제 입, 출력

    문제 방향
        1. g,p 입력 받기
        2. p[i] = i 로 초기화
            -> 왜? 아직 현재 도킹이 안되어있음을 의미.
        3. gi 를 find 하여 자기 자신 이라면 ? 도킹이 안되어있으면 그대로 도킹 가능 == uni(find(gi),gind(gi)-1)
            gi find 하여 0 과 자기 자신이 아니라면 ? 자기 자신에 도킹이 되어있으므로 옆으로 도킹 가능
            gi find 하여 0이라면 도킹 할 수 없음을 의미하여 종료 
        

*/

#include<bits/stdc++.h>
using namespace std;

int G,P;
vector<int> p(100'001);
int ans;
int find (int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void uni(int u,int v){
    u = find(u);
    v = find(v);
    
    p[u] = v ;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> G >> P;

    // p[i] = i 로 초기화
    for(int i = 0; i <= G ; i ++) p[i] = i ;

    for(int i = 1 ; i <= P ; i ++){
        int g;
        cin >> g;
        
        int dock = find(g);
        if(dock == 0 ) break; //  gi find 하여 0이라면 도킹 할 수 없음을 의미하여 종료 

        // gi 를 find 하여 자기 자신 이라면 ? 도킹이 안되어있으면 그대로 도킹 가능 == uni(find(gi),gind(gi)-1)
        // gi find 하여 0 과 자기 자신이 아니라면 ? 자기 자신에 도킹이 되어있으므로 옆으로 도킹 가능
        uni(dock,dock-1);
        ans ++;
    }

    cout << ans;
    
}