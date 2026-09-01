const int MAXN = 1000001;
int divisors[MAXN];

void divisors() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j]++;
        }
    }
}