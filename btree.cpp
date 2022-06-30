#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    bool isend=false;
    node *next[26];
};

void insert(node *n,string s){
    node *curr=n;
    for(char c:s){
        if(curr->next[c-'a']==NULL){
            curr->next[c-'a']=new node();
        }
        curr=curr->next[c-'a'];
    }
    curr->isend=true;
}

bool search(node *n,string s){
    node *curr=n;
    for(char c:s){
        if(curr->next[c-'a']==NULL){
            return false;
        }
        else{
            curr=curr->next[c-'a'];
        }
        curr->isend=true;
    }
    return curr->isend;
}

int main(){
    node *n=new node();
    insert(n,"hello");
    ifstream dict;
    dict.open("word.txt");
    string word;
    node *n=new node();
    while(getline(dict,word)){
        insert(n,word);
    }
    dict.close();
}