
//Single Hashing
https://www.spoj.com/problems/NHAY/

ll p_pow[N];
ll strHash[N];

void hashing(string& str, string& pat){
    int p = 31;
    ll patHash = 0;
    
    p_pow[0] = 1;
    for(int i = 1; i < str.size(); i++){
        p_pow[i] = (p_pow[i-1] * p) % MOD;
    }
    for(int i = 0; i < pat.size(); i++){
        patHash = (patHash + (pat[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    
    
    for(int i = 0; i < str.size(); i++){
        strHash[i] = ((str[i] - 'a' + 1) * p_pow[i]) % MOD;
        if(i != 0)
            strHash[i] = (strHash[i-1] + strHash[i]) % MOD;
    }
    
    int len = (int)pat.size();
    vector<int> store;
    for(int i = 0; i < str.size(); i++){
        if(i + len - 1 < str.size()){
            ll temp;
            if(i == 0) temp = strHash[i + len - 1];
            else temp = (strHash[i + len - 1] - strHash[i - 1] + MOD) % MOD;
            ll temp2 = (patHash * p_pow[i]) % MOD;
            if(temp == temp2) store.push_back(i);
        }
        else break;
    }
    for(int i = 0; i < sz(store); i++){
        cout << store[i] << "\n";
    }
}



// Double Hashing
// https://www.spoj.com/problems/ADACLEAN/

void pre(){
    ll p = 53;
    p_pow1[0] = 1;
    for(int i = 1; i < N; i++)
        p_pow1[i] = (p_pow1[i-1] * p) % MOD;
    
    p = 37;
    p_pow2[0] = 1;
    for(int i = 1; i < N; i++)
        p_pow2[i] = (p_pow2[i-1] * p) % MOD;
}

int fun(){
    
    ll strHash1[N];
    ll strHash2[N];
    for(int i = 0; i < n; i++){
        if(i == 0) strHash1[i] = str[i] - 'a' + 1;
        else  strHash1[i] = (strHash1[i-1] + (str[i] - 'a' + 1) * p_pow1[i]) % MOD;
        
        if(i == 0) strHash2[i] = str[i] - 'a' + 1;
        else  strHash2[i] = (strHash2[i-1] + (str[i] - 'a' + 1) * p_pow2[i]) % MOD;
    }
    
    int last = n - k;
    vector<pair<ll,ll> > store;
    for(int i = 0; i < n - k + 1; i++){
        ll temp1, temp2;
        if(i == 0) temp1 = strHash1[i + k - 1];
        else temp1 = (strHash1[i + k - 1] - strHash1[i - 1] + MOD) % MOD;
        temp1 = (temp1 * p_pow1[last]) % MOD;
        
        if(i == 0) temp2= strHash2[i + k - 1];
        else temp2 = (strHash2[i + k - 1] - strHash2[i - 1] + MOD) % MOD;
        temp2 = (temp2 * p_pow2[last]) % MOD;
        
        store.push_back({temp1, temp2});
        last--;
    }
    
    SORT_UNIQUE(store);
    return sz(store);
    
}
