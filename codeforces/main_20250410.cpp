/**
 * https://codeforces.com/problemset/problem/474/F
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

ll getgcd(vector<vector<ll>> &v, ll l, ll len)
{
    ll ans = 0;
    for (ll i = 31; i >= 0; i--)
    {
        ll off = (1LL << i);
        if ((off & len) == off)
        {
            ans = (ans == 0 ? v[l][i] : gcd(ans, v[l][i]));
            len -= off;
            l += off;
        }
    }
    return ans;
}

ll bs(vector<ll> &v, ll lb)
{
    ll l = 0, r = v.size() - 1;
    ll ans = v.size();
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] >= lb)
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

ll bs1(vector<ll> &v, ll rb)
{
    ll l = 0, r = v.size() - 1;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] <= rb)
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
    ll n;
    cin >> n;
    vector<ll> v(n, 0);
    map<ll, vector<ll>> mp;
    vector<vector<ll>> st(n, vector<ll>(32, 0));

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        st[i][0] = v[i];
        mp[v[i]].push_back(i);
    }
    for (ll i = 1; i < 32; i++)
    {
        ll len = (1LL << i);
        for (ll j = 0; j < n; j++)
        {
            if (j + len - 1 >= n)
            {
                break;
            }
            st[j][i] = gcd(st[j][i - 1], st[j + len / 2][i - 1]);
            // cout << "j i " << j << " " << i << " " << st[j][i] << "\n";
        }
    }
    // cout << "finish build st\n";
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll len = r - l + 1;
        ll gd = getgcd(st, l, len);
        // cout << "gd=" << gd << "\n";
        if (mp[gd].size() == 0)
        {
            cout << r - l + 1 << "\n";
            continue;
        }
        ll lb = bs(mp[gd], l);
        ll rb = bs1(mp[gd], r);
        // cout << "lb rb " << lb << " " << rb << "\n";
        if (lb <= rb)
        {
            cout << r - l + 1 - (rb - lb + 1) << "\n";
        }
        else
        {
            cout << r - l + 1 << "\n";
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
