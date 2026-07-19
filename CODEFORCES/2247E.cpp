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
    ll mx = 2LL * n - 2;
    vll g(n);
    f(i , 1 , n) {
        g[i] = min((ll)i, (ll)n - (ll)i) - 1;
        mx += 2LL * g[i];
    }
    if(k % 2 != 0 || k < 2LL * n - 2 || k > mx) {
        op(-1);
        return;
    }
    vll p;
    p.push_back(1);
    for(int i = 2 ; i <= n ; i += 2) p.push_back(i);
    for(int i = (n % 2 == 1 ? n : n - 1) ; i >= 3 ; i -= 2) p.push_back(i);
    ll r = (k - (2LL * n - 2)) / 2;
    f(i , 1 , n) {
        if(r == 0) {
            cout << 1 << " " << p[i] << endl;
        } 
        else if(r >= g[i]) {
            cout << p[i-1] << " " << p[i] << endl;
            r -= g[i];
        } 
        else {
            cout << p[i - 1 - (g[i] - r)] << " " << p[i] << endl;
            r = 0;
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