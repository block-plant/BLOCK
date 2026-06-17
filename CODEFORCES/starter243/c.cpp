/**
 * Author: KUNWAR
 * Date:   2026-06-17
 * Time:   23:20:08
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t ;
    cin >> t;
    while(t--) {
        int n ; 
        cin >> n ;
        vector<int> a(n);
        int tot = 0 ;
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
            tot |= a[i];
        }
    
        int ans = 0 ;
        int cur = 0 ; 
        for(int i = 0 ; i < n ; i++) {
            cur |= a[i]; 
            if(cur == tot) {
                ans++ ; 
                cur = 0 ;
            }
        }
        cout << n - ans << endl;
    }
}
