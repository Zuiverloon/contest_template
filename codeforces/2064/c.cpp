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
    std::vector<ll> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    std::vector<ll> left(n, 0);
    std::vector<ll> right(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            left[i] = i - 1 < 0 ? 0 : left[i - 1];
        }
        else
        {
            left[i] = v[i] + (i - 1 < 0 ? 0 : left[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] > 0)
        {
            right[i] = i + 1 >= n ? 0 : right[i + 1];
        }
        else
        {
            right[i] = std::abs(v[i]) + (i + 1 >= n ? 0 : right[i + 1]);
        }
    }
    // printVector(left);
    // printVector(right);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            ans = std::max(ans, left[i] + (i + 1 >= n ? 0 : right[i + 1]));
        }
        else
        {
            ans = std::max(ans, (i - 1 < 0 ? 0 : left[i - 1]) + right[i]);
        }
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
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}