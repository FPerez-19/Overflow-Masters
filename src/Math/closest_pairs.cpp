vec<pair<ld, ld>> closestPair(vec<pair<ld, ld>> coord, int n) {
    sort(ALL(coord));
    set<pair<ld, ld>> s;
    ld squaredDistance = LLONG_MAX;
    vec<pair<ld, ld>> ans;
    int j = 0;
    for (int i = 0; i < n; ++i) {
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
                pair<ld, ld> one = {it->second, it->first};
                pair<ld, ld> two = {coord[i].first, coord[i].second};
                ans = {one, two};
                squaredDistance = preDist;
            }
        }

        // Insert the point as {y-coordinate, x-coordinate}
        s.insert({coord[i].second, coord[i].first});
    }
    return ans;
}