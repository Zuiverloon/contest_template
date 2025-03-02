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
    ll n;
    std::cin >> n;
    std::vector<std::string> v(n, std::string(n, ' '));
    ll limit = n * n;
    for (int i = 0; i <= n / 2; i += 1)
    {
        ll r = i, c = i;
        ll d = 0;
        char ch = i % 2 == 0 ? '#' : '.';
        // ll trans = 0;
        while (limit > 0)
        {
            // std::cout << r << " " << c << "\n";
            v[r][c] = ch;
            limit--;
            if (limit == 0)
            {
                break;
            }

            if (d == 0)
            {
                if (c + 1 >= n - i)
                {
                    d++;
                    r++;
                }
                else
                {
                    c++;
                }
            }
            else if (d == 1)
            {
                if (r + 1 >= n - i)
                {
                    d++;
                    c--;
                }
                else
                {
                    r++;
                }
            }
            else if (d == 2)
            {
                if (c - 1 < i)
                {
                    r--;
                    d++;
                }
                else
                {
                    c--;
                }
            }
            else if (d == 3)
            {
                if (r - 1 <= i)
                {
                    break;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    for (std::string s : v)
    {
        std::cout << s << "\n";
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