#include <iostream>
using namespace std;

void move (string from, string to, string extra, int number) {
	if (number ==1) cout << "Transfer ring " << number << " from " << from << " to " << to << endl;    
	else { 
	move(from, extra, to, number-1); 
	cout << "Transfer ring " << number << " from " << from << " to " << to << endl; 
	move (extra, to, from, number-1); 
	return;} 
}
  

int main () {
	int n;
	string a = "A";  
	string b = "B"; 
	string c = "C";  
	cout << "Enter a number: "; 
	cin >> n; 

	move(a, b, c, n); 
}
