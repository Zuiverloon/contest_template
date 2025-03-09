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

bool ismark(ll label, ll offset)
{
    return (label & (1LL << offset)) == (1LL << offset);
}

ll mark(ll label, ll offset)
{
    label |= (1LL << offset);
    return label;
}

auto f(std::vector<ll> &v, ll i)
{
    ll l = 0, r = i;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] >= 0)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

void solve(int cas)
{
    ll n, m;
    std::cin >> n >> m;
    std::unordered_map<ll, std::unordered_map<ll, ll>> mp;
    std::unordered_map<ll, std::unordered_set<ll>> vis;
    auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2) -> bool
    {
        return a1[0] > a2[0];
    };
    std::queue<std::vector<ll>> pq;
    FOR(i, 0, m, 1)
    {
        ll u, v, w;
        std::cin >> u >> v >> w;
        mp[u][v] = w;
        mp[v][u] = w;
    }
    pq.push(std::vector<ll>{0LL, 1LL << 1, 1});
    vis[1].insert(1LL << 1);
    ll ans = LLONG_MAX;
    while (!pq.empty())
    {
        auto frt = pq.front();
        pq.pop();
        // printVector(frt);
        if (frt[2] == n)
        {
            ans = std::min({ans, frt[0]});
            continue;
        }
        for (auto next : mp[frt[2]])
        {
            if (!ismark(frt[1], next.first))
            {
                pq.push(std::vector<ll>{frt[0] ^ next.second, mark(frt[1], next.first), next.first});
                // vis[next.first].insert(mark(frt[1], next.first));
            }
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