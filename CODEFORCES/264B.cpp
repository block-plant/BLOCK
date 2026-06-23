#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll N = 1e5 + 7 ;

ll spf[N];

void sieve() {
    for(int i = 1 ; i < N ; i++) spf[i] = i ;
    for(int i = 2 ; i * i < N ; i++) {
        if(spf[i] != i) continue;
        for(int j = i * i ; j < N ; j += i) {
            if(spf[j] == j) {
                spf[j] = i ;
            }
        }
    }
}

vector<ll> getfact(ll n) {
    vector<ll> fact;
    while(n > 1) {
        ll p = spf[n];
        fact.push_back(p);
        while(n % p == 0) {
            n = n / p;
        }
    }
    return fact;
}

void solve() {
    ll n ; 
    cin >> n ;
    vector<ll> a(n);
    ll mx = 0; 
    for(auto &x:a) {
        cin >> x;
        mx = max(mx, x);   
    }
    vector<ll> dp(mx+1 , 0);
    ll ans = 0 ; 
    for(int i = 0 ; i < n ; i++) {
        if(a[i] == 1) continue;
        vector<ll> fact = getfact(a[i]);
        ll temp = 0 ;
        for(auto x : fact) {
            temp = max(temp , dp[x] + 1);
        }
        for(auto x : fact) {
            dp[x] = max(temp , dp[x]);
        }
        ans = max(ans , temp);
    }
    ans = max(1LL, ans);
    cout << ans << endl;
}

int main() {
    int t = 1; 
    // cin >> t;
    sieve();
    while(t--) {
        solve();
    }
}
