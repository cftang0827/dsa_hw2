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


using namespace std;
typedef vector<string> Data;
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



    //	ofstream out1(argv[2],ios::out);

    //	if(!out1)
    //	{
    //		cerr<<"Output File error"<<endl;
    //exit(1);
    //	}

    //	out1 << "Click"<<'\t'<<"impression"<<'\t'<<"URL"<<'\t'<<'\t'<<"AdID"<<'\t'<<"AdvertiserID"<<'\t'<<"depth"<<'\t'<<"position"<<'\t'<<"QID"<<'\t'<<"KID"<<'\t'<<"TID"<<'\t'<<"DID"<<'\t'<<"UID"<<endl;

    int count = 0;
    while(in1 >>click>>impression>>URL>>AdID>>AdvertiserID>>depth>>position>>QID>>KID>>TID>>DID>>UID)
    {
        stringstream ss;
        Data data1;

        //		out1 << click[count]<<'\t'<<impression[count]<<'\t'<<URL[count]<<'\t'<<AdID[count]<<'\t'<<AdvertiserID[count]<<'\t'<<depth[count]<<'\t'<<position[count]<<'\t'<<QID[count]<<'\t'<<KID[count]<<'\t'<<TID[count]<<'\t'<<DID[count]<<'\t'<<UID[count]<<endl;
        //out1 << click[count]<<'\t'<<impression[count]<<endl;

        data1.push_back(click);
        data1.push_back(impression);
        data1.push_back(URL);
        data1.push_back(AdID);
        data1.push_back(AdvertiserID);
        data1.push_back(depth);
        data1.push_back(position);
        data1.push_back(QID);
        data1.push_back(KID);
        data1.push_back(TID);
        data1.push_back(DID);
        data1.push_back(UID);

        /*
           for(int i=0;i<12;i++)
           {
           cout<<data1[i]<<" ";
           }
           cout<<endl;
         */
        ss<<UID;
        int temp;
        ss>>temp;
        //cout<<"temp"<<temp<<endl;
        //cout<<"count:"<<count<<endl;
        //int index;
        //index = temp%tableSize ;
        //cout<<"index"<<index<<endl;
        list1[index].push_back(data1);
        //		system("PAUSE");

        //cout<<"temp:"<<temp<<endl;

        //cout<<"temp%10="<<temp%10<<endl;
        //cout<<"count:"<<count<<endl;





        /*
           switch(temp%10)
           {

           case 1:
           a1.push_back(data1);
           break;	
           case 2:
           a2.push_back(data1);
           break;	
           case 3:
           a3.push_back(data1);
           break;
           case 4:
           a4.push_back(data1);
           break;	
           case 5:
           a5.push_back(data1);
           cout<<"FUXK"<<endl;
           break;
           case 6:
           a6.push_back(data1);
           cout<<"FUXK666"<<endl;
           break;	
           case 7:
           a7.push_back(data1);
           break;	
           case 8:
           a8.push_back(data1);
           break;	
           case 9:
           a9.push_back(data1);
           break;	
           default:
           a10.push_back(data1);
           }
         */
        //data1.clear();
        //cout<<"aaaaaaaaaaaaaaaaaaa"<<endl;

        count++;
        //datalist.push_back(data);
        if(count == inputSize)
            break;

    }

    //vector<DataList>::iterator iter = list[4].begin();
    /*
       cout<<"list1[0]size=="<<list1[0].size()<<endl;
       cout<<"list1[1]size=="<<list1[1].size()<<endl;
       cout<<"list1[2]size=="<<list1[2].size()<<endl;
       cout<<"list1[3]size=="<<list1[3].size()<<endl;
       cout<<"list1[4]size=="<<list1[4].size()<<endl;
       cout<<"list1[5]size=="<<list1[5].size()<<endl;
       cout<<"list1[6]size=="<<list1[6].size()<<endl;
       cout<<"list1[7]size=="<<list1[7].size()<<endl;
       cout<<"list1[8]size=="<<list1[8].size()<<endl;
       cout<<"list1[9]size=="<<list1[9].size()<<endl;
       for(int i=0;i<12;i++)
       cout<<"list1[4][5][i]:"<<list1[4][5][i]<<endl;
     */
    /*
       for(int i=0;i<list1[5].size();i++)
       {
       for(int j=0;j<12;j++)
       {
       cout<<list1[5][i][j]<<" ";
       }
       cout<<endl;
       }*/

    //system("PAUSE");
	t1 = t1-clock();
	printf ("It took me %d clicks in making data sheet(%f seconds).\n",t1,((float)t1)/CLOCKS_PER_SEC);

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
    cout<<"we r doing get function!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    int click_out=0;
    int imp_out=0;
    stringstream cs;
    stringstream is;
    stringstream us;
    stringstream as;
    stringstream qs;
    stringstream ds;
    stringstream ps;
    string ui;
    string di;
    string ai;
    string pi;
    string qi;

    int ci;
    int ii;

    as<<a;
    qs<<q;
    ps<<p;
    ds<<d;
    us<<u;
    as>>ai;
    qs>>qi;
    ps>>pi;
    ds>>di;
    us>>ui;
    int index1 = u%tableSize;
    /*
       cout<<"index1="<<index1<<endl;
       cout<<"ai"<<ai<<endl;
       cout<<"qi"<<qi<<endl;
       cout<<"pi"<<pi<<endl;
       cout<<"di"<<di<<endl;
       cout<<"ui"<<ui<<endl;
     */
    for(int i=0;i<list1[index1].size();i++)
    {
        /*
           cout<<"list1[index1][i][3]AdID="<<list1[index1][i][3]<<endl;
           cout<<"list1[index1][i][7]QID="<<list1[index1][i][7]<<endl;
           cout<<"list1[index1][i][5]Depth="<<list1[index1][i][5]<<endl;
           cout<<"list1[index1][i][6]Position="<<list1[index1][i][6]<<endl;
           cout<<"i:::"<<i<<endl;
         */
        if( (list1[index1][i][3] == ai) && (list1[index1][i][7] == qi) && (list1[index1][i][5] == di) &&(list1[index1][i][6] == pi) &&(list1[index1][i][11] ==ui) )
        {

            cs<<list1[index1][i][0];
            is<<list1[index1][i][1];
            cs>>ci;
            is>>ii;
            cs.clear();
            is.clear();
            //cout<<"ci:"<<ci<<endl;
            //cout<<"list[index1][i][0]:"<<list1[index1][i][0]<<endl;
            //cout<<"ci::"<<ci<<endl;
            click_out = click_out+ci;
            imp_out = imp_out +ii;

            //cout<<"get("<<u<<","<<a<<","<<q<<","<<p<<","<<d<<")=";
            //cout<<"("<<ci<<", "<<ii<<")"<<endl;
        }

    }
    cout<<"click_time:"<<click_out<<endl;
    cout<<"impression_time"<<imp_out<<endl;
    cout<<endl;

}

