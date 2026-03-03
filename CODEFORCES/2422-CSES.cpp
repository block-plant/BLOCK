/**
 * Author: KUNWAR
 * Date:   2026-03-03
 * Time:   20:21:06
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

// --- Macros ---
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define fkv(k, v, m) for(auto &[k, v] : m)
#define all(x) (x).begin(), (x).end()
#define get_sum(v, total) for(auto &x : v) total += x
#define cn continue
#define op(x) cout << x << endl

// --- Input Macros ---
#define read(...) __VA_ARGS__; read_input(__VA_ARGS__)
void read_input() {}
template<typename T, typename... Args>
void read_input(T& first, Args&... rest) { cin >> first; read_input(rest...); }
#define var(type, ...) type __VA_ARGS__; read_input(__VA_ARGS__)
#define i(x) int x; cin >> x
#define l(x) long long x; cin >> x
#define s(x) string x; cin >> x
#define c(x) char x; cin >> x

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    l(n);
    ll total = (n*n + 1)/2 ;  
    auto helper = [&](ll mid)->bool {
        ll sum = 0 ; 
        f(i , 1 , n+1)
        {
            sum += min(n , mid / i) ; 
        }  
        return (sum >= total) ; 
    };
    
    ll low = 1 ; 
    ll high = n*n ; 
    ll ans = LLONG_MAX ; 
    while(low <= high)
    {
        ll mid = (low + high) / 2 ;
        // cout << low << ' ' << mid << ' ' << high << endl ;
        if(helper(mid))
        {
            // cout << mid << endl;
            ans = mid ; 
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
    // l(t);
    ll t =1 ;
    while(t--) {
        solve();
    }
    return 0;
}