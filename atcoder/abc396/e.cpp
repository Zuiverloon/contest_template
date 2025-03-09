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

std::unordered_map<ll, std::unordered_set<ll>> dsump;
std::unordered_map<ll, std::unordered_map<ll, ll>> mp;
std::vector<bool> vis;
std::vector<ll> val;

void init()
{
    dsump.clear();
    mp.clear();
}

bool bfs(ll start, ll cur)
{
    if (!vis[cur])
    {
        dsump[start].insert(cur);
    }
    else
    {
        return true;
    }
    vis[cur] = true;
    for (auto next : mp[cur])
    {
        if (vis[next.first] && val[next.first] == (val[cur] ^ next.second))
        {
            continue;
        }
        if (vis[next.first] && val[next.first] != (val[cur] ^ next.second))
        {
            return false;
        }
        val[next.first] = (val[cur] ^ next.second);
        bool tmp = bfs(start, next.first);
        if (!tmp)
            return false;
    }
    return true;
}

void solve(int cas)
{
    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> x(m, 0);
    std::vector<ll> y(m, 0);
    std::vector<ll> z(m, 0);

    init();

    for (int i = 0; i < m; i++)
    {
        std::cin >> x[i] >> y[i] >> z[i];
    }
    // printVector(x);
    // printVector(y);
    for (int i = 0; i < m; i++)
    {
        ll zt = z[i];
        ll xt = x[i];
        ll yt = y[i];
        mp[xt][yt] = zt;
        mp[yt][xt] = zt;
    }

    vis = std::vector<bool>(n + 1, false);
    val = std::vector<ll>(n + 1, 0);
    std::vector<ll> ans(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool tmp = bfs(i, i);
            if (!tmp)
            {
                std::cout << "-1\n";
                return;
            }
            std::unordered_set<ll> group = dsump[i];
            // std::cout << "group size " << group.size() << "\n";
            for (ll off = 0; off < 32; off++)
            {
                ll cnt = 0;
                for (ll g : group)
                {
                    // std::cout << "val[g] " << g << " " << val[g] << "\n";
                    if ((val[g] & (1 << off)) == (1 << off))
                    {
                        cnt += 1;
                    }
                }
                ll bit = 0;
                if (cnt > group.size() - cnt)
                {
                    bit = 1;
                }
                for (ll g : group)
                {
                    ans[g] |= (bit << off) ^ (val[g] & (1 << off));
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        std::cout << ans[i] << " \n"[i == n];
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