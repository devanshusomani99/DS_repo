#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

int index = 1;
vector<int> art;

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int counter = -1;

void find(const vector< vector<int> >& adj, int low[], int dfn[], int a, int b){
    dfn[a] = index;
    low[a] = index;
    index++;

    int size = adj[a].size();
    for(int j=0; j<size; j++){
        if(dfn[adj[a][j]] == 0){
            if(a==0 && counter!=-2){
                counter++;
            }
            if(counter>=1 && a==0){
                art.push_back(a);
                counter = -2;
            }
            find(adj, low, dfn, adj[a][j], a);
            low[a] = min(low[a], low[adj[a][j]]);
            if(low[adj[a][j]] >= dfn[a] && a!=0){
                art.push_back(a);
            }
        }
        else if(dfn[adj[a][j]] < dfn[a] && adj[a][j]!=b){
            low[a] = min(low[a], dfn[adj[a][j]]);
        }
    }
}

int main(){

    freopen("input.txt", "r", stdin);

    int nodes, edges;

    cin >> nodes >> edges;
    vector< vector< int > > adj(nodes);
    for(int i=0;i<edges;i++){
        int a,b;
        cin >> a >> b;
        //cout << a << "   " << b << endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int i;
    int dfn[nodes];
    int low[nodes];
    for(i=0;i<nodes;i++){
        dfn[i] = 0;
    }

    for(i=0;i<nodes;i++){
        if(dfn[i] == 0){
            find(adj, low, dfn, i, 0);
        }
    }

    sort(art.begin(), art.end());
    art.erase( unique(art.begin(), art.end()), art.end());
    int size = art.size();

    for(i=0;i<size;i++){
        cout << art[i] << endl;
    }

    return 0;
}
