/**
 * Author: KUNWAR
 * Date:   2026-06-17
 * Time:   20:01:03
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ;
	cin >> t; 
	while(t--) {
	    int n , m ;
	    cin >> m >> n ;
	    int c = m - n / 3 - n % 3 ;
        cout << c - 2 * min(c / 2 , n / 3) << endl;
	}

}
