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

void print(std::string s)
{
    printf("%s", s.c_str());
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

ll fpow(ll base, ll ex)
{
    if (ex == 0)
    {
        return 1;
    }
    if (ex == 1)
    {
        return base;
    }
    ll tans = fpow(base, ex / 2);
    if (ex % 2 == 0)
        return tans * tans;
    else
        return tans * tans * base;
}

void f(std::string &slimit, ll offset, ll first, bool limit, ll &ans)
{
    ll n = slimit.length();
    if (offset >= n)
    {
        ans += 1;
        return;
    }
    if (first <= slimit[offset] - '0')
    {
        ans += fpow(first, n - offset);
    }
    else
    {
        ans += (ll)(slimit[offset] - '0') * fpow(first, n - offset - 1);
        f(slimit, offset + 1, first, true, ans);
    }
}

ll f(ll limit) // num <= limit
{
    if (limit < 10)
        return 0;
    std::string slimit = std::to_string(limit);
    ll len = slimit.length();

    ll ans = 0;
    for (ll i = 2; i < len; i++)
    {
        for (ll j = 1; j <= 9; j++) // left digit
        {
            ll tans = 1;
            for (ll k = 1; k < i; k++) // i == 2, 98,97, 87,86
            {
                tans *= j;
            }
            ans += tans;
        }
    }
    // std::cout << "tans = " << ans << "\n";
    //  for (int i = 0;i<len;i++){

    // }
    for (ll first = 1; first <= 9; first++)
    {
        if (first < slimit[0] - '0')
        {
            ans += fpow(first, len - 1);
        }
        else if (first == (ll)(slimit[0] - '0'))
        {
            f(slimit, 1, first, true, ans);
        }
    }

    return ans;
}

void solve(int cas)
{
    ll l, r;
    std::cin >> l >> r;
    ll lans = f(l - 1);
    ll rans = f(r);
    // std::cout << lans << " " << rans << "\n";
    std::cout << rans - lans << "\n";
    // std::cout << f(10) << "\n";		// 1
    // std::cout << f(100) << "\n";	// 46
    // std::cout << f(9999) << "\n";	// 2355
    // std::cout << f(99999) << "\n";	// 17688
    // std::cout << f(100000) << "\n"; // 17689
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