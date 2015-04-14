#include <iostream>

using namespace std;

void swap(int*,int*);
void rearrange(int* ,int);

int main()
{
	int a[9]={7,0,6,4,8,5,7,1,0};
	cout<<"before rearrange:"<<endl;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	
	
	rearrange(a,sizeof(a)/sizeof(a[0]));
	
	cout<<"after rearrange:"<<endl;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
}


void swap(int* i,int* j)
{
	int temp;
	temp = *i;
	*i =*j;
	*j = temp;
	
}

void rearrange(int a[],int size)
{
	if (size == 2)
	{
		swap(a+0,a+1);
	}else if(size > 2)
	{
		for(int i=size-1;i>0;i--)
		{
			if(*(a+i) %2 ==0 && *(a+i-1)%2!=0)
			{	
				swap(a+i,a+i-1);
				rearrange(a,size);
			}
		}
	}
}