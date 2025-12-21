// [BOJ11656] 접미사 배열 / 실버 4 / 정렬 II / 4 ms / 2820 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string s;
    cin >> s;
    string ss[s.size()];
    for(int i = 0 ; i < s.size(); i ++){
        for(int j = i ; j < s.size(); j ++) ss[i] += s[j];
        // cout << '\n';
    }

    sort(ss,ss+s.size());

    for(string ans : ss) cout << ans <<'\n';
    
}