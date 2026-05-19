/**
 * Author: KUNWAR
 * Date:   2026-05-19
 * Time:   23:14:44
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
    l(d);
    auto a = in<ll>(n);

    ll l = 1 ; 
    ll r = d ;

    ll currl = 1 ;
    ll currd = d ;

    auto check = [&](double k)->bool {
        vector<double> pref(n+1,0.0);

        f(i , 0 , n) {
            pref[i+1] = pref[i] + (a[i] - k) ; 
        }

        double mn = 0.0 ;
        ll cur = 0 ; 

        f(i , d , n+1) {
            if(pref[i - d] < mn) {
                mn = pref[i - d];
                cur = i - d;
            }
            if(pref[i] - mn >= 0) {
                currl = cur + 1 ;
                currd = i ; 
                return true;
            }
        }
        
        return false;
    };

    double low = 0.0 ;
    double high = 100.0 ; 

    double ans = 0.0 ;
    f(i , 0 , 100) {
        double mid = (high + low) / 2.0 ; 

        if(check(mid)) {
            low = mid ; 
            l = currl ; 
            r = currd ;
        }
        else {
            high = mid ;
        }
    }
    cout << l << ' ' << r << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}