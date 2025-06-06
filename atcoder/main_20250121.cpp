/**
 * https://atcoder.jp/contests/abc376/tasks/abc376_e
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

void print(ll t)
{
    printf("%lld\n", t);
}

void print(std::string &s)
{
    printf("%s\n", s.c_str());
}

void print(char *s)
{
    printf("%s\n", s);
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

void solve(int cas)
{
    ll n, k;
    std::cin >> n >> k;
    std::vector<std::vector<ll>> v(n, std::vector<ll>(2, 0));
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i][1];
    }
    std::sort(v.begin(), v.end(), [&](std::vector<ll> &a1, std::vector<ll> &a2)
              { return a1[0] < a2[0]; });
    auto cmp = std::less<ll>();
    ll tsum = 0;
    ll ans = LLONG_MAX / 2;
    std::priority_queue<ll, std::vector<ll>, std::function<bool(ll, ll)>> pq(cmp);
    for (int i = 0; i < k - 1; i++)
    {
        pq.push(v[i][1]);
        tsum += v[i][1];
    }
    for (int i = k - 1; i < n; i++)
    {
        if (pq.size() == k)
        {
            if (v[i][1] < pq.top())
            {
                tsum -= pq.top();
                tsum += v[i][1];
                pq.pop();
                pq.push(v[i][1]);
            }
        }
        else
        {
            pq.push(v[i][1]);
            tsum += v[i][1];
        }
        ans = std::min(ans, v[i][0] * tsum);
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
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}