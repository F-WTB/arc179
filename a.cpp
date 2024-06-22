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

int N, K, A[200000];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    if (K > 0) {
        sort(A, A + N);
        cout << "Yes\n";
        for (int i = 0; i < N; ++i) cout << A[i] << (i < N - 1 ? '\t' : '\n');
        return 0;
    }

    sort(A, A + N, greater<>());
    ll s = 0;
    for (int i = 0; i < N; ++i) {
        s += A[i];
        if (s < K) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < N; ++i) cout << A[i] << (i < N - 1 ? '\t' : '\n');
}
