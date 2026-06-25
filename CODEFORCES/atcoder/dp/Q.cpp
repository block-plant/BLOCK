#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    ll n ;
    cin >> n;
    vector<ll> h(n);
    for(auto &x : h) cin >> x;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    ll ans = 0 ;
    vector<ll> dp(n , 0);
    for(int i = 0 ; i < n ; i++) {
        dp[i] = a[i];
        for(int j = 0 ; j < i ; j++) {
            if(h[j] < h[i]) {
                dp[i] = max(dp[i] , dp[j] + a[i]);
            }
        }
        ans = max(ans , dp[i]);
    }
    cout << ans << endl;
}

int main() {
    int t = 1 ;
    // cin >> t ;
    while(t--) {
        solve(); 
    }
}
