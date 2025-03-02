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
    ll n;
    std::cin >> n;
    std::vector<std::string> v(n, "");
    std::vector<std::unordered_map<char, std::vector<ll>>> vmp(n, std::unordered_map<char, std::vector<ll>>());
    std::vector<std::unordered_map<char, std::vector<ll>>> revmp(n, std::unordered_map<char, std::vector<ll>>());
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2)
    {
        return a1[2] > a2[2];
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & a1, std::vector<ll> & a2)>> pq(cmp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != '-')
            {
                vmp[i][v[i][j]].push_back(j);
                revmp[j][v[i][j]].push_back(i);
                pq.push(std::vector<ll>{i, j, 1});
                for (int k = 0; k < n; k++)
                {
                    if (v[j][k] == v[i][j])
                    {
                        pq.push(std::vector<ll>{i, k, 2});
                    }
                }
            }
        }
    }
    std::vector<std::vector<ll>> ans(n, std::vector<ll>(n, INT_MAX));
    while (pq.size() > 0)
    {
        auto pre = pq.top();
        ll i = pre[0];
        ll j = pre[1];
        ll curlen = pre[2];
        ans[i][j] = std::min(ans[i][j], curlen);
        pq.pop();
        for (char c = 'a'; c <= 'z'; c++)
        {
            std::vector<ll> v1 = revmp[i][c];
            std::vector<ll> v2 = vmp[j][c];
            if (v1.size() != 0 && v2.size() != 0)
            {
                for (ll a : v1)
                {
                    for (ll b : v2)
                    {
                        if (curlen + 2 < ans[a][b])
                        {
                            ans[a][b] = curlen + 2;
                            pq.push(std::vector<ll>{a, b, curlen + 2});
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == INT_MAX)
            {
                ans[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printVector(ans[i]);
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