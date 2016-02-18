#include <iostream>
#include <cstdlib> 
#include <cmath> 
using namespace std; 


bool ok(int q[], int col){ 
	for (int i = 0; i < col; i++) {
		if (q[col] == q[i] || (col-i)==abs(q[col]-q[i])) return false; 
	}
	return true; 
}



void backtrack(int &col){ 
	col--; 
	if(col==-1) 
	{ exit(1);} 
}

void print(int q[]){ 
	 int i,j,k,l;

		typedef char box[5][7];

		box bb,wb,bq,wq,*board[8][8];

		//fill in bb=black box and wb=whitebox
		for(i=0;i<5;i++)
			for( j=0;j<7;j++){
				wb[i][j]=' ';
				wq[i][j]=' '; 
				bb[i][j]=char(219);
				bq[i][j] = char(219);

			}
		wq[0][3] = wq[1][2] = wq[1][4] = wq[2][3] = wq[3][3] = wq[4][2] =
			wq[4][3] = wq[4][4] = char(519);

		bq[0][3] = bq[1][2] = bq[2][3] = bq[3][3] = bq[4][2] = bq[4][3] = bq[4][4] = ' ';  



		//fill board with pointers to bb and wb in alternate positions
		for(i=0;i<8;i++) {
			for(j=0;j<8;j++) {
				if((i+j)%2 == 0) 
					board[i][j]=&wb; 
					
				
				else 
					board[i][j] = &bb;
				  
				
			}
		}


		for (i = 0; i < 8; i++) {
			if ((i+q[i]) % 2 == 0)
				board[q[i]][j] = &wq; 

			else board[q[i]][j] = &bq; 

		}


		// print the board via the pointers in array board

		// first print upper border
		cout<<" ";
		for(i=0;i<7*8;i++)
			cout<<'_';
		cout<<endl;

		// now print the board
		for(i=0;i<8;i++)
			for(k=0;k<5;k++)
			{cout<<" "<<char(179); //print left border
				for(j=0;j<8;j++) 
					for(l=0;l<7;l++)
						cout<<(*board[i][j])[k][l];
				cout<<char(179)<<endl; // at end of line print bar and then newline
			} 

		//before exiting print lower border 
		cout<<" "; 
		for(i=0;i<7*8;i++)
			cout<<char(196);
		cout<<endl;


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
		backtrack(c);  

		from_backtrack= true;

	} 
}


