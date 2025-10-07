

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
ll mod1e8 = 100000000LL - 3;

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

void printYes()
{
	cout << "Yes\n";
}

void printNo()
{
	cout << "No\n";
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

ll getexgcd(ll i, ll mod)
{
	ll x, y;
	exgcd(i, mod, x, y);
	if (x < 0)
	{
		x += mod;
	}
	return x % mod;
}

#define FOR(i, s, j, o) for (ll i = s; i < j; i += o)
#define FORR(i, s, j, o) for (ll i = s; i > j; i += o)

struct DSU
{
	vector<ll> fa;
	ll n;

public:
	DSU(ll len) : n(len)
	{
		fa = vector<ll>(len, 0);
		for (ll i = 0; i < fa.size(); i++)
		{
			fa[i] = i;
		}
	}

	ll get(ll o)
	{
		return 0;
	}

	void merge(ll x, ll y)
	{
	}
};

struct FT
{
private:
	vector<ll> v;
	ll n;
	ll lowbit(ll i)
	{
		return i & (-i);
	}

public:
	FT(ll len) : n(len)
	{
		v = vector<ll>(len, 0);
	}

	void add(ll pos, ll val)
	{
	}

	ll get(ll pos)
	{
		return 0;
	}

	ll get(ll l, ll r)
	{
		return get(r) - get(l - 1);
	}
};

struct LST
{
private:
	vector<ll> tree;
	vector<ll> tag;
	ll n;
	void pushdown(ll lb, ll rb, ll o)
	{

		return;
	}

public:
	LST(ll len) : n(len - 1)
	{
		tree = vector<ll>(4 * n + 10, 0);
		tag = vector<ll>(4 * n + 10, 0);
	}

	ll get(ll l, ll r)
	{
		return get(1, n, l, r, 0);
	}

	ll get(ll lb, ll rb, ll l, ll r, ll o)
	{
		return 0;
	}

	void update(ll l, ll r, ll val)
	{
		return update(1, n, l, r, val, 0);
	}

	void update(ll lb, ll rb, ll l, ll r, ll val, ll o)
	{
	}
};

// sparse table
struct ST
{
private:
	vector<vector<ll>> st;
	ll n;
	ll width;

public:
	ST(ll _n, ll _width) : n(_n), width(_width)
	{
		st = vector<vector<ll>>(n, vector<ll>(width, 0));
	}

	void init(vector<ll> &v)
	{
	}

	ll get(ll l, ll r)
	{
		return 0;
	}
};

void solve(int cas)
{
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
