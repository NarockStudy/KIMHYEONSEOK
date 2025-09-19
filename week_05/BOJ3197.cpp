// [BOJ3197] 백조의 호수 / 플래티넘 5 / BFS / 120 ms / 16752 KB
/*
    문제 입,출력
        r,c         :       ~1'500      int
        
        board[r+@][c+@]                 int
        vis [r+@][c+@]                  bool
        q                               queue<pair<int,int>>
        dx,dy[]                         int        
        tmp[r+@][c+@]                   int
        cnt                             int

    문제 방향
        =============================시간 초과 ===========================
        char -> int 형으로 변환
            . -> 0
            X -> 1
            L -> 2
        
        무한 루프 시작

            tmp bfs 시작 
                . 이면 q에 넣고 X 발견하면 board 갱신

            LL 끼리 만날 수 있으면 종료


            vis 배열 초기화 
            tmp = board 갱신
        =============================시간 초과 ===========================
        
        board 갱신 대신 q 갱신으로 변경



            L - L bfs

            빙판 bfs

            다음 큐 갱신

        
*/


#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int r,c;
char board[1502][1502];
bool vis[1502][1502];        // 물 
bool swan_vis[1502][1502];   // 백조 
int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};

int cnt;
vector<pair<int,int>> L;
queue<pair<int,int>> water_q, water_next_q;
queue<pair<int,int>> swans_q, swans_next_q;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

     cin >> r >> c;


    for(int i=0 ; i<r; i++){
        for(int j=0 ; j<c; j++){
            cin >> board[i][j];
            if(board[i][j] != 'X') {
                water_q.push({i,j});
                vis[i][j] = 1;
            }
            if(board[i][j] == 'L') {
                L.push_back({i,j});
            }
        }
    }

    swans_q.push(L[0]);
    swan_vis[L[0].X][L[0].Y] = 1;

    while(1){
        // 백조 BFS 
        bool is_valid = false;
        while(!swans_q.empty() && !is_valid){
            auto cur = swans_q.front(); swans_q.pop();

            for(int dir = 0 ; dir < 4 ; dir ++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
                if(swan_vis[nx][ny]) continue;
                 swan_vis[nx][ny] = 1;
                if(board[nx][ny] == 'X'){
                    swans_next_q.push({nx,ny});
                    continue;
                }
                if(nx==L[1].X && ny==L[1].Y) {
                    is_valid = true;
                    break;
                }
                swans_q.push({nx,ny});
            }
        }

        if(is_valid) break;
        
        // 빙판 녹이기 BFS
        while(!water_q.empty()){
            auto cur = water_q.front(); water_q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                if(board[nx][ny] == 'X'){
                    board[nx][ny] = '.';
                    water_next_q.push({nx,ny});
                } else {
                    water_q.push({nx,ny});
                }
            }
        }
        
        // 큐 갱신
        swans_q = swans_next_q; 
        water_q = water_next_q;
        while(!swans_next_q.empty()) swans_next_q.pop();
        while(!water_next_q.empty()) water_next_q.pop();
        cnt++;
    }


    cout << cnt ;
}





// #include<bits/stdc++.h>
// using namespace std;

// #define X first
// #define Y second

// int r,c;

// int board[1502][1502];
// int tmp[1502][1502];
// bool vis[1502][1502];
// bool connect_vis[1502][1502];
// int dx[] ={1,0,-1,0};
// int dy[] ={0,1,0,-1};

// vector<pair<int,int>> L;
// int cnt;
// int main(void){
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     cin >> r >> c;
//     for(int i = 0 ; i < r; i++){
//         for(int j = 0 ; j < c ; j ++){
//             char c;
//             cin >> c;
//             if(c == 'X') board[i][j] =  1;
//             else if (c == 'L') {
//                 board[i][j] = 2;
//                 L.push_back({i,j});
//             }
//         }
//     }


//     for(int i = 0 ; i < r ; i ++){
//         for(int j = 0 ; j < c ; j ++){
//             tmp[i][j] = board[i][j];
//         }
//     }

//     while(1){
        
//         queue<pair<int,int>> q;

//         for(int i = 0 ; i < r ; i ++){
//             for(int j = 0 ; j < c ; j ++){
//                 if(board[i][j] == 0) {
//                     q.push({i,j});
//                     vis[i][j] = 1;
//                 }
//             }
//         }

//         while(!q.empty()){
//             auto cur = q.front(); q.pop();

//             for(int dir = 0; dir <4 ; dir++){
//                 int nx = cur.X + dx[dir];
//                 int ny = cur.Y + dy[dir];

//                 if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
//                 if(vis[nx][ny]) continue;
//                 if(board[nx][ny] != 1) continue;
//                 tmp[nx][ny] = 0;
//                 vis[nx][ny] = 1;
//             }
//         }


//         // L - L 연결 검사
//         int st_x = L[0].X;
//         int st_y = L[0].Y;
//         q.push({st_x,st_y});
//         connect_vis[st_x][st_y] = 1;
//         bool is_valid = false;
//         while(!q.empty() && !is_valid){
//             auto cur = q.front(); q.pop();
//             if(cur.X == L[1].X && cur.Y == L[1].Y) {
//                 is_valid = true;
//                 break;
//             }
//             for(int dir = 0; dir <4 ; dir++){
//                 int nx = cur.X + dx[dir];
//                 int ny = cur.Y + dy[dir];

//                 if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
//                 if(connect_vis[nx][ny]) continue;
//                 if(board[nx][ny] == 1) continue;
//                 q.push({nx,ny});
//                 connect_vis[nx][ny] = 1;
//             }
//         }
        
//         // cout << "valid test : " << is_valid << '\n';
//         if(is_valid) break;


//         for(int i = 0 ; i < r; i++){
//             for(int j = 0 ; j < c ; j ++){
//                 board[i][j] = tmp[i][j];
//             } 
//         }

//         for(int i = 0 ; i < r ; i ++) {
//             fill(vis[i],vis[i]+c,0);
//             fill(connect_vis[i],connect_vis[i]+c,0);
//         }

//         // for(int i = 0 ; i < r; i++){
//         //     for(int j = 0 ; j < c ; j ++){
//         //         cout << tmp[i][j] << ' ';
//         //     } cout << '\n';
//         // }

//         cnt ++ ;


        
//     }

 
    
//     cout << cnt;
// }
