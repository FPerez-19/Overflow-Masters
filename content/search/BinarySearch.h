/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: folklore
 * Description: Index of x in a sorted array, or -1. low and high are inclusive.
 * The midpoint is computed as low + (high - low) / 2 so it cannot overflow.
 * Time: O(\log N)
 * Status: untested
 */
#pragma once
int binSearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
