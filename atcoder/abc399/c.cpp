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

void printYes()
{
    std::cout << "Yes\n";
}

void printNo()
{
    std::cout << "No\n";
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

std::unordered_map<ll, std::unordered_set<ll>> mp;
std::vector<bool> reach;

void dfs(ll n, ll fa, ll &node, ll &edge)
{
    reach[n] = true;
    node++;
    edge += mp[n].size();
    for (auto next : mp[n])
    {
        if (next != fa && !reach[next])
        {
            dfs(next, n, node, edge);
        }
    }
}

ll find(ll n)
{
    ll node = 0;
    ll edge = 0;
    dfs(n, -1, node, edge);
    // std::cout << "n node edge " << n << " " << node << " " << edge << "\n";
    return edge / 2 - (node - 1);
}

void solve(int cas)
{
    ll n, m;
    std::cin >> n >> m;
    reach = std::vector<bool>(n + 1, false);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!reach[i])
        {
            ll tans = 0;
            tans = find(i);
            // std::cout << "tans=" << tans << "\n";
            ans += tans;
        }
    }
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