#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <time.h>
#include <algorithm>
#include <map>

#define inputSize 149639106
#define tableSize 23907634
//#define tableSize 34895628
//#define inputSize 11

using namespace std;
typedef vector<unsigned long long> Data;
typedef vector<Data> DataList;

unsigned long long NumOfData1;
unsigned long long click1;
unsigned long long impression1;
unsigned long long URL1;
unsigned long long AdID1;
unsigned long long AdvertiserID1;
unsigned long long depth1;
unsigned long long position1;
unsigned long long QID1;
unsigned long long KID1 ;
unsigned long long TID1;
unsigned long long DID1 ;
unsigned long long UID1;


DataList *list1 = new  DataList[tableSize];	
DataList *list2 = new DataList[22238278];

//function declaration
void get(int ,int, int, int, int);
void clicked(int u);
void impressed(unsigned long long, unsigned long long);
bool myfunction(const Data&,const Data&);
bool myfunc(Data ,Data );
bool pred(Data,Data);
void profit(unsigned long long , double);
int main(int argc,char* argv[])
{
    clock_t t;
	clock_t t1;
	t1 = clock();
    t = clock();
    ifstream in1(argv[1],ios::in);
    if( !in1 )
    {
        cerr<<"Input File fail"<<endl;
    }
	Data data1(12);
    int count = 0;
	string order;
	unsigned long long get_in1,get_in2,get_in3,get_in4,get_in5;
	unsigned long long click_in; 
	unsigned long long impressed_in1,impressed_in2;
	unsigned long long profit_in1;
	double profit_in2;
    while(in1 >>click1>>impression1>>URL1>>AdID1>>AdvertiserID1>>depth1>>position1>>QID1>>KID1>>TID1>>DID1>>UID1)
    {
		data1[0] = click1;
		data1[1] = impression1;
		data1[2] = URL1;
		data1[3] = AdID1;
		data1[4] = AdvertiserID1;
		data1[5] = depth1;
		data1[6] = position1;
		data1[7] = QID1;
		data1[8] = KID1;
		data1[9] = TID1;
		data1[10] = DID1;
		data1[11] = UID1;
        
        list1[UID1].push_back(data1);
		list2[AdID1].push_back(data1);
		
	
        count++;
       
        if(count == inputSize)
            break;

    }
	//cout<<"list1[306055] sieze=="<<list1[306055].size()<<endl;
	
	for(long i=0;i<tableSize-1;i++)
	{
		if(list1[i].size() != 0)
		{
			sort(list1[i].begin(),list1[i].end(),myfunction);
		}
	}
	//cout<<"OK"<<endl;
	while(cin>>order)
	{
		if(order == "get")
		{
			cin>>get_in1>>get_in2>>get_in3>>get_in4>>get_in5;
			get(get_in1,get_in2,get_in3,get_in4,get_in5);
			
		}else if(order == "clicked")
		{			
			cin>>click_in;
			clicked(click_in);	
		}else if(order == "impressed")
		{
			cin>>impressed_in1>>impressed_in2;
			impressed(impressed_in1,impressed_in2);
		}else if(order == "profit")
		{
			cin>>profit_in1>>profit_in2;
			profit(profit_in1,profit_in2);
			
		}else if(order == "quit")
		{
			break;	
		}
			
	}
	
	//data1.erase(data1.begin()+12);
    //delete []list1;
    //return 0;
}



void get(int u,int a,int q,int p,int d)
{
    int click_out=0;
    int imp_out=0;
   
    for(int i=0;i<list1[u].size();i++)
    {
        
        if( (list1[u][i][3] == a) && (list1[u][i][7] == q) && (list1[u][i][5] == d) &&(list1[u][i][6] == p) &&(list1[u][i][11] ==u) )
        { 
			click_out = click_out +list1[u][i][0];
			imp_out = imp_out +list1[u][i][1];
            
        }

    }
	cout<<"********************"<<endl;
	cout<<click_out<<" "<<imp_out<<endl;
	cout<<"********************"<<endl;


}

void clicked(int u)
{
    DataList temp_array;   
    unsigned long pter;
    
    for(int i=0;i<list1[u].size();i++)
    {
        
		pter = list1[u][i][0];

        if(list1[u][i][11] == u && pter!=0 )
        {
           
				Data temp(2);
 
				temp[0] = list1[u][i][3];
				temp[1] = list1[u][i][7];
				temp_array.push_back(temp);
			
        }

    }
    sort(temp_array.begin(),temp_array.end(),myfunc);
	
	cout<<"********************"<<endl;
    for(int i=0;i<temp_array.size();i++)
    {
		if(i==0)
		{
			cout<<temp_array[i][0]<<" "<<temp_array[i][1]<<endl;
		}else if(i>0)
		{
			if(!(temp_array[i][0] == temp_array[i-1][0] && temp_array[i][1] == temp_array[i-1][1]))
			{
				
				cout<<temp_array[i][0]<<" "<<temp_array[i][1];
				
				cout<<endl;
			}
		}
    }
	cout<<"********************"<<endl;
}

