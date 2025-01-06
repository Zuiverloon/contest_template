/**
 * https://codeforces.com/problemset/problem/2048/C
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

void f(std::string &s)
{
    std::vector<ll> sb(s.length(), 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            sb[i] = 1;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (sb[i] == 0)
        {
            ll l2 = s.length() - i;
            // std::cout << "l2=" << l2 << "\n";
            ll zero = 0;
            ll start = -1, end = -1;
            for (int j = 0; j + l2 - 1 < s.length(); j++)
            {
                // std::cout << "start j = " << j << "\n";
                bool haszero = false;
                for (int k = 0; k < l2; k++)
                {
                    if ((sb[j + k] ^ sb[i + k]) == 0)
                    {
                        // std::cout << (j + k) << " " << (i + k) << " xor is zero\n";
                        haszero = true;
                        if (i + k > zero)
                        {
                            zero = i + k;
                            start = j;
                            end = j + l2 - 1;
                        }
                        break;
                    }
                }
                if (!haszero)
                {
                    // std::cout << "not have zero\n";
                    std::cout << 1 << " " << s.length() << " " << j + 1 << " " << j + 1 + l2 - 1 << "\n";
                    return;
                }
            }
            if (start == -1)
            {
                std::cout << 1 << " " << s.length() << " " << 1 << " " << l2 << "\n";
            }
            else
            {
                std::cout << 1 << " " << s.length() << " " << start + 1 << " " << end + 1 << "\n";
            }
            return;
        }
    }
    std::cout << 1 << " " << s.length() << " " << 1 << " " << 1 << "\n";
}

void solve(int cas)
{
    std::string s;
    std::cin >> s;
    f(s);
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