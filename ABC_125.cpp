//A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,T;
    cin >> A >> B >> T;
    //cout << floor(T + 0.5) << endl;
    cout << floor((T + 0.5) / A ) * B << endl;
}

//B
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N ;
    int counter = 0;
    vector<int> v(N), c(N);
    for(int i = 0;i<N;i++) cin >> v[i];
    for(int i = 0;i<N;i++) cin >> c[i];
    for(int i = 0;i<N; i++) {
        if (v[i] > c[i]) counter += (v[i] - c[i]);
    }
    cout << counter << endl;
}

//C
#include <bits/stdc++.h>
using namespace std;
/*
int get_gcd(int A,int B){
    if(A == 0) return(B);
    if(B == 0) return(A);

    vector<int> yaku = {};
    for(int i = 1;i<=(A + 1)/2;i++){
        if (A % i == 0){
            if(B % i == 0) yaku.push_back(i);
            if(B % (A/i) == 0) yaku.push_back(A/i);
        }
    }

    return *max_element(yaku.begin(),yaku.end());
}
*/
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i= 0;i<N;i++) cin >> A[i];


    vector<int> vecgcd;
    for(int i = 0;i<N;i++){
        int gcd_1 = 0;
        int gcd_2 = 0;
        for(int j = 0; j<i; j++) gcd_1 = __gcd(gcd_1,A[j]);
        for(int j = N-1; j>i; j--) gcd_2 = __gcd(gcd_2,A[j]); 
        vecgcd.push_back(__gcd(gcd_1,gcd_2));
    }
    cout << *max_element(vecgcd.begin(),vecgcd.end()) << endl;
}
