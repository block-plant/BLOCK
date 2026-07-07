#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    ll n ;
    cin >> n;
    vector<ll> b(n);
    for(auto&x:b) cin >> x;
    vector<bool> dp(n + 1 , false);
    dp[0] = true;
    for(int i = 0 ; i < n ; i++) {
        if(i - b[i] >= 0 && dp[i- b[i]]) {
            dp[i + 1] = 1;
        }
        if(dp[i] && i + b[i] + 1 <= n) {
            dp[i + b[i] + 1] = 1;
        }
    }
    if(dp[n]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
int main() {
    int t;
    cin >> t ;
    while(t--) {
        solve();
    }
}