class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 100005;
    using ll = long long;
    vector<ll> fact, inv_fact;

    ll power(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void init_factorial() {
        fact.assign(MAX, 1);
        inv_fact.assign(MAX, 1);
        for (int i = 1; i < MAX; i++)
            fact[i] = fact[i - 1] * i % MOD;
        inv_fact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 1; i--)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    ll C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        init_factorial();
        ll ans=0;
        int change = n-k-1;
        return ((C(n-1, change)*m)%MOD*power(m-1, change))%MOD;
    }
};