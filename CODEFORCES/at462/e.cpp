/**
 * Author: KUNWAR
 * Date:   2026-06-13
 * Time:   18:30:58
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
    l(a);
    l(b);
    l(x);
    l(y);
    x = abs(x);
    y = abs(y);

    ll ans = 0 ;
    ll k = min(x, y);
    ans += k * min(2 * a, 2 * b);
    ll rem = max(x,y) - k ; 
    ans += (rem / 2) * min({a + b, 4 * a, 4 * b});
    if(rem & 1) {
        if(x > y) {
            // cout << x <<' ' << y << << ' ' << rem << ' ' << k <<  endl;
            ans += min(a, 3 *b);
        }
        else {
            ans += min(b , 3*a);
        }
    }
    cout << ans << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}