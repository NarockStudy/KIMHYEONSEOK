// [BOJ16933] 벽 부수고 이동하기 3 / 골드 1 / BFS / 1180 ms / 98396 KB

/*
    문제 입, 출력
        n,m   :       ~1'000      int
        k       :       ~10         int
        
        dist[n+@][m+@][k+@][2]         int
        board[n+@][m+@]             int
        
        q                           queue<E>
        E                           struct
        dx,dy[]                     int
        

    문제 방향

        문자 -> int 형 변환으로 입력 처리
        
        dist 를 1로 시작하기에 -1 초기화 불 필요해 보임. -> dist > 0 으로 처리
        
        시작할때, 낮임으로 0,0,0 시작할 것.

        bfs 시작
            
            범위 검사
            재방문 검사
            벽이 아닌 경우 -> 다음 q 에 푸시해야됨. 낮 -> 밤, 밤 -> 낮 처리해서
            벽인 경우 -> k 값 검사 이후 낮 이면 -> 부셔, 다음 q 삽입
                                        밤이면 낮까지 기다렸다가 부셔   
        
            == 벽인 경우 ->
                 k 값 검사
                    낮이라면 그대로 부셔
                    밤이라면 dist만 +1 , 밤 -> 낮 하고 다시 넣어
                q 삽입
                 

*/

#include<bits/stdc++.h>
using namespace std;

struct E {int X,Y,bcnt,day;};
char c;
int n,m;
int k;

int board[1'010][1'010];
int dist[1'010][1'010][11][2];

queue<E> q;
int dx[] = { 1,0,-1,0};
int dy[] = {0,1,0,-1};




int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            cin >> c;
            board[i][j] = c - '0';
        } 
    }
    
    q.push({1,1,0,0});      // 낮이면 0 , 밤이면 1
    dist[1][1][0][0] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // cout << cur.X << ' ' << cur.Y << ' ' << cur.bcnt << ' ' << ((cur.day == 1 ) ? "sunny " : "night ") << dist[cur.X][cur.Y][cur.bcnt][cur.day] << '\n';

        if(cur.X == n && cur.Y == m){
            cout << dist[cur.X][cur.Y][cur.bcnt][cur.day];
            return 0;
        }
        for(int dir = 0 ; dir <4 ; dir ++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int ncnt = cur.bcnt;
            int nday = 1 - cur.day;

            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            
            
            if(board[nx][ny] == 1) {// 벽일 경우
                ncnt ++;
            }
            if(ncnt > k ) continue;     // k 값 검사.
            // if(dist[nx][ny][ncnt][nday] != 0 ) continue;
            if(board[nx][ny] == 0 ){
                if(dist[nx][ny][ncnt][nday] != 0 ) continue;
                dist[nx][ny][ncnt][nday] = dist[cur.X][cur.Y][cur.bcnt][cur.day] + 1;
                q.push({nx,ny,ncnt,nday});
                // cout << nx << ' ' << ny << ' ' << ncnt << ' ' << nday << '\n';
            }
            if(board[nx][ny] == 1 && cur.day == 0){    // 벽 + 낮
                if(dist[nx][ny][ncnt][nday] != 0 ) continue;
                dist[nx][ny][ncnt][nday]  = dist[cur.X][cur.Y][cur.bcnt][cur.day] + 1;
                q.push({nx,ny,ncnt,nday});
            }
            if(board[nx][ny] == 1 && cur.day == 1){   // 벽 + 밤
                if(dist[cur.X][cur.Y][cur.bcnt][nday] != 0 ) continue;
                dist[cur.X][cur.Y][cur.bcnt][nday] = dist[cur.X][cur.Y][cur.bcnt][cur.day] + 1;
                q.push({cur.X,cur.Y,cur.bcnt,nday});
            }

        }
    }

    
    cout << -1;

}
