// [BOJ21944] 문제 추천 시스템 Version 2 / 골드 2 / 이진 검색 트리 / 136 ms / 12664 KB
/*
    문제 입, 출력

    문제 방향

*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int PROBLEM = 100'000;
const int LEVEL = 100;
const int ALGORITHM = 100;

set<int> problem[LEVEL+1][ALGORITHM+1];
set<int> problem2[LEVEL+1];
pair<int,int> solved[PROBLEM+1];


int n,m;
int p,l,g,x;
string cmd;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n;
    for(int i = 0 ; i < n  ; i ++ ) {
        cin >> p >> l >> g;
        problem[l][g].insert(p);
        problem2[l].insert(p);
        solved[p] = {l,g};
    }

    cin >> m;
    for(int i = 0 ; i < m; i ++ ){
        cin >> cmd;
        if(cmd == "recommend"){
            cin >> g >> x;
            if(x == 1){
                for(int j = 100; j >= 1 ; j--){ // 가장 어려운 문제 번호를 출력
                    if(problem[j][g].empty()) continue;
                    cout << *(prev(problem[j][g].end())) << '\n'; // 문제 번호가 큰 것으로 출력
                    break;
                }
            } else{
                for(int j = 1 ; j <= 100 ; j ++){   // 가장 쉬운 문제 번호를 출력
                    if(problem[j][g].empty()) continue;
                    cout << *(problem[j][g].begin()) <<'\n';//문제 번호가 작은 것으로 출력
                    break;
                }
            }
        }
        else if(cmd == "recommend2"){
            cin >> x;
            if(x == 1){
                for(int j = 100; j >= 1 ; j--){ // 가장 어려운 문제 번호를 출력
                    if(problem2[j].empty()) continue;
                    cout << *(prev(problem2[j].end())) << '\n'; // 문제 번호가 큰 것으로 출력
                    break;
                }
            } else{
                for(int j = 1 ; j <= 100 ; j ++){   // 가장 쉬운 문제 번호를 출력
                    if(problem2[j].empty()) continue;
                    cout << *(problem2[j].begin()) <<'\n';//문제 번호가 작은 것으로 출력
                    break;
                }
            }
        }
        else if(cmd == "recommend3"){
            cin >> x >> l;
            bool is_valid = false;
            if(x==1){
                for(int j = l ; j <=100; j ++ ){    // 난이도 L보다 크거나 같은 문제 중 
                    if(problem2[j].empty()) continue;
                    cout << *(problem2[j].begin()) << '\n'; //문제가 여러 개라면 그 중 문제 번호가 작은 것으로 출력
                    is_valid = true;
                    break;
                }
            } else{
                for(int j= l-1 ; j >= 1;  j-- ){ // 난이도 L보다 작은 문제 중 가장 어려운 문제 번호
                    if(problem2[j].empty()) continue;
                    cout << *(prev(problem2[j].end())) << '\n';
                    is_valid = true;
                    break;
                }
            }
            if(!is_valid) cout << "-1\n";
        }

        else if(cmd == "add"){
            cin >> p >> l >> g;
            problem[l][g].insert(p);
            problem2[l].insert(p);
            solved[p] = {l,g};
        }

        else if(cmd == "solved"){
            cin >> p;
            int rl,rg;
            tie(rl,rg) = solved[p];
            problem[rl][rg].erase(p);
            problem2[rl].erase(p);

        }

    }
    
}