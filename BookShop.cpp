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
// // ll dp[10001][100001];
// ll solve(ll p[], ll pg[], ll n, ll x, vector<vector<int>> dp)
// {
// 	if (n == 0 or x == 0)
// 		return 0;
// 	// ll ans,op1,op2;
// 	if (dp[n][x] != -1)
// 		return dp[n][x];
// 	if (p[n - 1] <= x)
// 		return dp[n][x] = max(pg[n - 1] + solve(p, pg, n - 1, x - p[n - 1], dp),
// 		                      solve(p, pg, n - 1, x, dp));
// 	else
// 		return dp[n][x] = (solve(p, pg, n - 1, x, dp));

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
		int n, x;
		cin >> n >> x;
		int p[n];
		rep(i, 0, n)
		cin >> p[i];
		// vector<vector<int>> dp( n + 1 , vector<int> (x + 1, -1));
		int pg[n];
		rep(i, 0, n)
		cin >> pg[i];
		// mems(dp, -1);
		// cout << solve(p, pg, n, x, dp);

		// int dp[n + 1][x + 1];
		vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

		// mems(dp, 0);
		rep(i, 0, x + 1)
		dp[0][i] = 0;

		rep(i, 0, n + 1)
		dp[i][0] = 0;

		rep(i, 1, n + 1)
		{
			rep(j, 0, x + 1)
			{
				if (p[i - 1] <= j)
				{
					dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - p[i - 1]] + pg[i - 1]);
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[n][x];

	}
	return 0;
}