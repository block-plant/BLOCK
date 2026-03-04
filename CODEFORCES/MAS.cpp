// this ques is from the edu section of codeforces 

// codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A

/**
 * Author: KUNWAR
 * Date:   2026-03-04
 * Time:   18:05:49
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

    auto a = in<ld>(n);

    auto help = [&](vector<ld>&b)->ld {
        ld min_so_far = 0 ; 
        vector<ld> pref(n);
        f(i , 0 , n)
        {
            pref[i] = b[i] ;
            if(i > 0) pref[i] += pref[i-1] ; 
        }
        ld ans = -1e18 ;
        f(i , d-1 , n)
        {
            ld dis = pref[i] - min_so_far ; 
            min_so_far = min(min_so_far , pref[i-d+1]) ;
            ans = max(ans , dis);
        }
        return ans ;
    };

    auto helper = [&](ld x)->bool {
        vector<ld> b(n);
        f(i , 0 , n)
        {
            b[i] = a[i] - x ;
        }
        return (help(b) >= 0) ; 
    };
    
    
    
    auto helping = [&](vector<ld>&b)->pair<ll,ll> {
        ld min_so_far = 0 ;
        // out(b);
        vector<ld> pref(n);
        f(i , 0 , n)
        {
            pref[i] = b[i] ;
            if(i > 0) pref[i] += pref[i-1] ; 
        }
        ld ans = -1e18 ;
        ll min_idx = -1 ;
        f(i , d-1 , n)
        {
            ld dis = pref[i] - min_so_far ; 
            ans = max(ans , dis);
            if(ans >= 0)
            {
                return make_pair(min_idx+2 , i+1) ; 
            }
            if(min_so_far > pref[i-d+1])
            {
                min_so_far = pref[i-d+1];
                min_idx = i-d+1;
            }
        }
        return {-1,-1} ;
    };

    auto helpering = [&](ld x)->pair<ll,ll> {
        vector<ld> b(n);
        f(i , 0 , n)
        {
            b[i] = a[i] - x ;
        }
        return (helping(b)) ; 
    };

    ld low = 0 ; 
    ld high = 100 ; 

    f(i , 0 , 100)
    {
        ld mid = (high + low) /2 ; 
        if(helper(mid))
        {
            low = mid ; 
        }
        else 
        {
            high = mid ; 
        }
    }
    
    pair<ll,ll> ans = helpering(low) ;
    cout << ans.first << ' ' << ans.second << endl;
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