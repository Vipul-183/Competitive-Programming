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


////////////////////////////////////////////////////      ¯\_(ツ)_/¯       \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void solve(){
    ll n, k;
    cin >> n >> k;
    vll arr(n);
    fi(i, 0, n) cin >> arr[i];
    ll dp[n];
    dp[0] = 0;
    fi(i, 1, n){
        dp[i] = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        for (int j = 2; j<=k; j++){
            if(i-j<0)
                break;
            dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
        }
    }
    cout << dp[n-1];
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
