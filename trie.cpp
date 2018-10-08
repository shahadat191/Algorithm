/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

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
#include<stdio.h>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>


struct node{
    bool end;
    node *next[26 + 1];
    node(){
        end = false;
        for(int i = 0; i<26; i++)
            next[i] = NULL;
    }
} *root;

void insert(char *str, int len){
    node *curr = root;
    for(int i = 0; i<len; i++){
        int id = str[i] - 'a';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->end = 1;
}


bool search(char *str, int len){
    node *curr = root;
    for(int i = 0; i<len; i++){
        int id = str[i] - 'a';
        if(curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->end;
}



void del(node *curr){
    for(int i = 0; i<26; i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete (curr);
}


int main(){
    
    int t;
    cin>>t;
    while(t--){
        root = new node();
        int n;
        cin>>n;
        
        while (n--) {
            char str[50];
            cin>>str;
            insert(str, (int)strlen(str));
        }
        
        int q;
        cin>>q;
        while (q--) {
            char str[50];
            cin>>str;
            
            bool foo = search(str, (int)strlen(str));
            if(foo)
                cout<<"found";
            else
                cout<<"noe";
            cout<<endl;
        }
        
        del(root);
    }
}

