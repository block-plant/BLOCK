/**
 * Author: KUNWAR
 * Date:   2026-06-08
 * Time:   23:52:03
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

ll power(ll base, ll exp) {
    ll res = 1;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) ;
        base = (base * base) ;
        exp /= 2;
    }
    return res;
}

void solve() {
    l(n);
    for(ll k = 2; k * k < n; k++) {
        ll p = 1 + k + k*k; 
        ll cur = k * k;
        while(p <= n) {
            if(p == n) {
                op("YES");
                return;
            }
            if(cur > n / k) {
                break;
            }
            cur *= k;
            p += cur;
        }
    } 
    op("NO");
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}