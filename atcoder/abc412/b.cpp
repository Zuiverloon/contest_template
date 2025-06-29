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

ll ans = INT_MAX;

vector<ll> stk(8, 0);
ll tot = 0;

void dfs(ll pos, vector<vector<ll>> &l, ll remain, vector<vector<bool>> &nei, ll tans, vector<ll> &deg)
{
    if (pos == l.size())
    {
        if (remain != 0)
            return;
    }
    if (remain == 0)
    {
        for (ll i = 1; i < deg.size(); i++)
        {
            if (deg[i] != 2)
            {
                return;
            }
        }
        // printVector(stk);
        // cout << "tans=" << tans << "\n";
        // cout << "ttans=" << ((tot - tans) + ((ll)deg.size() - 1LL - tans)) << "\n";
        ans = min(ans, (tot - tans) + ((ll)deg.size() - 1LL - tans));
        return;
    }
    if (l.size() - pos < remain - 1)
    {
        return;
    }
    // pick l[pos]
    deg[l[pos][0]]++;
    deg[l[pos][1]]++;
    if (deg[l[pos][0]] <= 2 && deg[l[pos][1]] <= 2)
    {
        stk[remain - 1] = pos;
        dfs(pos + 1, l, remain - 1, nei, tans + ((nei[l[pos][0]][l[pos][1]]) ? 1 : 0), deg);
    }
    deg[l[pos][0]]--;
    deg[l[pos][1]]--;
    // not pick l[pos]
    dfs(pos + 1, l, remain, nei, tans, deg);
}

ll bs(vector<ll> &v, ll p, ll target)
{
    ll ans = -1;
    ll l = 0, r = p;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] * 2 >= target)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

void solve(int cas)
{
    string s, t;
    cin >> s >> t;
    set<char> ts;
    for (char c : t)
    {
        ts.insert(c);
    }
    for (ll i = 1; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (!isinset(ts, s[i - 1]))
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    return;
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
