#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    ll n ;
    cin >> n; 
    vector<ll> a(n) ;
    for(auto&x : a) cin >> x;
    vector<ll> dp(n + 1 , -1);
    dp[n] = 0;
    for(int i = n - 1 ; i >= 0 ; i--) {
        ll t = (1 + a[i] + i > n) ? 1e9 : dp[a[i] + 1 + i];
        dp[i] = min({t , 1 + dp[i + 1]});
    }
    cout << dp[0] << endl;
}

int main() {
    int t ;
    cin >>t ;
    while(t--) {
        solve();
    }
}
