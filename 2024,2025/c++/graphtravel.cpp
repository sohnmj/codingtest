#include<iostream>
using namespace std;

void printnode(int* post,int* mid, int size) {
	
	
	if (size == 0) {
		return;
	}
	int root = *post;
	int st;
	for (int i = 0; i < size; i++) {
		if (*(mid+i) == root) {
			st = i;
			break;
		}
	}
	if (st > 0) {
		printnode(post + 1, mid, st);
	}
	if (st < size-1) {
		printnode(post + st + 1, mid + st + 1, size-st-1);
	}



	cout << root;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int* post = new int[n + 1];


		for (int j = 0; j < n; j++) {
			cin >> post[j];
		}
		int* mid = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> mid[j];
			for (int k = 0; k < n; k++) {
				if (k > 0) {

				}
				if (mid[j] == post[k]) {
					break;
				}
			}
		}
		printnode(post, mid, n );

	}
}