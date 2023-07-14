#ifndef __TREE_H_
#define __TREE_H_

typedef struct _node node;
typedef struct _node *Search_tree;
typedef long long ll;

struct _node
{
    ll e, sum;
    ll a, b;
    ll is_BST, check;
    ll max, min;
    Search_tree left;
    Search_tree right;
};

Search_tree Make_tree_node(ll x);
Search_tree Find(Search_tree T, ll x);

ll min(ll a, ll b);
ll max(ll a, ll b);
ll fun(Search_tree T);

void fill(Search_tree T);
void In_order_traversal(Search_tree T);

#endif