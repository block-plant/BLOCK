/**
 * Author: KUNWAR
 * Date:   2026-04-19
 * Time:   05:33:47
**/

#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


const int n = 1e6 + 1 ;
vector<long long> spf(1e6 + 1);
vector<bool> isPrime(1e6 + 1, true);


vector<pair<long long, long long>> bandp(long long x) {
    vector<pair<long long, long long>> ans ;
    while(x != 1) {
        long long cur = spf[x];
        int cnt = 0 ;
        while(x % cur == 0) {
            cnt++ ; 
            x /= cur ;
        }
        ans.push_back({cur , cnt}); 
    }
    return ans;
}

void spffx() {
    isPrime[0] = false;
    isPrime[1] = false;
    spf[0] = 1;
    spf[1] = 1;
    for(int i = 2 ; i <= n ; i++) spf[i] = i ; 
    
    for(int i = 2 ; i * i <= n ; i++) {
        if(isPrime[i]) {
            spf[i] = i ;
            for(int j = i * i ; j <= n ; j += i) {
                isPrime[j] = false;
                spf[j] = min(spf[i] , (long long)j);
            }
        }
    }
}

long long gp(long long base , long long power) {
    power++ ; 
    long long h = pow(base , power);
    h-- ; 
    base-- ; 
    return (long long)(h / base);
}

void solve() {
    long long n;
    cin >> n ; 
    
    long long ans = 1 ; 
    
    vector<pair<long long,long long>> a = bandp(n);
    
    for(int i = 0 ; i < a.size() ; i++) {
        long long base = a[i].first;
        long long power = a[i].second;
        ans *= gp(base , power);    
    }

    cout << ans - n << endl;
}

int main() {
    fastio();
    spffx() ;
    long long t ;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}