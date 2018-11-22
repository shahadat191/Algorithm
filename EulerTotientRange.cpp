#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>

#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

int const MX = 100010;

ll sum = 0;
llu prime[MX];
void sieve(){
    for(int i = 2; i<=MX; i++){
        prime[i] = i;
    }
    for(int i = 2; i<=MX; i++){
        if(prime[i] == i){
            for(int j = i; j<=MX; j+=i){
                prime[j] -= prime[j]/i;
                sum++;
            }
        }
    }
    for(int i = 2; i<=MX; i++){
        prime[i] += prime[i-1];
    }

}


int main(){
   // input;
    sieve();
    cout<<sum<<endl;
    
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", cas++, prime[b]-prime[a-1]);
    }
}
