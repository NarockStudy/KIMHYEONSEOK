// [BOJ3190] 뱀   / 골드 4 / 시뮬레이션 / 0 ms / 2064 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

#define X first 
#define Y second


int board[51][51];
// bool vis[51][51];
int n,m;
int x,y,d;

// 북, 동, 남, 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


/*
    
*/
int ans ;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;

    cin >> x>> y >> d;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <m; j++){
            cin >> board[i][j];
        }
    }

    while(1){
        if(board[x][y] == 0) {
            ans ++;
            board[x][y] = 2;
        }

        bool is_find = false;
        for(int dir = 0 ; dir <4 ; dir ++){
            d = (d + 3) % 4;  
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
            if(board[nx][ny] == 0){
                tie(x,y) = {nx,ny};
                is_find = true;
                break;
            }
        }

        if(!is_find){
            int bd = (d + 2 ) % 4;
            
            int nx = x + dx[bd];
            int ny = y + dy[bd];
            // if(nx < 0 || ny < 0 || nx >= n || ny >= m ) break;  // 벽 
            if(board[nx][ny] == 1) break;       // 벽 


            x = nx ;
            y = ny ;
        }



    }

    cout << ans;


    
}