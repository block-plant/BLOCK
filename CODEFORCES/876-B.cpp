/**
 * Author: KUNWAR
 * Date:   2026-02-21
 * Time:   09:37:16
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
    l(k);
    l(m);
    
    auto a = in<ll>(n);
    
    vvll freq(m);
    f(i , 0 , n)
    {
        freq[a[i] % m].push_back(a[i]);
    }
    
    vll ans(k) ;
    ans[0] = -1 ;
    for(auto v : freq)
    {
        if(v.size() >= k)
        {
            f(i , 0 , k)
            {
                ans[i] = v[i] ;
            }
            break;
        }
    }
    
    if(ans[0] == -1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        out(ans);
    }
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

// ab ess ques me aisa h ki k elements select krne h jinke beech ka difference m ho 
// toh pehle harr element ko m se divide krdo 
// ab maan lo ki ek na ek aisa element hoga jo base ka kaam krega , aur uske upar numbers honge like base+m , base+2m
// m se modulo lene ke baad simply sirf base bachega 
// different types of bases count krlo , jiska count >= k usme se first k elements lelo
