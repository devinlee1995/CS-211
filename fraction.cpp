#include <iostream>
using namespace std;
 

int p(int a[], int size);
int q (int a[], int size) {
	if (size ==1) 
		return 1;
	return p(a+1, size-1); //move to next one (a[1]) 
}

int p(int a[], int size) {
	if (size ==1) 
		return *a; 
	return a[0]*p(a+1, size-1) + q(a+1, size-1); 
}







int main () {

int a[4] = {1,2,3,4};
int size = 4; 
	int n = p(a,size); 
	int d = q(a,size); 
cout << n << "/" << d; 
return 0; 
}



