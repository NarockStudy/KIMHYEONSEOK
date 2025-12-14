// [BOJ19700] 수업 / 골드 1 / 이진 검색 트리 / 248 ms / 10684 KB
/*
    문제 입, 출력

    문제 방향
        1. 키 순으로 내림차순 정렬
        2. set / multiset 은  "오른차순"임으로 음수 + lower_bound 활용 

        3. 그리디 식으로 키 순으로 multiset에 삽입
            3-1. 찾지 못을 경우, 맨 앞자리에 세움 == (insert(-1)) // 내림차순 원소들이 차례로 들어오기 때문
            3-2. 삽입 시, -(원소의 등수) +1 을 함 == 이유는 원소가 들어가면 +1 되기 때문
            3-3. 삭제  + 새로 -1 하여 삽입.


*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int NMAX = 500'000;

int n;
pair<int,int> arr[NMAX + 1];
multiset<int> ms;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i ++ ) {
        cin >> arr[i].X >> arr[i].Y ;
    }

    sort(arr,arr+n,greater<pair<int,int>>());   // 내림차순 정렬 

    for(int i = 0 ; i < n ; i ++ ){
        multiset<int>::iterator it = ms.lower_bound(-arr[i].Y + 1);
        if(it == ms.end()) ms.insert(-1);
        else {
            int val = *it;
            
            ms.erase(it);
            ms.insert(val - 1);
        }
    }
    
    
    cout << ms.size();
    
}