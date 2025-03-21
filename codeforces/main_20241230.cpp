/**
 * https://codeforces.com/problemset/problem/2033/D
 */

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

// g++ main.cpp -o main

ll mod1e9 = 1e9 + 7;
ll mod998 = 998244353;
ll modboj = 987654321LL;

void print(ll t)
{
    printf("%lld\n", t);
}

void print(std::string s)
{
    printf("%s", s.c_str());
}

void printVector(std::vector<ll> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%lld%c", v[i], " \n"[i == v.size() - 1]);
    }
}

void printVector(std::vector<std::string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%s%c", v[i].c_str(), " \n"[i == v.size() - 1]);
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
    scanf("%lld", &n);
    std::vector<ll> v(n, 0);
    ll presum = 0;
    std::vector<ll> dp(n + 1, 0);
    std::map<ll, ll> mp;
    ll ans = 0;
    mp[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &v[i]);
        presum += v[i];
        if (mp.find(presum) == mp.end())
        {
            // printf("%lld Not found\n", v[i]);
            //  mp[presum] += 1;
            //  ans = std::max(ans, mp[presum]);
            dp[i + 1] = std::max(dp[i], mp[presum]);
            mp[presum] = dp[i + 1];
            // ans = std::max(ans, dp[i + 1]);
        }
        else
        {
            dp[i + 1] = std::max(dp[i], mp[presum] + 1);
            mp[presum] = dp[i + 1];
            // ans = std::max(ans, dp[i + 1]);
        }
    }
    // printVector(dp);
    print(dp[n]);
}

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
    // print(1LL << 40);
    // initmobelong();

    int n = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}