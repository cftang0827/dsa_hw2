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
DataList *list2 = new DataList[22238277];

//function declaration
void get(int ,int, int, int, int);
void clicked(int u);
//void clicked(int u);
bool replicate(DataList , int);
bool replicate1(DataList , int,int);
void impressed(unsigned long long, unsigned long long);
bool myfunction(const Data&,const Data&);
bool myfunc(Data ,Data );
bool myfunc11(Data ,Data );
bool myfunc1(DataList,DataList);
void profit(unsigned long long , float);
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
	unsigned long long profit_in1;
	float profit_in2;
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
		//cout<<"index" <<i<<endl;
		//system("PAUSE");
	}

	t1 = t1-clock();
	printf ("It took me %d clicks in making data sheet(%f seconds).\n",t1,((float)t1)/CLOCKS_PER_SEC);
	//impressed(490234,6231944);
	//profit (21375650, 0.5);
	while(cin>>order)
	{
		clock_t t2;
		clock_t t3;
		clock_t t4;
		clock_t t9;
		t2 = clock();
		t3 = clock();
		t4 = clock();
		t9 = clock();
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
			
		}else if(order == "profit")
		{
			cin>>profit_in1>>profit_in2;
			profit(profit_in1,profit_in2);
			t9 = t9 -clock();
			printf ("It took me %d clicks in impressed(%f seconds).\n",t9,((float)t9)/CLOCKS_PER_SEC);
		}else if(order == "quit")
		{
			break;	
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

        if(list1[u][i][11] == u && pter!=0 )
        {
           
				Data temp(2);
            //temp.push_back(list1[u][i][3]);
            //temp.push_back(list1[u][i][7]);
				temp[0] = list1[u][i][3];
				temp[1] = list1[u][i][7];
				temp_array.push_back(temp);
			
        }

    }
    sort(temp_array.begin(),temp_array.end(),myfunc);
	//sort(temp_array.begin(),temp_array.end(),myfunc11);
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
				for(int j=0;j<2;j++)
				{
					cout<<temp_array[i][j]<<" ";
				}
				cout<<endl;
			}
		}
    }
	cout<<"********************"<<endl;

	//cout<<endl;
}


bool myfunc(Data data1,Data data2)
{
	if(data1[0] != data2[0])
    return(data1[0] < data2[0]);
	else{
		return(data1[1]<=data2[1]);
	}
}

/*
bool replicate(DataList a, int iter)
{
    bool temp = true;
    if(iter != 0)
    {
			
				if(a[iter][3] == a[iter-1][3] && a[iter][7] == a[iter-1][7])
				{
					temp = false;
					break;
				}
				
			
			
    }
    return temp;
}
*/
/*
void impressed(int u1,int u2)
{
	
	//int index3 = u1%tableSize;
	//int index4 = u2%tableSize;
	
	//DataList temp1;
	//DataList temp2;
	map<unsigned long long,DataList> container;
	
	
	
		for(int i=0;i<list1[u1].size();i++)
		{
			
			if(list1[u1][i][1] != 0)
			container[list1[u1][i][3]].push_back(list1[u1][i]);
		}
		//cout<<endl;
	
		
		for(int j=0;j<list1[u2].size();j++)
		{
			if(list1[u2][j][1] != 0)
			container[list1[u2][j][3]].push_back(list1[u2][j]);
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
			
					cout<<'\t'<<con[h][k][2]<<" "<<con[h][k][4]<<" "<<con[h][k][8]<<" "<<con[h][k][9]<<" "<<con[h][k][10];
					cout<<endl;
				
			
		}
		cout<<endl;
		
	}
	//container.erase(container.begin(),container.end());
	//temp1.erase(temp1.begin(),temp1.end());
	//temp2.erase(temp2.begin(),temp2.end());
	cout<<"********************"<<endl;



}
*/

