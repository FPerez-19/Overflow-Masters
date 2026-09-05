/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: __gnu_pbds
 * Description: Order-statistics tree: a set that also answers "k-th smallest"
 * and "how many elements are smaller than x", both in logarithmic time. Also a
 * faster hash table than unordered\_map (no count method: use find).
 * Usage: indexed_set<char> s; *s.find_by_order(0); s.order_of_key('a');
 * Time: O(\log N) per operation on indexed\_set.
 * Status: untested
 */
#pragma once
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename Key, typename Val = null_type>
using indexed_set =
    tree<Key, Val, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <class Key, class Val = null_type>
using htable = gp_hash_table<Key, Val>;
