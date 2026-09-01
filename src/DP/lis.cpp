int lis(vec<int>& arr) {
    if (arr.empty()) return 0;
    vec<int> tails;
    tails.push_back(arr[0]);

    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > tails.back()) {
            tails.push_back(arr[i]);
        } else {
            *lower_bound(ALL(tails), arr[i]) = arr[i];
        }
    }
    return tails.size();
}