/**
 * Author: Ayush Kunwar Singh
 * Time:   20:30:45
 * Date:   2026-04-25
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define all(x) (x).begin(), (x).end()
#define i(x) int x ; cin >> x
#define l(x) long long x; cin >> x
#define op(x) cout << x << endl

void fastio() { ios_base::sync_with_stdio(false); cin.tie(NULL); }

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { if(vec.empty() || vec[0].empty()) return; for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); cout << "\n"; } }

void solve() {
    l(n);
    auto a = in<ll>(n);
    vll b = a ; 

    sort(all(b));
    ll m = b[n/2];

    vi less(n + 1, 0);
    vi more(n + 1, 0);
    
    f(i, 0, n) {
        less[i+1] = less[i] + (a[i] < m ? 1 : 0);
        more[i + 1] = more[i] + (a[i] > m ? 1 : 0);
    }

    vll dp(n+1, -1);
    dp[0] = 0;
    
    f(i , 1 , n+ 1) {
        for(ll j = i - 1 ; j >= 0 ; j -= 2) {
            if(dp[j] != -1) {
                ll len = i - j;
                ll l = less[i] - less[j];
                ll g = more[i] - more[j];
                if(l <= len / 2 && g <= len / 2) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
    }
    
    op(dp[n]);
}

int main() {
    fastio();
    l(t);
    while(t--) solve();
    return 0;
}