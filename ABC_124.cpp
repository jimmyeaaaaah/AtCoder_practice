//C
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> s;
    int ans = 0;
    string S;
    cin >> S;
    for(int i =0;i<S.size(); i++){
        if (S[i] == '0') s.push_back(0);
        else s.push_back(1);
    }

    for(int i = 0;i<S.size();i++){
        if (i%2 == s[i]) ans++;
    }
    int b = S.size() - ans;
    cout << min(ans, b) << endl;

}

//D
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,a, nega = 0;
    long long ans = 0;
    cin >> N;
    //vector<int> A(N);
    vector<long long> A_abs(N);
    for(int i = 0;i<N;i++) {
        cin >> a;
        if (a < 0) {
            nega++;
            A_abs[i] = -a;
        }else A_abs[i] = a;
    }

    
    for(int i= 0;i<N;i++) ans += A_abs[i];
    if (nega%2 == 1) {
        long long minA = *min_element(A_abs.begin(),A_abs.end());
        ans -= 2*minA;
    }
    cout << ans << endl;

}