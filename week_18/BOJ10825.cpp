// [BOJ10825] 국영수 / 실버 4 / 정렬 II / 52 ms / 6600 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

struct E{
    int kor,eng,mat;
    string name;
};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    int n;
    cin >> n;
    E arr[n];
    int k,e,m;
    string na;
    for(int i = 0 ; i < n ; i ++ ) {
        cin >> na >> k >> e >> m;
        arr[i] = {k,e,m,na};
    }

    sort(arr,arr+n,[](const E& a, const E& b){
        if(a.kor != b.kor) return a.kor > b.kor;
        if(a.eng != b.eng) return a.eng < b.eng;
        if(a.mat != b.mat) return a.mat > b.mat;
        return a.name < b.name;
    });

    for(E ans : arr) cout << ans.name << '\n';
    
}