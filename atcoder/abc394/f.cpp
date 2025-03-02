
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

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;

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

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

ll ans = -1;
std::vector<std::unordered_set<ll>> v;
std::vector<ll> dp;

ll dfs(ll o, ll f)
{
    // std::cout << "o f " << o << " " << f << "\n";
    if (dp[o] != -1)
    {
        return dp[o];
    }
    // ll tans = 1;
    std::vector<ll> nxt;
    for (ll next : v[o])
    {
        if (next != f)
        {
            nxt.push_back(dfs(next, o));
        }
    }
    std::sort(nxt.begin(), nxt.end(), std::greater<ll>());
    if (nxt.size() < 1)
    {
        dp[o] = 1;
        return dp[o];
    }
    else if (nxt.size() < 3)
    {
        ans = std::max(ans, 1 + nxt[0]);
        dp[o] = 1;
        return dp[o];
    }
    else if (nxt.size() < 4)
    {
        dp[o] = 1 + nxt[0] + nxt[1] + nxt[2];
        return dp[o];
    }
    else
    {
        dp[o] = 1 + nxt[0] + nxt[1] + nxt[2];

        ans = std::max(ans, 1 + nxt[0] + nxt[1] + nxt[2] + nxt[3]);
        return dp[o];
    }
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    v = std::vector<std::unordered_set<ll>>(n + 1, std::unordered_set<ll>());
    dp = std::vector<ll>(n + 1, -1);
    bool valid = false;
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
        if (v[a].size() >= 4 || v[b].size() >= 4)
        {
            valid = true;
        }
    }
    if (!valid)
    {
        std::cout << "-1\n";
        return;
    }
    dfs(1, -1);
    std::cout << ans << "\n";
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