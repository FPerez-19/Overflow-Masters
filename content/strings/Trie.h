/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Prefix tree over a map per node, so the alphabet can be anything.
 * Node 0 is the root and eee marks the end of an inserted word. Call initTrie()
 * before the first insert, and again between test cases.
 * Usage: initTrie(); insert(word);
 * Time: O(|word| \log \Sigma) per insert
 * Status: untested
 */
#pragma once
struct Trie {
    map<char, int> ch;
    bool eee;
    Trie() : eee(false) {}
};
vec<Trie> t;
void initTrie() {
    t.clear();
    t.pb(Trie());
}
void insert(string &word) {
    int v = 0;
    for (char c : word) {
        if (!t[v].ch[c]) {
            t[v].ch[c] = sz(t);
            t.pb(Trie());
        }
        v = t[v].ch[c];
    }
    t[v].eee = 1;
}
