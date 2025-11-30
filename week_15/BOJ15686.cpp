// [BOJ15686] 치킨 배달 / 골드 5 / 시뮬레이션 / 0 ms / 2036 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,m;
int board[51][51];

vector<pair<int,int>> house;
vector<pair<int,int>> c_house;

int ans = 0x5f5f5f5f;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n >> m ;
    for(int i = 1; i <=n ; i++){
        for(int j = 1 ; j<=n ; j++){
            cin >> board[i][j];

            if(board[i][j] == 1) house.push_back({i,j});
            else if(board[i][j] == 2) c_house.push_back({i,j});
        }
    }

    vector<int> sel;
    for(int i = 0 ; i < c_house.size(); i++){
        sel.push_back((i < c_house.size()-m ) ? 0 : 1 );
    }

    // 전체가 c_house.size() 이고 m개만 1 일떄 
    // 0은 c - m 개 

    do{

        int dist = 0;
        for(auto h : house){
            int tmp = 0x5f5f5f5f;
            for(int i = 0 ; i < c_house.size(); i++){
                if(sel[i] == 0) continue;
                tmp = min(tmp,abs(h.X-c_house[i].X) + abs(h.Y - c_house[i].Y));
            }
            dist += tmp;
        }


        ans = min(dist,ans);
        // for(int s : sel ) cout << s;
        // cout << '\n';


    }while(next_permutation(sel.begin(),sel.end()));
 
    
    cout << ans;
}