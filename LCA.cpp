#include <bits/stdc++.h>

using namespace std;

#define ll int

// required
const ll MX = 200005, LG = 21;

vector<vector<int>> adj(MX);
vector<int> level(MX);
ll dp[LG][MX],n,q;
 
void dfs(ll x,ll par,ll lev){
    dp[0][x]=par;
    level[x]=lev;
    for(auto z: adj[x]){
        if(z!=par){
            dfs(z,x,lev+1);
        }
    }
}
 
void build(){
    dfs(1,-1,0);

    for (int i = 1; i < LG; i++){
        for (int j = 0; j < n + 1; j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}

ll LCA(ll x,ll y){
    
    if(level[x]<level[y])
        swap(x, y);
    ll z = level[x] - level[y];
    for (ll i = LG - 1; i >= 0; i--){
        if ((1ll << i) & z){
            x = dp[i][x];
        }
    }
    if (x == y)
        return x;
    for (ll i = LG - 1; i >= 0; i--){
        if (dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}

// optional
ll dist_bw_two_nodes(ll x, ll y){
    return level[x] + level[y] - 2 * level[LCA(x, y)];
}

ll kth_ancestor(ll x, ll k){
    if(level[x]<k)
        return -1;
    for (int i = 0; i < LG;i++){
        if (k & (1 << i)){
            x = dp[i][x];
            
        }
    }
    return x;
}

// question related only



int main(){

    cin >> n >> q;
    for (int i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    build();
    for (int i = 0; i < q; i++){
        ll x, y;
        cin >> x >> y;
        cout << LCA(x, y) << "\n";
    }

        return 0;
}