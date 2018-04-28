#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

bool compare(const pair< int, pair<int,int> >&a, const pair< int, pair<int,int> >&b){
    return a.first < b.first;
}

int find_leader(vector <int> s,int node){
    if(s[node] != node){
        s[node] = find_leader(s,s[node]);
    }
    return s[node];
}

int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);

    int cities,n_roads;
    cin >> cities >> n_roads;

    vector< pair< int, pair<int,int> > > edges(n_roads);

    for(int i=0;i<n_roads;i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    sort(edges.begin(),edges.end(),compare);

    vector<int> subset_leader(cities);

    for(int i=0;i<cities;i++){
        subset_leader[i] = i;
    }

    int e = 0,path_length = 0;

    for(int i=0;i<n_roads;i++){
        int leader1 = find_leader(subset_leader, edges[i].second.first);
        int leader2 = find_leader(subset_leader, edges[i].second.second);

        if(leader1 != leader2){
            subset_leader[leader2] = leader1;
            path_length += edges[i].first;
            e++;
        }
        if(e == cities-1){
            break;
        }
    }

    cout << path_length << endl;
    return 0;
}
