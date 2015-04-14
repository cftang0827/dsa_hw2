#include <iostream>

using namespace std;
void find_double(int*,int);

int main()
{
	int B[20] = {1,2,2,3,4,5,5,6,6,7,8,9,10,11,12,13,14,15,10,11};
	for(int i=0;i<sizeof(B)/sizeof(B[0]);i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
	find_double(B,sizeof(B)/sizeof(B[0]));
	
}




void find_double(int B[],int s)
{
	int *temp = new int[s-5];
	for(int i=0;i<s-5;i++)
	{
		temp[i] = 0;
	}
	int indexOfDouble[5];
	int index = 0;
	for(int i=0;i<s;i++)
	{	
		temp[B[i]-1]++;
	
		if(temp[B[i]-1] == 2)
		{
	
			indexOfDouble[index] = B[i];
			index++;
		}
	}
	for(int i=0;i<sizeof(indexOfDouble)/sizeof(indexOfDouble[0]);i++)
	{
		cout<<indexOfDouble[i]<<" ";
	}
	cout<<endl;
	
}