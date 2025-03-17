/**
 * https://codeforces.com/problemset/problem/1900/C
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

ll highbit(ll a)
{
    ll lb = lowbit(a);
    while (lb != a)
    {
        a -= lb;
        lb = lowbit(a);
    }
    return lb;
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

std::vector<ll> s;
std::vector<ll> l;
std::vector<ll> r;

ll ans = LLONG_MAX / 2;

void dfs(ll o, ll step)
{
    // std::cout << "o step " << o << " " << step << "\n";
    if (l[o] == 0 && r[o] == 0)
    {
        ans = std::min({ans, step});
        return;
    }
    if (l[o] != 0)
    {
        dfs(l[o], step + (s[o] == 1 ? 0 : 1));
    }
    if (r[o] != 0)
    {
        dfs(r[o], step + (s[o] == 2 ? 0 : 1));
    }
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    ans = LLONG_MAX / 2;
    s = std::vector<ll>(n + 1, 0);
    l = std::vector<ll>(n + 1, 0);
    r = std::vector<ll>(n + 1, 0);
    FOR(i, 1, n + 1, 1)
    {
        if (str[i - 1] == 'L')
        {
            s[i] = 1;
        }
        else if (str[i - 1] == 'R')
        {
            s[i] = 2;
        }
    }
    FOR(i, 1, n + 1, 1)
    {
        std::cin >> l[i] >> r[i];
    }
    dfs(1, 0);
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