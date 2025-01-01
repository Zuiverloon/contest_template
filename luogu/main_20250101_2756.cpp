/**
 *  https://www.luogu.com.cn/problem/P2756
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

void print(std::string s)
{
    printf("%s", s.c_str());
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

std::unordered_map<ll, std::unordered_set<ll>> rel;

std::vector<ll> mx;
std::vector<ll> my;
std::vector<bool> visy;

bool dfs(ll x)
{
    for (auto next : rel[x])
    {
        if (!visy[next])
        {
            visy[next] = true;
            if (my[next] == -1 || dfs(my[next]))
            {
                mx[x] = next;
                my[next] = x;
                return true;
            }
        }
    }
    return false;
}

void solve(int cas)
{
    ll m, n;
    std::cin >> m >> n;
    mx = std::vector<ll>(m + 1, -1);
    my = std::vector<ll>(n + 1, -1);
    visy = std::vector<bool>(n + 1, false);
    ll a, b;
    std::cin >> a >> b;
    while (a != -1 && b != -1)
    {
        rel[a].insert(b);
        // rel[b].insert(a);

        std::cin >> a >> b;
    }
    std::vector<ll> ans;
    for (int i = 1; i <= m; i++)
    {
        if (mx[i] == -1)
        {
            visy = std::vector<bool>(n + 1, false);
            if (dfs(i))
            {
                ans.push_back(i);
            }
        }
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " " << mx[ans[i]] << "\n";
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