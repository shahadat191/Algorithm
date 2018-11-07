/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */
 #include<bits/stdc++.h>
 using namespace std;
 
string a, b;
string mul;
int mx = 0;
string res(100010, '0');
 
void pass(char c){
    int carr = 0;
    int temp = c - 48;
    for(int i = b.size()-1; i>=0; i--){
        int temp1 = b[i] - 48;
        temp1 *= temp;
        carr += temp1;
        mul.push_back(carr%10 + 48);
        carr /= 10;
    }
    while (carr != 0) {
        mul.push_back(carr%10 + 48);
        carr /= 10;
    }
    reverse(mul.begin(), mul.end());
}
void add(){
    int i = 0;
    int carr = 0;
 
    while (mul.size() > 0) {
        int temp = mul.back() - 48;
        carr += temp + (res[i] - 48);
        res[i] = carr%10 + 48;
        carr /= 10;
        mul.pop_back();
        i++;
    }
    while (carr != 0) {
        carr += res[i] - 48;
        res[i] = carr%10 + 48;
        carr /= 10;
        i++;
    }
    mx = max(i, mx);
}
 
int main(){
    cin>>a>>b;
    int j = 0;
    for(int i = a.size()-1; i>=0; i--){
        for(int k = 0; k<j; k++)
            mul.push_back('0');
        pass(a[i]);
        add();
        j++;
    }
 
    for(int i = mx-1; i>=0; i--)
        cout<<res[i];
    cout<<endl;
}
 
