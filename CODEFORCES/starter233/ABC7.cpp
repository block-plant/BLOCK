/**
 * Author: KUNWAR
 * Date:   2026-04-08
 * Time:   20:21:30
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

void solve() {
    i(n);
    vvi e(n, vi(3));
    
    f(j , 0 , 3) 
    {
        f(i , 0 , n) 
        {
            cin >> e[i][j];
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    
    int cur_mx = -2e9;
    int mn = 2e9;

    f(i , 0 , n) 
    {
        sort(all(e[i]));
        pq.push({e[i][0], {(int)i, 0}});
        cur_mx = max(cur_mx, e[i][0]);
    }

    while(true) 
    {
        auto top = pq.top();
        pq.pop();

        int mini = top.first;
        int idx = top.second.first;
        int e_idx = top.second.second;

        mn = min(mn, cur_mx - mini);

        if(e_idx + 1 < 3) 
        {
            int temp = e[idx][e_idx + 1];
            pq.push({temp, {idx, e_idx + 1}});
            cur_mx = max(cur_mx, temp);
        }     
        else 
        {
            break;
        }
    }

    op(mn);
}

int main() {
    fastio();
    l(t);
    while(t--) 
    {
        solve();
    }
    return 0;
}