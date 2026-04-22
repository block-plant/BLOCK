/**
 * Author: KUNWAR
 * Date:   2026-04-22
 * Time:   20:21:57
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
    l(n);
    s(s);

    vll g(n, 0); 
    // vector<char> suf(n);
    // suf[n-1] = str[n-1];
    // fr(i, n-2, 0) suf[i] = max(str[i], suf[i+1]);
    char preva = 'a' - 1;
    char prevb = 'a' - 1;
    bool psbl = false;

    f(i, 0, n) {
        bool canA = (s[i] >= preva);
        bool canB = (s[i] >= prevb);

        if(canA && canB) 
        {
            g[i] = 0; 
            preva = s[i]; 
        } 
        else if(canA) 
        {
            g[i] = 0;
            preva = s[i];
        } 
        else if(canB) 
        {
            g[i] = 1;
            prevb = s[i];
        } 
        else 
        {
            g[i] = 1;
            prevb = s[i];
        }
    }

    string ansa = "", ansb = "";
    vll posa, posb;

    f(i , 0 , n) 
    {
        if(g[i] == 0) 
        {
            ansa += s[i];
            posa.push_back(i);
        } 
        else 
        {
            ansb += s[i];
            posb.push_back(i);
        }
    }

    sort(all(ansa));
    sort(all(ansb));

    string ans(n, ' ');
    f(i, 0, ansa.size()) ans[posa[i]] = ansa[i];
    f(i, 0, ansb.size()) ans[posb[i]] = ansb[i];

    op(ans);
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}