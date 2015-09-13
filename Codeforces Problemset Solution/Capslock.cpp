#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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
typedef map <int,int> mii;

double PI = acos(-1);

#define REP(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define READ_int(data) scanf("%d",&data);
#define RESET(c,v) memset(c, v, sizeof(c))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define ALL(vec) vec.begin(),vec.end()
#define sI(val) scanf("%d",&val)
#define sID(val,val2) scanf("%d %d",&val,&val2)
#define INF 2123123123

inline string IntToString(int a)
{
    char x[100];
    sprintf(x,"%d",a);
    string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[100];
    int res;
    strcpy(x,a.c_str());
    sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void)
{
    char x[1000005];
    scanf("%s",x);
    string s = x;
    return s;
}

// FPB gan
int gcd(int  a, int b)
{
    if(b == 0)return a;
    else return gcd(b,a%b);
}

//kpk gan
int lcm(int a,int b)
{
    return (a*(b/gcd(a,b)));
}

bitset<10000010> bs;
vi primes;

// Prima pertama terdapat di primes[1] yah :D
void sieve(LL upperbound)
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.pb(0);
    for(LL i=2; i<=upperbound+1; i++)if(bs[i])
        {
            for(LL j=i*i; j<= upperbound+1; j+=i)bs[j] = 0;
            primes.pb((int) i);
        }
}

int main()
{
    string data = GetString();

    if(islower(data[0])){
        int stat = 0;
        for(int a = 1; a < data.size(); a++){

            if(islower(data[a])){
              stat = 1;
              break;
            }
        }

        // If it's an accident
        if(stat == 0){
            //printf("Masuk2\n");
            for(int a = 0; a < data.size(); a++){

            if(islower(data[a])){
              data[a] = toupper(data[a]);
            }
            else data[a] = tolower(data[a]);
          }
        }
    }

    else{
        //printf("Masuk B\n");
        int stat2 = 0;
        for(int a = 0; a < data.size(); a++){
            if(islower(data[a])){
                stat2 = 1;
                break;
            }
        }

        if(stat2 == 0){
            for(int a = 0; a < data.size(); a++){

            if(islower(data[a])) data[a] = toupper(data[a]);
            else data[a] = tolower(data[a]);
          }
        }
    }

    printf("%s\n",data.c_str());
    return 0;
}
