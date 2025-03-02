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

void solve(int cas)
{
    ll n, m, x;
    std::cin >> n >> m >> x;
    std::unordered_map<ll, std::unordered_set<ll>> mp;
    std::unordered_map<ll, std::unordered_set<ll>> revmp;
    std::vector<ll> mdis(n + 1, LLONG_MAX / 2);
    std::vector<ll> rmdis(n + 1, LLONG_MAX / 2);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        std::cin >> u >> v;
        mp[u].insert(v);
        revmp[v].insert(u);
    }
    auto cmp = [&](std::vector<ll> &v1, std::vector<ll> &v2)
    {
        return v1[2] > v2[2];
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & v1, std::vector<ll> & v2)>>
        pq(cmp);
    pq.push(std::vector<ll>{1, 0, 0});
    pq.push(std::vector<ll>{1, 1, x});
    ll ans = 0;

    while (!pq.empty())
    {
        auto f = pq.top();
        pq.pop();
        // printVector(f);
        if (f[0] == n)
        {
            ans = f[2];
            break;
        }
        ll newdis = f[2] + 1;
        for (auto next : (f[1] == 0 ? mp[f[0]] : revmp[f[0]]))
        {
            if (f[1] == 0 && mdis[next] > newdis)
            {
                mdis[next] = newdis;

                pq.push(std::vector<ll>{next, f[1], newdis});
            }
            if (f[1] == 1 && rmdis[next] > newdis)
            {
                rmdis[next] = newdis;
                pq.push(std::vector<ll>{next, f[1], newdis});
            }
        }
        if (f[1] == 0 && f[2] + x < rmdis[f[0]])
        {
            rmdis[f[0]] = f[2] + x;
            pq.push(std::vector<ll>{f[0], 1, f[2] + x});
        }
        if (f[1] == 1 && f[2] + x < mdis[f[0]])
        {
            mdis[f[0]] = f[2] + x;
            pq.push(std::vector<ll>{f[0], 0, f[2] + x});
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