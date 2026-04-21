/**
 * Author: KUNWAR
 * Date:   2026-04-21
 * Time:   21:08:19
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

const ll MOD = 998244353;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll zero(ll m) {
    if(m < 0) return 0;
    return 1 + (m + 1) / 4;
}

ll one(ll m) {
    if(m < 0) return 0;
    return (m + 3) / 4;
}

void solve() {
    l(n);
    l(x); 
    ll zl = zero(x - 1) % MOD;
    ll ol = one(x - 1) % MOD;
    ll zr = (zero(n) - zero(x - 1)) % MOD;
    ll onr = (one(n) - one(x - 1)) % MOD;

    if(zr < 0) zr += MOD;
    if(onr < 0) onr += MOD;

    ll ans = (zl * zr) % MOD;
    ans = ((ans % MOD) + (ol * onr) % MOD) % MOD;
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