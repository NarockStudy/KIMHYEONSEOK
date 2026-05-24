// 	[Codetree] 플레이페어 암호 / L8 / 시뮬레이션 / 2 ms / 0 MB

/*
    문제 입, 출력

    문제 방향
        1. message ->  2 글자씩
        2. 암호 보드 만들기 
        3. 
            1. 같은 행 일 경우 열 + 1
            2. 같은 열 일 경우 행 + 1
            3. 서로 다른 행,열 일 경우, 열 교환 

*/




#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string s,k;
vector<string> c_s;
char board[6][6];
bool alpha_exist [26];
pair<int,int> alpha_idx [26];
vector<string> ans;
void table_init(){
    vector<char> tmp;
    alpha_exist['J' -'A'] = 1;
    for(auto c : k) {
        if(alpha_exist[c -'A']) continue;
        tmp.push_back(c);
        alpha_exist[c -'A'] = 1;
    }
    for(int i = 0 ; i < 26 ; i++){
        if(alpha_exist[i]) continue;
        tmp.push_back(char(i + 'A'));
    }

    int idx = 0;
    for(int i = 0 ; i <tmp.size(); i ++){
        int row = i / 5 + 1;
        int col = i % 5 + 1;
        board[row][col] = tmp[idx++];
        alpha_idx[ board[row][col] - 'A'] = {row,col};
    }
}




int main() {
    // Please write your code here.
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> s >> k;

    // cout << s << ' ' << k ;
    int idx = 0;
    while(idx < s.size()){
        string tmp;

        if(idx + 1 == s.size() ) {
            tmp += s[idx];
            tmp += 'X';
            c_s.push_back(tmp);
        }
        else if( s[idx] != s[idx+1]  ) {
            tmp += s[idx];
            tmp += s[idx+1] ;
            c_s.push_back(tmp);
            idx+=1;
        } 
        else{
            if(s[idx] == 'X') {
                tmp += s[idx];
                tmp += 'Q';
                c_s.push_back(tmp);
            } else {
                tmp += s[idx];
                tmp += 'X';
                c_s.push_back(tmp);
            }
        }
        idx+=1;
    }
    table_init();

    for(auto cur : c_s){
        char a = cur[0];
        char b = cur[1];
        char a__,b__;
        if(alpha_idx[a-'A'].X == alpha_idx[b-'A'].X ){
             a__ = board[alpha_idx[a-'A'].X ][(alpha_idx[a-'A'].Y ) % 5 + 1];
             b__ = board[alpha_idx[b-'A'].X ][(alpha_idx[b-'A'].Y ) % 5 + 1];
            // cout << cur << ' ' << a__ << b__;

        } else if(alpha_idx[a-'A'].Y == alpha_idx[b-'A'].Y){
             a__ = board[(alpha_idx[a-'A'].X ) % 5 + 1][alpha_idx[a-'A'].Y];
             b__ = board[(alpha_idx[b-'A'].X ) % 5 + 1][alpha_idx[b-'A'].Y];
        } else{
             a__ = board[alpha_idx[a-'A'].X][alpha_idx[b-'A'].Y];
             b__ = board[alpha_idx[b-'A'].X][alpha_idx[a-'A'].Y];
        }

        string tmp;
        tmp += a__; tmp += b__;
        cout << tmp ;

    }

    return 0;
}