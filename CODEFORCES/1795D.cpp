/**
 * Author: KUNWAR
 * Date:   2026-06-12
 * Time:   00:07:55
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

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

ll fact[MAXN];
ll invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    f(i , 1 , MAXN) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    fr(i , MAXN - 2 , 1) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    ll ans = fact[n];
    ans = (ans * invFact[r]) % MOD;
    ans = (ans * invFact[n - r]) % MOD;
    return ans;
}

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

void solve() {
    l(n);
    auto a = in<ll>(n);
    ll ans = 1;
    for(ll i = 0 ; i < n ; i += 3) {
        ll cnt = 0 ;
        ll mx = max({a[i] + a[i + 1] , a[i + 1] + a[i + 2] , a[i] + a[i + 2]});
        if(a[i] + a[i + 1] == mx) cnt++ ; 
        if(a[i + 1] + a[i + 2] == mx) cnt++ ; 
        if(a[i] + a[i + 2] == mx) cnt++ ; 
        ans = ((ans % MOD) * (cnt % MOD)) % MOD ; 
    }
    ll p = nCr(n/3 , n/6);
    ans = ((ans % MOD) * (p % MOD)) % MOD ; 
    cout << ans << endl;
}

int main() {
    precompute() ;
    fastio();
    // l(t);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}