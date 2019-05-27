//EDPC : https://atcoder.jp/contests/dp
//を解いていく
//参考 : https://atcoder.jp/contests/dp/tasks


//A
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
int N;
long long h[100010];
long long dp[100010];

template<class T> inline bool chmin(T& a, T b){
    if ( a > b){
        a = b;
        return true;
    }
    return false; 
}

int main(){
    const long long INF = 1LL << 60;

    cin >> N;
    for(int i = 0;i<N;i++) {cin >> h[i]; dp[i] = INF;}
    dp[0] = 0;
    for(int i = 0;i<N;i++){
        chmin(dp[i],dp[i-1] + abs(h[i] - h[i-1]));
        if ( i > 1) chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[N-1] << endl;
}

//B問題
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
//&a...参照. aだけ変えたくない場合に
template<class T> inline bool chmin(T &a, T b){
    if (a>b) {a = b;return true;}
    return false;
}

int main(){
    int N,K; cin >> N >> K;
    vector<long long> h(N);
    vector<long long> dp(N,INF);
    for(int i = 0;i<N;i++) cin >> h[i];
    dp[0] = 0;
    for(int i = 1;i<N;i++){
        for(int j = 0;j<K;j++){
            if (i-j > 0) chmin(dp[i], dp[i-j-1] + abs(h[i]-h[i-j-1]));
            else break;
        }
    }
    cout << dp[N-1] << endl;
}


//C問題
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N;
long long abc[1010][3];
long long dp[10010][3];

int main(){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++) {
        cin >> abc[i][0] >> abc[i][1] >> abc[i][2]; 
        for(int j= 0;j<3;j++) dp[i][j] = -1;
        }
    dp[0][0] = abc[0][0];
    dp[0][1] = abc[0][1];
    dp[0][2] = abc[0][2];

    for(int i = 1;i<N;i++){
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                if (j != k) chmax(dp[i][j],dp[i-1][k]+abc[i][j]);
            }
        }
    }
    long long res = 0;
    for (int j = 0; j < 3; ++j) chmax(res, dp[N-1][j]);
    cout << res << endl;
}

//D問題
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

long long w[110];
long long v[110];
long long dp[110][10010] = {0};

int main(){
    int N, W;
    cin >> N >> W;
    for(int i= 0;i<N;i++) cin >> w[i] >> v[i];

    for(int i = 0; i<N; i++){
        for(int j=0; j<=W; j++){
            if ((j - w[i]) >= 0)  chmax(dp[i+1][j], dp[i][j - w[i]] +v[i]);
            chmax(dp[i+1][j], dp[i][j]);
        }
        //dp[i+1][w[i+1]] = v[i+1];
    }

    long long ans = 0;
    for(int i = 0;i<=W; i++) chmax(ans, dp[N-1][i]);
    cout << ans << endl;

}


//E問題




//類題

//AOJ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0168

#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int dan[30],dp[35] = {0};
    int N = 0;
    while(true){
        cin >> dan[N];
        if (dan[N] == 0) break;
        N++;
    }
    dp[0] = 1;
    for(int i : dan){
        if (i == 0) break;
        for(int k = 1; k<i+1; k++){
            if (dp[k] == 0){
                for(int j = 1; j<=3; j++){
                    if((k - j)>= 0) dp[k] += dp[k-j];
                }
            }
        }
        int ans = ceil(ceil(dp[i] / 10.0) /365.0);
        //int ans = dp[i];
        cout << ans << endl;
    }
}

//ABC99_C https://atcoder.jp/contests/abc099/tasks/abc099_c

#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

int main(){
    int N; cin >> N;
    long long dp[N+10];
    for(int i =0;i<N+10;i++) dp[i] = INF;
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2;i<=N; i++){
        chmin(dp[i],dp[i-1] + 1);
        int six = 1; int nine = 1;
        while((i - pow(6,six)) >= 0){
            chmin(dp[i],dp[i - (long long)pow(6,six)] + 1);
            six++;
        }
        while((i - pow(9,nine)) >= 0){
            chmin(dp[i],dp[i - (long long)pow(9,nine)] + 1);
            nine++;
        }
    }
    //for(int i = 0;i<N+1;i++) cout << dp[i] << ' ';
    cout << dp[N] << endl;
}

//ABC15_D https://atcoder.jp/contests/abc015/tasks/abc015_4
//ちょっとむずいからまた今度
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int W,N.K; cin >> W >> N >> K;
    int dp[K+1][W+1] = {-1};
    int a[N], b[N];
    for(int i = 0; i<N; i++) cin >> a[i] >> b[i];

    for(int k = 1; i<K+1; i++){
        for(int w = 1; j<W+1; j++){
            dp[k][w] = 
        }
    }
}

