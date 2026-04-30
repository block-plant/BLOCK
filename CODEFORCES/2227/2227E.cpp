/**
 * Author: Ayush Kunwar Singh
 * Time:   20:26:48
 * Date:   2026-04-30
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

    vll s(n);
    s[n-1] = a[n-1];
    fr(i , n-2 , 0) {
        s[i] = min(a[i], s[i + 1]);
    }

    ll temp = 0;
    f(i , 0 , n) {
        temp += (a[i] - s[i]);
    }

    int mx = 0;
    int cur = 1;
    f(i , 1 , n) {
        if(s[i] == s[i-1]) {
            cur++;
        } 
        else {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    mx = max(mx, cur);

    ll ans = max(0, mx-1);
    cout << temp + ans << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) solve();
    return 0;
}