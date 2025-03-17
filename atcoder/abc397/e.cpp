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

void solve(int cas)
{
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> degree(n * k + 1, 0);
    std::vector<ll> le(n * k + 1, 1);
    std::vector<ll> sub(n * k + 1, 0);
    std::vector<std::unordered_set<ll>> nei(n * k + 1, std::unordered_set<ll>());
    for (int i = 0; i < n * k - 1; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        degree[a]++;
        degree[b]++;
        nei[a].insert(b);
        nei[b].insert(a);
    }
    if (n * k == 1)
    {
        std::cout << "Yes\n";
        return;
    }
    std::queue<ll> q;
    for (int i = 1; i < n * k + 1; i++)
    {
        if (degree[i] == 1)
        {
            q.push(i);
        }
    }
    ll path = 0;
    while (q.size() != 0)
    {
        ll ft = q.front();
        q.pop();
        // std::cout << "qft " << ft << "\n";
        if (le[ft] == k)
        {
            if (sub[ft] > 2)
            {
                std::cout << "No\n";
                return;
            }
            path++;
            for (auto t : nei[ft])
            {
                nei[t].erase(ft);
                degree[t]--;
                if (degree[t] == 1)
                {
                    q.push(t);
                }
            }
        }
        else if (le[ft] < k)
        {
            if (sub[ft] > 1)
            {
                std::cout << "No\n";
                return;
            }
            for (auto t : nei[ft])
            {
                nei[t].erase(ft);
                degree[t]--;
                le[t] += le[ft];
                sub[t]++;
                if (degree[t] == 1)
                {
                    q.push(t);
                }
            }
        }
        else if (le[ft] > k)
        {
            std::cout << "No\n";
            return;
        }
    }
    if (path == n)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
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