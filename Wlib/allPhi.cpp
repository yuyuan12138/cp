constexpr int N = 1E7;

bool isprime[N + 1];
int phi[N + 1];
std::vector<int> primes;

std::fill(isprime + 2, isprime + N + 1, true);
phi[1] = 1;
for (int i = 2; i <= N; i++) {
    if (isprime[i]) {
        primes.push_back(i);
        phi[i] = i - 1;
    }
    for (auto p : primes) {
        if (i * p > N) {
            break;
        }
        isprime[i * p] = false;
        if (i % p == 0) {
            phi[i * p] = phi[i] * p;
            break;
        }
        phi[i * p] = phi[i] * (p - 1);
    }
}