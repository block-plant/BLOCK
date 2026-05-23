// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D

/**
 * Author: KUNWAR
 * Date:   2026-05-23
 * Time:   08:50:50
**/

#include <algorithm>
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
    l(one);
    auto o = in<ll>(one);
    sort(all(o));
    l(two);
    auto t = in<ll>(two);
    sort(all(t));
    l(three);
    auto th = in<ll>(three);
    sort(all(th));
    l(four);
    auto f = in<ll>(four);
    sort(all(f));
    ll ans = LLONG_MAX;
    vll answers ;
    
    ll i = 0 , j = 0 , k = 0 , l = 0 ; 

    while(i < one && j < two && k < three && l < four) {
        vpll compare ;
        compare.push_back({o[i] , 1});
        compare.push_back({t[j] , 2});
        compare.push_back({th[k] , 3});
        compare.push_back({f[l] , 4});

        auto mn = *min_element(all(compare)) ;
        auto mx = *max_element(all(compare)) ;

        if((mx.first - mn.first) < ans) {
            ans = mx.first - mn.first ; 
            answers = {o[i] , t[j] , th[k] , f[l]} ;
        }
        if(mn.second == 1) i++ ;
        else if(mn.second == 2) j++ ; 
        else if(mn.second == 3) k++ ; 
        else if(mn.second == 4) l++ ; 
    }
    out(answers);
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