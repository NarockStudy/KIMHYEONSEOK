// [Codetree] 돌아가는 팔각 의자 / L11 / Simulation / 2 ms / 0 MB
/*
    Main Logic

        북, 남 : 0, 1

        step 1 :   n,d 입력받아, 왼쪽, 오른쪽 전파 검사
           왼쪽 : n 2번, n+1 6번  비교하여, 다르면 회전, 같으면 회전 전파끝
           오른쪽 : n-1 2번, n 6번 비교하여, 다르면 회전, 같으면 회전 전파끝

        step 2 : cw = 1, ccw =-1 이므로, 해당 board 회전
            주의 배열 채우는 순서 덮어쓰기됨으로, cw는 뒤에서부터 채워야됨.
        
*/

#include<bits/stdc++.h>
using namespace std;


const int N = 5;

int board[N][8];
char c;

int k,n,d;

int ans;

void print_board(int arr[N][8]);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    for(int i = 1; i < N; i++){
        for(int j = 0 ; j < 8; j++){
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    

    // print_board(board);

    cin >> k;
    while(k--){
        cin >> n >> d;
        // cout << n << ' ' << d << '\n';


        int dirs[5] = {};
        dirs[n] = d;

        // n 보다 오른쪽 dir 설정
        for(int i = n+1; i <= 4; i++){
            if(board[i-1][2] == board[i][6] ) break;
            dirs[i] = dirs[i-1] * -1;
        }

        // n 보다 왼쪽 dir 설정 
        for(int i = n - 1 ; i >= 1; i--) {
            if(board[i][2] == board[i+1][6]) break;
            dirs[i] = dirs[i+1] * -1;
        }

        for(int i = 1 ; i <=4; i++){
            if(!dirs[i]) continue;
            
            int dir = dirs[i];
            // cw 방향
            if(dir == 1){
                int tmp = board[i][7];  // 
                // 01000011 -> board[i][j] = board[i][j-1]
                for(int j = 7; j >= 1; j--){
                    board[i][j] = board[i][j-1];
                }
                board[i][0] = tmp;
            } 
            // ccw 방향 
            else if(dir == -1){
                int tmp = board[i][0];
                // board[i][j] = board[i][j+1]
                for(int j = 0; j < 7; j++){
                    board[i][j] = board[i][j+1];
                }
                board[i][7] = tmp;
            }
        }

        // for(int i = 1 ; i <=4; i ++) cout << dirs[i] << ' ';
        // cout << '\n';

        // print_board(board);
    }


    int tmp = 1;
    for(int i = 1; i < N; i++){
        ans += tmp * board[i][0];
        tmp *=2;
    }
    cout << ans;
    
}




void print_board(int arr[N][8]){
    for(int i = 1 ; i < N ; i ++ ){
        for(int j = 0 ; j < 8; j++){
            cout << arr[i][j] ;
        }
        cout << '\n';
    }
    cout << '\n';

} 