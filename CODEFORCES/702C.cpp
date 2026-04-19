/**
 * Author: KUNWAR
 * Date:   2026-04-19
 * Time:   21:02:17
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
    ll n , m ; 
    cin >> n >> m ; 

    vector<ll> c(n) , t(m) ;
    for(int i = 0 ; i < n ; i++) cin >> c[i];
    for(int i = 0 ; i < m ; i++) cin >> t[i];
    
    sort(c.begin() , c.end());
    sort(t.begin() , t.end());

    ll ans = 0 ;
    ll low = 0 ; 
    ll high = 1e18 + 7 ;

    auto check = [&](ll mid)->bool {
        vector<pair<ll,ll>> a ; 
        for(int i = 0; i < m; i++) 
        {
            ll start = t[i] - mid; 
            ll end = t[i] + mid;
            
            if(!a.empty() && a.back().second >= start) 
            {
                a.back().second = max(a.back().second, end); 
            } 
            else 
            {
                a.push_back({start, end});
            }
        }

        ll one = 0 ;
        for(int i = 0 ; i < (int)a.size() ; i++)
        {
            while(one < n && a[i].first <= c[one] && c[one] <= a[i].second) 
            {
                one++;
            }
        }

        return (one == n);
    };

    while(low <= high)
    {
        ll mid = (low + high) / 2 ;
        if(check(mid)) 
        {
            high = mid - 1 ;
            ans = mid ;
        }
        else
        {
            low = mid + 1 ; 
        }
    }

    cout << ans << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1 ; 
    // cin >> t; 

    while(t--) {
        solve();
    }
    return 0;
}