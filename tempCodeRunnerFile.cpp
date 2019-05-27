
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