

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

void f(std::set<ll> &s1, std::set<ll> &s2, std::set<ll> &target)
{
    if (s1.size() == 0 || s2.size() == 0)
        return;
    std::set<ll> &small = s1.size() <= s2.size() ? s1 : s2;
    std::set<ll> &big = s1.size() <= s2.size() ? s2 : s1;
    for (auto i : small)
    {
        if (isinset(big, i))
        {
            target.insert(i);
        }
    }
}

void solve(int cas)
{
    ll n, s1, s2;
    std::cin >> n >> s1 >> s2;
    ll m1;
    std::cin >> m1;
    std::vector<std::set<ll>> st1(n + 1, std::set<ll>());
    std::vector<std::set<ll>> st2(n + 1, std::set<ll>());
    for (int i = 0; i < m1; i++)
    {
        ll c, d;
        std::cin >> c >> d;
        st1[c].insert(d);
        st1[d].insert(c);
    }
    ll m2;
    std::cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        ll c, d;
        std::cin >> c >> d;
        st2[c].insert(d);
        st2[d].insert(c);
    }
    std::set<ll> target;
    for (int i = 1; i <= n; i++)
    {
        f(st1[i], st2[i], target);
    }
    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(n + 1, LLONG_MAX / 2));
    std::vector<std::vector<bool>> recur(n + 1, std::vector<bool>(n + 1, false));
    auto cmp = [&](auto &a1, auto &a2)
    {
        return a1[0] > a2[0];
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & a1, std::vector<ll> & a2)>> pq(cmp);
    pq.push(std::vector<ll>{0, s1, s2});

    while (!pq.empty())
    {
        auto fr = pq.top();
        pq.pop();
        ll tans = fr[0], ss1 = fr[1], ss2 = fr[2];
        std::set<ll> &next1 = st1[ss1];
        std::set<ll> &next2 = st2[ss2];
        for (ll u1 : next1)
        {
            for (ll u2 : next2)
            {
                ll cost = std::abs(u1 - u2);
                if (tans + cost < dp[u1][u2])
                {
                    dp[u1][u2] = tans + cost;
                    pq.push(std::vector<ll>{tans + cost, u1, u2});
                }
            }
        }
    }
    ll ans = LLONG_MAX / 2;
    bool infinite = true;
    for (ll i : target)
    {
        // std::cout << "in target " << i << " " << dp[i][i] << "\n";
        if (dp[i][i] != LLONG_MAX / 2)
        {
            infinite = false;
            ans = std::min(ans, dp[i][i]);
        }
    }
    if (infinite)
    {
        std::cout << -1 << "\n";
    }
    else
    {
        std::cout << ans << "\n";
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