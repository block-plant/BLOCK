/**
 * Author: KUNWAR
 * Date:   2026-05-27
 * Time:   20:37:34
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

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }
ll binpow(ll base, ll exp, ll mod) { ll res = 1; base %= mod; while(exp > 0) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
const ll N = 1e6 + 5 ;
vector<int> spf(N + 1); 

void sieve() {
    for(int i=1; i<=N; i++) spf[i] = i; 
    for(int i=2; i*i<=N; i++) {
        if(spf[i]==i) {
            for(int j=i*i; j<=N; j+=i) {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

inline ll getDivisorsOfSquare(ll x) {
    ll div = 1;
    while(x > 1) { 
        int p = spf[x]; 
        ll cnt = 0;
        while(x % p == 0) {
            cnt++;
            x /= p;
        }
        div *= (cnt * 2 + 1);
    }
    return div;
}

inline ll getDivisorsOfSquareLarge(ll x) {
    ll div = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ll cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            div *= (cnt * 2 + 1);
        }
    }
    if(x > 1) {
        div *= (1 * 2 + 1); 
    }
    return div;
}

ll pehle[N + 1] ;
ll tot = 0 ; 

void fx() {
    f(i , 1 , N+1) {
        ll div = getDivisorsOfSquare(i);
        pehle[i] = div ; 
        tot += div ; 
    }
}

void solve() {
    l(z);
    ll ans = 1LL * z * z ;
    ll prod = 0 ; 
    
    if(z <= N) {
        f(i , 0 , z+1) {
            prod += pehle[i];
        }
    }
    else {
        prod += tot ; 
        f(i , N + 1 , z + 1) { 
            prod += getDivisorsOfSquareLarge(i); 
        }
    }
    cout << ans - prod << "\n";
}

int main() {
    fastio();
    sieve();
    fx();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}