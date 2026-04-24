/**
 * Author: Ayush Kunwar Singh
 * Time:   12:23:05
 * Date:   2026-04-24
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

const ll m = 1e9 + 7;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a == 0 || b == 0) ? 0 : (a / gcd(a, b)) * b; }
ll binpow(ll base, ll exp, ll mod) { ll res = 1; base %= mod; while(exp > 0) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

void fastio() { ios_base::sync_with_stdio(false); cin.tie(NULL); }

void solve() {
    l(a);
    l(b);
    l(c);
    
    c = (c % (m - 2));
    ll p = binpow(b,c,m-1);   
    ll ans = binpow(a,p,m);
    op(ans);
}

int main() {
    fastio();
    l(t);
    while(t--) solve();
    return 0;
}
