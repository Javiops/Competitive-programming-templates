#include <bits/stdc++.h>
using namespace std;
#define int long long

//Combinatorics in modular arithmetic
//Binpow, binomial coeficient, inverses and factorials

const int MOD = 1e9 + 7;
vector<int> fact(1e6+5, 1);

int binpow(int a, int b){
    if(!b) return 1;
    else if(b % 2 == 0){
        int x = binpow(a, b / 2);
        return (x * x) % MOD;
    }else{
        int x = binpow(a, b / 2);
        x = (x * x) % MOD;
        return (x * a) % MOD;
    }
}


int c(int n, int x){
    if (n < x) return 0;
    return (fact[n] * binpow((fact[x] * fact[n - x]) % MOD, MOD - 2)) % MOD;
}


signed main()
{
    
    for(int i = 1; i <= 1e6; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    
    int tt; cin >> tt;
    while(tt--){
        int n, k; cin >> n >> k;
        cout << c(n, k) << endl;
    }
}
