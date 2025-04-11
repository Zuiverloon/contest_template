/**
 * https://codeforces.com/problemset/problem/1791/F
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

ll digitsum(ll i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += i % 10;
        i /= 10;
    }
    return ans;
}

// vector<ll> sgtree;
vector<ll> tag;

void pushdown(ll lb, ll rb, ll o)
{
    if (lb == rb)
    {
        return;
    }
    tag[o * 2 + 1] += tag[o];
    tag[o * 2 + 2] += tag[o];
    tag[o] = 0;
}

void add(ll lb, ll rb, ll l, ll r, ll o)
{
    if (l > rb || r < lb)
        return;
    if (l <= lb && r >= rb)
    {
        tag[o]++;
        return;
    }
    pushdown(lb, rb, o);
    ll mid = (lb + rb) / 2;
    if (l <= mid)
    {
        add(lb, mid, l, r, o * 2 + 1);
    }
    if (r > mid)
    {
        add(mid + 1, rb, l, r, o * 2 + 2);
    }
}

ll get(ll lb, ll rb, ll pos, ll o)
{
    if (pos > rb || pos < lb)
    {
        return 0;
    }
    if (pos == lb && pos == rb)
    {
        return tag[o];
    }
    pushdown(lb, rb, o);
    ll mid = (lb + rb) / 2;
    if (pos <= mid)
    {
        return get(lb, mid, pos, o * 2 + 1);
    }
    else
    {
        return get(mid + 1, rb, pos, o * 2 + 2);
    }
}

ll f(ll num, ll cnt)
{
    if (num < 10)
        return num;
    if (cnt == 0)
        return num;
    return f(digitsum(num), cnt - 1);
}

void solve(int cas)
{
    ll n, q;
    std::cin >> n >> q;
    vector<ll> v(n, 0);
    // sgtree = vector<ll>(4 * n + 10, 0);
    tag = vector<ll>(4 * n + 10, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < q; i++)
    {
        ll d;
        cin >> d;
        if (d == 1)
        {
            ll l, r;
            cin >> l >> r;
            add(0, n - 1, l - 1, r - 1, 0);
        }
        else
        {
            ll pos;
            cin >> pos;
            pos--;
            ll cnt = get(0, n - 1, pos, 0);
            // std::cout << "cnt=" << cnt << "\n";
            cout << f(v[pos], cnt) << "\n";
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