void clicked(int u)
{
    //Data temp;
    DataList temp_array;
    stringstream ss;
    string us;
    ss<<u;
    ss>>us;
    int index2 = u%tableSize;
    int pter;
    stringstream rr;
    for(int i=0;i<list1[index2].size();i++)
    {
        rr.clear();
        rr<<list1[index2][i][0];
        rr>>pter;

        if(list1[index2][i][11] == us && pter>=1 &&replicate(list1[index2],i ))
        {
            //cout<<"clicked("<<u<<")=";
            //cout<<"("<<list1[index2][i][3]<<", "<<list1[index2][i][7]<<")"<<endl;


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

	cout<<endl;
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
	stringstream ss1;
	stringstream ss2;
	string us1;
	string us2;
	ss1<<u1;
	ss2<<u2;
	ss1>>us1;
	ss2>>us2;
	DataList temp1;
	DataList temp2;
	map<string,DataList> container;
	//map<string,DataList> container2;
	
	for(int i=0;i<list1[index3].size();i++)
	{
		if(list1[index3][i][11] == us1 )//&& list1[index3][i][0]!="0")
		{
			temp1.push_back(list1[index3][i]);
		}
		cout<<temp1[i][3]<<" ";
		//DataList t1;
		if(temp1[i][1] != "0")
		container[temp1[i][3]].push_back(temp1[i]);
	}
	cout<<endl;
	for(int j=0;j<list1[index4].size();j++)
	{
		if(list1[index4][j][11] == us2 )//&&list1[index4][j][0]!="0")
		{
			temp2.push_back(list1[index4][j]);
		}
		cout<<temp2[j][3]<<" ";
		if(temp2[j][1] != "0")
		container[temp2[j][3]].push_back(temp2[j]);
	}
	cout<<endl;
	
	//cout<<container[temp2[0][3]][0][3]<<endl;
	vector<DataList> con;
	for(map<string,DataList>::iterator it=container.begin();it!=container.end(); ++it)
	{
		
		cout<<it->first<<": "<<endl;
		for(int u=0;u<(it->second).size();u++)
		{
			cout<<(it->second)[u][2]<<" "<<(it->second)[u][4]<<" "<<(it->second)[u][8]<<" "<<(it->second)[u][9]<<" "<<(it->second)[u][10]<<" "<<(it->second)[u][11]<<" ";
			cout<<endl;
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
		
		cout<<"temp1_size:"<<temp1.size()<<endl;
		cout<<"temp2_size:"<<temp2.size()<<endl;
		cout<<"con_size:"<<con.size()<<endl;
	}



}

bool myfunc1(DataList a,DataList b)
{
	return (a[0][3] > b[0][3]);
}