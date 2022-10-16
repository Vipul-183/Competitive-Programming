#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define ll long long
#define ld long double
#define lb lower_bound
#define pb push_back
#define fi(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define vpll vector<pll>
#define vvl vector<vector<ll>>
#define all(v) v.begin(), v.end()
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define mxe(v) *max_element(v.begin(), v.end())
#define pll pair<ll, ll>
#define ff first
#define ss second
#define mll map<ll, ll>
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*1ll * (b)) / gcd(a, b)
#define nl "\n"
#define sp " "
#define sz(x) (int)x.size()
#define take(v) for (auto i : v ) cin >> i ;

using namespace std;

ld PI = (acos(-1));
ll md = 1000000007;
// ll md = 998244353;
ll pw(ll a, ll b){ll c=1,m=a;while (b){if (b&1)c=(c*m);m=(m*m);b/=2;}return c;}
ll pwmd(ll a, ll b){ll c = 1, m = a;while (b){if (b & 1)c = ((c * m)) % md;m = (m * m) % md;b /= 2;}return c;}
ll modinv(ll n){return pwmd(n, md - 2);}
bool prime(ll a){for(int i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
ll ceel(ll a,ll b){if(a%b==0) return a/b;else return a/b+1;}

template <class T1, class T2>
T1 mul(T1 x,T2 y){
    T1 ans = (x * y) % md;
    return (ans + md) % md;
}

template <class T1, class T2>
T1 add(T1 x, T2 y){
    T1 ans = (x + y) % md;
    return (ans + md) % md;
}
template <class T>
T sub(T x, T y){
    T ans = (x - y) % md;
    return (ans + md) % md;
}
////////////////////////////////////////////////////     ¯\_(ツ)_/¯     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




void solve(){
    ll n, k;
    cin >> n >> k;
    vll v(n);
    fi(i, 0, n) cin >> v[i];
    ll dp[k + 1][n], pre[k + 1][n];
    fi(i, 0, k + 1) dp[i][0] = (i <= v[0] ? 1 : 0);
    fi(i, 0, n) dp[0][i] = 1;
    pre[0][0] = 1;
    fi(i,1,k+1){
        // cout << 1 << nl;
        if (i <= v[0])
            pre[i][0] = pre[i - 1][0] + 1;
        else
            pre[i][0] = pre[i - 1][0];
    }
    fi(i, 1, n){
        pre[0][i] = 1;
    }

    fi(i, 1, n){
        fi(j, 1, k+1){
            ll cur = max(0ll,sub(pre[j][i - 1] , ((j - v[i]-1 >= 0) ? pre[j - v[i]-1][i - 1] : 0)));
            dp[j][i] = cur;
            pre[j][i] = (pre[j-1][i] + cur)%md;
        }
    }
    // fi(i,0,n){
    //     fi(j, 0, k+1) cerr << dp[j][i] << sp;
    //     cerr << nl;
    // }
    // cerr << nl;
    // fi(i,0,n){
    //     fi(j, 0, k+1) cerr << pre[j][i] << sp;
    //     cerr << nl;
    // }
    cout << dp[k][n - 1];
}




signed main()
{
    fast;
    // t = 1;
    ll tests = 1;
    // cin >> tests;


    while (tests--)
    {
        // cout<<"Case #"<<t<<": ";
        // t++;
        solve();
        
    }

    return 0;
}
