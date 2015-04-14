#include <iostream>
#include <iomanip> 
using namespace std;
void make2Dto1D(int [][5],int row,int col);
void get(int i,int j,int row,int col,int B[]);
void put(int i,int j,int row,int col,int B[],int NewNum);
int main()
{
	int a[5][5] = {{1,0,0,0,0},{2,6,0,0,0},{3,7,10,0,0},{4,8,11,13,0},{5,9,12,14,15}};
	//output 2D array
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout << setw(5);
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//make 2D to 1D
	int a_row = 5;
	int a_col = 5;
	cout<<endl;
	cout<<endl;
	make2Dto1D(a,a_row,a_col);
	
		
}

void make2Dto1D(int a[][5],int row,int col)
{
	int *B = new int[((row+1)*col)/2];
	int index = 0;
	for(int i=0;i<col;i++)
	{
		for(int j = i;j<row;j++)
		{
			B[index] = a[j][i];
			index++;
		}
	}
	//output 1D array
	for(int i=0;i<((row+1)*col)/2;i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
	
	cout<<"get function at (i,j):"<<endl;
	get(3,2,5,5,B);
	get(0,0,5,5,B);
	get(2,1,5,5,B);
	get(4,1,5,5,B);
	get(1,2,5,5,B);
	cout<<endl;
	put(4,2,5,5,B,60);//change the value at (4,2) to 60
	cout<<endl;
	get(4,2,5,5,B);
}

void get(int i,int j,int row,int col,int B[])//get value at (i,j)
{
	if(i<j)
	{
		cout<<"the data in ("<<i<<","<<j<<") is :"<<0<<endl;	
	}
		
	else{
		cout<<"the data in ("<<i<<","<<j<<") is :";
		cout<<B[((col+(col-(j-1)))*j)/2 + (i-j)];
		cout<<endl;
	}
}

void put(int i,int j,int row,int col,int B[],int NewNum)//a-->origin 2D array, B-->1D array
{
	if(i<j)
	{
		cout<<"<Warning> The position you want to put is not in the lower triangular matrix...."<<endl;
		
	}else{
		cout<<"Put "<<NewNum<<" into matrix"<<endl;
		B[((col+(col-(j-1)))*j)/2 + (i-j)] = NewNum;	
	}
	
}



