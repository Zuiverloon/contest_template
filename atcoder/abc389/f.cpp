

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

// clang++ -std=c++17 main.cpp -o main

ll mod1e9 = 1000000007LL;
ll mod998 = 998244353LL;

void print(ll t)
{
    printf("%lld\n", t);
}

void print(std::string &s)
{
    printf("%s\n", s.c_str());
}

void print(char *s)
{
    printf("%s\n", s);
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

std::vector<ll> sgtree;
std::vector<ll> tag;
std::vector<ll> vq;

void pushdown(ll lb, ll rb, ll o)
{
    if (tag[o] == 0 || lb == rb)
    {
        return;
    }
    tag[o * 2 + 1] += tag[o];
    tag[o * 2 + 2] += tag[o];
    tag[o] = 0;
}

ll get(ll lb, ll rb, ll pos, ll o)
{
    if (lb == rb && lb == pos)
    {
        return vq[pos - 1] + tag[o];
    }
    if (tag[o] != 0)
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

void update(ll lb, ll rb, ll l, ll r, ll val, ll o)
{
    if (l > rb && r < lb)
    {
        return;
    }
    if (l <= lb && r >= rb)
    {
        tag[o] += val;
        return;
    }
    if (tag[o] != 0)
    {
        pushdown(lb, rb, o);
    }
    ll mid = (lb + rb) / 2;
    if (l <= mid)
    {
        update(lb, mid, l, r, val, o * 2 + 1);
    }
    if (r > mid)
    {
        update(mid + 1, rb, l, r, val, o * 2 + 2);
    }
}

ll bsrb(ll val, ll q)
{
    // std::cout << "bsrb\n";
    ll ans = -1;
    ll l = 1, r = q;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll tv = get(1, q, mid, 0);
        // std::cout << "get i ans " << mid << " " << get(1, q, mid, 0) << "\n";
        if (tv <= val)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

ll bslb(ll val, ll q)
{
    // std::cout << "bslb\n";

    ll ans = q + 1;
    ll l = 1, r = q;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll tv = get(1, q, mid, 0);
        // std::cout << "get i ans " << mid << " " << get(1, q, mid, 0) << "\n";
        if (tv >= val)
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
    ll n;
    std::cin >> n;
    std::vector<std::vector<ll>> interval(n, std::vector<ll>(2, 0));
    for (int i = 0; i < n; i++)
    {
        std::cin >> interval[i][0] >> interval[i][1];
    }
    ll q;
    std::cin >> q;
    sgtree = std::vector<ll>(5 * q + 100, 0);
    tag = std::vector<ll>(5 * q + 100, 0);
    vq = std::vector<ll>(q, 0);
    std::vector<ll> nq(600000, 0);
    std::vector<ll> ansq(q, 0);
    for (int i = 1; i <= q; i++)
    {
        std::cin >> vq[i - 1];
        ansq[i - 1] = vq[i - 1];
    }
    std::sort(vq.begin(), vq.end());
    // printVector(vq);
    // for (int i = 1; i <= q; i++)
    // {
    // 	build(1, q, i, vq[i - 1], 0);
    // }
    // std::map<ll, ll> mp;
    for (int i = 1; i <= q; i++)
    {
        nq[vq[i - 1]] = i;
    }
    // std::cout << "beofre\n";
    for (int i = 0; i < n; i++)
    {
        ll l = interval[i][0], r = interval[i][1];
        ll fl = bslb(l, q), fr = bsrb(r, q);
        // std::cout << "l r " << l << " " << r << "\n";
        // std::cout << "fl fr " << fl << " " << fr << "\n";
        if (fl == q + 1 || fr == -1)
        {
            continue;
        }
        if (fl <= fr && fl >= 1)
        {
            update(1, q, fl, fr, 1, 0);
        }
    }
    std::vector<ll> ans(q, 0);
    for (int i = 0; i < q; i++)
    {
        ll pos = nq[ansq[i]];
        // std::cout << "pos=" << pos << "\n";
        ansq[i] = get(1, q, pos, 0);
    }
    for (int i = 0; i < q; i++)
    {
        print(ansq[i]);
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