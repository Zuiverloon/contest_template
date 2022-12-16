#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// g++ main.cpp -o main

template <typename T>
void printVector(vector<T> v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << " ";
	}
	cout << v[v.size() - 1] << endl;
}

template <typename T>
void printVectorNoSpace(vector<T> v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i];
	}
	cout << v[v.size() - 1] << endl;
}



int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool isPrime(int a)
{
	if (a == 1)
		return false;
	if (a == 2)
		return true;
	if (a % 2 == 0)
		return false;
	int limit = (int)sqrt(a);
	for (int i = 3; i <= limit; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}


template <typename T>
bool isinset(unordered_set<T> s, T n)
{
	return s.find(n) != s.end();
}

ll power(int a, int n)
{
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans *= a;
	}
	return ans;
}

void printCase(int i)
{
	cout << "case #" << i << ":" << endl;
}

struct cmp
{
    bool operator()(string& s1, string& s2)
    {
        if (s1+s2<s2+s1)return s1>s2;
		else return s2>s1;
    }
};

bool vequal(vector<int>& v1,vector<int>& v2){
	for (int i = 0;i<v1.size();i++){
		if (v1[i]!=v2[i])return false;
	}
	return true;
}

int main(){
	return 0;
}


