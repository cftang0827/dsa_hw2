#include <iostream>

using namespace std;

void swap(int*,int*);
void rearrange(int* ,int);

int main()
{
	//int a[2]={3};
	int a[20]={7,2,6,4,8,5,7,1,667,24,234,44,13,42,55,98,24315,23,23,23};
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
		bool pot = false;
		if(a[i]%2 == 0 )
		{
			temp[begin] = a[i];
			begin++;
			
		}else if(a[i]%2 != 0 )
		{
			temp[end] = a[i];
			end--;
			
		}else if (begin == end &&pot == false)
		{
			pot = true;
		}else if(pot == true)
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