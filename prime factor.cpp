#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>

#define sc(a) scanf("%d", &a)
#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

int const MX = 1000000;

ll sum = 0;
int prime[MX+5];
map<int,int> smap;

void sieve(){
    for(int i = 2; i<=MX; i+=2){
        prime[i] = 2;
    }
    for(int i = 3; i*i<=MX; i++){
        if(prime[i] == 0){
            for(int j = i*i; j<=MX; j+=i){
                if(prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
}

vector<int> fun(int n){
    vector<int> store;
    
    while (prime[n] != 0) {
        store.push_back(prime[n]);
        n /= prime[n];
    }
    store.push_back(n);
    return store;
}


int main(){
   // input;
    sieve();
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> store = fun(n);
        for(int i = 0; i<store.size()-1; i++)
            cout<<store[i]<<" ";
        cout<<store.back()<<endl;
        
        
    }
    
}
