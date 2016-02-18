#include <iostream>
#include <cmath> 
using namespace std; 
int factorial (int x) {
	return (x == 1 ? x:x*factorial(x-1)); 
}

bool ok (int *q, int c, int n) {
	for (int i = 0; i < c; i++) {
		int i1 = q[i]/n; 
		int j1 = q[i] %n; 
		int i2 = q[c] / n; 
		int j2 = q[c] %n; 
		if (i1 + j1 == i2 + j2) 
			return false; 
		if (i1-j1 == i2-j2) 
			return false; 
		if (q[i] == q[c]) 
			return false; 
	}

	return true; 
}

void print (int *q, int n) {
	static int count = 0; 
	cout << "count: " << ++count << endl; 
	for (int k = 0; k < n; k++) {
		cout << q[k]; 
		cout << endl; 
	}
}

void move (int *q, int i, int k, int n, int &count) {
	if (i==k) {
		count++; 
		return; 
	}
	for (int j = 0; j<n*n; j++) {
		q[i] = j; 
		if (ok(q,i,n)) 
			move(q,i+1,k,n,count); 
	}
}


int main () {
	int n, k; 
	cout << "Tell me the N: "; 
	cin >> n; 
	cout << "Tell me the K: "; 
	cin >> k; 
	int count; 
	int *q = new int [k]; 
	move(q,0,k,n,count); 
	cout << count << endl; 
	cout << count/factorial(k) << endl; 
	delete [] q; 
	return 0; 
}


