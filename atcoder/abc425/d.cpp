
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

ll get(ll row, ll col)
{
    return (row << 32) + col;
}

ll getrow(ll val)
{
    return (val >> 32);
}

ll getcol(ll val)
{
    return val & 0xffffffff;
}

bool oneb(vector<string> &v, ll r, ll c)
{
    ll tmp = 0;
    if (r - 1 >= 0)
    {
        tmp += (v[r - 1][c] == '#');
    }
    if (r + 1 < v.size())
    {
        tmp += (v[r + 1][c] == '#');
    }
    if (c - 1 >= 0)
    {
        tmp += (v[r][c - 1] == '#');
    }
    if (c + 1 < v[0].size())
    {
        tmp += (v[r][c + 1] == '#');
    }
    return tmp == 1;
}

void solve(int cas)
{
    ll h, w;
    cin >> h >> w;
    vector<string> v(h, "");
    for (ll i = 0; i < h; i++)
    {
        cin >> v[i];
    }
    set<ll> q;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (v[i][j] == '.' && oneb(v, i, j))
            {
                q.insert(get(i, j));
            }
        }
    }
    while (q.size() > 0)
    {
        set<ll> nq;
        for (ll ps : q)
        {
            ll r = getrow(ps);
            ll c = getcol(ps);
            // cout << "r c " << r << " " << c << "\n";

            v[r][c] = '#';
        }
        for (ll ps : q)
        {
            ll r = getrow(ps);
            ll c = getcol(ps);
            if (r - 1 >= 0 && v[r - 1][c] == '.' && oneb(v, r - 1, c))
            {
                nq.insert(get(r - 1, c));
            }
            if (r + 1 < h && v[r + 1][c] == '.' && oneb(v, r + 1, c))
            {
                nq.insert(get(r + 1, c));
            }
            if (c - 1 >= 0 && v[r][c - 1] == '.' && oneb(v, r, c - 1))
            {
                nq.insert(get(r, c - 1));
            }
            if (c + 1 < w && v[r][c + 1] == '.' && oneb(v, r, c + 1))
            {
                nq.insert(get(r, c + 1));
            }
        }
        q = nq;
    }
    ll ans = 0;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            ans += (v[i][j] == '#');
        }
    }
    cout << ans << "\n";

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
