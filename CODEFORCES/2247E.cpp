/**
 * Author: KUNWAR
 * Date:   2026-07-19
 * Time:   22:07:04
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
#define op(x) cout << x << "\n"

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
    l(k);
    ll ec = n / 2;
    ll oc = (n - 1) / 2;
    ll mg = (ec * (ec - 1)) / 2 + (oc * (oc - 1)) / 2;
    ll mx = 2LL * n - 2 + 2LL * mg;
    if(k % 2 != 0 || k < 2LL * n - 2 || k > mx) {
        op(-1);
        return;
    }
    ll r = (k - (2LL * n - 2)) / 2;
    vi e = {1}, o = {1};
    f(i , 2 , n + 1) {
        if(i % 2 == 0) {
            ll g = min(r, (ll)e.size() - 1);
            cout << e[g] << " " << i << endl;
            r -= g;
            e.resize(g + 1); 
            e.push_back(i);
        } else {
            ll g = min(r, (ll)o.size() - 1);
            cout << o[g] << " " << i << endl;
            r -= g;
            o.resize(g + 1);
            o.push_back(i);
        }
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