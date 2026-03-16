/**
 * Author: KUNWAR
 * Date:   2026-03-17
 * Time:   00:51:00
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

bool solve() {
    l(n); 
    l(k); 

    auto a = in<ll>(n);

    vll P(n + 1, 0);
    f(i , 0 , n)
    {
        ll val = (a[i] <= k) ? 1 : -1;
        P[i + 1] = P[i] + val;
    }
    
    ll max_P = -1e18;        
    ll min_P = 1e18;          
    ll min_non_neg_P = 1e18;  

    f(j , 2 , n)
    {
        ll cur_i = j - 1; 
        
        max_P = max(max_P, P[cur_i]);
        min_P = min(min_P, P[cur_i]);
        if(P[cur_i] >= 0) 
        {
            min_non_neg_P = min(min_non_neg_P, P[cur_i]);
        }

        bool right_wins = (P[n] - P[j] >= 0);

        if(right_wins) 
        {
            if(max_P >= 0 || min_P <= P[j]) 
            {
                return true;
            }
        } 
        else 
        {
            if(min_non_neg_P <= P[j]) 
            {
                return true;
            }
        }
    }
    return false;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}