// https://codeforces.com/problemset/problem/2114/D

#include <functional> //c++17 function
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cctype>
#include <chrono>
#include <utility>
#include <list>
#include <stdio.h>
#include <iostream>

// #include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;
ll mod1e8 = 100000000LL - 3;

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void printVector(std::vector<ll> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " \n"[i == v.size() - 1];
        // printf("%lld%c", v[i], " \n"[i == v.size() - 1]);
    }
}

void printVector(std::vector<std::string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " \n"[i == v.size() - 1];
        // printf("%s%c", v[i].c_str(), " \n"[i == v.size() - 1]);
    }
}

template <typename T>
void printMatrix(std::vector<std::vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printVector(v[i]);
    }
}

template <typename T>
bool isinset(std::set<T> &s, T n) // 判断是否在set内
{
    return s.find(n) != s.end();
}

template <typename T>
bool isinset(std::unordered_set<T> &s, T n) // 判断是否在set内
{
    return s.find(n) != s.end();
}

void ppqq()
{
    // 	auto cmp = [](int a, int b) -> bool
    // 	{ return a < b; };
    // 	std::priority_queue<int, std::vector<int>, std::function<bool(int a, int b)>> q(cmp);
}

ll lowbit(ll a)
{
    return a & (-a);
}

ll highbit(ll a)
{
    ll lb = lowbit(a);
    while (lb != a)
    {
        a -= lb;
        lb = lowbit(a);
    }
    return lb;
}

ll countone(ll a)
{
    ll ans = 0;
    while (a > 0)
    {
        ans += (a & 1);
        a >>= 1;
    }
    return ans;
}

// get multipliactive inverse by euclid method
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

// get multiplicative inverse by quick power
// ax = 1(mod b)
// x = a**(b-2) mod b
ll qpow(ll a, ll b)
{
    ll ans = 1;
    ll mod = b;
    b -= 2;
    a = (a % mod + mod) % mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (a * ans) % mod;
        a = (a * a) % mod;
    }
    return ans;
}

/***     dsu template           */
// vector<ll> fa;

// ll get(ll i)
// {
// 	if (fa[i] != i)
// 	{
// 		fa[i] = get(fa[i]);
// 	}
// 	return fa[i];
// }

// void merge(ll a, ll b)
// {
// 	fa[get(b)] = get(a);
// }

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

// vector<ll> ft;
// void add(ll i, ll x)
// {
// 	while (i < ft.size())
// 	{
// 		ft[i] += x;
// 		i += lowbit(i);
// 	}
// }

// ll get(ll i)
// {
// 	ll ans = 0;
// 	while (i > 0)
// 	{
// 		ans += ft[i];
// 		i -= lowbit(i);
// 	}
// 	return ans;
// }

ll getmin(vector<vector<ll>> &mn, ll l, ll r)
{
    if (r < l)
    {
        return mod1e9;
    }
    ll len = r - l + 1;
    ll base = 24;
    ll bit = 1LL << 24;
    ll ans = mod1e9;
    while (len > 0)
    {
        // cout << l << " getmin " << len << "\n";

        if ((len & bit) == bit)
        {
            // cout << l << " getminfound " << len << " " << base << " " << bit << "\n";

            ans = min(ans, mn[l][base]);
            len -= bit;
            l += bit;
        }
        bit >>= 1;
        base--;
    }
    return ans;
}

ll getmax(vector<vector<ll>> &mn, ll l, ll r)
{
    if (r < l)
    {
        return 0;
    }
    ll len = r - l + 1;
    ll base = 24;
    ll bit = 1LL << 24;
    ll ans = 0;
    while (len > 0)
    {
        // cout << l << " getmax " << len << "\n";
        if ((len & bit) == bit)
        {
            // cout << l << " getmaxfound " << len << " " << base << " " << bit << "\n";
            ans = max(ans, mn[l][base]);
            len -= bit;
            l += bit;
        }
        bit >>= 1;
        base--;
    }
    return ans;
}

void solve(int cas)
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(2, 0));
    vector<vector<ll>> min1(n, vector<ll>(25, 0));
    vector<vector<ll>> min2(n, vector<ll>(25, 0));
    vector<vector<ll>> max1(n, vector<ll>(25, 0));
    vector<vector<ll>> max2(n, vector<ll>(25, 0));
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        min1[i][0] = v[i][0];
        max1[i][0] = v[i][0];
        min2[i][0] = v[i][1];
        max2[i][0] = v[i][1];
    }
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    for (ll j = 1; j < 25; j++)
    {
        ll offset = 1 << (j - 1);
        for (ll i = 0; i < n; i++)
        {
            if (i + offset + offset > n)
            {
                break;
            }
            min1[i][j] = min(min1[i][j - 1], min1[i + offset][j - 1]);
            min2[i][j] = min(min2[i][j - 1], min2[i + offset][j - 1]);
            max1[i][j] = max(max1[i][j - 1], max1[i + offset][j - 1]);
            max2[i][j] = max(max2[i][j - 1], max2[i + offset][j - 1]);
            // cout << i << " " << j << " " << min1[i][j] << " " << max1[i][j] << " " << min2[i][j] << " " << max2[i][j] << "\n";
        }
    }
    ll ans;
    ll mn1 = getmin(min1, 0, n - 1);
    ll mx1 = getmax(max1, 0, n - 1);
    ll mn2 = getmin(min2, 0, n - 1);
    ll mx2 = getmax(max2, 0, n - 1);
    ans = (abs(mn1 - mx1) + 1) * (abs(mn2 - mx2) + 1);
    // cout
    // 	<< "tm\n";
    for (ll i = 0; i < n; i++)
    {
        // remove point[i]
        ll mn1 = min(getmin(min1, 0, i - 1), getmin(min1, i + 1, n - 1));
        ll mx1 = max(getmax(max1, 0, i - 1), getmax(max1, i + 1, n - 1));
        ll mn2 = min(getmin(min2, 0, i - 1), getmin(min2, i + 1, n - 1));
        ll mx2 = max(getmax(max2, 0, i - 1), getmax(max2, i + 1, n - 1));
        ll a1 = abs(mn1 - mx1) + 1;
        ll a2 = abs(mn2 - mx2) + 1;
        // cout << "a1 a2 " << a1 << " " << a2 << "\n";
        ll tans = a1 * a2;
        if (a1 * a2 == n - 1)
        {
            tans += min(a1, a2);
        }
        ans = min(ans, tans);
    }
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // initmobelong();

    int n = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}