bool myfunc(Data data1,Data data2)
{
	if(data1[0] != data2[0])
    return(data1[0] < data2[0]);
	else{
		return(data1[1]<data2[1]);
	}
}
void impressed(unsigned long long u1,unsigned long long u2)
{
	vector<unsigned long long> file;
	
	
	int i = 0;
	int j = 0;
	while(i<list1[u1].size()&&j<list1[u2].size())
	{
		if(list1[u1][i][3] < list1[u2][j][3])
		{
			i++;
		}
		else if(list1[u1][i][3] > list1[u2][j][3])
		{
			j++;
		}
		else if (list1[u1][i][3] == list1[u2][j][3])
		{
			file.push_back(list1[u1][i][3]);
			i++;
			j++;
		}
	}
	sort( file.begin(), file.end() );
	file.erase( unique( file.begin(), file.end() ), file.end() );
	
	DataList a;
	DataList b;
	int k=0;
	int p=0;
	for(int i=0;i<file.size();i++)
	{
		for(int j=0;j<list1[u1].size();j++)
		{
			
			if(list1[u1][j][3] == file[i] &&list1[u1][j][1] >=1 )
			{
				a.push_back(list1[u1][j]);
			}
		}
		for(int s=0;s<list1[u2].size();s++)
		{	
			if(list1[u2][s][3] == file[i]&&list1[u2][s][1] >=1)
			{
				a.push_back(list1[u2][s]);		
			}
		}
	}
	sort(a.begin(),a.end(),myfunction);
	a.erase( unique( a.begin(), a.end(),pred ), a.end() );
	cout<<"********************"<<endl;
	int uu=0;
	for(int i=uu;i<file.size();i++)
	{
		cout<<file[i]<<endl;
		for(int j=0;j<a.size();j++)
		{	
			if(a[j][3] == file[i])
			{	
				cout<<'\t'<<a[j][2]<<" "<<a[j][4]<<" "<<a[j][8]<<" "<<a[j][9]<<" "<<a[j][10]<<endl;
			}else{
				uu = j;
			}						
		}
	}
	cout<<"********************"<<endl;
	
	
}

bool pred(Data a,Data b)
{
	if(a[2] == b[2] && a[4] == b[4] && a[8] == b[8] && a[9] == b[9] && a[10] == b[10]   )
	{
		return true;
	}else
		return false;
}

bool myfunction(const Data& a,const Data& b)
{
	if(a[3] != b[3])
		return (a[3]<b[3]);
	else if(a[2] != b[2])
		return (a[2]<b[2]);
	else if(a[4] != b[4])
		return (a[4]<b[4]);
	else if(a[8] != b[8])
		return (a[8]<b[8]);
	else if(a[9] != b[9])
		return (a[9]<b[9]);
	else 
		return (a[10]< b[10]);
	
}



void profit(unsigned long long a, double th)
{
	
	map<unsigned long long,double> temp,temp_click,temp_impress;
	for(int i=0;i<list2[a].size();i++)
	{
		if(list2[a][i][1] != 0)
		{
			double click_num = double(list2[a][i][0]);
			double impress_num = double(list2[a][i][1]);
			temp_click[list2[a][i][11]] = temp_click[list2[a][i][11]] + click_num;
			temp_impress[list2[a][i][11]] = temp_impress[list2[a][i][11]] + impress_num;
						
		}
		else{
			temp_click[list2[a][i][11]] = 0;
			temp_impress[list2[a][i][11]] = 0;
		}
	}
	for(int i=0;i<list2[a].size();i++)
	{
		double temp1;
		if(temp_impress[list2[a][i][11]] ==0)
		{
			temp1 = 0;
		}else
		{
			temp1 = temp_click[list2[a][i][11]]/temp_impress[list2[a][i][11]];
		}
		temp[list2[a][i][11]] = temp1;
	}
	
	cout<<"********************"<<endl;
	for(map<unsigned long long,double>::iterator it=temp.begin();it!=temp.end(); ++it)
	{
		if(it->second>=th)
		{
			cout<<it->first<<endl;
		}
	}
	cout<<"********************"<<endl;
}





