/**
 * https://www.luogu.com.cn/problem/P3379
 * 倍增LCA模版
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

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;

void print(ll t)
{
    printf("%lld\n", t);
}

void print(std::string s)
{
    printf("%s", s.c_str());
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

std::vector<std::unordered_set<ll>> mp;
std::vector<std::vector<ll>> fa;
std::vector<ll> dep;
ll lay = 22;

void dfs(ll o, ll f)
{
    dep[o] = dep[f] + 1;
    fa[o][0] = f;
    for (int i = 1; i < lay; i++)
    {
        fa[o][i] = fa[fa[o][i - 1]][i - 1];
    }
    for (auto ne : mp[o])
    {
        if (ne != f)
            dfs(ne, o);
    }
}

ll lca(ll a, ll b)
{
    if (dep[a] < dep[b])
    {
        return lca(b, a);
    }
    ll gap = dep[a] - dep[b];
    ll base = 0;
    while (gap > 0)
    {
        if ((gap & 1) == 1)
        {
            a = fa[a][base];
        }
        gap >>= 1;
        base += 1;
    }
    if (a == b)
    {
        return a;
    }
    for (int i = lay - 1; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return a == b ? a : fa[a][0];
}

void solve(int cas)
{
    ll n, m, s;
    std::cin >> n >> m >> s;
    fa = std::vector<std::vector<ll>>(n + 1, std::vector<ll>(lay, 0));
    dep = std::vector<ll>(n + 1, 0);

    mp = std::vector<std::unordered_set<ll>>(n + 1, std::unordered_set<ll>());
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    dfs(s, 0);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        ll ans = lca(a, b);
        print(ans);
        // std::cout << "ans=" << ans << "\n";
    }
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