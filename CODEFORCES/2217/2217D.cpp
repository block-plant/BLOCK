/**
 * Author: KUNWAR
 * Date:   2026-04-07
 * Time:   20:45:00
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define f(i,a,b) for(ll i=a;i<b;i++)
#define op(x) cout << x << endl

#define read(...) __VA_ARGS__; read_input(__VA_ARGS__)
void read_input() {}
template<typename T, typename... Args>
void read_input(T& first, Args&... rest) { cin >> first; read_input(rest...); }
#define l(x) long long x; cin >> x

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }

void solve() {
    l(n);
    l(k);
    auto a = in<ll>(n);
    auto p = in<ll>(k);

    ll x = a[p[0] - 1];
    vll points;
    
    ll prev = x;
    f(i , 1 , n+1) 
    {
        if(a[i-1] != prev) 
        {
            points.push_back(i);
            prev = a[i-1];
        }
    }
    
    if(prev != x) 
    {
        points.push_back(n + 1);
    }

    if(points.empty()) 
    {
        op(0);
        return;
    }

    vll gaps(k + 1, 0);
    for(ll i : points) 
    {
        auto it = lower_bound(p.begin(), p.end(), i);
        ll idx = distance(p.begin(), it);
        gaps[idx]++;
    }

    ll pts = points.size();
    ll m = pts / 2;
    ll ans = 0;
    for(ll count : gaps) 
    {
        ans = max(ans, count);
    }

    op(max(m, ans));
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}