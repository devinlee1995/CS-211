#include<iostream>
#include<climits>
#include<cmath>  
using namespace std; 
 
const int rows = 5; 
const int cols = 6; 
 
int min (int a, int b, int c) {
	int temp; 
	temp = (a <= b) ? a:b; 
	return (temp <= c) ? temp:c; 
}

void cost (int weight [][cols], int memo[][cols]) {
	for (int j = 1; j < cols; j++) 
		for (int i = 0; i < rows; i++) 
	memo[i][j] = weight[i][j] + min(memo[i][j-1], memo[(i-1) >=0?(i-1):(rows-1)][j-1], memo[(i+1)<=rows-1?(i+1):0][j-1]); 
	
}


void path(int memo[][cols], int i, int j){ // i is the row, j is the column 
	if (j==0) {
		cout << memo[i][j] << "-->"; 
		return; 
	}

	int minNum = min(memo[i][j-1], memo[(i-1) >=0?(i-1):(rows-1)][j-1], memo[(i+1)<=rows-1?(i+1):0][j-1]); 
	if (minNum == memo[i][j-1]) {
		path(memo,i,j-1); 
		cout << memo[i][j] - memo[i][j-1] << "-->"; 
	}

	else if (minNum == memo[(i-1) >=0?(i-1):rows-1][j-1]) {
		path(memo,(i-1) >=0?(i-1):rows-1, j-1); 
		cout << memo[i][j] - memo[(i-1) >=0?(i-1):rows-1][j-1] << "-->"; 
	}
	else
		 if (minNum == memo[(i+1)<=rows-1?(i+1):0][j-1]) {
			path(memo,(i+1)<=rows-1?(i+1):0,j-1); 
			cout << memo[i][j] - memo[(i+1)<=rows-1?(i+1):0][j-1] << "-->"; 
		}
 
 } 

 
int main(){ 
 int weight[rows][cols]={
 {3,4,1,2,8,6},
 {6,1,8,2,7,4},
 {5,9,3,9,9,5},
 {8,4,1,3,2,6},
 {3,7,2,1,2,3}};

int memo[rows][cols] = {
{3,0,0,0,0,0},
{6,0,0,0,0,0},
{5,0,0,0,0,0},
{8,0,0,0,0,0},
{3,0,0,0,0,0}};

int min = INT_MAX; 
int row; 
int col = cols-1; 
cost(weight, memo); 
for (int i = 0; i < rows; i++) {
	if (memo[i][col] < min) {
		min = memo[i][col]; 
		row = i; 
	}
}
cout << "The shortest path is of length " << min << endl; 
path(memo, row, col); 

 return 0; 
 
}
