/**
 * Author: KUNWAR
 * Date:   2026-02-21
 * Time:   11:28:40
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

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }
ll binpow(ll base, ll exp, ll mod) { ll res = 1; base %= mod; while(exp > 0) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    l(n);
    l(m);
    auto a = in<ll>(n);
    auto b = in<ll>(m);
    
    vll diff(n);
    diff[0] = a[0];
    ll g = 0; 
    f(i , 1 , n)
    {
        diff[i] = abs(a[i] - a[i-1]) ;
        g = gcd(diff[i] , g);
    }
    
    f(i , 0 , m)
    {
        ll temp = gcd(g , diff[0] + b[i]);
        cout << temp << ' ' ; 
    }
    cout << endl;
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

// aisa samaj lo ki : GCD(A,B) = GCD(A,B-A);
// GCD(A,B,C,D) = GCD(A,B-A,C-B,D-C);
// now for array [a,b,c,d,e]
// GCD(a,b,c,d,e) = GCD(a,b-a,c-b,d-c,e-d)
// now if we add any element y to the array then only the first elements will be changed 

// so we can calculate the GCD(b-a,c-b,d-c,e-d);
// and then when y is added to all , a becomes a+y 
// then the answer GCD will become GCD(a+y , g) : where g is the GCD of the diff array