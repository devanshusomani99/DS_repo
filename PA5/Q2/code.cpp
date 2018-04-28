#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

int extract_min(const vector<int>& v, bool fixed[], int n){
    int index = n-1;
    int min = 50000000;

    for(int i=0;i<n;i++){
        if(fixed[i]==false){
            if(v[i]<min){
                index = i;
                min = v[i];
            }
        }
    }
    return index;
}

int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);

    int n_blocks,n_roads;
    cin >> n_blocks >> n_roads;
    vector< vector< pair<int,int> > > adj(n_blocks);
    for(int i=0;i<n_roads;i++){
        int a,b,w;
        cin >> a >> b >> w;
        //cout << a << "   " << b << "   " << w << endl;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }

    vector<int> d(n_blocks);
    bool fixed[n_blocks] = {0};

    for(int i=0;i<n_blocks;i++){
        d[i]=1000000;
    }
    //cout << "ddd";
    d[0] = 0;
    int path_length = -1;

    for(int i=0;i<n_blocks;i++){
        int next = extract_min(d,fixed,n_blocks);
        if(next == n_blocks-1){
            path_length = d[next];
            break;
        }
        fixed[next] = true;

        int size = adj[next].size();
        for(int j=0;j<size;j++){
            if(fixed[(adj[next][j].first)] == false && (adj[next][j].second + d[next] < d[(adj[next][j].first)])){
                d[(adj[next][j].first)] = adj[next][j].second + d[next];
            }
        }
    }
    cout << path_length << endl;
    return 0;
}
