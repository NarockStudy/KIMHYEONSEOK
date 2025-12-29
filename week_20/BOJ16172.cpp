// [BOJ16172] 나는 친구가 적다 (Large) / 브론즈 2 / KMP / 4 ms / 3460 KB
/*
    문제 입,출력

    문제 방향

        failure : 실패함수이다.  즉, O(|a| + |b| )를 구현하기 위한 인덱스 배열 
        
        a를 순회 하더라도, b의 0 부터 시작하는 게 아니라 failure를 이용해서 
        이미 구한 길이 만큼 점프 할 수 있다.

        먼저 isdigit 을 이용하여 숫자 제외시킴.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> failure (string& s){
    vector<int> f(s.size());

    int j = 0 ; 
    for(int i = 1 ; i < s.size(); i ++ ){
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }

    return f;

}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s,k;
    cin >> s >> k;

    // remove digit
    string s_1;
    for(int i = 0 ; i < s.size(); i ++){
        if(isdigit(s[i])) continue;
        s_1 += s[i];
    }
    s = s_1;


    vector<int> f= failure(k);
    bool is_find = false;
    int j = 0;

    for(int i = 0 ; i < s.size() ; i ++ ){
        while(j > 0 && s[i] != k[j]) j = f[j-1];
        if(s[i] == k[j]) j ++;
        if(j == k.size()) {
            is_find = true;
            break;
        }
    }


    if(is_find) cout << 1;
    else cout << 0;
    
}
