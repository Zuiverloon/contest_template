

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
// vector<ll> fa;

// ll get(ll i)
// {
// 	if (fa[i] != i)
// 	{
// 		fa[i] = get(fa[i]);
// 	}
// 	return fa[i];
// }

// void merge(ll a, ll b)
// {
// 	fa[get(b)] = get(a);
// }

/***     dsu template           */

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

vector<ll> ft;
void add(ll i, ll x)
{
    while (i < ft.size())
    {
        ft[i] += x;
        i += lowbit(i);
    }
}

ll get(ll i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += ft[i];
        i -= lowbit(i);
    }
    return ans;
}

ll nord = 1;
vector<ll> ord;
vector<ll> in;
vector<ll> out;

vector<set<ll>> nei;

void dfs(ll o, ll fa)
{
    ord[o] = nord;
    nord++;
    in[o] = ord[o];
    for (ll next : nei[o])
    {
        if (next != fa)
        {
            dfs(next, o);
        }
    }
    out[o] = nord - 1;
    // cout << o << " " << ord[o] << " " << in[o] << " " << out[o] << "\n";
    return;
}

void solve(int cas)
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(2, 0));
    ord = vector<ll>(n + 1, 0);
    out = vector<ll>(n + 1, 0);
    in = vector<ll>(n + 1, 0);
    ft = vector<ll>(n + 1, 0);
    nei = vector<set<ll>>(n + 1, set<ll>());
    for (ll i = 1; i <= n - 1; i++)
    {
        cin >> v[i][0] >> v[i][1];
        nei[v[i][0]].insert(v[i][1]);
        nei[v[i][1]].insert(v[i][0]);
    }
    for (ll i = 1; i <= n; i++)
    {
        add(i, 1);
    }
    dfs(1, -1);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll d;
        cin >> d;
        if (d == 1)
        {
            ll x, w;
            cin >> x >> w;
            add(in[x], w);
        }
        else
        {
            ll y;
            cin >> y;
            ll mord = max({ord[v[y][0]], ord[v[y][1]]});
            ll pick = (mord == ord[v[y][0]] ? v[y][0] : v[y][1]);
            ll tot = get(n);
            ll sub = (get(out[pick]) - get(in[pick] - 1));
            // cout << "tot=" << tot << " sub=" << sub << "\n";
            cout << abs((tot - sub) - sub) << "\n";
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
