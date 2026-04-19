/**
 * Author: KUNWAR
 * Date:   2026-04-19
 * Time:   23:29:11
**/

#include <bits/stdc++.h>
using namespace std;

// --- Type Definitions ---
using ll = long long;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll n ;
    cin >> n ;
    vector<ll> a(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        ll b ;
        cin >> b ;
        a[i] = abs(b) ;
    } 

    sort(a.begin() , a.end());

    ll ans = 0 ; 

    for(int i = 0 ; i < n ; i++)
    {
        ll cur = a[i];
        auto it = upper_bound(a.begin() + i + 1, a.end(), 2LL * cur);
        ans += (it - (a.begin() + i + 1));
    }
    cout << ans << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}