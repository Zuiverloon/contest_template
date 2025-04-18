

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

template <typename T>
void print(T &s)
{
    std::cout << s << "\n";
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

std::unordered_set<ll> st;
std::vector<ll> v;
std::vector<ll> ans;

void dfs(ll offset, ll bag, ll tans)
{
    if (offset == 0)
    {
        ans[0] += v[offset];
        tans ^= ans[0];
        dfs(1, 1, tans);
        return;
    }
    if (offset == v.size())
    {
        st.insert(tans);
        return;
    }
    for (int i = 0; i < bag; i++)
    {
        tans ^= ans[i];
        ans[i] += v[offset];
        tans ^= ans[i];
        dfs(offset + 1, bag, tans);
        tans ^= ans[i];
        ans[i] -= v[offset];
        tans ^= ans[i];
    }
    ans[bag] += v[offset];
    tans ^= v[offset];
    dfs(offset + 1, bag + 1, tans);
    ans[bag] -= v[offset];
    tans ^= v[offset];
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    v = std::vector<ll>(n, 0);
    ans = std::vector<ll>(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    dfs(0, 0, 0);
    // std::cout << "prestart prefix " << prestart << " " << prefix << "\n";
    ll ans = st.size();
    print(ans);
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