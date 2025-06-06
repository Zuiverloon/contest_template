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

std::vector<ll> pm;

void init()
{
    std::vector<ll> ispm(100010, true);
    for (ll i = 2; i < (ll)std::sqrt(100010 + 0.5); i++)
    {
        if (!ispm[i])
        {
            continue;
        }
        for (ll j = i * i; j < ispm.size(); j += i)
        {
            ispm[j] = false;
        }
    }
    for (ll i = 2; i < ispm.size(); i++)
    {
        if (ispm[i])
        {
            pm.push_back(i);
        }
    }
    // printVector(pm);
}

ll bs(std::vector<ll> &pm, ll t)
{
    ll ans = -1;
    ll l = 0, r = pm.size();
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (pm[mid] <= t)
        {
            ans = pm[mid];
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
    ll n;
    std::cin >> n;
    ll mid = (1 + n) / 2;
    ll tpm = bs(pm, mid);
    if (n == 2)
    {
        std::cout << "2 1\n";
        return;
    }
    else if (n == 3)
    {
        std::cout << "2 1 3\n";
        return;
    }
    // std::cout << "tpm=" << tpm << "\n";
    std::vector<ll> ans(n, 0);
    ans[0] = tpm;
    ll l = tpm - 1, r = tpm + 1;
    ll ansp = 1;
    while (l > 0 && r <= n)
    {
        ans[ansp++] = l;
        l--;
        ans[ansp++] = r;
        r++;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (ans[i] == 0)
        {
            ans[i] = i + 1;
        }
        else
        {
            break;
        }
    }
    printVector(ans);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // initmobelong();
    init();

    int n = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}