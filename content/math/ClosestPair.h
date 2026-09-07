/**
 * Author: Franco Perez
 * Date: 2026-09-05
 * License: CC0
 * Source: sweep line
 * Description: Closest pair of points, sweeping on x with a set ordered by y and
 * a window of width D. Returns the two points; the set stores them swapped as
 * {y, x}, which is what makes the y-range lookup work.
 * Usage: coord as {x, y}; the input is sorted in place.
 * Time: O(N \log N)
 * Status: untested
 */
#pragma once
vec<pair<ld, ld>> closestPair(vec<pair<ld, ld>> coord, int n) {
    sort(all(coord));
    set<pair<ld, ld>> s;
    ld squaredDistance = LLONG_MAX;
    vec<pair<ld, ld>> ans;
    int j = 0;
    L(i, 0, n) {
        ld D = ceil(sqrt(squaredDistance));
        while (coord[i].first - coord[j].first >= D) {
            s.erase({coord[j].second, coord[j].first});
            j += 1;
        }
        auto start = s.lower_bound({coord[i].second - D, coord[i].first});
        auto end = s.upper_bound({coord[i].second + D, coord[i].first});
        for (auto it = start; it != end; ++it) {
            ld dx = coord[i].first - it->second;
            ld dy = coord[i].second - it->first;
            ld preDist = min(squaredDistance, dx * dx + dy * dy);
            if (preDist < squaredDistance) {
                ans = {{it->second, it->first}, {coord[i].first, coord[i].second}};
                squaredDistance = preDist;
            }
        }
        s.insert({coord[i].second, coord[i].first});
    }
    return ans;
}
