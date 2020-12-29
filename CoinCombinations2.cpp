/*
 ▓█████▄  ▄████▄  ▓██   ██▓ ██▓███   ██░ ██ ▓█████  ██▀███
▒██▀ ██▌▒██▀ ▀█   ▒██  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒
 ░██   █▌▒▓█    ▄   ▒██ ██░▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒
 ░▓█▄   ▌▒▓▓▄ ▄██▒  ░ ▐██▓░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀▀█▄
 ░▒████▓ ▒ ▓███▀ ░  ░ ██▒▓░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒
  ▒▒▓  ▒ ░ ░▒ ▒  ░   ██▒▒▒ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒▓ ░▒▓░
  ░ ▒  ▒   ░  ▒    ▓██ ░▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░
  ░ ░  ░ ░         ▒ ▒ ░░  ░░        ░  ░░ ░   ░     ░░   ░
    ░    ░ ░       ░ ░               ░  ░  ░   ░  ░   ░
  ░      ░         ░ ░
*/
//focus less on how much problem you should solve within a fixed time and focus more on getting the problem solved and
//learning something from it
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>=b; i--)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vii vector <pair<ll,ll> >
#define sedes set <ll, greater <ll> >
#define seasc set <ll>
#define pb push_back
#define mkp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define umap unordered_map<ll, ll>
#define map map<ll, ll>
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define mems(a, i) memset(a, i, sizeof(a))
#define endl '\n'
#define all(v) v.begin(),v.end()
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define printx(x) printf("%lld\n",x);
#define printxy(x,y) cout << x << y <<endl;
#define printxyz(x,y,z) cout << x << y << z <<endl;
#define deba(a) cout << #a << a << endl;
#define debab(a,b) cout << #a << a << #b << b << endl;
// ll solve(ll n, ll a[], ll sum, ll i)
// {
// 	if (sum == 0)
// 		return 1;
// 	if (i >= n)
// 		return 0;
// 	ll ans = 0;
// 	if (a[i] <= sum)
// 	{
// 		ans = solve(n, a, sum, i + 1) + solve(n, a, sum - a[i], i);
// 	}
// 	return ans;
// }
int main()
{
	fast;
// #ifndef ONLINE_JUDGE
// 	freopen("/home/kushagra/Desktop/Work/input.txt", "r", stdin);
// 	freopen("/home/kushagra/Desktop/Work/output.txt", "w", stdout);
// #endif
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, sum;
		cin >> n >> sum;
		int a[n + 1];
		rep(i, 0, n)
		cin >> a[i];
		int dp[n + 1][sum + 1];
		// deba(a[0]);
		rep(i, 1, n + 1)
		{
			// deba(a[i - 1]);
			rep(j, 0, sum + 1)
			{
				if (j == 0)
					dp[i][j] = 1;
				else
				{
					ll op1 = (a[i - 1] > j) ? 0 : dp[i][j - a[i - 1]];
					ll op2 = (i == 1) ? 0 : dp[i - 1][j];
					dp[i][j] = ((op1) % MOD + (op2) % MOD) % MOD;
				}
				// cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		// cout << endl;
		cout << (dp[n][sum]) % MOD;
		// cout << solve(n, a, sum, 0);
	}
	return 0;
}