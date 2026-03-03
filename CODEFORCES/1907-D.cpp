/**
 * Author: KUNWAR
 * Date:   2026-03-03
 * Time:   17:28:04
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
    int n ; 
    cin >> n ; 
    vector<pair<int,int>> seg(n);

    for(int i = 0 ; i < n ; i++)
    {
        int a = 0 ; 
        int b = 0 ; 
        cin >> a >> b ;
        seg[i] = {a,b};
    }

    int low = 0 ;
    int high = 1e9 + 5 ;

    int ans = INT_MAX ; 

    auto helper = [&](int mid)->bool {
        int curx = 0 ;
        int cury = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            int newx = curx - mid ; 
            int newy = cury + mid ;
            int l = seg[i].first ;
            int r = seg[i].second ; 
            if((r < newx) || (newy < l))
            {
                return false ;
            }
            curx = max(newx, l);
            cury = min(newy, r); 
            if(curx > cury) return false ;
        }
      
        return true ;
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

    cout << ans << endl;
}

int main() {
    fastio();
    int t ; 
    cin >> t ;
    while(t--) {
        solve();
    }
    return 0;
}