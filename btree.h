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
    for(char &c:s)c=tolower(c);
    for(char c:s){
        if(c<'a' ||c>'z')
            continue;
        if(curr->next[c-'a']==NULL){
            curr->next[c-'a']=new node();
        }
        curr=curr->next[c-'a'];
    }
    curr->isend=true;
}

bool search(node *n,string s){
    node *curr=n;
    for(char &c:s)c=tolower(c);
    for(char c:s){
        if(curr->next[c-'a']==NULL){
            return false;
        }
        else{
            curr=curr->next[c-'a'];
        }
    }
    return curr->isend==true;
}

ifstream dict;
node *bTreeNode=new node();

void  createDict(){
    dict.open("word.txt");
    string word;
    while(getline(dict,word)){
        insert(bTreeNode,word);
    }
}

void closeDict(){
    dict.close();
}