

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

ll bs(std::vector<ll> &v, ll right, ll val)
{
    ll ans = right + 1;
    ll l = 1, r = right;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] >= val)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

ll bs1(std::vector<ll> &v, ll right, ll val)
{
    ll ans = right + 1;
    ll l = 1, r = right;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] > val)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

void solve(int cas)
{
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> v[i];
    }
    std::vector<ll> dp(n + 1, 0x3f3f3f3f);
    std::unordered_map<ll, std::vector<std::vector<ll>>> mp;
    for (int i = 0; i < q; i++)
    {
        ll r, x;
        std::cin >> r >> x;
        mp[r].push_back(std::vector<ll>{x, i});
    }
    std::vector<ll> ans(q, 0);
    for (int i = 1; i <= n; i++)
    {
        ll pos = bs(dp, n, v[i]);
        // std::cout << i << " " << pos << "\n";
        dp[pos] = v[i];
        for (auto p : mp[i])
        {
            ans[p[1]] = bs1(dp, i, p[0]) - 1;
        }
    }
    for (ll i : ans)
    {
        std::cout << i << "\n";
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