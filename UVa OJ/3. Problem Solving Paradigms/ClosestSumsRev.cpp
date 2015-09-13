// Template by Hierony

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double PI = acos(-1);

#define REP(i,n) for((i) = 0; (i) < (int)(n); (i)++)
#define READ_INT(data) scanf("%d",&data); 
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

vector <int> Number,Query;
int a,b,c;

int main()
 {
 	int nNumbers,nQuerys;
 	int diff,sums;
 	int temp,counter = 1;
	while(1)
 	{
 		scanf("%d",&nNumbers);
 		if(!nNumbers) break;
 		
 		else
 		{
 			// Tampung number
 			REP(a,nNumbers)
 			{
 				scanf("%d",&temp);
 				Number.pb(temp);
 			}
 			
 			// Tampung Query
 			scanf("%d",&nQuerys);
 			REP(a,nQuerys)
 			{
 				scanf("%d",&temp);
 				Query.pb(temp);
 			}
			 
			 int status;
			 // Proses Pencarian
			printf("Case %d:\n",counter);
			REP(a,nQuerys)
			{
				status = 0;
				for(b = 0; b < (nNumbers - 1); b++)
				{
					for(c = b+1; c < nNumbers; c++)
					{
					 // Awal
					 if(status == 0)
					 {
					 	status = 1;
					 	sums = Number[b] + Number[c];
					 	diff = abs( (sums - Query[a]) );
					 	printf("--0Sums [%d] : %d\n",b,sums);
					 	printf("--0Temp [%d] : %d\n",b,diff);
					 }
					 
					 // Jika tidak
					 else 
					 {
					 	temp = abs( ( (Number[b] + Number[c]) - Query[a]) );
					 	if(diff == 0) 
						 {
						 	sums = Number[b] + Number[c];
						 	break;	
						 }
						 
						else if(diff > temp ) sums = Number[b] + Number[c]; 
						
						printf("--1Temp [%d] : %d\n",b,temp);
						printf("--1Sums [%d] : %d\n",b,sums);
					 	printf("--1diff [%d] : %d\n",b,diff);
					 }
					}
					
					if(b == nNumbers - 1)
					{
						temp = abs( ( (Number[b] + Number[b+1]) - Query[a]) );
					 	if(diff == 0) 
						 {
						 	sums = Number[b] + Number[b+1];
						 	break;	
						 }
						 
						else if(diff > temp ) sums = Number[b] + Number[b+1]; 
						
						printf("--1Temp [%d] : %d\n",b,temp);
						printf("--1Sums [%d] : %d\n",b,sums);
					 	printf("--1diff [%d] : %d\n",b,diff);
					}
				}
				printf("Closest sum to %d is %d.\n",Query[a],sums);
			}					
 		}
 		counter++;
 		
 		// Refresh
 		Number.erase(Number.begin(),Number.begin() + nNumbers);
 		Query.erase(Query.begin(), Query.begin() + nQuerys);
 	}
 	
 	return 0;
 }
