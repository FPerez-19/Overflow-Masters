int main() {
    int cant = 0, start = 0, end = 0, sum = 0;
    while (end < n) {
        while (end < n && sum < x) {
            sum += arr[end];
            end++;
        }
        while (start <= end && sum > x) {
            sum -= arr[start];
            start++;
        }
        if (sum == x) {
            cant++;
            sum -= arr[start];
            start++;
        }
    }
    cout << cant;
    return 0;
}