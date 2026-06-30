// 	[Codetree] 순서대로 방문하기 / L11 / Backtracking / 1 ms / 0 MB
/*
    Main Logic
        solve_naive : 시작점과 끝점을 모두 담는다.
            -   각 경로에서 m 개의 포인트가 순서대로 담기는지 확인한다.
            -   cnt를 하여 m이 라면 올바른 경로 
            
        solve : t_idx 를 이용하여, 바로 다음 포인트까지 경로 추적 
            -   다음 포인트까지 도달했다면, 다음 경로로 이동,
                그 경로가 마지막 경로였다면, 올바른 경로로 추가
        

                
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,m;
int board[10][10];
bool vis[10][10];
pair<int,int> points[100];
vector<pair<int,int>> paths[100'001];
int idx;
vector<pair<int,int>> path;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans;

void solve_naive();
void solve_1(int curX, int curY);


void solve(int curX, int curY, int t_idx) {
    if(curX == points[t_idx].X && curY == points[t_idx].Y){
        if(t_idx == m -1){
            ans++;
            return;
        }
        t_idx++;
    }
    for(int dir = 0 ; dir < 4 ; dir ++){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
        if(board[nx][ny]) continue;
        if(vis[nx][ny])continue;
        
        vis[nx][ny] = 1;
        solve(nx,ny,t_idx);
        vis[nx][ny] = 0;
    }


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    // solve_naive();

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> points[i].X >> points[i].Y;
    }

    vis[points[0].X][points[0].Y] = 1;
    solve(points[0].X, points[0].Y, 1);

    cout << ans;
    return 0;

}


void solve_1(int curX, int curY){
    path.push_back({curX,curY});
    if(curX == points[m-1].X && curY == points[m-1].Y) {
        for(auto p : path) paths[idx].push_back({p.X,p.Y});
        idx++;
        return;
    }
    
    for(int dir = 0 ; dir < 4 ; dir ++){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
        if(board[nx][ny]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        solve_1(nx,ny);
        vis[nx][ny] = 0;
        path.pop_back();
    }

}


void solve_naive(){


    cin >> n >> m;
    
    for(int i = 1 ; i <=n ; i++){
        for(int j = 1 ; j <=n; j ++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < m ; i ++){
        cin >> points[i].X >> points[i].Y;
    }



    vis[points[0].X][points[0].Y] = 1;
    solve_1(points[0].X,points[0].Y);





    // 1 ~ m - 1 까지 안에 들어가 있는지 확인 
    for(int i = 0; i < idx  ; i ++){
        int idx2 = 1;
        pair<int,int> cur = points[idx2] ;
        int cnt = 1;
        for(int j = 0 ; j < paths[i].size(); j ++){
            if(paths[i][j].X == cur.X &&  paths[i][j].Y == cur.Y){
                cnt ++;
                cur = points[++idx2]; 
            }
        }

        if(cnt == m) ans ++;

    }



    cout << ans;
    
}
