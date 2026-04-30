/**
 * Author: Ayush Kunwar Singh
 * Time:   20:09:11
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

void solve() {
    l(n);
    string s; 
    cin >> s; 

    vll freq(2,0);
    f(i , 0 , n) {
        if(s[i] == '(') freq[0]++ ; 
        else freq[1]++ ; 
    }

    if(freq[0] == freq[1]) {
        cout << "Yes" << endl; 
        return ;
    } 

    cout << "No" << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) solve();
    return 0;
}