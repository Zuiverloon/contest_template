/**
 * https://codeforces.com/problemset/problem/1923/C
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
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> v(n + 1, 0);
    std::vector<ll> pre(n + 1, 0);
    std::vector<ll> ones(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll t;
        std::cin >> t;
        v[i] += t;
        pre[i] = pre[i - 1];
        pre[i] += v[i];
        ones[i] = ones[i - 1];
        if (t == 1)
        {
            ones[i]++;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        ll l, r;
        std::cin >> l >> r;
        if (l == r)
        {
            print("NO");
            continue;
        }
        ll sm = pre[r] - pre[l - 1];
        ll onecount = ones[r] - ones[l - 1];

        if (sm - onecount * 2 < r - l + 1 - onecount)
        {
            print("NO");
            continue;
        }
        else
        {
            print("YES");
            continue;
        }
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