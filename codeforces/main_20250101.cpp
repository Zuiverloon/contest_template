/**
 * https://codeforces.com/contest/2009/problem/F
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

ll f(ll l, ll r, ll shift, std::vector<ll> &ps)
{
    l += shift;
    r += shift;
    l %= (ps.size() - 1);
    r %= (ps.size() - 1);
    if (l > r)
    {
        return ps[r + 1] + ps[ps.size() - 1] - ps[l];
    }
    else
    {
        return ps[r + 1] - ps[l];
    }
}

void solve(int cas)
{
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> v(n, 0);
    std::vector<ll> ps(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
        ps[i + 1] = ps[i] + v[i];
    }
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        std::cin >> l >> r;
        l--;
        r--;
        ll c1 = l / n;
        ll s1 = l % n;
        ll c2 = r / n;
        ll s2 = r % n;
        print(f(s1, n - 1, c1, ps) + f(0, s2, c2, ps) + ps[n] * (c2 - c1 - 1));
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