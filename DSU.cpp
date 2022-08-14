#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> color,len;

bool find(int x, int y)
{
    return color[x] == color[y];
}

void merge(int x, int y){
    x = color[x];
    y = color[y];
    if(x == y)
        return;
    if(len[x]<len[y])
        swap(x, y);
    for (int i = 0; i < len[y]; i++){
        adj[x].push_back(adj[y][i]);
        color[adj[y][i]] = x;
    }
    len[x] += len[y];
    len[y] = 0;
}

int main()
{

    int n, m;
    cin >> n, m;
    color.resize(n + 1);
    len.resize(n + 1, 1);
    adj.clear();

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }



    return 0;
}