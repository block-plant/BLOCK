/**
 * Author: KUNWAR
 * Date:   2026-03-03
 * Time:   19:02:16
**/

#include <bits/stdc++.h>
using namespace std;

// --- Type Definitions ---
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll n ;
    cin >> n ; 
    ll k ; 
    cin >> k ; 

    vector<ll> a(n);

    for(ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    ll ans = LLONG_MAX ;
    auto helper = [&](ll mid)->bool {
        ll sum = 0 ;
        vector<ll> sums;
        
        for(ll i = 0 ; i < n ; i++)
        {
            if(a[i] > mid) return false; 
            if(a[i] + sum > mid)
            {
                sums.push_back(sum);
                sum = 0 ; 
            }
            sum += a[i]; 
        }
        sums.push_back(sum);
        
        if((ll)sums.size() <= k)
        {
            ans = *max_element(sums.begin() , sums.end());
            return true ;
        }
        return false; 
    };

    ll low = 0 ; 
    ll high = 1e18 + 7;  

    while(low <= high)
    {
        ll mid = (low + high) / 2 ;
        if(helper(mid))
        {
            high = mid - 1; 
        }
        else 
        {
            low = mid + 1; 
        }
    }
    cout << ans << endl;
}

int main() {
    fastio();
    long long t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}