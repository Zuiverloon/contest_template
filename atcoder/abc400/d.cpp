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

void printYes()
{
    std::cout << "Yes\n";
}

void printNo()
{
    std::cout << "No\n";
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

ll bs(ll t)
{
    ll l = 1, r = std::min(t, 1000000000LL);
    ll ans = 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (mid * mid <= t)
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

void solve(int cas)
{
    ll h, w;
    std::cin >> h >> w;
    std::vector<std::string> v(h, "");
    for (ll i = 0; i < h; i++)
    {
        std::cin >> v[i];
    }
    std::vector<std::vector<ll>> dis(h, std::vector<ll>(w, LLONG_MAX / 2));
    ll a, b, c, d;
    std::cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2)
    {
        return a1[2] > a2[2];
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & v1, std::vector<ll> & v2)>> pq(cmp);
    dis[a][b] = 0;
    pq.push(std::vector<ll>{a, b, 0});
    ll ans = 0;
    while (!pq.empty())
    {
        auto fr = pq.top();
        pq.pop();
        // printVector(fr);

        if (fr[0] == c && fr[1] == d)
        {
            std::cout << fr[2] << "\n";
            return;
        }

        ll tdis = fr[2];
        ll th = fr[0], tw = fr[1];
        if (dis[th][tw] < tdis)
        {
            continue;
        }
        if (th + 1 < h)
        {
            if (v[th + 1][tw] == '.')
            {
                if (dis[th + 1][tw] > tdis)
                {
                    dis[th + 1][tw] = tdis;
                    pq.push(std::vector<ll>{th + 1, tw, tdis});
                }
            }
            else
            {
                if (dis[th + 1][tw] > tdis + 1)
                {
                    dis[th + 1][tw] = tdis + 1;
                    pq.push(std::vector<ll>{th + 1, tw, tdis + 1});
                }
                if (th + 2 < h && v[th + 2][tw] == '#' && dis[th + 2][tw] > tdis + 1)
                {
                    dis[th + 2][tw] = tdis + 1;
                    pq.push(std::vector<ll>{th + 2, tw, tdis + 1});
                }
            }
        }
        if (th - 1 >= 0)
        {
            if (v[th - 1][tw] == '.')
            {
                if (dis[th - 1][tw] > tdis)
                {
                    dis[th - 1][tw] = tdis;
                    pq.push(std::vector<ll>{th - 1, tw, tdis});
                }
            }
            else
            {
                if (dis[th - 1][tw] > tdis + 1)
                {
                    dis[th - 1][tw] = tdis + 1;
                    pq.push(std::vector<ll>{th - 1, tw, tdis + 1});
                }
                if (th - 2 >= 0 && v[th - 2][tw] == '#' && dis[th - 2][tw] > tdis + 1)
                {
                    dis[th - 2][tw] = tdis + 1;
                    pq.push(std::vector<ll>{th - 2, tw, tdis + 1});
                }
            }
        }
        if (tw + 1 < w)
        {
            if (v[th][tw + 1] == '.')
            {
                if (dis[th][tw + 1] > tdis)
                {
                    dis[th][tw + 1] = tdis;
                    pq.push(std::vector<ll>{th, tw + 1, tdis});
                }
            }
            else
            {
                if (dis[th][tw + 1] > tdis + 1)
                {
                    dis[th][tw + 1] = tdis + 1;
                    pq.push(std::vector<ll>{th, tw + 1, tdis + 1});
                }
                if (tw + 2 < w && v[th][tw + 2] == '#' && dis[th][tw + 2] > tdis + 1)
                {
                    dis[th][tw + 2] = tdis + 1;
                    pq.push(std::vector<ll>{th, tw + 2, tdis + 1});
                }
            }
        }
        if (tw - 1 >= 0)
        {
            if (v[th][tw - 1] == '.')
            {
                if (dis[th][tw - 1] > tdis)
                {
                    dis[th][tw - 1] = tdis;
                    pq.push(std::vector<ll>{th, tw - 1, tdis});
                }
            }
            else
            {
                if (dis[th][tw - 1] > tdis + 1)
                {
                    dis[th][tw - 1] = tdis + 1;
                    pq.push(std::vector<ll>{th, tw - 1, tdis + 1});
                }
                if (tw - 2 >= 0 && v[th][tw - 2] == '#' && dis[th][tw - 2] > tdis + 1)
                {
                    dis[th][tw - 2] = tdis + 1;
                    pq.push(std::vector<ll>{th, tw - 2, tdis + 1});
                }
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