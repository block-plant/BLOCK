/**
 * Author: KUNWAR
 * Date:   2026-03-02
 * Time:   22:46:39
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
    int n;
    cin >> n ; 

    int m ;
    cin >> m ; 

    vector<pair<int,int>> seg(m);
    for(int i = 0 ; i < m ; i++)
    {
        int a = 0 ; 
        int b = 0 ; 
        cin >> a ; 
        cin >> b ; 
        a-- ; 
        b-- ; 
        seg[i] = {a,b} ;
    }

    int q ;
    cin >> q ;
    vector<int> chg(q);
    for(int i = 0 ; i < q ; i++)
    {
        int x ;
        cin >> x ;
        x-- ; 
        chg[i] = x ; 
    }

    int low = 0 ; 
    int high = q ; 

    int ans = INT_MAX ;
    
    auto helper = [&](int mid)->bool {
        vector<int> a(n , -1);
        for(int i = 0 ; i < mid ; i++)
        {
            a[chg[i]] = 1 ;
        }

        for(int i = 0 ; i < n ; i++)
        { 
            if(i > 0)
            {
                a[i] += a[i-1] ; 
            }
        }

        for(int i = 0 ; i < m ; i++)
        {
            int l = seg[i].first ;
            int r = seg[i].second ;
            
            int ans = a[r] ;
            if(l > 0) ans -= a[l-1] ;

            if(ans > 0) return true ;
        }
        return false ;
    };

    while(low <= high)
    {
        int mid = (low + high) / 2 ;

        if(helper(mid))
        {
            ans = min(ans , mid);
            high = mid - 1 ;
        }
        else
        {
            low = mid + 1 ;
        }
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    fastio();
    int t = 0; 
    cin >> t; 
    while(t--) {
        solve();
    }
    return 0;
}