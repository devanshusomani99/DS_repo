#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct NODE{
    string info;
    struct NODE* left;
    struct NODE* right;
    int rank;
}node;

int size=0;

int counter = 0;

int final_rank;

void findrank(node* root, string s) {
    if(s==root->info) {
        final_rank = root->rank + counter;
        return;
    }
    else if(s>root->info){
        counter = counter + root->rank;
        findrank(root->right,s);
    }
    else findrank(root->left,s);
}

node* memorise(node* root, string word) {

    if(root==NULL) {
        node* foo = (node*) malloc(sizeof(node));
        foo->left = NULL;
        foo->right = NULL;
        foo->info = word;
        foo->rank = 1;
        return foo;
    }
    if(word<root->info){
        root->rank++;
        root->left = memorise(root->left, word);
    }
    else{
        root->right = memorise(root->right, word);
    }
    return root;
}

node* successor(node* root){
    while(root->left!=NULL) root = root->left;
    return root;
}

node* forget(node* root, string word){
    if(root==NULL){
        return root;
    }
    if(word<root->info) {
        root->left = forget(root->left,word);
        root->rank--;
    }
    else if(word>root->info) root->right = forget(root->right, word);
    else {
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        node* k = successor(root->right);
        root->info = k->info;
        root->right = forget(root->right,k->info);
    }
    return root;
}

int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);

    int q,i;
    cin >> q;
    node* root = (node*) malloc(sizeof(node));
    root = NULL;
    for(i=0 ; i<q ; i++) {
        string what;
        cin >> what;
        string word;
        cin >> word;
        if(what == "learn") {
            root = memorise(root, word);
            /*cout << endl;
            cout << "ROOT ---- " << root->info << " Rank ---" << root->rank << endl;
            if(root->left!=NULL) cout << "LEFT ---- " << root->left->info <<" Rank ---" << root->left->rank << endl;
            if(root->right!=NULL) cout << "RIGHT ---- " << root->right->info <<" Rank ---" << root->right->rank << endl;
            cout << endl;*/
        }
        else if(what == "findrank") {
            findrank(root, word);
            cout << final_rank << endl;
            counter=0;
            //cout << counter << endl;
            //cout << "FIND ---- " << v[0] << endl;
        }
        else if(what == "forget") {
            findrank(root, word);
            cout << final_rank << endl;
            counter=0;
            root = forget(root, word);
            //cout << "FORGET ---- " << v[0] << endl;
        }
        /*cout << endl;
        cout << "-----" << endl;
        cout << "-----" << endl;
        cout << endl;*/
    }
    return 0;
}
