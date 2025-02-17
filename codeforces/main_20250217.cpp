/**
 * https://codeforces.com/problemset/problem/1788/B
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

void solve(int cas)
{
    ll ans1 = 0, ans2 = 0;
    ll n;
    std::cin >> n;
    // if (n <= 10)
    // {
    // 	if (n % 2 == 0)
    // 	{
    // 		std::cout << n / 2 << " " << n / 2 << "\n";
    // 	}
    // 	else
    // 	{
    // 		std::cout << n / 2 << " " << n / 2 + 1 << "\n";
    // 	}
    // 	return;
    // }
    if (n % 2 == 0)
    {

        std::cout << n / 2 << " " << n / 2 << "\n";
        return;
    }
    std::string s = std::to_string(n);
    ll carry = 0;
    ll base10 = (ll)std::pow(10, s.length() - 1);
    for (int i = 0; i < s.length(); i++)
    {
        ll digit = s[i] - '0';
        if (carry == 1)
        {
            digit += 10;
        }
        // std::cout << "digit=" << digit << "\n";
        if (digit % 2 == 0)
        {
            ans1 += digit / 2 * base10;
            ans2 += digit / 2 * base10;
            carry = 0;
        }
        else
        {
            if (digit == 19)
            {
                ans1 += 14 * base10;
                ans2 += 5 * base10;
            }
            else if (digit == 1 && i != s.length() - 1)
            {
            }
            else if (digit == 1 && i == s.length() - 1)
            {
                ans1 += 1;
            }
            else if (i != s.length() - 1)
            {
                ans1 += digit / 2 * base10;
                ans2 += (digit / 2) * base10;
            }
            else if (i == s.length() - 1)
            {
                ans1 += digit / 2 * base10;
                ans2 += (digit / 2 + 1) * base10;
            }
            carry = digit == 19 ? 0 : 1;
        }
        base10 /= 10;
    }
    std::cout << ans1 << " " << ans2 << "\n";
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