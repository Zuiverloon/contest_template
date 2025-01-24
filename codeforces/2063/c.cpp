
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

void print(int t)
{
    printf("%d\n", t);
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

ll f(std::vector<ll> &deg, std::unordered_map<ll, std::unordered_set<ll>> &mp)
{
    ll mdg = 0;
    ll no = 0;
    for (int i = 1; i < deg.size(); i++)
    {
        if (deg[i] > mdg)
        {
            mdg = deg[i];
            no = i;
        }
    }
    if (mdg == 0)
    {
        return -1;
    }
    ll ans = deg[no] - 1;
    deg[no] = 0;
    for (ll ne : mp[no])
    {
        deg[ne]--;
        mp[ne].erase(no);
    }
    return ans;
}

ll getvmax(std::vector<ll> &v)
{
    ll ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        ans = std::max(ans, v[i]);
    }
    return ans;
}

void getvmaxn(std::vector<ll> &deg, std::vector<ll> &vmaxn, ll vmax)
{
    for (int i = 1; i < deg.size(); i++)
    {
        if (deg[i] == vmax)
            vmaxn.push_back(i);
    }
}

void solve(int cas)
{
    ll n;
    std::cin >> n;
    std::unordered_map<ll, std::unordered_set<ll>> mp;
    std::vector<ll> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    if (n == 2)
    {
        print(0);
        return;
    }
    ll vmax = getvmax(deg);
    ll ans = 1;
    std::vector<ll> vmaxn;
    getvmaxn(deg, vmaxn, vmax);
    // std::sort(deg.begin(), deg.end(), std::greater<ll>());
    if (vmaxn.size() >= 3)
    {
        // std::cout << "size>=3" << "\n";
        ans += 2 * (vmax - 1);
    }
    else if (vmaxn.size() == 2)
    {
        // std::cout << "size=2" << "\n";
        if (isinset(mp[vmaxn[0]], vmaxn[1]))
        {
            ans += (vmax - 1);
            ans += (vmax - 2);
        }
        else
        {
            ans += (2 * (vmax - 1));
        }
    }
    else
    {
        // std::cout << "size=1" << "\n";
        ans += (deg[vmaxn[0]] - 1);
        // printVector(vmaxn);
        for (ll ne : mp[vmaxn[0]])
        {
            deg[ne]--;
        }
        deg[vmaxn[0]] = 0;
        std::sort(deg.begin(), deg.end(), std::greater<ll>());
        ans += (deg[0] - 1);
    }
    print(ans);
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