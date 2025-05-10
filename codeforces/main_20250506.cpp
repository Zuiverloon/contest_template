/**
 * https://codeforces.com/problemset/problem/2093/D
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

void f1(ll n, ll x, ll y, ll offset)
{
    if (n < 0)
        return;
    // cout << n << " " << x << " " << y << " " << offset << "\n";
    ll len = (1LL << n);
    ll add = len / 2 * len / 2;
    if (n == 1 || (x <= len / 2 && y <= len / 2))
    {
        if (n == 1)
        {
            ll tans = 0;
            if (x == 1 && y == 1)
            {
                tans = 1;
            }
            else if (x == 2 && y == 2)
            {
                tans = 2;
            }
            else if (x == 2 && y == 1)
            {
                tans = 3;
            }
            else
            {
                tans = 4;
            }
            cout << offset + tans << "\n";
        }
        else
        {
            f1(n - 1, x, y, offset);
        }
    }
    else if (x > len / 2 && y > len / 2)
    {
        f1(n - 1, x - len / 2, y - len / 2, offset + add);
    }
    else if (x > len / 2 && y <= len / 2)
    {
        f1(n - 1, x - len / 2, y, offset + add * 2);
    }
    else
    {
        f1(n - 1, x, y - len / 2, offset + add * 3);
    }
}

void f2(ll n, ll x, ll y, ll offset)
{
    ll len = (1LL << n);
    ll add = len / 2 * len / 2;
    if (n == 1 || offset <= add)
    {
        if (n == 1)
        {
            if (offset == 1)
            {
                cout << x << " " << y << "\n";
            }
            else if (offset == 2)
            {
                cout << x + 1 << " " << y + 1 << "\n";
            }
            else if (offset == 3)
            {
                cout << x + 1 << " " << y << "\n";
            }
            else
            {
                cout << x << " " << y + 1 << "\n";
            }
        }
        else
        {
            f2(n - 1, x, y, offset);
        }
    }
    else if (offset <= add * 2)
    {
        f2(n - 1, x + len / 2, y + len / 2, offset - add);
    }
    else if (offset <= add * 3)
    {
        f2(n - 1, x + len / 2, y, offset - add * 2);
    }
    else
    {
        f2(n - 1, x, y + len / 2, offset - add * 3);
    }
}

void solve(int cas)
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            ll x, y;
            cin >> x >> y;
            // cout << x << " " << y << "\n";
            f1(n, x, y, 0);
        }
        else
        {
            ll d;
            cin >> d;
            // cout << d << "\n";
            f2(n, 1, 1, d);
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
