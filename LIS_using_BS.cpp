int lis(vector<int>& ar){
    vector<int> store;
    store.push_back(ar[0]);
    
    for(int i = 1; i < ar.size(); i++){
        if(store.back() <= ar[i])
            store.push_back(ar[i]);
        else{
            int pos = GET_POS(store, ar[i]);
            store[pos] = ar[i];
        }
    }
    return (int)store.size();
}

