// [BOJ17219] 비밀번호 찾기 / 실버 4 / 해시 / 124 ms / 16448 KB
/*
    문제 입,출력

    문제 방향
        1. qurey == key를 통해  value 값을 찾음
        2. 중복되지 않으므로 해시 자료구조 이용 

*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string,string> um;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0 ; i < n ; i ++){
        string s1,s2;
        cin >> s1 >> s2;
        um[s1] = s2;
    }

    for(int i = 0 ; i < m ; i ++){
        string s1;
        cin >> s1;
        //  qurey == key를 통해  value 값을 찾음
        cout << um[s1] << '\n';
    }


    
}
