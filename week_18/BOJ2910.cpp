// [BOJ2910] 빈도 정렬 / 실버 3 / 정렬 II / 0 ms / 2024 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n,c;

    cin >> n >> c;

    vector<pair<int,int>> vec;
    for(int i = 0 ; i < n ; i ++ ){
        int t;
        cin >> t;
        bool is_find = false;
        for(auto& x : vec) {
            if(x.first == t) {
                x.second ++;
                is_find = true; 
                }
            if(is_find ) break;
        }
        if(!is_find) vec.push_back({t,1});
    }

    stable_sort(vec.begin(),vec.end(),[](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second;
    });

    
    for(auto &x : vec){
        while(x.second--) cout << x.first << ' ';
    }
    
}