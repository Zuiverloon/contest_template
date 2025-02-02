

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
    std::string s;
    std::cin >> s;
    std::string tmp = std::string(s);
    ll ans = 0;
    while (tmp.length() > 1)
    {
        std::string ntmp(tmp.size() / 3, '0');
        for (int i = 0; i < tmp.size(); i += 3)
        {
            ll t = tmp[i] - '0' + tmp[i + 1] - '0' + tmp[i + 2] - '0';
            if (t > 1)
            {
                ntmp[i / 3] = '1';
            }
        }
        tmp = ntmp;
        // std::cout << "tmp=" << tmp << "\n";
    }
    if (tmp[0] == '0')
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }
    // std::cout << "ans=" << ans << "\n";
    std::vector<std::vector<ll>> dp(s.size(), std::vector<ll>(2, 0));
    // dp[x][0] 0; dp[x][1] 1;
    for (int i = 0; i < s.size(); i++)
    {
        dp[i][0] = (s[i] == '0' ? 0 : 1);
        dp[i][1] = (s[i] == '1' ? 0 : 1);
    }
    for (int i = 0; i < n; i++)
    {
        std::vector<std::vector<ll>> ndp(dp.size() / 3, std::vector<ll>(2, LLONG_MAX));
        for (int j = 0; j < ndp.size(); j++)
        {
            ndp[j][0] = std::min(ndp[j][0], dp[j * 3][0] + dp[j * 3 + 1][0] + dp[j * 3 + 2][0]);
            ndp[j][0] = std::min(ndp[j][0], dp[j * 3][1] + dp[j * 3 + 1][0] + dp[j * 3 + 2][0]);
            ndp[j][0] = std::min(ndp[j][0], dp[j * 3][0] + dp[j * 3 + 1][1] + dp[j * 3 + 2][0]);
            ndp[j][0] = std::min(ndp[j][0], dp[j * 3][0] + dp[j * 3 + 1][0] + dp[j * 3 + 2][1]);

            ndp[j][1] = std::min(ndp[j][1], dp[j * 3][1] + dp[j * 3 + 1][1] + dp[j * 3 + 2][1]);
            ndp[j][1] = std::min(ndp[j][1], dp[j * 3][0] + dp[j * 3 + 1][1] + dp[j * 3 + 2][1]);
            ndp[j][1] = std::min(ndp[j][1], dp[j * 3][1] + dp[j * 3 + 1][0] + dp[j * 3 + 2][1]);
            ndp[j][1] = std::min(ndp[j][1], dp[j * 3][1] + dp[j * 3 + 1][1] + dp[j * 3 + 2][0]);
        }
        dp = ndp;
    }
    // std::cout << "dpsize " << dp.size() << "\n";
    if (ans == 1)
    {
        std::cout << dp[0][0] << "\n";
    }
    else
    {
        std::cout << dp[0][1] << "\n";
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