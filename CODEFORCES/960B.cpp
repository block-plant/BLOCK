/**
 * Author: KUNWAR
 * Date:   2026-06-13
 * Time:   21:54:37
**/

#include <bits/stdc++.h>
#include <queue>
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
    l(k1);
    l(k2);
    auto a = in<ll>(n);
    auto b = in<ll>(n);

    priority_queue<ll , vector<ll> , less<ll>> pq ; 
    f(i , 0 , n) pq.push(abs(a[i] - b[i]));

    ll k = k1 + k2 ;

    while(k > 0 && pq.top() > 0) {
        ll mx = pq.top();
        pq.pop();
        ll mn = 0 ; 
        if(!pq.empty()) {
            mn = pq.top() ; 
        }
        ll diff = mx - mn ; 
        ll rem = max(1LL , diff);
        rem = min(k , rem);
        k -= rem ; 
        mx -= rem; 
        pq.push(mx);
    }

    if(k & 1) { 
        ll temp = pq.top();
        pq.pop();
        pq.push(temp + 1);
    }

    ll ans = 0 ;
    while(!pq.empty()) {
        ll temp = pq.top();
        pq.pop();
        ans += (temp * temp);
    }
    cout << ans << endl;
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