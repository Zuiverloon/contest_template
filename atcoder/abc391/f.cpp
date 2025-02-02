

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
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> a(n, 0);
    std::vector<ll> b(n, 0);
    std::vector<ll> c(n, 0);
    std::unordered_map<ll, std::unordered_map<ll, std::unordered_map<ll, ll>>> mp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());
    auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2)
    {
        return a1[0] < a2[0];
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & a, std::vector<ll> & b)>>
        pq(cmp);
    pq.push(std::vector<ll>{a[n - 1] * b[n - 1] + b[n - 1] * c[n - 1] + c[n - 1] * a[n - 1], n - 1, n - 1, n - 1});
    mp[n - 1][n - 1][n - 1] = 1;
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        std::vector<ll> fr = pq.top();
        // printVector(fr);
        pq.pop();
        ans = fr[0];
        ll
            a1 = fr[1],
            a2 = fr[2], a3 = fr[3];
        if (a1 > 0)
        {
            a1--;
            if (mp[a1][a2][a3] != 1)
            {
                pq.push(std::vector<ll>{a[a1] * b[a2] + b[a2] * c[a3] + a[a1] * c[a3], a1, a2, a3});
                mp[a1][a2][a3] = 1;
            }
            a1++;
        }
        if (a2 > 0)
        {
            a2--;
            if (mp[a1][a2][a3] != 1)
            {
                pq.push(std::vector<ll>{a[a1] * b[a2] + b[a2] * c[a3] + a[a1] * c[a3], a1, a2, a3});
                mp[a1][a2][a3] = 1;
            }
            a2++;
        }
        if (a3 > 0)
        {
            a3--;
            if (mp[a1][a2][a3] != 1)
            {
                pq.push(std::vector<ll>{a[a1] * b[a2] + b[a2] * c[a3] + a[a1] * c[a3], a1, a2, a3});
                mp[a1][a2][a3] = 1;
            }
            a3++;
        }
        // std::cout << ans << "\n";
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