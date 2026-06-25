#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll N = 21 ;
ll dp[1 << N] ;
const ll MOD = 1e9 + 7 ;

ll recurse(ll mask , ll n , vector<vector<ll>>&a) {
    ll row = __builtin_popcount(mask);
    if(row == n) return 1;
    if(dp[mask] != -1) return dp[mask] % MOD ;
    ll ans = 0 ;
    for(ll col = 0 ; col < n ; col++) {
        if(!(mask & (1 << col)) && a[row][col] == 1) {
            ans = ((ans % MOD) + (recurse(mask | (1 << col) , n , a) % MOD)) % MOD;
        }
    }
    return dp[mask] = ans ;
}

void solve() {
    int n ;
    cin >> n ;
    vector<vector<ll>> a(n , vector<ll>(n , 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = recurse(0 , n , a);
    cout << ans << endl;
}
int main() {
    int t = 1 ;
    // cin >> t ;
    while(t--) {
        solve();
    }
}
