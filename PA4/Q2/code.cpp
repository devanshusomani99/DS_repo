#include <iostream>
#include <string>
#include <new>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct NODE{
    string word;
    int number;
    NODE* next;
}node;

int hashit(string s,int size){
    int i=0,sum = 0;
    while(i<size){
        sum = sum + s[i] - 'a';
        i++;
    }
    //cout << sum%122 << endl;
    int m = 618;
    return (m*sum)%10000;
}

node* insert(node* root, string s){
    node* last = new node;
    last->word = s;
    last->number = 1;
    last->next = NULL;
    root->next = last;
    return last;
}

int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);

    int n,i;
    cin >> n;
    int max = 0;
    string max_string;
    node* root[10000] = {NULL};
    for(i=0;i<n;i++){
        string s;
        int value;
        cin >> s;
        int size = s.length();
        value = hashit(s,size);
        int flag=0;
        node* current = root[value];
        if(current==NULL){
            node* first = new node;
            first->next=NULL;
            first->word=s;
            first->number=1;
            root[value]=first;
            current=first;
        }
        else{
            while(current->next!=NULL){
                //cout << "IS " << current->word << " = " << s << endl;
                if(current->word==s){
                    current->number++;
                    flag=1;
                    break;
                }
                current = current->next;
            }

            if(flag==0 && current->word==s){
                current->number++;
                flag=1;
            }

            if(flag==0){
                current = insert(current, s);
            }

        }
        if(current->number>max){
            max = current->number;
            max_string = current->word;
        }
        // cout << value << "---------" << current->word << "----------" << max << "--------" << max_string <<endl;
        // if(root[value]->next!=NULL) {cout << "----" << endl << root[value]->next->word << " ------ " << root[value]->next->number << endl;
        // if(root[value]->next->next!=NULL) cout << "----" << endl << root[value]->next->next->word << " ------ " << root[value]->next->next->number << endl;}
    }
    cout << max_string << endl;
    return 0;
}
