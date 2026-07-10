/**
 * Author: KUNWAR
 * Date:   2026-07-10
 * Time:   23:26:43
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
using ld = long double;

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
    vll x(n) , h(n);
    f(i , 0 , n) cin >> x[i] >> h[i];
    vll dp(n , -1);
    ll ans = 0 ;
    ll lmt = -1e10;
    f(i , 0 , n) {
        if(x[i] - lmt > h[i]) {
            ans++ ; 
            lmt = x[i];
        }
        else if(i == n-1 || x[i] + h[i] < x[i + 1]) {
            ans++ ; 
            lmt = x[i] + h[i];
        }
        else {
            lmt = x[i];
        }
    }
    cout << ans << endl;
    // auto re = [&](auto&self , ll i ,  ll lmt)->ll {
    //     if(i >= n) return 0 ;
    //     ll left = -1 ; 
    //     ll right = -1 ; 
    //     ll ans = 0 ; 
    //     if(x[i] - lmt > h[i]) {
    //         left = 1 + self(self , i + 1 , x[i]);
    //     }
    //     if(i == n-1 || x[i] + h[i] < x[i + 1]) {
    //         right = 1 + self(self , i + 1 , x[i] + h[i]);
    //     }
    //     ll none = self(self , i + 1 , lmt);
    //     return ans += max({left , right , none});
    // };
    // ll ans = re(re , 0 , -1e10);
    // cout << ans << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}