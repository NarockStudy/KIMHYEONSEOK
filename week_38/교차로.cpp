// 교차로 / L8 / Basic / 8 ms / 0 MB

/*
    문제 입, 출력

    문제 방향
        1. priority_queue 로 시간 오름차순으로 관리

        2. road_q 전부 비워있다면, 현재시간을 pq.top T로 변경

        3. 현재 시간 기준으로 pq에 있는 원소들을 road_q에 배치

        4. 대기 상태 인지  판단하기
            데드락일 경우 이후 전부 -1 처리
        5. 교차로 통과 차량 찾기 
            - road_idx 를 저장하기
        6. 통과 시간 저장 및 road_q 원소 제거.

        7. cur 1 증가 
            why ? A,B 원소가 road_q에 있다면, A가 먼저 통과하고, 
            B는 pass_idxs에 포함이 되지 않고 road_q에 존재하므로 통과 시간 1초 대기해야 된다.


*/

#include<bits/stdc++.h>
using namespace std;

#define T get<0>(pq.top())
#define W get<1>(pq.top())
#define I get<2>(pq.top())

const int C = 4;
const long long MX = 0x3fff'ffff'ffff'ffff;

int N;
int ans[200'010];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
queue<int> road_q[C];



int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    

    cin >> N;

    fill(ans,ans+N,-1);

    for(int i = 0; i < N ; i ++){
        int t;
        char w;
        cin >> t >> w;

        pq.push({t,w-'A',i});
    }


    // while(!pq.empty()){

    //     int t,w,i;
    //     tie(t,w,i) = pq.top();
    //     pq.pop();
    //     cout <<  t << ' ' << char(w + 'A') << ' ' <<  i << '\n';
    // }

    long long cur = -1 ;
    while(!pq.empty() || !road_q[0].empty() || !road_q[1].empty() || !road_q[2].empty() || !road_q[3].empty()){


        if( road_q[0].empty() && road_q[1].empty() && road_q[2].empty() &&road_q[3].empty()) {
            cur = T;
        }

        while(!pq.empty() && T  <= cur) {
            road_q[W].push(I);
            pq.pop();
        }

        bool wait[C] = {};
        int cnt = 0;
        for(int i = 0 ; i < C; i ++){   
            if(!road_q[i].empty()){
                wait[i] = 1;
                cnt ++ ;   
            }
        }
        // 데드락
        if(cnt == 4) break;
        
        vector<int> pass_idxs;
        for(int i = 0; i < C; i ++){
            if(wait[i] && !wait[(i + 3) % 4]) {
                pass_idxs.push_back(i);
            }
        }

        for(int i = 0 ; i < pass_idxs.size(); i ++){
                ans[road_q[pass_idxs[i]].front()] = cur;
                road_q[pass_idxs[i]].pop();
        }


        cur ++ ;
        
        




    }


    for(int i = 0 ; i < N; i ++) cout << ans[i] << '\n';
    
}