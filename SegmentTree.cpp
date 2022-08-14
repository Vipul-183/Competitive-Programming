#include <bits/stdc++.h>

using namespace std;

int seg_len = 0;
vector<int> seg;

void build(int N, vector<int> arr)
{
    seg.clear();
    seg_len = (int)(log2(N));

    if (__builtin_popcount(N) > 1)
        seg_len++;
    seg_len = (1 << seg_len);

    seg_len *= 2;
    for (int i = 0; i < seg_len; i++)
    { // depends
        seg.push_back(1000000000);
    }
    for (int i = seg_len / 2; i < seg_len / 2 + N; i++)
    {
        seg[i] = (arr[i - seg_len / 2]);
    }

    // Code below depends on the problem
    for (int i = seg_len / 2 - 1; i > 0; i--)
    {
        seg[i] = min(seg[2 * i], seg[(2 * i) + 1]);
    }
}

// ask queries like query(1, x, y, 1, seg_len/2)
int query(int node, int x, int y, int start, int end)
{
    if (x <= start && y >= end)
    {
        return seg[node];
    }
    if (x > end || y < start)
    {
        return 1000000000; // depends on problem
    }
    int mid = (start + end) / 2;
    return min(query(2 * node, x, y, start, mid), query(2 * node + 1, x, y, mid + 1, end));
}

void update(int index, int value)
{
    // x is 1 based index
    int ind = index + (seg_len / 2) - 1;
    seg[ind] = value;
    while (ind / 2 > 0)
    {
        ind /= 2;
        seg[ind] = min(seg[2 * ind], seg[(2 * ind) + 1]);
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    build(N, arr);

    for (int i = 0; i < Q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 2)
        {
            cout << query(1, y, z, 1, seg_len / 2) << "\n";
        }
        else
        {
            update(y, z);
        }
    }

    return 0;
}