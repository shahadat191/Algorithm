
typedef long long ll;
ll mul(ll a, ll b, ll mod){
    a %= mod;
    b %= mod;
    ll res = 0;
    while (b) {
        if(b&1){
            res += a;
            if(res >= mod) res -= mod;
        }
        a <<= 1;
        if(a >= mod) a -= mod;
        b >>= 1;
    }
    return res;
}

ll mpow(ll x, ll y, ll mod){
    ll res = 1;
    while (y) {
        if(y & 1) res = mul(res, x, mod);
        x = mul(x, x, mod);
        y >>= 1;
    }
    return res;
}


int const N = 100000;
vector<int> P;
bool prime[N+10];
void sieve(){
    for(int i = 3; i*i < N; i += 2){
        if(prime[i]) continue;
        for(int j = 2*i; j < N; j += i)
            prime[j] = 1;
    }
    P.push_back(2);
    for(int i = 3; i < N; i += 2)
        if(!prime[i]) P.push_back(i);
}


void factor(int n, vector<ll>& f){
    for(int i = 0; P[i]*P[i] <= n; i++){
        while (n % P[i] == 0) {
            f.push_back(P[i]);
            n /= P[i];
        }
    }
    if(n > 1) f.push_back(n);
}

bool isPrime(ll n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    ll d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }
    
    for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(a == n) return 1;
        bool f = 0;
        ll x = mpow(a, d, n);
        if(x == 1 || x == n - 1) f = 1;
        for(int i = 0; i < s; i++){
            x = mul(x, x, n);
            if(x == 1) f = 1;
        }
        if(f == 0) return false;
    }
    return true;
}

ll gcd(ll a, ll b){
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll pollard_rho(ll n, ll c){
    ll x = 2, y = 2;
    while (true) {
        x = mul(x, x, n) + c;
        if(x >= n) x -= n;
        y = mul(y, y, n) + c;
        y = mul(y, y, n) + c;
        if(y >= n) y -= n;
        ll g = gcd(abs(x - y), n);
        if(g > 1) return g;
    }
    return n;
}

/*
ll pollard_rho(ll n, ll c){
    ll x = 2, y = 2, i = 1, k = 1;
    while (true) {
        x = (mul(x, x, n) + c);
        if(y >= n) y -= n;
        ll d = gcd(abs(x - y), n);
        if(d > 1) return d;
        
        if(i == k) y = x, k <<= 1;
        i++;
    }
    return n;
}
*/

void factorize(ll n, vector<ll>& f){
    if(n == 1) return;
    if(n < 1e9){
        factor((int)n, f);
        return;
    }
    if(isPrime(n)){
        f.push_back(n);
        return;
    }
    
    ll d = n;
    for(int c = 2; ;c++){
        d = pollard_rho(n, c);
        if(d != n) break;
    }
    factorize(d, f);
    factorize(n/d, f);
}

/*

 614889782588491410 = 2 3 5 11 7 19 23 13 17 41 43 29 31 37 47#
85212786917071631
903117378121213091
 */

int32_t main(){
    //input;
    sieve();
    vector<ll> f;
    factorize( 614889782588491410LL, f);
    for(auto c: f) cout << c << " ";
}
