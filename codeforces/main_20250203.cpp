/**
 * https://codeforces.com/problemset/problem/1996/C
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

void f(std::string &s, std::vector<std::vector<ll>> &dp)
{

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i + 1][j] = dp[i][j];
        }
        dp[i + 1][s[i] - 'a']++;
    }
}

ll diff(std::vector<ll> &s1l, std::vector<ll> &s1r, std::vector<ll> &s2l, std::vector<ll> &s2r)
{

    ll ans = 0;
    for (int i = 0; i < s1r.size(); i++)
    {
        ans += std::abs((s1r[i] - s1l[i]) - (s2r[i] - s2l[i]));
    }
    return ans / 2;
}

void solve(int cas)
{
    ll n, q;
    std::cin >> n >> q;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<std::vector<ll>> dp1(n + 1, std::vector<ll>(26, 0));
    std::vector<std::vector<ll>> dp2(n + 1, std::vector<ll>(26, 0));
    f(s1, dp1);
    f(s2, dp2);
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        std::cin >> l >> r;
        std::
                cout
            << diff(dp1[l - 1], dp1[r], dp2[l - 1], dp2[r]) << "\n";
    }
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