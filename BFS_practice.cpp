//AOJ本 12_4

#include <bits/stdc++.h>
#include <queue>
using namespace std;
static const int INF = 1<<21;
//Mは隣接行列 (M[0][1] = 1 だったら、点0→1に辺が伸びてる)
int n, M[100][100];
int d[100];

void bfs(int s){
    queue<int> q;
    q.push(s); //qにsを追加

    int u;
    while(!q.empty()){
        //qの先頭をuに入れて、uはqから取り出す
        u = q.front(); q.pop();
        for(int i=0; i<n; i++){
            if (M[u][i] == 0) continue; // u→i に辺が伸びてない
            if(d[i] != INF) continue; //d[i] が訪問済み
            d[i] = d[u] + 1;
            q.push(i);
        }
    }
}

int main(){
    int u, k, v;
    cin >> n;
    for(int i = 0; i<n; i++){
        //隣接行列
        for(int j = 0;j<n; j++) M[i][j] =0;
    }

    //M[][]に入力
    for(int i = 0;i<n; i++){
        cin >> u >> k;
        u--; //オリジンを0に
        for(int j = 0;j<k;j++){
            cin >> v;
            v--;
            M[u][v] = 1;
        }
    }

    //d[](s=0からの距離を入れる)を初期化
    for(int i = 0;i<n; i++) d[i] = INF;
    d[0] = 0;

    bfs(0); //0は始点

    for(int i = 0; i<n; i++){
        cout << i+1 << ((d[i] == INF) ? (-1):d[i]) << endl;
    }
}

//ATC_2 https://atcoder.jp/contests/atc002/tasks/abc007_3
//未AC

#include <bits/stdc++.h>
using namespace std;
int R,C; 
int sy,sx,gy,gx; 
char c[50][50];
int d[50][50];
static const int INF = 1<<21;

void dfs(int y,int x){
    queue<int> q;
    q.push(y); q.push(x);
    while(!q.empty()){
        int ny = q.front(); q.pop();
        int nx = q.front(); q.pop();

        if(ny-1>=1) if(c[ny-1][nx] == '.'&& d[ny-1][nx] == INF) {
            d[ny-1][nx] = d[ny][nx] + 1; q.push(ny-1);q.push(nx);}
        if(ny+1<R-1)if(c[ny+1][nx] == '.'&& d[ny+1][nx] == INF) {
            d[ny+1][nx] = d[ny][nx] + 1;q.push(ny+1);q.push(nx);}
        if(nx-1>=1) if(c[ny][nx-1] == '.'&& d[ny][nx-1] == INF) {
            d[ny][nx-1] = d[ny][nx] + 1;q.push(ny);q.push(nx-1);}
        if(nx+1<C-1)if(c[ny-1][nx] == '.'&& d[ny][nx+1] == INF) {
            d[ny][nx+1] = d[ny][nx] + 1;q.push(ny);q.push(nx+1);}
    }
}

int main(){
    cin >> R >> C;
    cin >> sy >> sx >> gy >> gx;
    sy--;sx--;gy--;gx--;
    
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++) {cin >> c[i][j]; d[i][j] = INF;}
    }
    d[sy][sx] = 0;
    dfs(sy,sx);

    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++) {
            cout << (d[i][j] == INF ? -1 : d[i][j]);
            if(j == C-1) cout << endl;}
    }


    cout << d[gy][gx] << endl;
}