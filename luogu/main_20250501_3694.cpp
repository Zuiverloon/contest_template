/**
 * https://www.luogu.com.cn/problem/P3694
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
using namespace std;

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;
ll mod1e8 = 100000000LL - 3;

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

/***     dsu template           */
vector<ll> fa;

ll get(ll i)
{
    if (fa[i] != i)
    {
        fa[i] = get(fa[i]);
    }
    return fa[i];
}

void merge(ll a, ll b)
{
    fa[get(b)] = get(a);
}

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

vector<ll> v;
vector<ll> cnt;
vector<vector<ll>> psum;
vector<ll> mp;

ll f(ll tot, ll pos, ll m)
{
    if (tot == 0 && pos == 0)
    {
        return 0;
    }
    if (mp[tot] != 0)
    {
        return mp[tot] - 1;
    }
    ll ans = INT_MAX;
    for (ll i = 1; i <= m; i++)
    {
        ll offset = (1 << i);
        if ((tot & offset) != 0)
        {
            ans = min({ans, f(tot - offset, pos - cnt[i], m) + cnt[i] - (psum[i][pos] - psum[i][pos - cnt[i]])});
        }
    }
    // cout << tot << " " << pos << " " << ans << "\n";
    mp[tot] = ans + 1;
    return ans;
}

void solve(int cas)
{
    ll n, m;
    cin >> n >> m;
    v = vector<ll>(n, 0);
    cnt = vector<ll>(m + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }
    ll target = (1 << (m + 1)) + 5;
    mp = vector<ll>(target, 0);
    psum = vector<vector<ll>>(m + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (v[j] == i)
            {
                psum[i][j + 1] = psum[i][j] + 1;
            }
            else
            {
                psum[i][j + 1] = psum[i][j];
            }
        }
        // printVector(psum[i]);
    }
    ll tot = 0;
    for (ll i = 1; i <= m; i++)
    {
        tot += (1 << i);
    }
    cout << f(tot, n, m) << "\n";
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
