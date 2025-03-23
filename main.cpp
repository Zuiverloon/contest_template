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
	std::cin >> n >> k;
	std::vector<ll> v(n, 0);
	for (ll i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
	auto cmp = [&](std::vector<ll> &a1, std::vector<ll> &a2)
	{
		return a1[1] < a2[1];
	};
	std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::function<bool(std::vector<ll> & a, std::vector<ll> & b)>> pq(cmp);
	std::map<ll, std::map<ll, ll>> mp;
	pq.push(std::vector<ll>{1, 0, 0});
	pq.push(std::vector<ll>{1, v[0], k});
	mp[1][k] = v[0];
	ll ans = 0;

	while (pq.size() > 0)
	{
		auto fr = pq.top();
		pq.pop();
		ll timeleft = fr[2];
		ll deli = fr[1];
		ll offset = fr[0];

		ll nx = 0;
		if (deli < mp[offset][timeleft])
		{
			continue;
		}
		if (timeleft > n - offset)
		{
			continue;
		}
		if (timeleft == n - offset)
		{
			ans = std::max({ans, deli});
			continue;
		}
		if (timeleft == 0)
		{
			ans = std::max({ans, deli});
		}
		if (offset == n)
		{
			if (timeleft != 0)
			{
				continue;
			}
			else
			{
				ans = std::max({ans, deli});
				break;
			}
		}
		// do nothing
		nx = mp[offset + 1][timeleft];
		if ((nx != 0 && nx < deli) || nx == 0)
		{
			mp[offset + 1][timeleft] = deli;
			pq.push(std::vector<ll>{offset + 1, deli, timeleft});
		}
		// eat
		if (timeleft > 0)
		{
			nx = mp[offset + 1][timeleft - 1];
			if ((nx != 0 && nx < deli) || nx == 0)
			{
				mp[offset + 1][timeleft] = deli;
				pq.push(std::vector<ll>{offset + 1, deli, timeleft - 1});
			}
		}
		nx = mp[offset + 1][timeleft + k];
		if ((nx != 0 && nx < deli + v[offset]) || nx == 0)
		{
			// add
			mp[offset + 1][timeleft + k] = deli + v[offset];
			pq.push(std::vector<ll>{
				offset + 1,
				deli + v[offset],
				timeleft + k});
		}
	}
	std::cout << ans << "\n";
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