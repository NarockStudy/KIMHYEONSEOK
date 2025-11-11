// [BOJ10814] 나이순 정렬 / 실버 5 / 정렬 I / 36 ms / 7900 KB
/*
    문제 입,출력

    문제 방향

        1.  나이순으로 정렬

        2. 나이가 같다면, 입력한 순서대로 출력 == stable_sort 


*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int,string> arr[100'001];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++ ) cin >> arr[i].X >> arr[i].Y;
    

    // 나이가 같다면, 입력한 순서대로 출력 == stable_sort 
    stable_sort(arr,arr+n,[](const pair<int,string>& a, const pair<int,string>&b){
        return a.X < b.X ;  // 나이순으로 정렬
    });

    for(int i = 0 ; i < n ; i ++ ) cout << arr[i].X << ' ' << arr[i].Y << '\n';
}
