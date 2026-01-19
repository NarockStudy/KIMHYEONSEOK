// [BOJ13460] 구슬 탈출 2 / 골드1 / 시뮬레이션 / 0 ms / 2040 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

struct Pos{int x,y;};
struct State{
    Pos r,b;
    int dist;
};

int n,m;
int board[15][15];
Pos hole,r,b;
bool vis[11][11][11][11];

int dx[4] ={1,0,-1,0};
int dy[4] = {0,1,0,-1};

tuple<Pos,int,bool> moved(Pos s, int dir){
    int x = s.x;
    int y = s.y;
    int mv = 0;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(board[nx][ny] == 1) break;
        if(board[nx][ny] == 2) return {Pos{nx,ny},mv + 1 ,true};
        x =nx; y= ny;
        mv ++;
    }

    return {Pos{x,y},mv,false};
}

int bfs(Pos r0, Pos b0){
    queue<State> q;

    q.push({r0,b0,0});
    vis[r0.x][r0.y][b0.x][b0.y] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if (cur.dist >= 10) continue; // 다음 스텝이 11번째가 되므로 확장 중단

        for(int dir = 0 ; dir <4 ; dir ++){
            Pos nr,nb;
            int rmove,bmove;
            bool rhole,bhole;
            tie(nr,rmove,rhole) = moved(cur.r,dir);
            tie(nb,bmove,bhole) = moved(cur.b,dir);

            if(bhole) continue; // 실패
            if(rhole) return cur.dist + 1;

            if(nr.x == nb.x && nr.y == nb.y){
                if(rmove > bmove){
                    nr.x -= dx[dir];
                    nr.y -= dy[dir];
                }else{
                    nb.x -= dx[dir];
                    nb.y -= dy[dir];
                }
            }

            if(vis[nr.x][nr.y][nb.x][nb.y]) continue;
            vis[nr.x][nr.y][nb.x][nb.y] = 1;
            q.push({nr,nb,cur.dist+1});
        }
    }

    return -1;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m ;
    for(int i = 0 ; i < n; i ++){
        string s; cin >> s;
        for(int j = 0 ; j < m ; j ++){
            if(s[j] == '#') board[i][j] = 1;
            else if(s[j] == '.') board[i][j] = 0;
            else if(s[j] == 'O') {board[i][j] = 2; hole = {i,j};}
            else if(s[j] == 'R') {board[i][j] = 0; r = {i,j};}
            else if(s[j] == 'B') {board[i][j] = 0; b = {i,j};}
        }
    }

    cout << bfs(r,b) << '\n';
    return 0;

    
}