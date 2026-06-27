/**
 * Author: KUNWAR
 * Date:   2026-06-27
 * Time:   17:58:32
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
    l(m);
    map<ll, ll> a;
    vector<vector<pair<ll, ll>>> d(max(n, m) + 1);
    for(int i = 0 ; i < n ; i++) {
        ll c , e , f ;
        cin >> c >> e >> f; 
        d[e].push_back({c,f});
        a[c]++;
    }
    // sort(all(d));
    for(int i = 1 ; i <= m ; i++) {
        for(auto p : d[i]) {
            ll old_val = p.first;
            ll new_val = p.second;
            a[p.first]--;
            if(a[p.first] == 0) {
                a.erase(p.first);
            }
            a[p.second]++;
        }
        cout << a.size() << endl;
    }
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