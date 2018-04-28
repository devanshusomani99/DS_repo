#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int size=1;

void memorise(vector<string> &v, string word) {

    //cout << "dffdd    " << word << endl;
    v.push_back(word);
    //cout << "LAST ----> " << v[size] << endl;
    size++;
    if(size == 2) {
        return;
    }
    int i = size-1;
    //cout << "SIZE ----> " << size-1 << endl;
    while(i>1 && word < v[i/2]) {
        //cout << "sdsfdfjskfds" << endl;
        v[i] = v[i/2];
        v[i/2] = word;
        i=i/2;
    }
    return;
}

void heapify(vector<string> &v, int i){
    int l = 2*i;
    int r = 2*i+1;
    int s = i;
    if(l<size && v[l]<v[i]) {s = l;}
    if(r<size && v[r]<v[s]) {s = r;}
    if(s!=i)
    {
        string temp = v[i];
        v[i] = v[s];
        v[s] = temp;
        heapify(v,s);
    }
    return;
}

void forget(vector<string> &v){
    cout << v[1] << endl;
    v[1]=v[size-1];
    v.erase(v.begin()+size-1);
    size--;
    if(size == 1) {
        return;
    }
    heapify(v,1);
    return;
}

int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);

    int q,i;
    cin >> q;
    vector<string> v;
    v.push_back("0");
    for(i=0 ; i<q ; i++) {
        string what;
        cin >> what;
        //cout << "OPcode --- " << what << endl;
        if(what == "learn") {
            string word;
            cin >> word;
            //cout << "WORD " << word << endl;
            memorise(v, word);
            //cout << "MEMO ---- " << v[0] << endl;
        }
        else if(what == "reportsmallest") {
            cout << v[1] << endl;
        }
        else if(what == "forgetsmallest") {
            forget(v);
        }
        /*cout << endl;
        cout << "-----" << endl;
        for(int j=0; j<size; j++) {
            cout << v[j] << endl;
        }
        cout << "-----" << endl;
        cout << endl;*/
    }
    return 0;
}
