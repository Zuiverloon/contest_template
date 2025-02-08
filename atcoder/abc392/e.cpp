
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

ll get(std::vector<ll> &fa, ll a)
{
    if (fa[a] != a)
    {
        fa[a] = get(fa, fa[a]);
    }
    return fa[a];
}
ll f(std::unordered_map<ll, ll> &to, ll a, std::vector<ll> &fa3, ll f)
{
    for (auto &p : to)
    {
        if (p.first != a && get(fa3, p.first) != f)
        {
            return p.first;
        }
    }
    return 0;
}

void merge(std::vector<ll> &fa, ll a1, ll a2)
{
    fa[get(fa, a1)] = get(fa, a2);
}

void solve(int cas)
{
    ll n, m;
    std::cin >> n >> m;
    std::vector<std::vector<ll>> v(m, std::vector<ll>(2, 0));
    std::vector<ll> fa1(n + 1, 0);
    std::vector<ll> fa2(n + 1, 0);
    std::vector<ll> fa3(n + 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        fa1[i] = i;
        fa2[i] = i;
        fa3[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> v[i][0] >> v[i][1];

        merge(fa1, v[i][0], v[i][1]);
    }
    std::set<ll> con;

    std::unordered_map<ll, ll> to;
    std::unordered_map<ll, ll> to2;
    for (int i = 1; i <= n; i++)
    {
        ll ff = get(fa1, i);
        con.insert(ff);
        to[ff] = i;
        // to2[ff] = i;
    }
    // std::cout << "con size=" << con.size() << "\n";
    if (con.size() == 1)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        std::vector<std::vector<ll>> ans(con.size() - 1, std::vector<ll>(3, 0));
        ll ansp = 0;
        for (int i = 0; i < m; i++)
        {
            if (ansp == ans.size())
                break;
            ll a1 = v[i][0];
            ll a2 = v[i][1];
            ll ff1 = get(fa2, a1);
            ll ff2 = get(fa2, a2);
            // if (to[ff1] == 0)
            // {
            // 	continue;
            // }
            if (ff1 != ff2)
            {
                // std::cout << "merge\n";
                merge(fa2, a1, a2);
            }
            else
            {
                // std::cout << "reconnect\n";
                //  connect to another graph
                ll ff = get(fa1, a1);
                ll ano = f(to, ff, fa3, get(fa3, ff));
                // std::cout << "ano=" << ano << "\n";
                if (ano == 0)
                {
                    continue;
                }
                merge(fa3, ff, ano);
                ans[ansp][0] = i + 1;
                ans[ansp][1] = a1;
                ans[ansp++][2] = to[ano];
                to.erase(ano);
                // to.erase(ff);
            }
        }
        std::cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            printVector(ans[i]);
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