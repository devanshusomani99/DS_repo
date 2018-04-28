#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

void set_table(vector< string >& v){
    int i;
    v.clear();
    char a;
    string b;

    for(i=0;i<26;i++){
        a = i + 65;
        //cout << a << endl;
        b = a;
        v.push_back(b);
    }
    for(i=0;i<26;i++){
        a = i + 97;
        b = a;
        v.push_back(b);
    }
    for(i=0;i<10;i++){
        a = i + 48;
        b = a;
        v.push_back(b);
    }
    v.push_back(" ");
    v.push_back("CLEAR");
}

int main(){

    freopen("input.txt", "r", stdin);

    int a,b,flag=0;
    string output="";
    while(1){
        string out="";
        cin >> a;
        if(a == -1){
            break;
        }
        vector<string> table;
        set_table(table);

        output = output + table[a];
        string buffer = table[a];
        while(1){
            cin >> b;
            if(b == -1){
                break;
            }
            if(b == 63){
                break;
            }
            if(b > table.size()){
                cout << "Archive is corrupted!";
                flag = 1;
                break;
            }
            else if(b == table.size()){
                out = table[a];
                out = out + buffer;
            }
            else{
                out = table[b];
            }
            output = output + out;
            buffer = out[0];
            out = table[a];
            out = out + buffer;
            table.push_back(out);
            a = b;
            //cout << out << endl;
        }
        if(b == -1 || flag == 1){
            break;
        }
    }
    if(flag == 0){
        cout << output;
    }

    // for(int i=0;i<table.size();i++){
    //     cout << i << "--- " << table[i] << endl;
    // }

    return 0;
}
