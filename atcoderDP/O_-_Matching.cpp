#include <bits/stdc++.h>
#include <fstream>



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
#define take(v) for (auto& i : v ) cin >> i ;
#define sqrt(n) sqrt((long double) n)

using namespace std;

ld PI = (acos(-1));
ll md = 1000000007;
// ll md = 998244353;
ll pw(ll a, ll b){ll c=1,m=a;while (b){if (b&1)c=(c*m);m=(m*m);b/=2;}return c;}
ll pwmd(ll a, ll b){ll c = 1, m = a;while (b){if (b & 1)c = ((c * m)) % md;m = (m * m) % md;b /= 2;}return c;}
ll modinv(ll n){return pwmd(n, md - 2);}
bool prime(ll a){for(int i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
ll ceel(ll a,ll b){if(a%b==0) return a/b;else return a/b+1;}


// Debugging
void __print(int x) {cerr << x << nl;}
void __print(ll x) {cerr << x << nl;}
void __print(ld x) {cerr << x << nl;}
void __print(char x) {cerr << '\'' << x << '\'' << nl;}
void __print(const char *x) {cerr << '\"' << x << '\"' << nl;}
void __print(const string &x) {cerr << '\"' << x << '\"' << nl;}
void __print(bool x) {cerr << (x ? "true" : "false") << nl;}
void __print(vll v) {for(auto i: v) cerr << i << sp;cerr << nl;}



template <class T1, class T2>
T2 mul(T1 x,T2 y){
    T2 ans = (x * y) % md;
    return (ans + md) % md;
}

template <class T>
T add(T x, T y){
    T ans = (x + y) % md;
    return (ans + md) % md;
}
template <class T>
T sub(T x, T y){
    T ans = (x - y) % md;
    return (ans + md) % md;
}
////////////////////////////////////////////////////     ¯\_(ツ)_/¯     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



// const int N = 1e5 + 10;
ll inf = 1e18 + 42;

// The shorter way to do many things is to only do one thing at a time.

void solve(){
    ll n; 
    cin >> n; 
    vvl v(n);
    fi(i,0,n){
        fi(j,0,n){
            ll x;
            cin>>x;
            v[i].pb(x);
        }
    }
    vvl adj(n+1);
    fi(i,0,n){
        fi(j,0,n){
            if(v[i][j]==0)continue;
            adj[i].pb(j);
            
        }
    }
    
    vvl dp(n+1);
    fi(i,0,n+1){
        for(int j =0 ;j<(1ll<<n) ;j++ ){
            dp[i].pb(0);
        }
    }
    
    dp[0][0]=1;
    
    for(int i = 1; i <= n; i++){
        for(int j =0 ;j<(1ll<<n) ;j++ ){
            if( __builtin_popcount(j)==i){
                for(auto k: adj[i-1]) if(j&(1ll<<k))
                dp[i][j] = (dp[i][j] + dp[i-1][j&(~(1<<k))])%md; 
                
            }
        }
    }
    
    cout<<dp[n][(1ll<<n)-1];
    
    
    
    
}

signed main()
{
    
    
    fast
    ll t = 1;
    ll tests = 1;
    // cin >> tests;
    cout << fixed << setprecision(15);

    while (tests--)
    {
        solve();
    }

    return 0;
}
