#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void solve(const vector< vector<int> >& v, int index) {
    if(v[index].empty()) {
        cout << index+1 << " ";
        return;
    }
    else {
        int i;
        for(i=0; i<v[index].size()/2; i++) {
            solve(v, v[index][i] - 1);
        }
        cout << index+1 << " ";
        for(i=v[index].size()/2; i<v[index].size() ; i++) {
            solve(v, v[index][i] - 1);
        }
    }
}

int main(int argc, char const *argv[]) {

    freopen("input.txt", "r", stdin);

    int t,i;
    cin >> t;
    for(i=0;i<t;i++) {
        int n,k;
        cin >>n;
        vector< vector<int> > matrix(n);
        int a,b;
        for (k=0;k<n-1;k++) {
            cin >> a >> b;
            matrix[a-1].push_back(b);
        }
        for (k=0;k<n;k++) {
            sort(matrix[k].begin(), matrix[k].end());
        }
        solve(matrix,0);
        cout << endl;
    }
    return 0;
}
