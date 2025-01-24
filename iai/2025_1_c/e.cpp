
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

void print(int t)
{
    printf("%d\n", t);
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

std::vector<ll> sgtree;

ll get(ll lb, ll rb, ll l, ll r, ll o)
{
    if (l > rb || r < lb)
    {
        return LLONG_MAX;
    }
    if (l <= lb && r >= rb)
    {
        return sgtree[o];
    }
    ll mid = (lb + rb) / 2;
    ll tans = LLONG_MAX;
    if (l <= mid)
    {
        tans = std::min(tans, get(lb, mid, l, r, o * 2 + 1));
    }
    if (r > mid)
    {
        tans = std::min(tans, get(mid + 1, rb, l, r, o * 2 + 2));
    }
    return tans;
}

void update(ll lb, ll rb, ll pos, ll val, ll o)
{
    if (pos < lb || pos > rb)
    {
        return;
    }
    if (lb == rb && lb == pos)
    {
        sgtree[o] = val;
        return;
    }
    ll mid = (lb + rb) / 2;
    if (pos <= mid)
    {
        update(lb, mid, pos, val, o * 2 + 1);
    }
    else
    {
        update(mid + 1, rb, pos, val, o * 2 + 2);
    }
    sgtree[o] = std::min(sgtree[o * 2 + 1], sgtree[o * 2 + 2]);
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    std::vector<ll> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    sgtree = std::vector<ll>(4 * (n + 1) + 100, LLONG_MAX);
    std::vector<ll> ans(n + 1, LLONG_MAX / 2);
    ans[n] = 0;
    ll offset = 10000000;
    update(0, n, n, ((0LL + offset) << 32LL) + n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        ll start = i + v[i] + 1;
        if (start <= n)
        {
            ll qv = get(0, n, start, n, 0);
            ll pos = qv & 0xffffffff;
            // std::cout << "pos " << pos << " " << (qv >> 32) << "\n";
            ans[i] = std::min(ans[i], ans[pos] + pos - start);
        }
        ans[i] = std::min(ans[i], 1 + ans[i + 1]);
        // std::cout << i << " " << ans[i] << "\n";
        update(0, n, i, ((ans[i] + offset) << 32) + i, 0);
        // std::cout << "update " << i << " " << ((ans[i] + offset)) << " " << i << "\n";
        offset--;
    }
    print(ans[0]);
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