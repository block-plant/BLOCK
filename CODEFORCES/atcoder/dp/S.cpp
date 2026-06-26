#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
vector<ll> digs ; 
const ll MOD = 1e9 + 7 ;
ll d ;
const ll N = 1e5 ; 
ll dp[N][100][2][2] ;

ll recurse(ll pos , ll sum , bool leading_zero , bool tight) {
    if(pos == digs.size()) {
        return (!leading_zero && sum == 0) ? 1 : 0;
    }
    if(dp[pos][sum][leading_zero][tight] != -1) return dp[pos][sum][leading_zero][tight];
    ll ans = 0 ;
    ll limit = tight ? digs[pos] : 9 ; 
    for(int i = 0 ; i <= limit ; i++) {
        ll next_tight = (tight) && (i == limit);
        ll next_leading_zero = leading_zero && (i == 0) ;
        ll next_rem = next_leading_zero ? 0 : (sum + i) % d ; 
        ans = ((ans % MOD) + (recurse(pos + 1 , next_rem , next_leading_zero , next_tight) % MOD)) % MOD ; 
    }
    return dp[pos][sum][leading_zero][tight] = ans % MOD ;
}

void solve() {
    string p ;
    cin >> p >> d;
    for(char c : p) {
        digs.push_back(c - '0');
    }
    memset(dp, -1, sizeof(dp));
    ll ans = recurse(0 , 0 , 1 , 1);
    cout << ans << endl;
}

int main() {
    int t = 1 ;
    // cin >> t;
    while(t--) {
        solve();
    }
}
