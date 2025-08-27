// Calc a^b^c % MOD by fermat's theorem.
// MOD is prime, a^(p-1) = 1 (mod p)

ll pou(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b&1) ans *= a, ans%=m;
        a*=a;
        a%=m;
        b/=2;
    }
    return ans;
}
 
void test_case(ll a, ll b, ll c) {
    b = pou(b, c, MOD - 1);
    return pou(a, b, MOD);
}
