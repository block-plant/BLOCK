/**
 * Author: Ayush Kunwar Singh
 * Time:   20:49:18
 * Date:   2026-04-28
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

    int lo = 0, hi = (int)n;
    int mexwf = 0;


    auto helper = [&](ll k)->bool {
        multiset<ll> pool(all(a));
        vll cnt(k + 1, 0);

        for(ll x : a) {
            if (x <= k) cnt[x]++;
        }

        for(int x = k - 1; x >= 0; --x) {
            if(cnt[x] > 0) {
                cnt[x]--;
                auto it = pool.find(x);
                if (it == pool.end()) return false;
                pool.erase(it);
            } 
            else 
            {
                ll need = 2LL * x + 1;
                auto it = pool.lower_bound(need);
                if (it == pool.end()) return false;
                pool.erase(it);
            }
        }

        return true;
    };

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(helper(mid)) {
            mexwf = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << mexwf << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) solve();
    return 0;
}
