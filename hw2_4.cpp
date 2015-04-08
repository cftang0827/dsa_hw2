#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <time.h>
#include <algorithm>
#include <map>
#define inputSize 2000000
#define tableSize 100000


using namespace std;
typedef vector<unsigned long long > Data;
typedef vector<Data> DataList;
string NumOfData;
string click;
string impression;
string URL;
string AdID;
string AdvertiserID;
string depth;
string position;
string QID;
string KID ;
string TID;
string DID ;
string UID;
string a ;

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

//function declaration
void get(int ,int, int, int, int);
void clicked(int u);
//void clicked(int u);
bool replicate(DataList , int);
void impressed(int, int);

bool myfunc(Data ,Data );
bool myfunc1(DataList,DataList);
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
        //exit(1);
    }

    int count = 0;
    while(in1 >>click1>>impression1>>URL1>>AdID1>>AdvertiserID1>>depth1>>position1>>QID1>>KID1>>TID1>>DID1>>UID1)
    {
        Data data1;
/*
		stringstream a1, a2, a3, a4, a5, a6, a7,a8,a9,a10,a11,a12;
		a1<<click;
		a2<<impression;
		a3<<URL;
		a4<<AdID;
		a5<<AdvertiserID;
		a6<<depth;
		a7<<position;
		a8<<QID;
		a9<<KID;
		a10<<TID;
		a11<<DID;
		a12<<UID;
		
		a1>>click1;
		a2>>impression1;
		a3>>URL1;
		a4>>AdID1;
		a5>>AdvertiserID1;
		a6>>depth1;
		a7>>position1;
		a8>>QID1;
		a9>>KID1;
		a10>>TID1;
		a11>>DID1;
		a12>>UID1;
		
	*/
        data1.push_back(click1);
        data1.push_back(impression1);
        data1.push_back(URL1);
        data1.push_back(AdID1);
        data1.push_back(AdvertiserID1);
        data1.push_back(depth1);
        data1.push_back(position1);
        data1.push_back(QID1);
        data1.push_back(KID1);
        data1.push_back(TID1);
        data1.push_back(DID1);
        data1.push_back(UID1);
		
        int temp = UID1;
        
        int index;
        index = temp%tableSize ;
        
        list1[index].push_back(data1);
	
        count++;
       
        if(count == inputSize)
            break;

    }

	t1 = t1-clock();
	printf ("It took me %d clicks in making data sheet(%f seconds).\n",t1,((float)t1)/CLOCKS_PER_SEC);
	string order;
	unsigned long long get_in1,get_in2,get_in3,get_in4,get_in5;
	unsigned long long click_in; 
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
			
		}		
		
		
	}
	
	
	
    //get(490234,21560664,2255103,2,2);
	//clicked(490234);
	//impressed(6231944,490234);
   
	
    t = t-clock();
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

    delete []list1;
    //	return 0;
}

int count1=0;

void get(int u,int a,int q,int p,int d)
{
    
    int click_out=0;
    int imp_out=0;
	
    int index1 = u%tableSize;
    
    for(int i=0;i<list1[index1].size();i++)
    {
        
        if( (list1[index1][i][3] == a) && (list1[index1][i][7] == q) && (list1[index1][i][5] == d) &&(list1[index1][i][6] == p) &&(list1[index1][i][11] ==u) )
        { 
			click_out = click_out +list1[index1][i][0];
			imp_out = imp_out +list1[index1][i][1];
            
        }

    }
    cout<<"click_time:"<<click_out<<endl;
    cout<<"impression_time"<<imp_out<<endl;
    //cout<<endl;

}

void clicked(int u)
{
    
    DataList temp_array;
   
    int index2 = u%tableSize;
    unsigned long pter;
    
    for(int i=0;i<list1[index2].size();i++)
    {
        
		pter = list1[index2][i][0];

        if(list1[index2][i][11] == u && pter>=1 &&replicate(list1[index2],i ))
        {
            
            Data temp;
            temp.push_back(list1[index2][i][3]);
            temp.push_back(list1[index2][i][7]);
            temp_array.push_back(temp);

        }

    }
    sort(temp_array.begin(),temp_array.end(),myfunc);
    for(int i=0;i<temp_array.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<temp_array[i][j]<<" ";
        }
        cout<<endl;
    }

	//cout<<endl;
}


bool myfunc(Data data1,Data data2)
{
    return(data1[0] <= data2[0]);
}

bool replicate(DataList a, int iter)
{
    bool temp = true;
    if(iter != 0)
    {
        for(int g=0;g<iter;g++)
        {
            if(a[g][3] == a[iter][3])
                temp = false;
            break;
        }
    }
    return temp;
}


void impressed(int u1,int u2)
{
	
	int index3 = u1%tableSize;
	int index4 = u2%tableSize;
	
	DataList temp1;
	DataList temp2;
	map<unsigned long,DataList> container;
	
	
	for(int i=0;i<list1[index3].size();i++)
	{
		if(list1[index3][i][11] == u1 )//&& list1[index3][i][0]!="0")
		{
			temp1.push_back(list1[index3][i]);
		}
		//cout<<temp1[i][3]<<" ";
		
		if(temp1[i][1] != 0)
		container[temp1[i][3]].push_back(temp1[i]);
	}
	//cout<<endl;
	for(int j=0;j<list1[index4].size();j++)
	{
		if(list1[index4][j][11] == u2 )//&&list1[index4][j][0]!="0")
		{
			temp2.push_back(list1[index4][j]);
		}
		//cout<<temp2[j][3]<<" ";
		if(temp2[j][1] != 0)
		container[temp2[j][3]].push_back(temp2[j]);
	}
	cout<<endl;
	
	//cout<<container[temp2[0][3]][0][3]<<endl;
	vector<DataList> con;
	for(map<unsigned long,DataList>::iterator it=container.begin();it!=container.end(); ++it)
	{
		
		//cout<<it->first<<": "<<endl;
		for(int u=0;u<(it->second).size();u++)
		{
			//cout<<(it->second)[u][2]<<" "<<(it->second)[u][4]<<" "<<(it->second)[u][8]<<" "<<(it->second)[u][9]<<" "<<(it->second)[u][10]<<" "<<(it->second)[u][11]<<" ";
			//cout<<endl;
			if((it->second).size()!=1 )
			{
				if((it->second)[u][11] != (it->second)[u+1][11])
				{
					con.push_back(it->second);
					break;
				}
			}
		}
	}
	cout<<endl;
	sort(con.begin(),con.end(),myfunc1);
	for(int h=0;h<con.size();h++)
	{
		for(int k=0;k<con[h].size();k++)
		{
			cout<<con[h][k][3]<<" "<<con[h][k][2];
			cout<<endl;
		}
		cout<<endl;
	}



}

bool myfunc1(DataList a,DataList b)
{
	return (a[0][3] > b[0][3]);
}