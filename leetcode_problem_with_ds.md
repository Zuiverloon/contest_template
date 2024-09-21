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

dijkstra: 743
st 表(RMQ 区间最大最小值) sparse table: https://www.luogu.com.cn/problem/P3865
树形 dp：834(换根 dp)
