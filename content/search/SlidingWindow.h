/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Number of contiguous subarrays whose sum is exactly x. Only valid
 * for non-negative values: the window can shrink because the sum is monotone in
 * its endpoints. With negatives, use a prefix-sum map instead.
 * Time: O(N)
 * Status: untested
 */
#pragma once
int count_windows(vec<ll> &arr, ll x) {
    int n = sz(arr), cant = 0, start = 0, end = 0;
    ll sum = 0;
    while (end < n) {
        while (end < n && sum < x) sum += arr[end++];
        while (start <= end && sum > x) sum -= arr[start++];
        if (sum == x) {
            cant++;
            sum -= arr[start++];
        }
    }
    return cant;
}
