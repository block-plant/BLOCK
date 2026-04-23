/**
 * Author: Ayush Kunwar Singh
 * Time:   20:15:27
 * Date:   2026-04-23
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
    i(n); 
    i(k);
    
    vi a(n);
    f(i , 0 , n) cin >> a[i];
    
    vi b(n);
    f(i , 0 , n) cin >> b[i];
    
    int left = max(0, n - k);
    int right = min(n - 1, k - 1);
    
    if(left > right) 
    {
        f(i , 0 , n)
        {
            if(b[i] != -1 && b[i] != a[i]) 
            {
                op("NO");
                return;
            }
        }
        op("YES");
        return;
    }
    
    vector<bool> seen(n+1, false);
    vector<bool> used(n+1, false);
    
    f(i , left , right+1) 
    {
        seen[a[i]] = true;
    }
    
    f(i , 0, n) 
    {
        if(b[i] == -1) continue;
        
        if(i < left || i > right) 
        {
            if(b[i] != a[i]) 
            {
                op("NO");
                return;
            }
        } 
        else 
        {
            if(!seen[b[i]]) 
            {
                op("NO");
                return;
            }
            if(used[b[i]]) 
            {
                op("NO");
                return;
            }
            used[b[i]] = true;
        }
    }
    op("YES");
}

int main() {
    fastio();
    l(t);
    while(t--) solve();
    return 0;
}