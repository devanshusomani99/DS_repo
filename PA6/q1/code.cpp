#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <algorithm>

using namespace std;

stack<int> s;
int index = 0;

int min(const vector<int> &a, int size){
    int i;
    int min = a[0];

    for(i=0;i<size;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    //cout << "MIN --- " << min << endl;
    return min;
}

bool compare(const vector<int> &a, const vector<int> &b){
    int x = min(a, a.size());
    int y = min(b, b.size());
    return x < y;
}

void dfs_store(bool visited[], const vector< vector<int> >& adj, int k, vector< vector<int> >& scc){
    visited[k] = true;
    scc[index].push_back(k);

    int i;
    int size = adj[k].size();
    for(i=0;i<size;i++){
        if(visited[adj[k][i]] == false){
            dfs_store(visited, adj, adj[k][i], scc);
        }
    }
}

void dfs(bool visited[], const vector< vector<int> >& adj, int k){
    visited[k] = true;

    int i;
    int size = adj[k].size();
    for(i=0;i<size;i++){
        if(visited[adj[k][i]] == false){
            dfs(visited, adj, adj[k][i]);
        }
    }
    s.push(k);
}

int main(){

    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector< vector<int> > adj(n);
    vector< vector<int> > tradj(n);
    vector< vector<int> > scc(n);
    bool edge[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edge[i][j] = false;
        }
    }

    int i;
    for(i=0;i<n;i++){
        while(1){
            int a;
            cin >> a;
            if(a == -1){
                break;
            }
            adj[i].push_back(a);
            edge[i][a] = true;
            tradj[a].push_back(i);
        }
    }

    bool visited[n] = {0};

    for(i=0;i<n;i++){
        if(visited[i] == false){
            dfs(visited, adj, i);
        }
    }

    for(i=0;i<n;i++)
        visited[i] = false;

    while(s.empty() == false){
        i = s.top();
        s.pop();

        if(visited[i] == false){
            dfs_store(visited, tradj, i, scc);
            index++;
        }
    }

    scc.erase(scc.begin()+index, scc.end());
    sort(scc.begin(), scc.end(), compare);

    // cout << "qwert" << endl;
    // for(i=0;i<index;i++){
    //     int size3 = scc[i].size();
    //     for(int c=0;c<size3;c++){
    //         cout << scc[i][c] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "qwert" << endl;

    cout << index << endl;

    int j, flag = 0;
    vector< vector<int> > sccadj(index);

    for(i=0;i<index;i++){
        int size1 = scc[i].size();
        for(j=i+1;j<index;j++){
            int size2 = scc[j].size();
            for(int k=0;k<size1;k++){
                for(int l=0;l<size2;l++){
                    if(flag == 1){
                        break;
                    }
                    if(edge[scc[i][k]][scc[j][l]] == true){
                        flag = 1;
                        sccadj[i].push_back(j);
                        //cout << "i -- " << i << " j -- " << j << " k -- " << k << " l -- " << l << " first -- " << scc[i][k] << " second -- " << scc[j][l] << " edge -- " << edge[scc[i][k]][scc[j][l]] << endl;
                    }
                    else if(edge[scc[j][l]][scc[i][k]] == true){
                        flag = 1;
                        sccadj[j].push_back(i);
                    }
                }
                if(flag == 1){
                    flag = 0;
                    break;
                }
            }
        }
    }

    for(i=0;i<index;i++){
        int size = sccadj[i].size();
        for(j=0;j<size;j++){
            cout << sccadj[i][j] << " ";
        }
        cout << "-1" << endl;
    }


    return 0;
}
