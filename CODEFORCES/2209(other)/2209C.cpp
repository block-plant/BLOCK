/**
 * Author: KUNWAR
 * Date:   2026-03-21
 * Time:   20:39:49
**/

#include <bits/stdc++.h>
#include <iostream>  
#include <vector>   
#include <string>
#include <algorithm>
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

vll a = {3,1,0,2,0,0,4,5,0} ; 
bool testing = false; 

void solve() {
    l(n);
    auto ask = [&](ll left, ll right) -> ll {
        auto interactor = [&](ll l, ll r) -> ll {
            if(a[l-1] == a[r-1]) return 1 ;
            else return 0 ;  
        };

        cout << "? " << left << ' ' << right << endl;
        
        if(testing) {
            ll simulated_response = interactor(left, right);
            cout << simulated_response << endl;
            return simulated_response;
        }

        ll response;
        cin >> response;
        return response;
    };

    if(n == 1) 
    {
        cout << "! 1" << endl;
        return;
    }
    if(ask(1, 2) == 1) { cout << "! 1" << endl; return; }
    if(ask(2, 3) == 1) { cout << "! 2" << endl; return; }
    if(ask(1, 3) == 1) { cout << "! 3" << endl; return; }

    for(ll i = 4; i <= 2 * n - 1; i += 2) 
    {
        if(ask(i, i + 1) == 1) 
        {
            cout << "! " << i << endl;
            return;
        }
    }

    cout << "! " << 2 * n << endl;
}

int main() {
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}