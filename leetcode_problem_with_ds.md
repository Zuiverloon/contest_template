## 并查集(dsu)

场景: 求节点所属集合，求图连通性  
模版: [leetcode 2316](https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)  
lc: 886,2316,839,1697

```c++
std::vector<ll> fa;

ll get(ll x){
    if (fa[x]!=x){
        fa[x] = get(fa[x]);
    }
    return fa[x];
}

void merge(ll x, ll y){
    fa[get(x)] = get(y);
}
```

线段树(单点修改、区间修改、区间查询) segment tree:2569,2286(单点修改)
拓扑排序:207,剑指 Offer II 114. 外星文字典(https://leetcode.cn/problems/Jf1JuT/)
排序:912
kmp:28

## 倍增 LCA(Least Common Ancestor)

场景：求树中任意两点最近公公祖先
模版：[LUOGU 3379](https://www.luogu.com.cn/problem/P3379)

```c++
#define famax 21
std::vector<std::vector<ll>> nei;
std::vector<ll> dep;
std::vector<std::vector<ll>> fa;

void dfs(ll o, ll f)
{
	dep[o] = dep[f] + 1;
	fa[o][0] = f;
	for (ll i = 1; i < famax; i++)
	{
		fa[o][i] = fa[fa[o][i - 1]][i - 1];
	}
	for (ll n : nei[o])
	{
		if (n != f)
		{
			dfs(n, o);
		}
	}
}

ll lca(ll a, ll b)
{
	if (dep[a] < dep[b])
	{
		return lca(b, a);
	}
	ll gap = dep[a] - dep[b];
	ll base = 0;
	while (gap > 0)
	{
		if ((gap & 1) == 1)
		{
			a = fa[a][base];
		}
		base++;
		gap >>= 1;
	}
	if (a == b)
	{
		return b;
	}
	for (int i = famax - 1; i >= 0; i--)
	{
		if (fa[a][i] != fa[b][i])
		{
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	if (a == b)
	{
		return a;
	}
	return fa[a][0];
}

for (int i = 0; i < n - 1; i++)
	{
		ll a, b;
		std::cin >> a >> b;
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
dfs(s, 0);

```

## 树状数组(fenwick tree)

场景：单点更新，区间查询（可差分 如区间和）  
模版: [leetcode 307](https://leetcode.cn/problems/range-sum-query-mutable/description/)  
lc: 307, 2659,315

```c++
// ft[8] = v[1]+...+v[8] lowbit(8) = 8
// ft[7] = v[7] lowbit(7) = 1
// ft[6] = v[5]+v[6] lowbit(6) = 2
std::vector<ll> ft;

ll lowbit(ll i){
    return i&(-i);
}

ll get(ll pos) {
    ll ans = 0;
    while (pos>0){
        ans+=ft[pos];
        pos-=lowbit(pos);
    }
    return ans;
}

void add(ll pos, ll val){
    while (pos<ft.size()){
        ft[pos]+=val;
        pos+=lowbit(pos);
    }
}
```

## 主席树(动态开点前缀和权值线段树)

场景：n=100000，求 n 次某一区间内某个权值出现次数
模版：[luogu 3567](https://www.luogu.com.cn/problem/P3567)

```c++
struct hjtree
{
	int l;
	int r;
	int v;
};

std::vector<hjtree>
	tree(12000000); // 存每个主席树节点
int cnt = 0;
std::vector<int> root(500005); // 存每个下标的根结点 每个下标本应该是一棵树 为了节省空间 复用了前一棵树的大部分（除了一条链）

void build(int &o, int pre, int l, int r, int x)
{
	o = ++cnt;
	// 给当前节点一个新的数组空间
	tree[o] = tree[pre]; // 初始化当前节点，与前任节点相同
	tree[o].v++;
	if (l == r) // 搜到叶子 返回
		return;
	int mid = (l + r) / 2;
	if (x <= mid)
	{
		build(tree[o].l, tree[pre].l, l, mid, x); // 修改当前节点的左儿子， 当前节点的左儿子和前任节点的左儿子应该相同
	}
	else
	{
		build(tree[o].r, tree[pre].r, mid + 1, r, x); // 或修改右儿子
	}
}

int query(int rr, int rl, int l, int r, int val)
// 区间为[rl,rr], 值域为(l,r)中 有没有某个权值出现的次数大于val次
{
	if (tree[rr].v - tree[rl].v <= val)
	{
		return 0;
	}
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) / 2;
	int t1 = query(tree[rr].l, tree[rl].l, l, mid, val);
	if (t1 != 0)
		return t1;
	return query(tree[rr].r, tree[rl].r, mid + 1, r, val);
}

```

dijkstra: 743
st 表(RMQ 区间最大最小值) sparse table: https://www.luogu.com.cn/problem/P3865
树形 dp：834(换根 dp)
