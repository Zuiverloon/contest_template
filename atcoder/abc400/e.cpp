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

void init(std::vector<ll> &prime)
{
    std::vector<bool> isp(1000001, true);
    for (ll i = 2; i < isp.size(); i++)
    {
        if (isp[i])
        {
            for (ll j = i * i; j < isp.size(); j += i)
            {
                isp[j] = false;
            }
        }
    }
    for (ll i = 2; i < isp.size(); i++)
    {
        if (isp[i])
        {
            prime.push_back(i);
        }
    }
}

ll bs(std::vector<std::vector<ll>> &v, ll t)
{
    ll ans = LLONG_MAX;
    ll l = 0, r = v.size() - 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid][0] >= t)
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
    std::vector<ll> prime;
    init(prime);
    // std::cout << prime.size() << "\n";
    // printVector(prime);
    ll q;
    std::cin >> q;
    std::vector<std::vector<ll>> v(q, std::vector<ll>(3, 0));
    for (ll i = 0; i < q; i++)
    {
        ll tq;
        std::cin >> tq;
        v[i][0] = (ll)std::sqrt(tq);
        v[i][1] = i;
        v[i][2] = -1;
    }
    auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2)
    {
        return a1[1] > a2[1];
    };
    std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & v1, std::vector<ll> & v2)>> pq(cmp);
    std::sort(v.begin(), v.end(), [&](auto &a1, auto &a2)
              { return a1[0] < a2[0]; });
    // for (ll i = 0; i < v.size(); i++)
    // {
    // 	printVector(v[i]);
    // }
    for (ll i = 0; i < prime.size(); i++)
    {
        for (ll j = i + 1; j < prime.size(); j++)
        {
            if (prime[i] * prime[j] <= 1000000LL)
            {
                pq.push(std::vector<ll>{prime[i], prime[j], prime[i] * prime[j]});
            }
            else
            {
                break;
            }
        }
    }
    // std::vector<ll> ans(q, 0);
    while (!pq.empty())
    {
        auto fr = pq.top();
        // std::cout << "fr ";
        // printVector(fr);
        pq.pop();
        ll t = fr[2];
        ll pos = bs(v, t);
        if (pos == LLONG_MAX)
            continue;
        v[pos][2] = std::max({v[pos][2], t});
        if (t * fr[0] <= 1000000LL)
        {
            pq.push(std::vector<ll>{fr[0], fr[1], t * fr[0]});
        }
        if (t * fr[1] <= 1000000LL)
        {
            pq.push(std::vector<ll>{fr[0], fr[1], t * fr[1]});
        }
    }

    // for (ll i = 0; i < v.size(); i++)
    // {
    // 	printVector(v[i]);
    // }
    for (ll i = 0; i < q; i++)
    {
        if (i != 0 && v[i][2] == -1)
        {
            v[i][2] = v[i - 1][2];
        }
        // std::cout << v[i][2] * v[i][2] << "\n";
    }
    std::sort(v.begin(), v.end(), [&](auto &a1, auto &a2)
              { return a1[1] < a2[1]; });
    for (ll i = 0; i < q; i++)
    {
        std::cout << v[i][2] * v[i][2] << "\n";
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