#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

    // freopen("input.txt", "r", stdin);

    int n,op;
    cin >> n >> op;
    vector< vector< int > > adj(n);
    bool exist[n] = {0};
    for(int i=0;i<op;i++){
        string word;
        int a;
        cin >> word >> a;
        //cout << word << "  " << a << endl;
        if(word == "addnode"){
            exist[a-1] = true;
        }
        else if(word == "delnode"){
            exist[a-1] = false;
            adj[a-1].clear();
            //cout << adj[a-1].size() << "========" << endl;
            for(int j=0;j<n;j++){
                adj[j].erase(remove(adj[j].begin(), adj[j].end(), a), adj[j].end());
            }
        }
        else if(word == "addlink"){
            int b;
            cin >> b;
            //cout << "ss" << b << endl;
            adj[a-1].push_back(b);
            adj[b-1].push_back(a);
        }
        else if(word == "remlink"){
            int b;
            cin >> b;
            adj[a-1].erase(remove(adj[a-1].begin(), adj[a-1].end(), b), adj[a-1].end());
            adj[b-1].erase(remove(adj[b-1].begin(), adj[b-1].end(), a), adj[b-1].end());
        }
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        if(exist[c-1]==false){
            cout << "not in network" << endl;
        }
        else{
            if(adj[c-1].empty()){
                cout << "no connections" << endl;
            }
            else{
                int size = adj[c-1].size();
                for(int j=0;j<size;j++){
                    cout << adj[c-1][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
