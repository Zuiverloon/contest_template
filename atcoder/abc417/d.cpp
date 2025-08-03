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

// get multipliactive inverse by euclid method
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

// get multiplicative inverse by quick power
// ax = 1(mod b)
// x = a**(b-2) mod b
ll qpow(ll a, ll b)
{
    ll ans = 1;
    ll mod = b;
    b -= 2;
    a = (a % mod + mod) % mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (a * ans) % mod;
        a = (a * a) % mod;
    }
    return ans;
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
    if (a == b)
        return;
    fa[get(b)] = get(a);
}

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

// vector<ll> ft;
// void add(ll i, ll x)
// {
// 	while (i < ft.size())
// 	{
// 		ft[i] += x;
// 		i += lowbit(i);
// 	}
// }

// ll get(ll i)
// {
// 	ll ans = 0;
// 	while (i > 0)
// 	{
// 		ans += ft[i];
// 		i -= lowbit(i);
// 	}
// 	return ans;
// }

void solve(int cas)
{
    fa = vector<ll>(5005000, 0);
    for (ll i = 0; i < fa.size(); i++)
    {
        fa[i] = i;
    }
    ll n;
    cin >> n;
    vector<ll> pre(1001, -1);
    for (ll i = 0; i < pre.size(); i++)
    {
        pre[i] = i;
    }
    ll sum = 0;
    for (ll t = 0; t < n; t++)
    {
        vector<ll> next(pre.size(), -1);
        ll p, a, b;
        cin >> p >> a >> b;
        sum += b;
        // smaller element assgin to larger number
        for (ll i = 0; i < pre.size(); i++)
        {
            ll target = -1;
            if (p >= i)
            {
                target = i + a;
            }
            else
            {
                target = max(0LL, i - b);
            }
            if (next[target] == -1)
            {
                next[target] = pre[i];
            }
            else
            {
                // ll f1 = get(next[target]);
                // ll f2 = pre[i];
                // merge(f1, f2);

                // cout << "merge " << next[target] << " " << pre[i] << "\n";
                merge(next[target], pre[i]);
            }
        }
        ll j = b;
        for (ll i = pre.size() - 1; i >= 0 && j >= 1; i--)
        {
            if (next[i] == -1)
            {
                next[i] = i + sum;
                // mn = min(mn, i + sum);
                // mx = max(mx, i + sum);
                // cout << "hit " << i + sum << "\n";
                // if (i + sum == 2501)
                // {
                // 	cout << "hit 2501\n";
                // }
            }
            else
            {
                merge(next[i], i + sum);
            }
            j--;
        }
        // cout << "mn mx " << mn << " " << mx << "\n";
        pre = next;
    }
    vector<ll> ans(fa.size(), -1);
    for (ll i = 0; i < pre.size(); i++)
    {
        if (pre[i] >= 0)
        {
            ans[get(pre[i])] = i;
        }
    }
    ll q;
    cin >> q;

    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        // if (x == 1000000000)
        // {
        // 	cout << "fk\n";
        // 	return;
        // }
        if (x >= fa.size() || (get(x) == x && ans[x] == -1))
        {
            cout << x - sum << "\n";
        }
        else
        {
            ll f = get(x);
            if (ans[f] == -1)
            {
                // cout << "f=" << f << "\n";
                // cout << "ansf == -1\n";
                cout << f - sum << "\n";
            }
            else
            {
                cout << ans[f] << "\n";
            }
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
    // std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}
