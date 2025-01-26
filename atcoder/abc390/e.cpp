

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

template <typename T>
void print(T &s)
{
    std::cout << s << "\n";
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

ll valid(std::vector<std::vector<ll>> &v, ll l, ll r, ll tar)
{
    std::vector<ll> cost(5001, 0);
    for (ll i = l; i <= r; i++)
    {
        ll calo = v[i][1];
        ll vv = v[i][2];
        for (ll j = 5000; j >= 0; j--)
        {
            if (j - vv >= 0)
            {
                cost[j] = std::max(cost[j], cost[j - vv] + calo);
            }
        }
    }
    for (ll i = 0; i < 5001; i++)
    {
        if (cost[i] >= tar)
        {
            return i;
        }
    }
    return LLONG_MAX / 4;
}

void solve(int cas)
{
    ll n, x;
    std::cin >> n >> x;
    std::vector<std::vector<ll>> v(n, std::vector<ll>(3, 0));
    for (ll i = 0; i < n; i++)
    {
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    std::sort(v.begin(), v.end(), [&](std::vector<ll> &a1, std::vector<ll> &a2)
              { return a1[0] < a2[0]; });
    ll end1 = -1, end2 = -1;
    for (ll i = 0; i < n; i++)
    {
        if (v[i][0] == 1)
        {
            end1 = std::max(end1, i);
        }
        if (v[i][0] == 2)
        {
            end2 = std::max(end1, i);
        }
    }
    ll v1sum = 0, v2sum = 0, v3sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i][0] == 1)
        {
            v1sum += v[i][1];
        }
        if (v[i][0] == 2)
        {
            v2sum += v[i][1];
        }
        if (v[i][0] == 3)
        {
            v3sum += v[i][1];
        }
    }
    ll l = 0, r = std::min(v1sum, std::min(v2sum, v3sum));
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll x1 = valid(v, 0, end1, mid);
        ll x2 = valid(v, end1 + 1, end2, mid);
        ll x3 = valid(v, end2 + 1, n - 1, mid);
        // std::cout << mid << " " << x1 << " " << x2 << " " << x3 << "\n";
        if (x1 + x2 + x3 <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    print(ans);
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