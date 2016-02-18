#include <iostream>
#include<algorithm> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 


bool ok(int *k, int n) { 
	for (int i = 0; i < n; i++) {
		if (k[i] == k[n] || (abs(k[i]-k[n]) == n-i)) 
			return false; 
		}
	return true; 
}


void move(int *q, int i, int size, int &count){
	if (i == size) {
		++count; 
		return; 
	}
	
	for (int j = 0; j < size; j++) {
		q[i] = j; 
		if (ok(q,i)) 
			move (q,i+1, size, count); 
	}

} 
	

int main(){ 
	int n; 
	cout << "Enter a number of Queens: " << endl;
	cin >> n; 

	for (int i = 1; i <= n; i++) {
		int count = 0; 
		int *q = new int[i]; 
		move(q,0,i,count); 
		delete [] q; 
		cout << count << endl; 
	}
	return 0; 
}













