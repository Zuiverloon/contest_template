
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
using namespace std;

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
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

ll countone(ll a)
{
    ll ans = 0;
    while (a > 0)
    {
        ans += (a & 1);
        a >>= 1;
    }
    return ans;
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
vector<vector<ll>> v;
vector<set<ll>> tv;
vector<set<ll>> tva;
vector<ll> tm;
ll ans = 0 - 1;
ll n = 0;
ll m = 0;

void dfs(ll i, ll j, ll tans, ll remain)
{
    // cout << i << " " << j << " " << tans << "\n";
    tans *= 10LL;
    tans += v[i][j];
    tans %= m;
    if (remain == 1)
    {
        // cout << j << " remain1 " << ((tans * tm[n - 1])) % m << "\n";
        tv[i].insert(((tans * tm[n - 1])) % m);
    }
    else
    {
        dfs(i + 1, j, tans, remain - 1);
        dfs(i, j + 1, tans, remain - 1);
    }
}

void dfs1(ll i, ll j, ll tans, ll remain)
{
    tans += (v[i][j] * tm[n - remain - 1]);
    tans %= m;
    if (remain == 1)
    {
        ll tar = m - tans;
        tva[i - 1].insert(tar);
        tva[i].insert(tar);
    }
    else
    {
        dfs1(i - 1, j, tans, remain - 1);
        dfs1(i, j - 1, tans, remain - 1);
    }
}

void f(vector<ll> &v1, vector<ll> &v2)
{
    ll t1 = 0, t2 = 0;
    while (t1 < v1.size() && t2 < v2.size())
    {
        if (v1[t1] < v2[t2])
        {
            ans = max({ans, (m + v1[t1] - v2[t2]) % m});
            t1++;
        }
        else if (v1[t1] > v2[t2])
        {
            ans = max({ans, (m + v1[t1] - v2[t2]) % m});
            t2++;
        }
        else
        {
            ans = max({ans, (m + v1[t1] - v2[t2]) % m});
            t2++;
        }
    }
}

void solve(int cas)
{
    cin >> n >> m;
    v = vector<vector<ll>>(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    tm = vector<ll>(n + 1, 0);
    tv = vector<set<ll>>(n, set<ll>());
    tva = vector<set<ll>>(n, set<ll>());
    ll bs = 1;
    for (ll i = 0; i <= n; i++)
    {
        tm[i] = bs;
        bs *= 10LL;
        bs %= m;
    }
    if (n == 1)
    {
        cout << v[0][0] % m << "\n";
        return;
    }
    // printVector(tm);
    // tmod = fmod(n - 1, m);
    // cout << "tmod=" << tmod << "\n";
    // first n
    dfs(0, 0, 0, n);

    // then n-1
    dfs1(n - 1, n - 1, 0, n - 1);
    for (ll i = 0; i < n; i++)
    {
        vector<ll> tvv1(tv[i].size(), 0);
        ll tp = 0;
        for (ll l : tv[i])
        {
            tvv1[tp++] = l;
        }
        vector<ll> tvv2(tva[i].size(), 0);
        tp = 0;
        for (ll l : tva[i])
        {
            tvv2[tp++] = l;
        }
        sort(tvv1.begin(), tvv1.end());
        sort(tvv2.begin(), tvv2.end());
        f(tvv1, tvv2);
        // printVector(tv[i]);
    }
    cout << ans << "\n";
    // cout << "t=" << t << "\n";
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
