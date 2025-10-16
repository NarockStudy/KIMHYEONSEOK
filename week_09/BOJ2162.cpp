// [BOJ2162] 선분 그룹 / 플래티넘 5 / Union-Find / 112 ms / 2180 KB
/*
    문제 입, 출력

    문제 방향

        1. 입력받기 
        2. i, i+1 를 이용해서 n^2 전부 선분 교차 확인

        3. 선분 교차 판정을 이용
            먼저 외적을 이용해 세 점의 ccw ,cw  확인하기 
                ex) 교차한다고 가정하면 
                    ab X ac : ccw  , ab X ad : cw 이다.
            예외 : 일직선에 있을 경우
                한 점이 선분 위에 있을 경우 확인하고 있다면 교차임
                두 선분이 동 떨어져있다면 교차 X 

        4. cnt 배열을 두어서 같은 집합의 크기 셈. 
            (p[u]-- 로 해서 min(ans,p[i])을 이용해서 제출했는데 틀림 이유 모르겠음)
*/

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

struct Point{int x,y;};
int n;
int x_1,x_2,y_1,y_2;

vector<int> p(3001,-1);
vector<pair<Point,Point>> points(3001);

int cnt[3001];
int ans_cnt,ans;

int find(int x){
    if(p[x] < 0 ) return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    p[u]--;
    p[v] = u ;
    // cnt 배열을 두어서 같은 집합의 크기 셈. 
    cnt[u] +=cnt[v];
    return true;
}

int ccw(Point a,Point b,Point c){
    // conduct

    /*
        i   j   k
        ab.x ab.y 0
        ac.x ac.y 0
        == (ab.x * ac.y - ab.y * ac.x )k
    */
    int ab_x = b.x - a.x ; int ab_y = b.y - a.y;
    int ac_x = c.x - a.x; int ac_y = c.y - a.y;
    int val = (ab_x * ac_y) - (ab_y * ac_x);
    if(val < 0 ) return -1;
    else if(val == 0) return 0;
    else return 1;
}
bool isonline(Point a,Point b,Point c){
    return (min(a.x,b.x) <= c.x && max(a.x,b.x) >= c.x
            && min(a.y,b.y) <= c.y && max(a.y,b.y) >= c.y);
}
bool is_intersect(Point a,Point b,Point c,Point d){

    // 외적을 이용해 세 점의 ccw ,cw  확인하기 
    int ab_c = ccw(a,b,c);
    int ab_d = ccw(a,b,d);
    int cd_a = ccw(c,d,a);
    int cd_b = ccw(c,d,b);

    //  선분 교차 판정
    if(ab_c * ab_d < 0 && cd_a * cd_b < 0) return true;

    // 일직선에 있을 경우
    if(isonline(a,b,c) && ab_c == 0) return true;
    if(isonline(a,b,d) && ab_d == 0) return true;
    if(isonline(c,d,a) && cd_a == 0) return true;
    if(isonline(c,d,b) && cd_b == 0) return true;

    return false;
    
}


int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    

    cin >> n;
    
    fill(cnt,cnt+n,1);

    for(int i = 0 ; i < n ; i ++ ){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        points[i] = {{x_1,y_1},{x_2,y_2}};
    }

    for(int i = 0 ; i < n - 1; i ++){
        for(int j = i + 1 ; j < n ; j++){
            if(is_intersect(points[i].X,points[i].Y,points[j].X,points[j].Y)) 
                uni(i,j);
        }
    }
    

    for(int i = 0; i < n; i ++ ) 
        if(p[i] < 0 ) ans ++;
    
    ans_cnt = *max_element(cnt,cnt+n);
    
    // for(int i = 0; i < n ; i++ ) cout << p[i] << ' ';
    // cout << '\n';


    cout << ans << '\n';   
    cout << ans_cnt ;
    
}