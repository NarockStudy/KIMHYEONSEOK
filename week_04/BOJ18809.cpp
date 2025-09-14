// [BOJ18809] Gaaaaaaaaaarden / 골드 1 / 백트래킹 / 300 ms / 2068 KB
/*
    문제 입, 출력

        n,m,g,r     :       ~50,50,5,5      int
        board[n+@][m+@]                     int
        seq[g+r+@]                          int
        land                                vector<pair<int,int>>
        dx,dy[]                             int
        queue                               pair<int,int>
        state                               pair<int,int>
        ans        :                        int
    문제 방향

        board를 입력받아 배양 가능한 땅 배열만 저장.
            저장하여 후보군을 순열 생성

        하나의 순열에서 bfs를 통해 최대값 flower 값 찾기

*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[60][60];
vector<pair<int,int>> land;
int n,m,g,r;

int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};
int seq[10];

pair<int,int> state[60][60];
int tmp_cnt;

int ans;



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> g >> r;
    
    for(int i = 0 ;  i < n ; i++){
        for(int j =0 ; j < m ;j ++){
            cin >> board[i][j];
            if(board[i][j] == 2) land.push_back({i,j});
        }
    }
    // 후보군을 순열 생성
    fill(seq+land.size()-g-r,seq+land.size()-r,1);
    fill(seq+land.size()-r,seq+land.size(),2);

    do{
        // ================== 초기화 ================= //

        tmp_cnt = 0;
        queue<pair<int,int>> q;

        for(int i = 0 ; i<n; i++) fill(state[i],state[i]+m,make_pair(0,0));
        for(int i = 0 ; i < land.size(); i ++){
            if(seq[i] == 0) continue;
            state[land[i].X][land[i].Y] = {0,seq[i]};
        }
        // ================== 초기화 ================= //

        // ================== bfs ================= //
        for (int i=0; i<land.size(); i++) {
            if (seq[i] == 1 || seq[i] == 2) {
                state[land[i].X][land[i].Y] = {0, seq[i]};
                q.push(land[i]);
            }
        }
        
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int curtime = state[cur.X][cur.Y].X;
            int curcolor = state[cur.X][cur.Y].Y;
            if (curcolor == 3) continue;

            for (int dir=0; dir<4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == 0) continue;

                if (state[nx][ny].Y == 0) {
                    state[nx][ny] = {curtime+1, curcolor};
                    q.push({nx,ny});
                }
                else if (state[nx][ny].Y == 1) {
                    if (curcolor == 2 && state[nx][ny].X == curtime+1) {
                        tmp_cnt++;
                        state[nx][ny].Y = 3;
                    }
                }
                else if (state[nx][ny].Y == 2) {
                    if (curcolor == 1 && state[nx][ny].X == curtime+1) {
                        tmp_cnt++;
                        state[nx][ny].Y = 3;
                    }
                }
            }
        }
        // ================== bfs ================= //

        ans = (ans < tmp_cnt) ? tmp_cnt : ans;
    }
    while(next_permutation(seq,seq+land.size()));

    cout << ans ;
}