// [BOJ13414] 수강신청 / 실버 3 / 해시 / 152 ms / 25360 KB
/*
    문제 입,출력

    문제 방향
        1. 중복된 대기목록을 삭제한다 == 새로운 원소 삽입하면 지워짐 == 해시 알고리즘
        2. sort를 이용해서 k or l 중 작은 값을 출력 

*/

#include<bits/stdc++.h>

using namespace std;

unordered_map<string,int> um;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k,l;
    cin >> k >> l;
    
    // 중복된 대기목록을 삭제한다 == 새로운 원소 삽입하면 지워짐 == 해시 알고리즘
    for(int i = 1; i <= l ; i ++){
        string s;
        cin >> s;
        um[s] = i;        
    }
    
    vector<pair<string,int>> vec(um.begin(),um.end());


    // sort를 이용해서 k or l 중 작은 값을 출력 
    sort(vec.begin(),vec.end(),[](const pair<string,int>&a,const pair<string,int>&b){
        return a.second < b.second;
    });

    k = min(k, (int)vec.size());
    for(int i = 0 ; i < k ; i ++){
        cout << vec[i].first << '\n';
    }
    
    
    return 0;
}