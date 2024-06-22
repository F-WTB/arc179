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

int N;
vector<int> v;

map<pr, bool> b, m;

auto cmp = [](int i, int j) {
    if (b[make_pair(i, j)])
        return m[make_pair(i, j)];
    b[make_pair(i, j)] = 1;
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    cin >> m[make_pair(i, j)];
    return m[make_pair(i, j)];
};

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        v.push_back(i);
    sort(v.begin(), v.end(), cmp);

    for (int t = 0; t < N - 1; ++t) {
        int i = *v.begin();
        int j = *v.rbegin();
        v.erase(v.begin());
        v.erase(v.end() - 1);
        cout << "+ " << i + 1 << ' ' << j + 1 << endl;
        int k;
        cin >> k;
        --k;
        auto it = lower_bound(v.begin(), v.end(), k, cmp);
        v.insert(it, k);
    }
    cout << '!' << '\n';
}
