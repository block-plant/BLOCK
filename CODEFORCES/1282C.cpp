/**
 * Author: KUNWAR
 * Date:   2026-05-28
 * Time:   20:50:27
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
    l(n); l(T); l(a); l(b);

    auto t = in<ll>(n);
    auto p = in<ll>(n);
    
    ll total_easy = 0, total_hard = 0;
    f(i, 0, n) {
        if(t[i] == 1) total_hard++;
        else total_easy++;
    }

    vpll mp(n) ;
    f(i , 0 , n) {
        mp[i] = {p[i] , t[i]} ;
    }
    sort(all(mp));
    
    priority_queue<pll, vector<pll>, greater<pll>> min_pq;
   
    ll time = 0; 
    ll score = 0; 
    ll ans = 0; 
    ll right = 0; 
    ll easy_done = 0, hard_done = 0;

    if(mp[0].first > 0) {
        ll free_time = mp[0].first - 1;
        ll opt_easy = min(total_easy, free_time / a);
        ll opt_hard = min(total_hard, (free_time - (opt_easy * a)) / b);
        ans = max(ans, opt_easy + opt_hard);
    }

    while(right < n) {
        auto [deadline , type] = mp[right] ;
        ll cur = ((type == 1) ? b : a) ; 

        score++ ; 
        time += cur ; 
        if(type == 1) hard_done++; 
        else easy_done++;
        
        while(right + 1 < n && time >= mp[right + 1].first) {
            min_pq.push(mp[right + 1]);
            right++ ; 
        }
        
        while(!min_pq.empty()) {
            auto top = min_pq.top();
            min_pq.pop();
            ll p_cost = (top.second == 1) ? b : a;
            score++ ;
            time += p_cost;
            if(top.second == 1) hard_done++; 
            else easy_done++;
            while(right + 1 < n && time >= mp[right + 1].first) {
                min_pq.push(mp[right + 1]);
                right++ ; 
            }
        }
        
        if(time <= T) { 
            ll leave_time = (right + 1 < n) ? mp[right + 1].first - 1 : T;
            if(time <= leave_time) {
                ll free_time = leave_time - time;
                ll opt_easy = min(total_easy - easy_done, free_time / a);
                ll opt_hard = min(total_hard - hard_done, (free_time - (opt_easy * a)) / b);
                ans = max(ans, score + opt_easy + opt_hard);
            }
        }
        right++ ; 
    }
    cout << ans << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}