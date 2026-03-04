/**
 * Author: KUNWAR
 * Date:   2026-03-04
 * Time:   23:16:50
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

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }
ll binpow(ll base, ll exp, ll mod) { ll res = 1; base %= mod; while(exp > 0) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

const int MOD = 998244353;
const int MAXN = 2000005;
long long fact[MAXN], invFact[MAXN];

long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) { return ((a - b) % MOD + MOD) % MOD; }
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long power(long long b, long long e) { long long r=1; while(e){if(e&1)r=mul(r,b);b=mul(b,b);e>>=1;} return r; }
long long modInverse(long long n) { return power(n, MOD - 2); }
long long divide(long long a, long long b) { return mul(a, modInverse(b)); }
long long nCr(int n, int r) { return (r<0 || r>n) ? 0 : mul(fact[n], mul(invFact[r], invFact[n-r])); }
long long nPr(int n, int r) { return (r<0 || r>n) ? 0 : mul(fact[n], invFact[n-r]); }

void precompute() {
    fact[0] = 1; invFact[0] = 1;
    for(int i=1; i<MAXN; i++) fact[i] = mul(fact[i-1], i);
    invFact[MAXN-1] = modInverse(fact[MAXN-1]);
    for(int i=MAXN-2; i>=1; i--) invFact[i] = mul(invFact[i+1], i+1);
}

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    l(n) ;
    auto a = in<ll>(n) ; 

    map<ll ,ll> freq ; 
    f(i , 0 , n)
    {
        freq[a[i]]++ ; 
    }

    vpll distinct(freq.rbegin() , freq.rend()) ;
    ll G = 0 ;
    
    map<ll , ll> prob_v ; 

    for(auto [V , C] : distinct)
    {
        ll pv = 0 ; 
        if(G == 0) 
        {
            pv = (C % 2 == 1 ? 1 : 0);
        } 
        else 
        {
            ll total_ways_inv = modInverse(nCr(C + G, G));
            for(int k = 1; k <= C; k += 2) 
            {
                ll ways = nCr(C + G - k - 1, G - 1);
                pv = (pv + ways * total_ways_inv) % MOD;
            }
        }
        prob_v[V] = pv ; 
        G += C ; 
    }

    ll expected_val = 0 ; 
    ll inv2 = modInverse(2) ; 

    for(int bit = 0 ; bit < 30 ; bit++)
    {
        ll prod = 1 ;
        bool contri = false ;

        for(auto [V , pv] : prob_v)
        {
            if((V >> bit) & 1)
            {
                contri = true; 
                ll term = (1 - 2*pv) % MOD ;
                if(term < 0) term += MOD ;
                prod = (prod * term) % MOD ;
            }
        }

        if(contri)
        {
            ll prob_bit_is_1 = (1 - prod + MOD) % MOD * inv2 % MOD ; 
            ll bit_contri = (prob_bit_is_1 * (1LL << bit)) % MOD ;
            expected_val = (expected_val + bit_contri) % MOD ;
        }
    }

    cout << expected_val << endl;
}

int main() {
    precompute() ; 
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}