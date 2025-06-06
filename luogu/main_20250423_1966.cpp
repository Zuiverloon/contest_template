/**
 * https://www.luogu.com.cn/problem/P1966
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

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

vector<ll> sgtree;

void pushdown(ll lb, ll rb, ll o)
{
    if (lb == rb)
    {
        return;
    }
    sgtree[o * 2 + 1] += sgtree[o];
    sgtree[o * 2 + 2] += sgtree[o];
    sgtree[o] = 0;
}

ll get(ll lb, ll rb, ll pos, ll o)
{
    if (pos < lb || pos > rb)
        return 0;
    if (pos <= lb && pos >= rb)
    {
        return sgtree[o];
    }
    if (sgtree[o] != 0)
    {
        pushdown(lb, rb, o);
    }
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

void add(ll lb, ll rb, ll l, ll r, ll val, ll o)
{
    if (r < lb || l > rb)
    {
        return;
    }
    if (l <= lb && r >= rb)
    {
        sgtree[o] += val;
        return;
    }
    if (sgtree[o] != 0)
        pushdown(lb, rb, o);
    ll mid = (lb + rb) / 2;
    if (l <= mid)
    {
        add(lb, mid, l, r, val, o * 2 + 1);
    }
    if (r > mid)
    {
        add(mid + 1, rb, l, r, val, o * 2 + 2);
    }
}

void solve(int cas)
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2, 0));
    vector<vector<ll>> b(n, vector<ll>(2, 0));
    sgtree = vector<ll>(4 * n + 10, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i][0];
        b[i][1] = i;
        add(0, n - 1, i, i, i, 0);
    }
    sort(a.begin(), a.end(), [&](vector<ll> &a1, vector<ll> &a2)
         {
		if (a1[0]!=a2[0]){
			return a1[0] < a2[0];
		}else{
			return a1[1] < a2[1];
		} });
    sort(b.begin(), b.end(), [&](vector<ll> &a1, vector<ll> &a2)
         {
		if (a1[0]!=a2[0]){
			return a1[0] < a2[0];
		}else{
			return a1[1] < a2[1];
		} });
    map<ll, ll> mpa;
    map<ll, ll> mpb;
    for (ll i = 0; i < n; i++)
    {
        mpa[a[i][1]] = i;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll posa = mpa[i];
        ll tmppos = (get(0, n - 1, b[posa][1], 0));
        ans += (tmppos - i);
        ans %= mod1e8;
        // cout << "tmppos=" << tmppos << "\n";
        add(0, n - 1, 0, b[posa][1], 1, 0);
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
