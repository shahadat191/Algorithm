#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define xx first
#define yy second
#define pb push_back
#define modulo 1000000007
#define loop(inp, n) for(int i = 0; i<n; i++) scanf("%d", &inp[i])
//#define loop(i,a,b)  for(int i=a;i<b;i++)
//#define loope(i,a,b)  for(int i=a;i<=b;i++)
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define ms(a,b) memset(a, b, sizeof(a))
#define print(case) printf("Case %d: ",case)
#define MAX -2000000000000000000
#define nl printf("\n")

//const long double PI = 3.141592653589793238L;
//const double PI = 3.141592653589793;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, int> pll;


int main(){
    
    
    
    
    
    
    ll t, i, j, ans;
    scanf("%lld",&t);
    
    for(i=1; i<=t; i++)
    {
        
        ll mx=100000000000000000, sum, s, loc, num, res=0;
        ll a[100005], b[100005], c[100005], d[100005], e[100005];
        ll n, x;
        scanf("%lld",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&x);
            a[j]=x;
            b[j]=x;
        }
        sort(a+1,a+n+1);
        ll k=1;
        for(j=n; j>=1; j--)
        {
            e[k]=a[j];
            k++;
        }
        c[0]=0;
        for(j=1; j<=n-1; j++)
        {
            c[j]=(a[j+1]-a[0])+c[j-1];
        }
        d[0]=0;
        for(j=1; j<=n-1; j++)
        {
            d[j]=(e[0]-e[j+1])+d[j-1];
        }
        for(j=1; j<=n; j++)
        {
            sum=c[n-1]-c[j-1];
            num=n-j+1;
            sum+=(a[j]-a[1])*num;
            loc=n-j+1;
            s=d[n-1]-d[loc-1];
            s+=(e[1]-e[loc])*(j-1);
            if(s+sum<mx)
            {
                mx=s+sum;
                res=a[j];
            }
        }
        for(j=1; j<=n; j++)
        {
            if(b[j]==res)
            {
                printf("Case %lld: %lld\n",i,j);
                break;
            }
        }
        
    }
}
