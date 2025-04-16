/**
 * https://www.luogu.com.cn/problem/P1725
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

ll countone(ll a)
{
    ll ans = 0;
    while (a > 0)
    {
        ans += (a & 1);
        a >>= 1;
    }
    return ans;
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
    ll n, l, r;
    cin >> n >> l >> r;
    n++;
    vector<ll> v(n, 0);
    vector<ll> ans(n, -0x3f3f3f3f);

    auto cmp = [&](vector<ll> &a1, vector<ll> &a2)
    {
        return a1[1] < a2[1];
    };
    priority_queue<vector<ll>, vector<vector<ll>>, function<bool(vector<ll> & a1, vector<ll> & a2)>> pq(cmp);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // printVector(v);
    //  pq.push(vector<ll>{0, 0});
    ll a = -0x3f3f3f3f;
    ans[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        //	cout << "i=" << i << "\n";
        if (i - l >= 0 && ans[i - l] != -0x3f3f3f3f)
        {
            pq.push(vector<ll>{i - l, ans[i - l]});
        }
        while (!pq.empty())
        {
            auto tp = pq.top();
            if (tp[0] + r < i)
            {
                pq.pop();
            }
            else
            {
                ans[i] = v[i] + tp[1];
                break;
            }
        }
        // cout << "ansi " << i << " " << ans[i] << "\n";
        if (i + r > n - 1)
        {
            a = max({a, ans[i]});
        }
    }
    // printVector(ans);
    cout << a << "\n";
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
