// [BOJ14499] 주사위 굴리기 / 골드4 / 시뮬레이션 / 24 ms / 2024 KB

/*  
// 지도가 n x m 이 있다.
// 주사위가 그 위에 있다.
// 주사위의 시작 좌표 부터 명령어를 실행 
    // 유효성 검사를 해서 바깥이면 무시
        // 가능하면
            // 지도의 칸에 수가 0 이면, 주사위의 바닥면에 쓰여 있는 수가 지도에 복사
            // 지도의 칸에 수가 0 이 아니라면 -> 지도 칸의 수를 바닥면을오 복사  지도 칸에 0 복사
        // 주사위의 상단 값 출력 


    // x: 세로 , y: 가로
    /// n: 세로, m : 가로 

// 1 : top ||  2 : north  |  5 : south  | 4 : west , 5 : east , 6 : bottom
*/


#include<bits/stdc++.h>
using namespace std;



int board[22][22];
int tmp;
int top = 1;
int north = 2;
int south = 5;
int west = 4;
int east = 3 ;
int bottom = 6;

int dices[7];       
int main(void){
    int n,m,x,y,k;
    cin >> n >> m >> x >> y >> k;

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> board[i][j] ;
        }
    }

    for(int i = 0; i < k; i ++){
        int cmd;
        cin >> cmd;

        switch(cmd){
            case(1):        // 동쪽이동
                if(y+1 >= m)     break;
                
                y++;
                tmp = top ;
                top = west;
                west = bottom;
                bottom = east;
                east = tmp; 
                
                if(board[x][y] == 0 ) board[x][y] = dices[bottom];
                else                  {dices[bottom] = board[x][y]; board[x][y] = 0;}
                cout <<  dices[top] << '\n' ;
                break;
            case(2):        // 서쪽이동 
                if(y-1 < 0)     break;
                
                y--;

                tmp = top; 
                top = east;
                east = bottom;
                bottom = west;
                west = tmp;
                if(board[x][y] == 0 ) board[x][y] = dices[bottom];
                else                  {dices[bottom] = board[x][y]; board[x][y] = 0;}
                cout <<  dices[top] << '\n' ;
                 break;
            case(3):        // 북쪽이동 
                if(x-1 < 0)     break;
                
                x--;
                
                tmp = top;
                top = south;
                south = bottom;
                bottom = north;
                north = tmp;
                if(board[x][y] == 0 ) board[x][y] = dices[bottom];
                else                  {dices[bottom] = board[x][y]; board[x][y] = 0;}
                cout <<  dices[top] << '\n' ;
                break;
            case(4):        // 남쪽이동
                if(x+1 >= n)    break;
                
                x++;
                
                tmp = top;
                top = north;
                north = bottom;
                bottom = south;
                south = tmp;
                if(board[x][y] == 0 ) board[x][y] = dices[bottom];
                else                  {dices[bottom] = board[x][y]; board[x][y] = 0;}
                cout <<  dices[top] << '\n' ;

                break;
        }

    }
}


