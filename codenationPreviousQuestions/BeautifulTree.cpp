#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> val, MEX, size_of_sets;
vector<set<int>> vst;


void dfs(int x, int par){

}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        adj.resize(n);
        val.resize(n);
        MEX.resize(n);
        size_of_sets.resize(n,0);
        vst.resize(n);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    


        return 0;
}