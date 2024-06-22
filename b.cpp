#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int M, N, X[10], a[10];

mint dp[10001][1 << 10];

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; ++i) cin >> X[i], --X[i];

    dp[0][(1 << M) - 1] = 1;

    for (int i = 0; i < M; ++i)
        a[X[i]] |= 1 << i;

    for (int i = 0; i < N; ++i)
        for (int bit = 0; bit < 1 << M; ++bit)
            for (int k = 0; k < M; ++k)
                if (bit & (1 << k))
                    dp[i + 1][bit ^ (1 << k) | a[k]] += dp[i][bit];

    mint ans = 0;
    for (int i = 0; i < 1 << M; ++i)
        ans += dp[N][i];
    cout << ans << '\n';
}
