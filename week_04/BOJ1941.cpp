// [BOJ1941] 소문난 칠공주 / 골드 3 / 백트래킹 / 140 ms / 2024 KB

/*
    문제 입, 출력
        board[5][5]                 int


        n                           const int         
        m                           cosnt int
        

    문제 방향

        문자 입력 받아 int 형으로 처리
        
        for 문 돌아서 해당 좌표들 ans 값으로 설정
            solve
                7개 좌표 선택
                    해당 조건에 만족하면 ans에 넣기
        
        
        1번째 방법.
        solve
            조합 480700 개 전부 뽑기.
            유효성 검사하기 -> is_valid() 호출

        is_valid
        1. 이다솜파 4명 확인
            cnt_1 < 4 
        2. 인접해야된다.  
            bfs로 상하좌우에 7개 중 하나 있는지 확인.
            cnt_2 == m(7)       

        2번째 방법.
        solve_2
            이다솜파 카운트해서 조합 뽑기
                4명 안되면 종료
        
        is_valid
            bfs 로 접 카운트 == 7 학인
            
        
*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int m = 7;
const int n = 5;
int board[5][5];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int sel[10];

int cnt;

bool is_adj(){
    vector<pair<int,int>> path; // 조합 중 한 가지
    int cnt_2   =   0;  // 인접 카운트

    queue<pair<int,int>> q;
    bool vis[m] = {};       // 0 초기화 방문 표시용 
    for(int i = 0 ; i <m ; i++)    path.push_back({sel[i]/5,sel[i]%5});

    q.push(path[0]);
    vis[0] = true;
    cnt_2++;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir ++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            for(int i = 0; i <m ; i++){
                if(vis[i]) continue;
                if(path[i].X == nx && path[i].Y == ny){
                    vis[i] = 1;
                    q.push(path[i]);
                    cnt_2++;
                }
            }
        }
    }

    // 인접한 수 7  유효성 검사
    return (cnt_2 == m);           
}

void solve_2(int k,int s_cnt){
    if(k == m){
        
        if(s_cnt >= 4 && is_adj())         cnt ++;

        return;
    }

    if(s_cnt + m - k < 4 )  return;          // 조거 희망 진압
    int st = 0;
    if(k!=0) st = sel[k-1] + 1 ;
    for(int i = st ; i<25; i ++){
        sel[k] = i;
        int add_s = (board[i/n][i%n]);
        solve_2(k+1,s_cnt + add_s);
    }
    
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < n ; j++){
            char c;
            cin >> c;
            if(c == 'S') board[i][j] = 1;
            // else board[i][j] = 2;
        }
    }
    // for(int i = 0 ; i < n * n; i ++){
    //     if(i != 0 && i%n == 0) cout << '\n';
    //     cout << board[i/n][i%n] << ' ';
    // }
   
    // solve(0);
    solve_2(0,0);

    cout << cnt ;
    
}