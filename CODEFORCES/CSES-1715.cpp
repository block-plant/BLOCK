/**
 * Author: KUNWAR
 * Date:   2026-05-27
 * Time:   12:09:26
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

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

ll extendedGCD(ll a, ll b, ll& x, ll& y) {
    if(b == 0) { x = 1; y = 0; return a; }
    ll x1, y1; 
    ll gcd = extendedGCD(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b);
    return gcd;
}

ll modInverseEEA(ll A, ll M) {
    ll x, y;
    ll gcd = extendedGCD(A, M, x, y);
    if(gcd != 1) return -1;
    return (x % M + M) % M; 
}

ll CRT2(ll r1, ll m1, ll r2, ll m2) {
    ll inv1 = modInverseEEA(m2, m1);
    ll inv2 = modInverseEEA(m1, m2);
    ll M = m1 * m2;
    ll part1 = (ll)(r1 * m2 * inv1 % M);
    ll part2 = (ll)(r2 * m1 * inv2 % M);
    return (part1 + part2) % M;
}

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll fact[MAXN], invFact[MAXN];

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

ll modInverse(ll n) { return power(n, MOD - 2); }

void precompute() {
    fact[0] = 1; invFact[0] = 1;
    f(i , 1 , MAXN) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    fr(i , MAXN - 2 , 1) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

ll nCr(ll n, ll r) {
    if(r < 0 || r > n) return 0;
    ll ans = fact[n];
    ans = (ans * invFact[r]) % MOD;
    ans = (ans * invFact[n - r]) % MOD;
    return ans;
}

ll mul_mod(ll a , ll b) {
    return ((a % MOD) * (b % MOD)) % MOD ;
}

void solve() {
    string s ;
    cin >> s ;

    ll n = s.length() ; 

    vll freq(26 , 0);

    f(i , 0 , n) freq[s[i] - 'a']++ ; 

    ll prod = fact[n] ; 
    for(auto x : freq) {
        if(x != 0) {
            prod = mul_mod(prod , invFact[x]); 
        }
    }
    
    cout << prod << endl;
}

int main() {
    fastio();
    precompute();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}