/**
 * Author: KUNWAR
 * Date:   2026-03-21
 * Time:   20:19:59
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

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

v#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long floor(long long x) 
{
    return x >= 0 ? x / 2 : (x - 1) / 2;
}

void solve() {
    l(n);
    auto a = in<ll>(n);

    f(i , 0 , n)
    {
        ll s = 0;
        vpll events;

        f(j , i+1 , n)
        {
            if(a[j] < a[i]) 
            {
                s++; 
                events.push_back({floor(a[i] + a[j] - 1) + 1, -1});
            } 
            else if(a[j] > a[i]) 
            {
                events.push_back({floor(a[i] + a[j]) + 1, 1});
            }
        }
        sort(events.begin(), events.end());

        ll maxs = s;

        for(size_t k = 0; k < events.size(); ++k) 
        {
            s += events[k].second;
            if(k == events.size() - 1 || events[k].first != events[k+1].first) 
            {
                maxs = max(maxs, s);
            }
        }

        cout << maxs << (i == n - 1 ? '' : ' ');
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l(t);
    while(t--) {
        solve();
    }
}
