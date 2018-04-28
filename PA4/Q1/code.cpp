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
    int depth;
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

int max(int a, int b){
    if(b>a) return b;
    return a;
}

int depthf(node* root){
    if(root==NULL) return 0;
    return root->depth;
}

int hdiff(node* root){
    //cout << "HDIFF checked ---- " << root->info << endl;
    if(root==NULL) return 0;
    return depthf(root->right) - depthf(root->left);
}

node* rot_left(node* a){
    node* b = a->right;
    b->rank = ((a->right->rank - 1) + (a->rank - 1) + 1) + 1;
    a->right = b->left;
    b->left = a;
    a->depth = 1 + max(depthf(a->left),depthf(a->right));
    b->depth = 1 + max(depthf(b->left),depthf(b->right));
    return b;
}

node* rot_right(node* a){
    node* b = a->left;
    a->rank = ((a->rank - 1) - (a->left->rank - 1) - 1) + 1;
    b->rank = a->left->rank;
    a->left = b->right;
    b->right = a;
    a->depth = 1 + max(depthf(a->left),depthf(a->right));
    b->depth = 1 + max(depthf(b->left),depthf(b->right));
    return b;
}

node* rot_lr(node* a){
    a->left = rot_left(a->left);
    a = rot_right(a);
    return a;
}

node* rot_rl(node* a){
    //cout << "RL Call";
    a->right = rot_right(a->right);
    //cout << "R done";
    a = rot_left(a);
    //cout << "L done";
    return a;
}

node* memorise(node* root, string word) {

    if(root==NULL) {
        node* foo = (node*) malloc(sizeof(node));
        foo->left = NULL;
        foo->right = NULL;
        foo->info = word;
        foo->rank = 1;
        foo->depth = 1;
        return foo;
    }
    if(word<root->info){
        root->rank++;
        root->left = memorise(root->left, word);
    }
    else{
        root->right = memorise(root->right, word);
    }
    //return root;

    root->depth = 1 + max(depthf(root->right), depthf(root->left));
    //cout << root->info << " ---- ERROR" << endl;
    if(hdiff(root)>1){
        //cout << "qwe" << endl;
        if(hdiff(root->right)==-1){
            //cout<< "qwerty" << endl;
            root = rot_rl(root);
        }
        else{
            root = rot_left(root);
        }
    }
    else if(hdiff(root)<-1){
        if(hdiff(root->left)==1){
            root = rot_lr(root);
        }
        else{
            root = rot_right(root);
        }
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

    root->depth = 1 + max(depthf(root->right), depthf(root->left));

    if(hdiff(root)>1){
        if(hdiff(root->right)==-1){
            root = rot_rl(root);
        }
        else{
            root = rot_left(root);
        }
    }
    else if(hdiff(root)<-1){
        if(hdiff(root->right)==1){
            root = rot_lr(root);
        }
        else{
            root = rot_right(root);
        }
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
            //cout << "sdsd0";
            root = memorise(root, word);
            /*cout << endl;
            cout << "ROOT ---- " << root->info << " Rank ---" << root->rank <<" Depth ---" << root->depth << endl;
            if(root->left!=NULL) cout << "LEFT ---- " << root->left->info <<" Rank ---" << root->left->rank <<" Depth ---" << root->left->depth << endl;
            if(root->right!=NULL) cout << "RIGHT ---- " << root->right->info <<" Rank ---" << root->right->rank <<" Depth ---" << root->right->depth << endl;
            if(root->left!=NULL && root->left->right!=NULL) cout << "LEFT RIGHT ---- " << root->left->right->info <<" Rank ---" << root->left->right->rank <<" Depth ---" << root->left->right->depth << endl;*/
            //if(root->right!=NULL) cout << "RIGHT ---- " << root->right->info <<" Rank ---" << root->right->rank <<" Depth ---" << root->right->depth << endl;
            //cout << endl;
        }
        else if(what == "findrank") {
            findrank(root, word);
            cout << final_rank << endl;
            counter=0;
            //cout << counter << endl;
            //cout << "FIND ---- " << endl;
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
