//https://qiita.com/drken/items/23a4f604fa3f505dd5ad
//4-2　グラフ上の探索

/* 
Gの構造 
入力が "0 1/ 0 3/ 1 3/ 3 2/ 3 4/ 4 1"の場合
0 | 1 3
1 | 3
2 | 
3 | 2 4 
4 | 1 

この時探索が終わる順番は
2 4 3 1 0
*/
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;

void rec(int v, const Graph &G, vector<bool> &status){
    status[v] = true;
    //auto: 型推論. つまりnextの型を宣言しなくても勝手にG[]の要素の型になる
    for(auto next : G[v]){ 
        //未訪問なら
        if(status[next] == false) rec(next, G, status);
    }
    //探索が終わった順に出力
    cout << v << ' ';
}

int main(){
    int N,M; cin >> N >> M; //N: 頂点数  M: 枝数
    Graph G(N);
    for(int i = 0; i<M; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    vector<bool> status(N,0);
    for(int v = 0; v < N; v++){
        if (status[v]) continue;
        rec(v,G,status); //頂点vから始める探索
    }
}


//ATC https://atc001.contest.atcoder.jp/tasks/dfs_a

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
int H,W;
char block[510][510];
int status[510][510] = {0};
int sg_id[2][2];


void rec(int i, int j){
    if (block[i][j] == '.' || block[i][j] == 's'){ 
        status[i][j] = 1; 
        if(i-1 >= 0) if (status[i-1][j] == 0) rec(i-1,j);
        if(i+1 < W) if (status[i+1][j] == 0)rec(i+1,j);
        if(j-1 >= 0) if (status[i][j-1] == 0)rec(i,j-1);
        if(j+1 < H) if (status[i][j+1] == 0)rec(i,j+1);
    }
}

int show_ans(int i, int j){
    if(i-1 >= 0) if(status[i-1][j] == 1){cout << "Yes" << endl; return 0;}
    if(i+1 < W) if(status[i+1][j] == 1){cout << "Yes" << endl; return 0;}
    if(j-1 >= 0) if(status[i][j-1] == 1){cout << "Yes" << endl; return 0;}
    if(j+1 < H) if(status[i][j+1] == 1){cout << "Yes" << endl; return 0;}
    cout << "No" << endl;
    return 0;
}

int main(){
    cin >> H >> W;
    for(int i =0;i<H;i++){
        for(int j=0; j<W; j++){
            cin >> block[i][j];
            if (block[i][j] == 's') sg_id[0][0] = i;sg_id[0][1] = j;
            if (block[i][j] == 'g') sg_id[1][0] = i;sg_id[1][1] = j;
        }
    }
    rec(sg_id[0][0], sg_id[0][1]);
    show_ans(sg_id[1][0],sg_id[1][1]);
}

