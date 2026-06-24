#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    ll n ;
    cin >> n ;
    vector<ll> a(n);
    for(auto&x : a) {
        cin >> x;
    }
    vector<ll> pref(n + 1, 0);
    for(int i = 1 ; i <= n ; i++) {
        pref[i] = a[i-1] + pref[i-1];
    }
    vector<vector<ll>> dp(n+1 , vector<ll>(n+1 , 0));
    for(int len = 2 ; len <= n ; len++) {            
        for(int i = 1 ; i <= n - len + 1 ; i++) {    
            int j = i + len - 1;
            dp[i][j] = 1e18;
            for(int k = i ; k < j ; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + pref[j] - pref[i-1]);
            }
        }
    }
    cout << dp[1][n] << endl;
}

int main() {
    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
