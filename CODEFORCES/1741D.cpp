/**
 * Author: KUNWAR
 * Date:   2026-07-25
 * Time:   23:41:28
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
    l(m);
    vll p(m);
    f(i , 0 , m) cin >> p[i];
    ll ans = 0;
    auto dfs = [&](auto self , ll l , ll r)->void {
        if(l == r) return; 
        ll mid = (l + r) / 2;
        self(self, l, mid);
        self(self, mid + 1, r);
        if(p[l] > p[mid + 1]) {
            f(i , 0 , mid - l + 1) {
                ll t = p[l + i] ; 
                p[l + i] = p[mid + 1 + i] ;
                p[mid + 1 + i] = t ;
            }
            ans++;
        }
    };
    dfs(dfs, 0, m - 1);
    if(is_sorted(all(p))) {
        cout << ans << endl;
    } 
    else {
        cout << -1 << endl;
    }
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}