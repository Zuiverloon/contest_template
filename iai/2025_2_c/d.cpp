

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

ll group = 0;
std::vector<ll> fa;

ll get(ll a)
{
    if (fa[a] != a)
    {
        fa[a] = get(fa[a]);
    }
    return fa[a];
}

void merge(ll a, ll b)
{
    fa[get(a)] = get(b);
}

void dfs(std::vector<std::vector<ll>> &v, std::vector<ll> &id, ll pos, ll &group, bool first)
{
    if (v[0][pos] == v[1][pos])
    {
        group++;
        return;
    }

    if (get(v[0][pos]) == get(v[1][pos]))
    {
        return;
    }
    if (first)
        group++;
    merge(v[0][pos], v[1][pos]);
    dfs(v, id, id[v[1][pos]], group, false);
}
ll pow(ll n)
{
    if (n == 1)
    {
        return 2;
    }
    if (n == 0)
        return 1;
    ll next = pow(n / 2);
    ll ans = next;
    next *= next;
    next %= mod1e9;
    if (n % 2 == 1)
    {
        return (next * 2) % mod1e9;
    }
    return next;
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    group = 0;
    fa = std::vector<ll>(n + 1, 0);
    for (int i = 0; i < fa.size(); i++)
    {
        fa[i] = i;
    }
    std::vector<std::vector<ll>> v(2, std::vector<ll>(n, 0));
    std::vector<ll> id(n + 1, 0);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> v[i][j];
            if (i == 0)
            {
                id[v[i][j]] = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // if (v[0][i] == v[1][i])
        // {
        // 	group++;
        // 	continue;
        // }
        dfs(v, id, i, group, true);
    }

    std::cout << pow(group) << "\n";
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