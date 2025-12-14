// [BOJ23326] 홍익 투어리스트 / 골드 3 / 이진 검색 트리 / 152 ms / 20768 KB
/*
    문제 입, 출력

    문제 방향

    // 1 : 현재 위치가 명소인지 구분 
    // 2 : x만큼 이동
    // 3 : 현 위치에서 위, 아래 중 가까운 명소인지 구분 
*/

#include<bits/stdc++.h>
using namespace std;

int n,q;
int query,i,x;
int cur = 1;
set<int> tour;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >>  n >> q;
    for(int i = 1; i <= n ; i ++ ) {
        int myoung;
        cin >> myoung;
        if(myoung) tour.insert(i);
    }


    while(q--){
        cin >> query;
        if(query == 1)
        {
            cin >> i;
            if(tour.find(i) != tour.end()) tour.erase(i);
            else tour.insert(i);
             
        }
        else if( query == 2)
        {
            cin >> x;
            cur = (cur + x - 1) % n ;
            // 현재 3이고 x 가 3 일때
            // 3 4 5 1 <---
            // 
            cur ++;
        }
        else if(query == 3)
        {

            if(tour.empty()) cout << "-1\n";
            else {
                set<int>::iterator it = tour.lower_bound(cur);
                if(it == tour.end()){
                    // n - cur : 시계방향으로 맨 앞으로 이동한 거리
                    // *tour.begin() : 맨 앞에서 가장 가까운 위치
                    cout << (n - cur) + *tour.begin() << '\n';  
                }
                else {
                     cout << (*it - cur) << '\n';
                }
            }
        }
    }
}