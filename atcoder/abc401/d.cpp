
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

void solve(int cas)
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans(s);
    ll os = 0;
    ll qs = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            os++;
        }
        else if (s[i] == '?')
        {
            qs++;
        }
    }
    if (os == k)
    {
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] == '?')
            {
                ans[i] = '.';
            }
        }
        cout << ans << "\n";
        return;
    }
    if (os + qs == k)
    {
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] == '?')
            {
                ans[i] = 'o';
            }
        }
        cout << ans << "\n";
        return;
    }
    else
    {
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    if (s[i + 1] == 'o')
                    {
                        s[i] = '.';
                    }
                }
                else if (i == n - 1)
                {
                    if (s[i - 1] == 'o')
                    {
                        s[i] = '.';
                    }
                }
                else
                {
                    if (s[i - 1] == 'o' || s[i + 1] == 'o')
                    {
                        s[i] = '.';
                    }
                }
            }
        }
        ans = string(s);
        ll ts = 0;
        ll cont = 0;
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] == '?')
            {
                cont++;
            }
            else
            {
                ts += (cont + 1) / 2;
                cont = 0;
            }
        }
        if (cont != 0)
        {
            ts += (cont + 1) / 2;
        }
        // cout << "ts=" << ts << "\n";
        if (ts + os != k)
        {
            cout << ans << "\n";
        }
        else
        {
            // cout << "ans=" << ans << "\n";
            cont = 0;
            for (ll i = 0; i < n; i++)
            {
                if (ans[i] == '?')
                {
                    cont++;
                }
                else
                {
                    // cout << "cont=" << cont << "\n";
                    if (cont % 2 == 0)
                    {
                        cont = 0;
                    }
                    else
                    {
                        char c = 'o';
                        for (ll j = 1; j <= cont; j++)
                        {
                            // cout << "inloop" << "\n";
                            ans[i - j] = c;
                            c = (c == 'o') ? '.' : 'o';
                        }
                        cont = 0;
                    }
                }
            }
            if (cont % 2 != 0)
            {
                char c = 'o';
                for (ll j = 1; j <= cont; j++)
                {
                    // cout << "inloop" << "\n";
                    ans[n - j] = c;
                    c = (c == 'o') ? '.' : 'o';
                }
                cont = 0;
            }
            cout << ans << "\n";
        }

        return;
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
