
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
ll ans = LLONG_MAX / 2;
vector<ll> c;
vector<vector<ll>> v;

bool verify(vector<ll> &a)
{
    for (ll i = 1; i < a.size(); i++)
    {
        if (a[i] < 2)
        {
            return false;
        }
    }
    return true;
}

void f(ll n, ll pos, ll cost, vector<ll> &a)
{
    // cout << pos << " " << cost << "\n";
    // printVector(a);
    if (pos > n)
    {
        return;
    }
    // no visit
    f(n, pos + 1, cost, a);
    // visit once
    vector<ll> tmp = v[pos];
    for (ll i = 0; i < tmp.size(); i++)
    {
        a[tmp[i]]++;
    }
    if (verify(a))
    {
        ans = min({ans, cost + c[pos]});
    }
    f(n, pos + 1, cost + c[pos], a);

    // visit twice
    for (ll i = 0; i < tmp.size(); i++)
    {
        a[tmp[i]]++;
    }
    if (verify(a))
    {
        ans = min({ans, cost + 2 * c[pos]});
    }
    f(n, pos + 1, cost + 2 * c[pos], a);

    // bac
    for (ll i = 0; i < tmp.size(); i++)
    {
        a[tmp[i]] -= 2;
    }
}

void solve(int cas)
{
    ll n;
    cin >> n;
    vector<ll> c(n, 0);
    vector<ll> a(n, 0);
    for (ll i = 1; i < n; i++)
    {
        cin >> c[i];
    }
    for (ll i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = n - 1;
    vector<ll> jump(n, INT_MAX);
    jump[0] = 0;

    for (ll i = 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            jump[i] = 0;
        }
        else
        {
            for (ll j = i - 1; j >= i - c[i]; j--)
            {
                jump[i] = min({jump[i], jump[j] + 1});
            }
        }
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        if (a[i] == 0)
        {
            // cout << i << " is empty\n";
            ans--;
            continue;
        }
        else
        {
            ll minpos = -1;
            ll mnval = INT_MAX;
            for (ll j = i - 1; j >= i - c[i]; j--)
            {
                if (mnval > jump[j])
                {
                    mnval = jump[j];
                    minpos = j;
                }
            }

            a[minpos] += a[i];
        }
    }
    cout << ans << "\n";
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
