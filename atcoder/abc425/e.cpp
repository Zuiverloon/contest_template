
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

ll inverse(ll a, ll b)
{
    ll x, y;
    exgcd(a, b, x, y);
    x += b;
    x %= b;
    return x;
}

ll c(ll down, ll up, vector<ll> &pro, vector<ll> &iv, ll m)
{
    // cout << "down up " << down << " " << up << "\n";
    if (down == up)
    {
        return 1;
    }
    if (up == 0)
    {
        return 1;
    }
    if (up > down - up)
    {
        up = down - up;
    }
    ll ans = 1;

    ans *= pro[down];
    ans %= m;
    ans *= iv[down - up];
    ans %= m;
    ans *= iv[up];
    ans %= m;
    // cout << "123  " << pro[down] << " " << iv[down - up] << " " << iv[up] << "\n";
    return ans;
}

void solve(int cas)
{
    ll q, m;
    cin >> q >> m;
    // vector<ll> pro(10000, 0);
    // vector<ll> iv(10000, 0);
    vector<vector<ll>> cc(5001, vector<ll>(5001, 0));
    cc[1][1] = 1;
    for (ll i = 1; i < cc.size(); i++)
    {
        cc[i][0] = 1;
        cc[i][i] = 1;
    }
    for (ll i = 2; i < cc.size(); i++)
    {
        for (ll j = 1; j < i; j++)
        {
            cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1];
            cc[i][j] %= m;
        }
    }

    // ll t = 1;
    // pro[1] = 1;
    // for (ll i = 2; i < pro.size(); i++)
    // {
    // 	t *= i;
    // 	t %= m;
    // 	pro[i] = t;
    // }
    // t = 1;
    // iv[1] = 1;
    // for (ll i = 2; i < iv.size(); i++)
    // {
    // 	t *= inverse(i, m);
    // 	t %= m;
    // 	iv[i] = t;
    // 	// cout << "iv " << i << " " << iv[i] << "\n";
    // }

    for (ll i = 0; i < q; i++)
    {
        ll n;
        cin >> n;
        vector<ll> v(n, 0);
        ll sm = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            sm += v[i];
        }
        ll tans = 1;
        for (ll i = 0; i < n; i++)
        {
            // tans *= c(sm, v[i], pro, iv, m);
            tans *= cc[sm][v[i]];
            tans %= m;
            sm -= v[i];
        }
        cout << tans << "\n";
    }
    // ll x, y;
    // exgcd(2, 5, x, y);
    // x += 5;
    // x %= 5;
    // cout << x << " " << y << "\n";

    // a<b<c
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
