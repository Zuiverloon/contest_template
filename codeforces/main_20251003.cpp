// https://codeforces.com/problemset/problem/1117/D

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

void printYes()
{
    cout << "Yes\n";
}

void printNo()
{
    cout << "No\n";
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

vector<vector<ll>> copy(vector<vector<ll>> &a)
{
    vector<vector<ll>> ta(a.size(), vector<ll>(a.size(), 0));
    for (ll i = 0; i < a.size(); i++)
    {
        for (ll j = 0; j < a.size(); j++)
        {
            ta[i][j] = a[i][j];
        }
    }
    return ta;
}

void mul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> ta = copy(a);
    for (ll i = 0; i < a.size(); i++)
    {
        for (ll j = 0; j < a.size(); j++)
        {
            ll tans = 0;
            for (ll k = 0; k < a.size(); k++)
            {
                tans += ta[i][k] * b[k][j];
                tans %= mod1e9;
            }
            a[i][j] = tans;
        }
    }
}

vector<vector<ll>> power(vector<vector<ll>> &v, ll m)
{
    if (m == 1)
    {
        return v;
    }
    ll tm = m / 2;
    vector<vector<ll>> ta = power(v, tm);
    vector<vector<ll>> tb = copy(ta);
    mul(ta, tb);
    if (m % 2 == 1)
    {
        mul(ta, v);
    }
    return ta;
}

void mul(vector<ll> &v, vector<vector<ll>> &vmod)
{
    vector<ll> tv(v);
    for (ll i = 0; i < vmod.size(); i++)
    {
        ll tans = 0;
        for (ll j = 0; j < v.size(); j++)
        {
            tans += vmod[i][j] * tv[j];
            tans %= mod1e9;
        }
        v[i] = tans;
    }
}

void solve(int cas)
{
    ll n, m;
    cin >> n >> m;
    if (n < m)
    {
        cout << 1 << "\n";
        return;
    }
    vector<ll> fm(m, 1);
    // for (ll i = 0; i < m - 1; i++)
    // {
    // 	fm[i] = m - i - 1;
    // }
    // printVector(fm);
    vector<vector<ll>> v(m, vector<ll>(m, 0));
    v[0][0] = 1;
    v[0][m - 1] = 1;
    for (ll i = 1; i < m; i++)
    {
        v[i][i - 1] = 1;
    }
    vector<vector<ll>> vmod = power(v, n - m + 1);
    mul(fm, vmod);
    // printVector(fm);

    cout << fm[0] << "\n";
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
