/**
 * Author: KUNWAR
 * Date:   2026-06-07
 * Time:   20:36:48
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

vector<ll> findBoundaries(vector<ll>& nums, bool backward, bool strictly, bool greater){
   ll n = nums.size();
   vector<ll> res(n, -1);
   vector<ll> st; 
   ll start = backward ? n - 1 : 0;
   ll end = backward ? -1 : n;
   ll step = backward ? -1 : 1;
   for(ll i = start; i != end; i += step){ 
       while(!st.empty()){
           bool condition;
           if(greater){
               condition = strictly ? (nums[st.back()] < nums[i]) : (nums[st.back()] <= nums[i]);
           } else {
               condition = strictly ? (nums[st.back()] > nums[i]) : (nums[st.back()] >= nums[i]);
           }
           if(condition){
               res[st.back()] = i;
               st.pop_back();
           } else {
               break;
           }
       }
       st.push_back(i);
   }
   return res;
}

void solve() {
    l(n);
    auto h = in<ll>(n);
    ll mx = max_element(all(h)) - h.begin() ;

    vll hnew(n);
    f(i , 0 , n) {
        hnew[i] = h[(mx + 1 + i) % n];
    }

    vll NGE = findBoundaries(hnew, false, false, true); 
    
    vll PGE = findBoundaries(hnew, true, false, true);

    vll pref(n, 0);
    fr(i , n-2 , 0) {
        ll nxt = NGE[i];
        if(nxt == -1) nxt = n - 1; 
        ll count = nxt - i;
        pref[i] = count * hnew[i] + pref[nxt];
    }

    vll suff(n, 0);
    f(i , 0 , n-1) {
        ll prev = PGE[i];
        ll count = i - prev;
        suff[i] = count * hnew[i] + (prev == -1 ? 0 : suff[prev]);
    }

    vll ans(n);
    f(i , 0 , n) {
        ll idx = (mx+1 + i) % n;
        ll r = pref[i];
        ll l = (i == 0) ? 0 : suff[i-1];
        ans[idx] = r + l;
    }

    out(ans);
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}