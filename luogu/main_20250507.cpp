/**
 * https://www.luogu.com.cn/problem/P2513
 *
 */

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

/***     dsu template           */
vector<ll> fa;

ll get(ll i)
{
    if (fa[i] != i)
    {
        fa[i] = get(fa[i]);
    }
    return fa[i];
}

void merge(ll a, ll b)
{
    fa[get(b)] = get(a);
}

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

vector<vector<ll>> dp;

ll dfs(ll n, ll k)
{
    if (k < 0)
        return 0;
    if (dp[n][k] >= 0)
        return dp[n][k];
    if (n == 1)
    {
        if (k == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    ll tans = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (k - n + 1 + i < 0)
            break;
        tans += dfs(n - 1, k - (n - 1 - i));
        tans %= 10000LL;
    }
    dp[n][k] = tans;
    return tans;
}

void solve(int cas)
{
    ll n, k;
    cin >> n >> k;
    dp = vector<vector<ll>>(n + 1, vector<ll>(k + 1, 0));
    vector<ll> presum(k + 1, 0);
    dp[1][0] = 1;
    presum[0] = 1;
    for (ll i = 1; i <= k; i++)
    {
        presum[i] = presum[i - 1] + dp[0][i];
    }
    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (ll j = 1; j <= k; j++)
        {
            ll mn = max(0LL, j - i + 1);
            ll mx = j;
            dp[i][j] = presum[mx] - (mn == 0 ? 0 : presum[mn - 1]) + 10000;
            dp[i][j] %= 10000;
        }
        for (ll j = 0; j <= k; j++)
        {
            presum[j] = (j == 0 ? 0 : presum[j - 1]) + dp[i][j];
            presum[j] %= 10000;
        }
    }
    cout << dp[n][k] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // initmobelong();

    int n = 1;
    // std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}
