#include <iostream>

using namespace std;

void swap(int*,int*);
void rearrange(int* ,int);

int main()
{
	int a[9]={243,6345,244,321,6456,2347,14324,0,0};
	cout<<"before rearrange:"<<endl;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	rearrange(a,sizeof(a)/sizeof(a[0]));	
}

void rearrange(int a[],int size)
{
	int *temp = new int[size];
	int begin = 0;
	int end = size-1;
	
	for(int i=0;i<size;i++)
	{
		if(a[i]%2 == 0 && !(begin == end))
		{
			temp[begin] = a[i];
			begin++;
			
		}else if(a[i]%2 != 0 && !(begin == end))
		{
			temp[end] = a[i];
			end--;
			
		}else if (begin == end)
		{
			break;
		}
		
	}
	cout<<"after rearrange:"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<temp[i]<<" ";
	}
	cout<<endl;
}