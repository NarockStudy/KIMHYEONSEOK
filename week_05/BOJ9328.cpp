// [BOJ9328] 열쇠  / 골드 1 / BFS / 4 ms / 2180 KB
/*
    문제 입,출력
        t       :       ~100            int
        h,w     :       ~100            int

        board[h+@][w+@]                 char
        vis[h+@][w+@]                   bool
        
        dx,dy[]                         int
        key[30]                         bool
        cnt                             int
    문제 방향

        테스트 케이스 만큼 반복
            보드,vis,key 초기화 
            
            보드 입력 및 키 입력 받기

            0,0 에서부터 bfs 시작
                열쇠라면 --> 저장되어있던 문 bfs에 넣기
                문이라면 --> 문 큐에 저장. 
                문서라면 --> cnt + 1

            cnt 출력 
*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t;
int h,w;
char board[110][110];
bool vis[110][110];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
string s;
bool key[30];
int cnt;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> t;

while(t--){
        cin >> h >> w;

        // ==========초기화 =========================
        for(int i=0; i<h+2; i++){
            for(int j=0; j<w+2; j++){
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        fill(key, key+26, 0);

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> board[i][j];
            }
        }
        cnt = 0;

        // ==========초기화 =========================

        cin >> s;
        if(s != "0"){
            for(auto c : s) key[c-'a'] = 1;
        }


        queue<pair<int, int>> door[26];
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= h+2 || ny >= w+2) continue;

                if(vis[nx][ny] || board[nx][ny] == '*') continue;
                vis[nx][ny] = 1;
            
                // ============열쇠 로직 ============
                if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
                int k = board[nx][ny] - 'a';
                key[k] = 1;
                    while(!door[k].empty()){
                        auto ndoor = door[k].front(); door[k].pop();
                        q.push({ndoor.X, ndoor.Y});
                    }
                }
                // ============문 로직 ============
                else if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z'){
                int k =  tolower(board[nx][ny]) - 'a'; 
                    if (!key[k]){ 
                        door[k].push({nx, ny});
                        continue;
                    }
                }
                // ============문서 로직 ============
                else if(board[nx][ny] == '$') cnt++;
                q.push({nx, ny});
            }
        }
    cout << cnt << "\n";
  }
}