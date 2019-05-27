//C
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,a,b,c,d,e;
    cin >> N;
    cin >> a >> b >> c >> d >> e;
    long long mine = min({a,b,c,d,e});
    cout << (N+mine-1)/ mine + 4 << endl;
}

//D
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z,k;
    vector<int> A(x);
    vector<int> B(y);
    vector<int> C(z);
    for(int i = 0;i<x;i++) cin >> A[i];
    for(int i = 0;i<y;i++) cin >> B[i];
    for(int i = 0;i<z;i++) cin >> C[i];
    
}