#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <time.h>
#include <algorithm>
#include <map>
#define inputSize 149639105
#define tableSize 23907634
//#define tableSize 34895628
//#define inputSize 200000

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

//function declaration
void get(int ,int, int, int, int);
void clicked(int u);
//void clicked(int u);
bool replicate(DataList , int);
bool replicate1(DataList , int);
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
	Data data1(12);
    int count = 0;
	string order;
	unsigned long long get_in1,get_in2,get_in3,get_in4,get_in5;
	unsigned long long click_in; 
	unsigned long long impressed_in1,impressed_in2;
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
	
        count++;
       
        if(count == inputSize)
            break;

    }

	t1 = t1-clock();
	printf ("It took me %d clicks in making data sheet(%f seconds).\n",t1,((float)t1)/CLOCKS_PER_SEC);
	
	while(cin>>order)
	{
		clock_t t2;
		clock_t t3;
		clock_t t4;
		t2 = clock();
		t3 = clock();
		t4 = clock();
		if(order == "get")
		{
			cin>>get_in1>>get_in2>>get_in3>>get_in4>>get_in5;
			get(get_in1,get_in2,get_in3,get_in4,get_in5);
			t2 = t2 - clock();
			cout<<"finished";
			printf ("It took me %d clicks in get(%f seconds).\n",t2,((float)t2)/CLOCKS_PER_SEC);
		}else if(order == "clicked")
		{			
			cin>>click_in;
			clicked(click_in);
			t3 = t3 - clock();
			cout<<"finished";
			printf ("It took me %d clicks in click(%f seconds).\n",t3,((float)t3)/CLOCKS_PER_SEC);
			
		}else if(order == "impressed")
		{
			cin>>impressed_in1>>impressed_in2;
			impressed(impressed_in1,impressed_in2);
			t4 = t4- clock();
			cout<<"finished";
			printf ("It took me %d clicks in impressed(%f seconds).\n",t4,((float)t4)/CLOCKS_PER_SEC);
			
		}else{
			cout<<"input error"<<endl;
		}	
	}
	
    t = t-clock();
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

	data1.erase(data1.begin()+12);
    delete []list1;
    //	return 0;
}



void get(int u,int a,int q,int p,int d)
{
    
    int click_out=0;
    int imp_out=0;
	
    //int index1 = u%tableSize;
    
    for(int i=0;i<list1[u].size();i++)
    {
        
        if( (list1[u][i][3] == a) && (list1[u][i][7] == q) && (list1[u][i][5] == d) &&(list1[u][i][6] == p) &&(list1[u][i][11] ==u) )
        { 
			click_out = click_out +list1[u][i][0];
			imp_out = imp_out +list1[u][i][1];
            
        }

    }
    //cout<<"click_time:"<<click_out<<endl;
    //cout<<"impression_time"<<imp_out<<endl;
	cout<<"********************"<<endl;
	cout<<click_out<<" "<<imp_out<<endl;
	cout<<"********************"<<endl;
    //cout<<endl;

}

void clicked(int u)
{
    
    DataList temp_array;
   
    //int index2 = u%tableSize;
    unsigned long pter;
    
    for(int i=0;i<list1[u].size();i++)
    {
        
		pter = list1[u][i][0];

        if(list1[u][i][11] == u && pter>=1 &&replicate(list1[u],i ))
        {
            
            Data temp;
            temp.push_back(list1[u][i][3]);
            temp.push_back(list1[u][i][7]);
            temp_array.push_back(temp);

        }

    }
    sort(temp_array.begin(),temp_array.end(),myfunc);
	cout<<"********************"<<endl;
    for(int i=0;i<temp_array.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<temp_array[i][j]<<" ";
        }
        cout<<endl;
    }
	cout<<"********************"<<endl;

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
	
	//int index3 = u1%tableSize;
	//int index4 = u2%tableSize;
	
	DataList temp1;
	DataList temp2;
	map<unsigned long long,DataList> container;
	
	
	for(int i=0;i<list1[u1].size();i++)
	{
		if(list1[u1][i][11] == u1 )//&& list1[index3][i][0]!="0")
		{
			temp1.push_back(list1[u1][i]);
		}
		//cout<<temp1[i][3]<<" ";
		
		if(temp1[i][1] != 0)
		container[temp1[i][3]].push_back(temp1[i]);
	}
	//cout<<endl;
	for(int j=0;j<list1[u2].size();j++)
	{
		if(list1[u2][j][11] == u2 )//&&list1[u2][j][0]!="0")
		{
			temp2.push_back(list1[u2][j]);
		}
		//cout<<temp2[j][3]<<" ";
		if(temp2[j][1] != 0)
		container[temp2[j][3]].push_back(temp2[j]);
	}
	//cout<<endl;
	
	//cout<<container[temp2[0][3]][0][3]<<endl;
	vector<DataList> con;
	for(map<unsigned long long,DataList>::iterator it=container.begin();it!=container.end(); ++it)
	{
		
		//cout<<it->first<<": "<<endl;
		for(int u=0;u<(it->second).size()-1;u++)
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
	//cout<<endl;
	sort(con.begin(),con.end(),myfunc1);
	cout<<"********************"<<endl;
	for(int h=0;h<con.size();h++)
	{
		cout<<con[h][0][3]<<endl;
		for(int k=0;k<con[h].size();k++)
		{
			if(replicate1(con[h],k))
			{
				cout<<'\t'<<con[h][k][2]<<" "<<con[h][k][4]<<" "<<con[h][k][8]<<" "<<con[h][k][9]<<" "<<con[h][k][10];
				cout<<endl;
			}
		}
		cout<<endl;
		
	}
	container.erase(container.begin(),container.end());
	temp1.erase(temp1.begin(),temp1.end());
	temp2.erase(temp2.begin(),temp2.end());
	cout<<"********************"<<endl;



}

bool myfunc1(DataList a,DataList b)
{
	return (a[0][3] < b[0][3]);
}


bool replicate1(DataList a, int iter)
{
    bool temp = true;
    if(iter != 0)
    {
        for(int g=0;g<iter;g++)
        {
            if(a[g][2] == a[iter][2])
                temp = false;
            break;
        }
    }
    return temp;
}
