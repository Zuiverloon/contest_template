
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

void f1(string &s, vector<ll> &v, char c)
{
    ll same = 0;
    ll nsame = 0;
    ll consec = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            consec++;
            same++;
        }
        else
        {
            consec = 0;
            nsame++;
        }

        if (i == 0)
        {
            if (same == 1)
            {
                v[0] = 0;
            }
            else
            {
                v[0] = 1;
            }
        }
        else
        {
            v[i] = nsame + (same - consec) * 2;
        }
    }
}

void f2(string &s, vector<ll> &v, char c)
{
    ll same = 0;
    ll nsame = 0;
    ll consec = 0;
    for (ll i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == c)
        {
            consec++;
            same++;
        }
        else
        {
            consec = 0;
            nsame++;
        }

        if (i == s.length() - 1)
        {
            if (same == 1)
            {
                v[i] = 0;
            }
            else
            {
                v[i] = 1;
            }
        }
        else
        {
            v[i] = nsame + (same - consec) * 2;
        }
    }
}

void solve(int cas)
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> l0(n, 0);
    vector<ll> r0(n, 0);
    vector<ll> l1(n, 0);
    vector<ll> r1(n, 0);
    f1(s, l0, '0');
    f1(s, l1, '1');
    f2(s, r0, '0');
    f2(s, r1, '1');
    // printVector(l0);
    // printVector(r0);
    // printVector(l1);
    // printVector(r1);
    ll ans = INT_MAX;
    ans = min({ans, l0[n - 1], l1[n - 1], r0[0], r1[0]});
    for (ll i = 0; i < n - 1; i++)
    {
        ans = min(ans, min(l0[i] + r0[i + 1], l1[i] + r1[i + 1]));
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
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}
