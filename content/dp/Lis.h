/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: patience sorting
 * Description: Length of the longest strictly increasing subsequence. tails is
 * not the subsequence itself, only its length is meaningful. For the
 * non-decreasing version use upper\_bound and compare with >=.
 * Time: O(N \log N)
 * Status: untested
 */
#pragma once
int lis(vec<int> &arr) {
    if (arr.empty()) return 0;
    vec<int> tails;
    tails.pb(arr[0]);
    L(i, 1, sz(arr)) {
        if (arr[i] > tails.back())
            tails.pb(arr[i]);
        else
            *lower_bound(all(tails), arr[i]) = arr[i];
    }
    return sz(tails);
}
