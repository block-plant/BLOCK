#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll MOD = 1e9 + 7 ;
const ll N = 3e3 + 7 ;
ll dp[N][N];
ll pref[N];
void solve() {
    int n ;
    cin >> n ; 
    string s;
    cin >> s ;
    dp[1][1] = 1;
    for(int len = 2 ; len <= n ; len++) {
        char c = s[len-2];
        pref[0] = 0 ;
        for(int i = 1 ; i < len ; i++) {
            pref[i] = (pref[i-1] + dp[len-1][i]) % MOD ;
        }
        for(int i = 1 ; i <= len ; i++) {
            if(c == '<') {
                dp[len][i] = pref[i-1];
            }
            else {
                dp[len][i] = (pref[len-1] - pref[i-1] + MOD) % MOD;
            }
        }
    }

    ll ans = 0 ;
    for(int i = 0 ; i <= n ; i++) {
        ans = ((ans % MOD) + (dp[n][i] % MOD)) % MOD ;
    }
    cout << ans << endl;
}
int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