void impressed(unsigned long long u1,unsigned long long u2)
{
	clock_t t5,t6;
	t5 = clock();
	t6 = clock();
	vector<unsigned long long> file;
	cout<<"list1[u1]size:"<<list1[u1].size()<<endl;
	cout<<"list1[u2]size:"<<list1[u2].size()<<endl;

	//sort(list1[u1].begin(),list1[u1].end(),myfunction);
	//sort(list1[u2].begin(),list1[u2].end(),myfunction);
	t5 = t5 - clock();
	printf ("It took me %d clicks in sort(%f seconds).\n",t5,((float)t5)/CLOCKS_PER_SEC);

	
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
	
	t6 = t6 - clock();
	printf ("It took me %d clicks in depart(%f seconds).\n",t6,((float)t6)/CLOCKS_PER_SEC);
	DataList a;
	DataList b;
	int k=0;
	int p=0;
	//int index = 0;
	for(int i=0;i<file.size();i++)
	{
		
		//int k=0;
		for(int j=0;j<list1[u1].size();j++)
		{
			
			if(list1[u1][j][3] == file[i] &&list1[u1][j][1] >=1 )
			{
				
				a.push_back(list1[u1][j]);
				//cout<<'\t'<<list1[u1][j][2]<<" "<<list1[u1][j][4]<<" "<<list1[u1][j][8]<<" "<<list1[u1][j][9]<<" "<<list1[u1][j][10]<<endl;
			}
			
		}
		
		
		
		
		//int p=0;
		for(int s=0;s<list1[u2].size();s++)
		{
			
			if(list1[u2][s][3] == file[i]&&list1[u2][s][1] >=1)
			{
				
				a.push_back(list1[u2][s]);
				
			}
			
		}
		
	}
	/*
	for(int i=0;i<a.size();i++)
	{
		for(int l=0;l<12;l++)
		{
			cout<<a[i][l]<<" ";
		}cout<<endl;
	}
	*/
	sort(a.begin(),a.end(),myfunction);
	/*
	cout<<"after sort::"<<endl;
	for(int i=0;i<a.size();i++)
	{
		for(int l=0;l<12;l++)
		{
			cout<<a[i][l]<<" ";
		}cout<<endl;
	}
	cout<<"push_bach and sort finish::"<<endl;*/
	/*
	for(int i=0;i<a.size();i++)
	{
			if(i>0)
			{
				if(a[i][4] == a[i-1][4] && a[i][2] == a[i-1][2] && a[i][8] == a[i-1][8] && a[i][9] == a[i-1][9] && a[i][10] == a[i-1][10])
				{
					a.erase(a.begin()+i-1);
					cout<<"a.size:"<<a.size()<<endl;
				}
			}
			
	}*/int ii=0;
	while(ii!=a.size())
	{
		for(ii=0;ii<a.size();ii++)
		{
			if(ii>0)
			{
				if(a[ii][4] == a[ii-1][4] && a[ii][2] == a[ii-1][2] && a[ii][8] == a[ii-1][8] && a[ii][9] == a[ii-1][9] && a[ii][10] == a[ii-1][10])
				{
					a.erase(a.begin()+ii-1);
					break;
					//cout<<"a.size:"<<a.size()<<endl;
				}
			}
			
		}
	}
	
	/*
	cout<<"a.size():"<<a.size()<<endl;
	cout<<"after erase"<<endl;
	for(int i=0;i<a.size();i++)
	{
		for(int l=0;l<12;l++)
		{
			cout<<a[i][l]<<" ";
		}cout<<endl;
	}
	
	
	
	*/
	cout<<"********************"<<endl;
	int uu=0;
	for(int i=uu;i<file.size();i++)
	{
		cout<<file[i]<<endl;
		for(int j=0;j<a.size();j++)
		{
				
			if(a[j][3] ==file[i])
			{
							
				cout<<'\t'<<a[j][2]<<" "<<a[j][4]<<" "<<a[j][8]<<" "<<a[j][9]<<" "<<a[j][10]<<endl;
			}else{
				uu = j;
			}						
		}
	}
	cout<<"********************"<<endl;
	
	
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




bool myfunc1(DataList a,DataList b)
{
	return (a[0][3] < b[0][3]);
}


bool replicate1(DataList a, int iter, int first)
{
    bool temp = true;
    if(iter != 0)
    {
			
				if(a[iter][2] == a[iter-1][2] && a[iter][4] == a[iter-1][4] && a[iter][8] == a[iter-1][8] && a[iter][9] == a[iter-1][9] && a[iter][10] == a[iter-1][10])
				{
					temp = false;
					//break;
				}
				
			
			
    }
    return temp;
	
}


void profit(unsigned long long a, float th)
{
	map<unsigned long long,float> temp;
	for(int i=0;i<list2[a].size();i++)
	{
		if(list2[a][i][1] != 0)
		{
			float tt = float(list2[a][i][0]) / float(list2[a][i][1]);
			//cout<<tt<<" "<<endl;
			
			temp[list2[a][i][11]] = temp[list2[a][i][11]]+tt;
		}
		else{
			temp[list2[a][i][11]] = temp[list2[a][i][11]]+0;
		}
	}
	cout<<"********************"<<endl;
	for(map<unsigned long long,float>::iterator it=temp.begin();it!=temp.end(); ++it)
	{
		if(it->second>=th)
		{
			cout<<it->first<<endl;
		}
	}
	cout<<"********************"<<endl;
}





