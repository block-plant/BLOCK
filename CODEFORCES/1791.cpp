/**
 * Author: KUNWAR
 * Date:   2026-07-20
 * Time:   23:44:58
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

using ll = long long ; 

void solve() {
    var(ll , n , c);
    vector<pair<ll , ll>> v(n);
    f(i , 0 , n) {
        l(a);
        ll l= i + 1 + a, r = n - i + a;
        v[i] = {min(l , r), l};
    }
    sort(v.begin(), v.end());
    vll pref(n + 1, 0);
    f(i , 0 , n) pref[i + 1] = pref[i] + v[i].first;
    ll ans = 0;
    f(i , 0 , n) {
        ll rem = c - v[i].second;
        if(rem < 0) continue;
        ll l = 0, r = n - 1, mx = 0;
        while(l <= r) {
            ll mid = l + (r - l) / 2;
            ll cst = (mid <= i) ? pref[mid] : pref[mid + 1] - v[i].first;
            if(cst <= rem) mx = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans = max(ans, 1 + mx);
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