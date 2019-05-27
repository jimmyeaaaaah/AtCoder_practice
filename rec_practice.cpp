//参考記事: https://qiita.com/drken/items/23a4f604fa3f505dd5ad

//メモ化再帰でフィボナッチ
#include <bits/stdc++.h>
using namespace std;

long long fibo(int n, vector<long long> &memo){
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != -1) return memo[n];
    return memo[n] = fibo(n-1,memo) +fibo(n-2,memo);
}

int main(){
    vector<long long> memo(50,-1);
    for(int n = 0;n<50;n++){
        cout << fibo(n,memo) << endl;
    }
}


//部分和
#include <bits/stdc++.h>
using namespace std;
vector<int> a(100000);

bool func(int n, int x){
    if(n == 0){
        if (x == 0) return true;
        else return false;
    }

    if (func(n-1,x-a[n-1])) return true;
    if (func(n-1,x)) return true;

    return false;
}

int main(){
    int n; cin >> n;
    for(int i = 0;i<n;i++) cin >> a[i];
    int X;cin >> X;

    if(func(n,X)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

//部分和(メモ化)
//わからん！！！！！！
#include <bits/stdc++.h>
using namespace std;

//数独ソルバー
#include <bits/stdc++.h>
using namespace std;

void rec(Field &field, vector<Field> &res){

}

//グラフ上の探索
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void rec(int v, const Graph &G, vector<bool> &seen, vector<int>&order){
    seen[v] = true;
    for(auto next : G[v]){
        if (seen[next]) continue;
        rec(next, G, seen, order);
    }
    //抜ける時にorderに追加
    order.push_back(v);
}

int main(){
    int N,M; cin >> N >> M;
    Graph G(N);
    for(int i = 0;i<M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    vector<bool> seen(N,0);
    vector<int> order;
    for(int v = 0;v<N;v++){
        if (seen[v]) continue;
        rec(v,G,seen,order);
    }
    reverse(order.begin(),order.end());
    for(auto v:order) cout << v << " -> ";
    cout << endl;
}

//ユークリッドの互除法
#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    int minab = min(a,b);
    int maxab = max(a,b);
    if (a == 0) return b;
    if (b == 0) return a;
    else return GCD(minab, maxab-minab);
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << GCD(a,b) << endl;
}

//模範解↓
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}