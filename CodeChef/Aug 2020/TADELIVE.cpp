#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX_N 100000

using namespace std;

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[2] > v2[2]; 
} 

void solve (vector< vector<int> > &arr , int n, int x, int y) {
	int i, tips = 0;

	for ( i = 0; i < n; i ++ ) {
		arr [i] [2] = abs (arr [i] [0] - arr [i] [1]);
	}

	sort (arr.begin (), arr.end () , sortcol);
	
	for ( i = 0; i < n; i ++ ) {
		if (arr [i] [0] > arr [i] [1]) {
			// andy gets more
			if (x > 0) {
				tips += arr [i] [0];
				x --;
			}
			else {
				tips += arr [i] [1];
				y --;
			}
		}
		else {
			// bob gets more
			if (y > 0) {
				tips += arr [i] [1];
				y --;
			}
			else {
				tips += arr [i] [0];
				x --;
			}
		}
	}

	cout << tips << endl;

	return;
}

int main () {
	int n, x, y, i;

	cin >> n >> x >> y;

	vector< vector<int> > arr (n , vector<int> (3));

	for ( i = 0; i < n; i ++ ) {
		cin >> arr [i] [0];
	}

	for ( i = 0; i < n; i ++ ) {
		cin >> arr [i] [1];
	}
	
	solve (arr, n, x, y);


	return 0;
}