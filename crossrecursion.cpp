#include <iostream>
#include <cstdlib> 
#include <cmath> 
using namespace std; 

	  
 
	bool ok(int *q, int col){
		int help[8][5] = {
			{-1}, 
			{0, -1}, 
			{0, 1, -1}, 
			{0, 2, -1}, 
			{1, 2, -1}, 
			{1, 2, 3, 4, -1}, 
			{2, 3, 5, -1}, 
			{4, 5, 6, -1} 
		}; 
		for (int i = 0; i < col; i++) 
			if (q[col] == q[i]) return false;
		for (int j = 0; help[col][j] != -1; j++) {  
			if (abs(q[col] - q[help[col][j]]) == 1) return false;  
			}	
		return true; 
	}
 
	
 
	void print(int *q){ 
 		static int count =0; 
 		cout<< "count: " << ++count<<endl<<endl; 
 		int i;  
 		for(i=0; i<8; i++){  
 			cout<<q[i]<<" ";
			} 
 			cout<<endl;
			cout << endl; 
		 
		} 	
		
	void move(int* q, int i) // try place in col i
	{
		if(i==8){
		print(q);
		return;}
			for(int j=0;j<8;j++) { // j is the row value				
				 q[i]=j;
				if(ok(q,i)) // try and place a queen in row j of col i,if yes
				move(q,i+1); // go to next column otherwise try next j
			}
		// no value of j worked so return;
	};

int main(){ 
 	int q[8]; 
 	move(q, 0);  
}


