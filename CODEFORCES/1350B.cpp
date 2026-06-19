#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() {
	int t ; 
	cin >> t; 
	while(t--) {
	    int n ; 
	    cin >> n ; 
	    vector<int> a(n + 1 , 0) ;
	    for(int i = 1 ; i <= n ; i++) cin >> a[i];
	    vector<vector<ll>> divs(n + 1);
	    for(int i = 1 ; i <= n ; i++) {
	        for(int j = i ; j <= n ; j += i) {
	            divs[j].push_back(i);
	        }
	    }
	    
	    auto lis = [&](vector<ll>&b)->ll {
            vector<ll> temp ;
            for(auto x : b) {
                auto it = lower_bound(temp.begin(), temp.end(), x);  
                if(it == temp.end()) {
                    temp.push_back(x);
                }
                else {
                    *it = x ;
                }
            }
            return temp.size();
	    };
	    
	    vector<ll> ans(n + 1 , 0);
	    ll Ans = 0 ;
	    for(int i = 1 ; i <= n ; i++) {
	       // cout << i << ' ' << Ans << endl;
	        vector<ll> divi;
	        for(auto x : divs[i]) {
	            divi.push_back(a[x]);
	        }
	        Ans = max(Ans , lis(divi));
	    }
	    cout << Ans << endl;
	}
}
