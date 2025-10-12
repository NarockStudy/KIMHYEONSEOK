// [BOJ14502] 연구소  / 골드 4 / 시뮬레이션 / 48 ms / 2024 KB
/*
    문제 입, 출력

    문제 방향

        0 위치 3개 선정 
*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int k = 3;
int n,m;
int board[10][10];
int tmp[10][10];
bool vis[10][10];
vector<int> zeroidx;
vector<int> sel;
vector<pair<int,int>> virus;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n >> m ;
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < m ; j ++){
            cin >> board[i][j];
            if(board[i][j] == 0) zeroidx.push_back(i*m + j);

            else if(board[i][j] == 2) virus.push_back({i,j});
        }
    }

    // 0.....0 1 1 1
    for(int i = 0 ; i < zeroidx.size(); i ++ ){
        sel.push_back(i < zeroidx.size() - 3 ? 0 : 1);
    }


    do{

        // tmp 배열 복사 
        for(int i = 0 ; i < n ; i ++ )
            for(int j = 0 ; j < m ; j ++)
                tmp[i][j] = board[i][j];

        // 조합 3개 선정하여 0 -> 1 마킹
        for(int i = 0 ; i < zeroidx.size(); i ++){
            if(sel[i] == 0) continue;
            tmp[zeroidx[i]/m][zeroidx[i]%m] = 1;
        }

        for(int i = 0 ; i < n ; i ++ ) fill(vis[i],vis[i]+m,0);

        queue<pair<int,int>> q;
        for(pair<int,int> v : virus)  {
            q.push({v.X,v.Y});
            vis[v.X][v.Y] = 1;
        }

        while(!q.empty()){
            auto cur = q.front(); q.pop();

            for(int dir = 0 ; dir <4 ; dir ++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || ny < 0 || nx >=n || ny >=m) continue;
                if(vis[nx][ny]) continue;
                if(tmp[nx][ny] != 0) continue;
                tmp[nx][ny] = 2;
                q.push({nx,ny});
                vis[nx][ny] = 1;                
            }
        }
        


        int cnt = 0;
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                if(tmp[i][j] == 0)  cnt++;
            }
        }

        ans = max(cnt,ans);

    }while(next_permutation(sel.begin(),sel.end()));


    cout << ans ;
}

// 3 2 14 
// 14 / 4 14