// [BOJ20166] 문자열 지옥에 빠진 호석/ 골드 1 / 해시 / 108 ms / 23264 KB
/*
    문제 입,출력

    문제 방향
        1. bfs 8 방향 구현
        2. 1 ~ 5 사이즈 만큼의 문자열 나온 횟수 다 찾기
            == why? n* m * 8^5 이므로 == 10 * 10 * 2^15 == 32*10^3 충분함.
        3. 
*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

unordered_map<string,int> um;
int n,m,k;
string board[11];
// bfs 8 방향 구현
int dx[8] ={1,0,-1,0,-1 ,-1, 1, 1};
int dy[8] ={0,1,0,-1,-1 , 1, 1,-1};


void bfs(int x,int y){
    
    // cout << tmp << '\n';
    string start(1, board[x][y]);
    um[start]++;

    queue<tuple<int,int,string>> q;
    q.push({x,y,start});

    
    while(!q.empty()){
        int x,y;
        string s;
        tie(x,y,s)= q.front(); q.pop();

        if(s.size() == 5) continue;

        // cout << x << ' ' << y << ' ' << s << '\n';

        for(int dir = 0 ; dir < 8 ; dir ++){
            // int nx = x + dx[dir];
            // int ny = y + dy[dir];
            // if(nx < 0 ) nx = n - 1;
            // if(nx >= n) nx = 0;
            // if(ny < 0) ny = m - 1;
            // if(ny >= m) ny = 0;

            int nx = (x + dx[dir] + n) % n;
            int ny = (y + dy[dir] + m) % m;

            
            // string ns = s + board[nx][ny];
            string ns = s + board[nx][ny];
            //  1 ~ 5 사이즈 만큼의 문자열 나온 횟수 다 찾기
            um[ns]++;
            q.push({nx,ny,ns});
        }
    }
    
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    
    cin >> n >> m >> k;

    for(int i = 0 ; i < n ; i ++)
        cin >> board[i];
    

    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < m ; j ++){
            bfs(i,j);
        }
    }

    for(int i = 0 ; i < k ; i ++){
        string s;
        cin >> s;
        cout << um[s] << '\n';
    }
}
