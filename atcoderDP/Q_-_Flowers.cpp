#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll seg_len = 0;
vector<ll> seg;

void build(ll N)
{
    seg.clear();
    seg_len = (ll)(log2(N));

    if (__builtin_popcount(N) > 1)
        seg_len++;
    seg_len = (1 << seg_len);

    seg_len *= 2;
    for (ll i = 0; i < seg_len; i++)
    { // depends
        seg.push_back(0);
    }
    
}

// ask queries like query(1, x, y, 1, seg_len/2)
ll query(ll node, ll x, ll y, ll start, ll end)
{
    if (x <= start && y >= end)
    {
        return seg[node];
    }
    if (x > end || y < start)
    {
        return 0; // depends on problem
    }
    ll mid = (start + end) / 2;
    return max(query(2 * node, x, y, start, mid), query(2 * node + 1, x, y, mid + 1, end));
}

void update(ll index, ll value)
{
    // x is 1 based index
    ll ind = index + (seg_len / 2) - 1;
    seg[ind] = value;
    while (ind / 2 > 0)
    {
        ind /= 2;
        seg[ind] = max(seg[2 * ind], seg[(2 * ind) + 1]);
    }
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> height(N), beauty(N);
    for (ll i = 0; i < N; i++)
        cin >> height[i];
    for (ll i = 0; i < N; i++)
        cin >> beauty[i];
    
    build(N);
    ll ans = 0;

    for (ll i = 0; i < N; i++)
    {
        ll x = height[i], z;
        
        z = query(1, 1, x-1, 1, seg_len / 2) ;

        ans = max(ans, z + beauty[i]);
        // cerr << ans << "\n";

        update(x, z+beauty[i]);
        
    }
    cout << ans;

    return 0;
}