// [BOJ1786] 찾기 / 플래티넘 5 / KMP / 44 ms / 9432 KB
/*
    문제 입, 출력

    문제 방향
        1. KMP 알고리즘
            failure(x) : s[0:x+1] 에서 접미사와 접두사와 같은 최대 길이
                        자기 자신 제외한 
        2. 하나만 찾는 게 아니라 중복하여 찾음.
            찾은 다음 로직은, 실패함수를 이용하여, j를 f[j-1] 로 이동
*/

#include<bits/stdc++.h>
using namespace std;

/*
        a b a b a c a 
i = 1   f = [0,0,0,0,0,0,0]
i = 2   f = [0,0,1,0,0,0,0]
i = 3   f = [0,0,1,2,0,0,0]
i = 4   f = [0,0,1,2,3,0,0]
i = 5   f = [0,0,1,2,3,0,0] k[5] != k[3] , k[5] != k[f[3-1]], k[5] != k[f[2-1]] j =0 이므로,f[0] = 0;
i = 6   f = [0,0,1,2,3,0,1] k[6] = k[f[0]]
*/
vector<int> failure(string& s){

    vector<int> f(s.size());

    for(int i = 1,j = 0 ; i < s.size(); i ++ ){
        while(j > 0 && s[i] != s[j]) j = f[j -1];
        if(s[i] == s[j]) f[i] = ++j;
    }

    return f;
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string t,p;
    getline(cin,t);
    getline(cin,p);

    vector<int> f = failure(p);
    vector<int> ans;
    for(int i = 0, j = 0 ; i < t.size(); i ++ ){
        while(j > 0 && t[i] != p[j]) j = f[j-1];
        if(t[i] == p[j]) j ++;

        if(j == p.size()) {

            /*
            ex)
            T:    a b c d e f g
            P:    c d e 
            ans : 3 
            1. 현재 i= 4(e) 에 위치에서 찾았다.
            2. j - 1 만큼 뒤로 가야 c의 인덱스를 찾을 수 있다.
            3. 0 - index 에서 1 -index 로 변환해야 되기 때문에 +1
            4. ans = i(==4) - (j(==3) - 1) + 1
            */
            ans.push_back(i - (j - 1) + 1);
            j = f[j-1];
        }
    }


    cout << ans.size() << '\n';
    for(int& a : ans) cout << a << ' ';
    
}

