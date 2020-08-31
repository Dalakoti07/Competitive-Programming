#include <bits/stdc++.h>
using namespace std;

void solveTestCase() {
	int N;
	cin >> N;
	vector<int> A(N), zeroSegmentLen;
	for(int i = 0; i < N; i ++) {
		cin >> A[i];
	}
	for(int i = 0; i < N; i ++) {
		if(A[i]) continue;
		int ptr = i;
		while((ptr+1 < N) && (A[ptr+1] == 0)) {
			ptr ++;
		}
		zeroSegmentLen.push_back(ptr-i+1);
		i = ptr;
	}
	if(zeroSegmentLen.size() == 0) { // when all cells are blocked.
		cout << "No\n";
	}
	else if(zeroSegmentLen.size() == 1) {
		if(zeroSegmentLen[0] % 2) cout << "Yes\n"; // only in odd length strip Nayeon can win.
		else cout << "No\n";
	}
	else {
		int maxLen = 0, id = -1;
		int M = zeroSegmentLen.size();
		for(int i = 0; i < M; i ++) {
			if(maxLen < zeroSegmentLen[i]) {
				maxLen = zeroSegmentLen[i];
				id = i;
			}
		}
		swap(zeroSegmentLen[0], zeroSegmentLen[id]);
		maxLen = 0, id = -1;
		for(int i = 1; i < M; i ++) {
			if(maxLen < zeroSegmentLen[i]) {
				maxLen = zeroSegmentLen[i];
				id = i;
			}
		}
		swap(zeroSegmentLen[1], zeroSegmentLen[id]);
		// By doing above operation we get maximum at index 0 and second maximum at index 1.
		if((zeroSegmentLen[0] % 2) && (zeroSegmentLen[1] <= ((zeroSegmentLen[0]-1)/2))) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); // fast IO
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;
	for(int i = 1; i <= testCase; i ++) {
		solveTestCase();
	}

}