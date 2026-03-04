// this ques is from the edu section of codeforces 

// codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A


/**
 * Author: KUNWAR
 * Date:   2026-03-04
 * Time:   14:08:26
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

using d = double ;

void solve() {
    l(n);
    l(limit);
    vector<double> a(n);
    f(i , 0 , n) cin >> a[i];
    
    d low = 0 ; 
    d high = 100 ;
    d best_r = limit -1  ;
    d best_l = 0 ;
    auto helper = [&](d x)->bool {
        vector<d> b(n);
        f(i , 0 , n) b[i] = a[i] - x ; 
        vector<d> pref(n);
        pref[0] = b[0] ;
        f(i , 0 , n)
        {
            if(i > 0) pref[i] = pref[i-1] + b[i] ; 
        }
        d min_pref = 0 ;
        ll min_idx = -1 ; 
        f(i , limit-1 , n)
        {
            if(i >= limit)
            {
                if(pref[i-limit] < min_pref)
                {
                    min_pref = pref[i-limit];
                    min_idx = i-limit ;
                }
            }
            if(pref[i] - min_pref >= 0)
            {
                best_l = min_idx + 1 ; 
                best_r = i ;
                return true;
            }
        }
        return false;
    };

    f(i ,0 , 100)
    {
        d mid = (high + low) / 2.0 ;

        if(helper(mid))
        {
            low = mid ; 
        }
        else 
        {
            high = mid ;
        }
    }

    cout << best_l+1 << ' ' << best_r+1 << endl; 
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