/**
 * Author: KUNWAR
 * Date:   2026-05-02
 * Time:   23:18:01
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

void solve() {
    l(n);
    l(k);
    l(p);
    l(q);

    auto a = in<ll>(n);
    vll ca(n);
    vll cb(n);
    ll sum = 0 ; 
    
    vll tri(n);

    f(i , 0,  n) {
        ca[i] = a[i] % p ; 
        cb[i] = (a[i] % q) % p ; 

        tri[i] = min(ca[i] , cb[i]);
        sum += tri[i];
    }

    vll ba(n);
    vll bb(n);

    f(i , 0 , n) {
        ba[i] = ca[i] - tri[i];
        bb[i] = cb[i] - tri[i];
    }

    ll cur = 0 ; 
    f(i , 0 , k) {
        cur += ba[i];
    }
    
    ll mn = cur ;
    
    f(i , k , n) {
        cur += ba[i] - ba[i-k];
        mn = min(mn, cur);
    }

    ll curb = 0 ;

    f(i , 0 , k) {
        curb += bb[i];
    }
    
    ll mnb = curb; 
    
    f(i , k , n) {
        curb += bb[i] - bb[i -k];
        mnb = min(mnb, curb);
    }

    cout << sum + min(mn, mnb) << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}