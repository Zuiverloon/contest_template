
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

vector<ll> fwt;

void add(ll i)
{
    while (i < fwt.size())
    {
        fwt[i]++;
        i += lowbit(i);
    }
}

ll get(ll i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += fwt[i];
        i -= lowbit(i);
    }
    return ans;
}

void solve(int cas)
{
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, unordered_set<ll>> mp;
    fwt = vector<ll>(n + 1, 0);
    // for (ll i = 1; i <= n; i++)
    // {
    // 	fa[i] = i;
    // }
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    vector<ll> ans(n, -1);
    ans[0] = 0;
    unordered_set<ll> reach;
    auto cmp = [&](ll a, ll b)
    {
        return a > b;
    };
    priority_queue<ll, std::vector<ll>, function<bool(ll a, ll b)>>
        pq(cmp);
    reach.insert(1);
    pq.push(1);
    ll mx = 0;
    while (pq.size() > 0)
    {
        ll tp = pq.top();
        pq.pop();
        add(tp);
        mx = std::max({mx, tp});
        for (ll next : mp[tp])
        {
            if (!isinset(reach, next))
            {
                reach.insert(next);
                pq.push(next);
            }
        }
        if (get(mx) == mx)
        {
            // std::cout << "gettp=" << get(tp) << "\n";
            // std::cout << "getn=" << get(n) << "\n";
            ans[mx - 1] = pq.size();
        }
    }
    for (ll i : ans)
    {
        cout << i << "\n";
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
