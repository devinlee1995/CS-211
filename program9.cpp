#include <iostream>
#include <cstdlib> 
#include <cmath> 
using namespace std; 

	  
 
	bool ok(int q[], int col){
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
 
	void backtrack(int &col){ 
 		col--; 
 		if(col==-1) 
 		{ exit(1);} 
	}
 
	void print(int q[]){ 
 		static int count =0; 
 		cout<< "count: " << ++count<<endl<<endl; 
 		int i;  
 		for(i=0; i<8; i++){  
 			cout<<q[i]<<" ";
			} 
 			cout<<endl;
			cout << endl; 
		 
		} 
	

	void print2(int q[]) {
		int cross[3][4];
		
		cross[1][0] = q[0]; 
		cross[0][1] = q[1]; 
		cross[1][1] = q[2]; 
		cross[2][1] = q[3]; 
		cross[0][2] = q[4]; 
		cross[1][2] = q[5]; 
		cross[2][2] = q[6]; 
		cross[1][3] = q[7]; 
	
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 4; c++) {
				if ((r == 0 && (c == 0 || c == 3)) || ((r == 2) && (c == 0 || c== 3))) {
				cout << " "; }
				else  
				cout << cross[r][c];  
				}
				cout << endl;  
		}
		cout << endl << endl; 
	}		
		
	
	
		
 
int main(){ 
 	int q[8]; q[0]=0; 
 	int c=1; 
 	
 	
 
 	bool from_backtrack=false; //runs first time  
 
 
 
 	while(true){ 
 		while(c<8){ 
 
 
 			if(!from_backtrack) 
 			q[c] = -1; //start at the top 
 
 
 			from_backtrack=false; 
 
 			while(q[c]<8){  
 				q[c]++; 
 				if(q[c]==8)
					 {backtrack(c);
					continue; }
 				 
 			 	if(ok(q,c)) 
 				break; 
 			} 
 		c++; 
 		} 
 	print(q);
	print2(q); 
 	backtrack(c);  
 
	 from_backtrack= true;
   
 } 
}


