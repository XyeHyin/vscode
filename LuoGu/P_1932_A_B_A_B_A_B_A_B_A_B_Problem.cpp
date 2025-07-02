// name: P_1932_A_B_A_B_A_B_A_B_A_B_Problem.cpp
// date 2025-06-21
// author: XyeHyin

#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")

// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

#define int long long
#define d64 long double
#define PII pair<int, int>
#define ff first
#define ss second
#define itn signed
#define dbg(x) std::cout << #x << ":" << x << " "
#define dbgl(x) std::cout << #x << ":" << x << "\n"
#define all(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define arrin0(a, n) rep(i, 0, n - 1) std::cin >> a[i]
#define arrout0(a, n) rep(i, 0, n - 1) std::cout << a[i]
#define endl "\n"
#define mem(a, x) memset(a, x, sizeof a)
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define yes() cout << "yes" << endl
#define no() cout << "no" << endl

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e18;
const int inf = 0x3f3f3f3f;
const PII d8[8] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                   {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const PII d4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const PII d3[3] = {{0, 1}, {1, 0}, {0, 1}};
const PII d2[2] = {{0, 1}, {1, 0}};
const double PI = acos(-1);
const double eps = 1e-9;
const int mod1 = 998244353;
struct BIGINT {
    static const itn base = 1000, base_digits = 3;

    // —— 算法切换阈值 ——
    static constexpr size_t KARATSUBA_THRESHOLD = 64;
    static constexpr size_t FFT_THRESHOLD = 2048;

    // —— NTT 参数 ——
    static const itn NTT_MOD = 998244353;
    static const itn NTT_ROOT = 3;

    vector<itn> a;
    itn sign;

    BIGINT() : sign(1) {}

    BIGINT(long long v) { *this = v; }

    BIGINT &operator=(long long v) {
        sign = v < 0 ? -1 : 1;
        v = llabs(v);
        a.clear();
        for (; v; v /= base)
            a.push_back(v % base);
        return *this;
    }

    BIGINT(const string &s) { read(s); }

    BIGINT &read(const string &s) {
        sign = 1;
        a.clear();
        itn pos = 0, len = s.size();
        if (s[0] == '-' || s[0] == '+') {
            if (s[0] == '-')
                sign = -1;
            pos++;
        }
        for (itn i = len - 1; i >= pos; i -= base_digits) {
            itn x = 0;
            itn l = max(pos, i - base_digits + 1);
            for (itn j = l; j <= i; j++)
                x = x * 10 + (s[j] - '0');
            a.push_back(x);
        }
        trim();
        return *this;
    }

    friend ostream &operator<<(ostream &os, const BIGINT &v) {
        if (v.sign == -1 && !v.isZero())
            os << '-';
        if (v.a.empty()) {
            os << '0';
        } else {
            os << v.a.back();
            char buf[16];
            for (itn i = (itn)v.a.size() - 2; i >= 0; --i) {
                snprintf(buf, sizeof(buf), "%03d", v.a[i]);
                os << buf;
            }
        }
        return os;
    }
    friend istream &operator>>(istream &is, BIGINT &v) {
        string s;
        is >> s;
        v.read(s);
        return is;
    }

    bool isZero() const { return a.empty(); }

    BIGINT operator-() const {
        BIGINT r = *this;
        if (!isZero())
            r.sign = -sign;
        return r;
    }

    // 比较绝对值
    static itn cmpAbs(const BIGINT &a, const BIGINT &b) {
        if (a.a.size() != b.a.size())
            return a.a.size() < b.a.size() ? -1 : 1;
        for (itn i = (itn)a.a.size() - 1; i >= 0; --i)
            if (a.a[i] != b.a[i])
                return a.a[i] < b.a[i] ? -1 : 1;
        return 0;
    }

    friend bool operator<(const BIGINT &a, const BIGINT &b) {
        if (a.sign != b.sign)
            return a.sign < b.sign;
        itn cmp = cmpAbs(a, b);
        return a.sign == 1 ? (cmp < 0) : (cmp > 0);
    }
    friend bool operator==(const BIGINT &a, const BIGINT &b) {
        return a.sign == b.sign && a.a == b.a;
    }
    friend bool operator!=(const BIGINT &a, const BIGINT &b) {
        return !(a == b);
    }
    friend bool operator>(const BIGINT &a, const BIGINT &b) { return b < a; }
    friend bool operator<=(const BIGINT &a, const BIGINT &b) {
        return !(b < a);
    }
    friend bool operator>=(const BIGINT &a, const BIGINT &b) {
        return !(a < b);
    }

    BIGINT &trim() {
        while (!a.empty() && a.back() == 0)
            a.pop_back();
        if (a.empty())
            sign = 1;
        return *this;
    }

    // 加减：先比较绝对值
    BIGINT operator+(const BIGINT &v) const {
        if (sign == v.sign) {
            BIGINT res = v;
            itn carry = 0;
            for (size_t i = 0; i < max(a.size(), v.a.size()) || carry; ++i) {
                if (i == res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    BIGINT operator-(const BIGINT &v) const {
        if (sign == v.sign) {
            if (cmpAbs(*this, v) >= 0) {
                BIGINT res = *this;
                itn carry = 0;
                for (size_t i = 0; i < v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                return res.trim();
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    // 3. Karatsuba 乘法实现
    static vector<long long> multiply_karatsuba(const vector<itn> &x,
                                                const vector<itn> &y) {
        itn n = x.size(), m = y.size();
        if (min(n, m) < 32) {
            vector<long long> c(n + m);
            for (itn i = 0; i < n; ++i)
                for (itn j = 0; j < m; ++j)
                    c[i + j] += 1ll * x[i] * y[j];
            return c;
        }
        itn k = max(n, m) / 2;
        vector<itn> x0(x.begin(), x.begin() + min(n, k));
        vector<itn> x1(x.begin() + min(n, k), x.end());
        vector<itn> y0(y.begin(), y.begin() + min(m, k));
        vector<itn> y1(y.begin() + min(m, k), y.end());

        // 修复：确保高位数组至少和低位一样长，避免下面累加越界
        if (x1.size() < x0.size())
            x1.resize(x0.size());
        if (y1.size() < y0.size())
            y1.resize(y0.size());

        auto z0 = multiply_karatsuba(x0, y0);
        auto z2 = multiply_karatsuba(x1, y1);
        for (itn i = 0; i < (itn)x0.size(); ++i)
            x1[i] += x0[i];
        for (itn i = 0; i < (itn)y0.size(); ++i)
            y1[i] += y0[i];
        auto z1 = multiply_karatsuba(x1, y1);
        for (itn i = 0; i < (itn)z0.size(); ++i)
            z1[i] -= z0[i];
        for (itn i = 0; i < (itn)z2.size(); ++i)
            z1[i] -= z2[i];

        vector<long long> res(n + m);
        for (itn i = 0; i < (itn)z0.size(); ++i)
            res[i] += z0[i];
        for (itn i = 0; i < (itn)z1.size(); ++i)
            res[i + k] += z1[i];
        for (itn i = 0; i < (itn)z2.size(); ++i)
            res[i + 2 * k] += z2[i];
        return res;
    }

    // FFT 实现大整数乘法
    using cd = complex<long double>;
    inline static vector<cd> fwd_roots, inv_roots;
    inline static vector<itn> rev;
    static void prepare_fft(itn n) {
        if ((itn)rev.size() == n)
            return;
        rev.assign(n, 0);
        for (itn i = 1, j = 0; i < n; i++) {
            itn bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j |= bit;
            rev[i] = j;
        }
        fwd_roots.resize(n);
        inv_roots.resize(n);
        long double ang = 2 * PI / n;
        for (itn i = 0; i < n; i++) {
            fwd_roots[i] = cd(cos(ang * i), sin(ang * i));
            inv_roots[i] = conj(fwd_roots[i]);
        }
    }

    static void fft(vector<cd> &a, bool invert) {
        itn n = a.size();
        prepare_fft(n);
        for (itn i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        for (itn len = 2; len <= n; len <<= 1) {
            itn step = n / len;
            for (itn i = 0; i < n; i += len) {
                for (itn j = 0; j < len / 2; j++) {
                    cd u = a[i + j];
                    cd v = a[i + j + len / 2] *
                           (invert ? inv_roots[step * j] : fwd_roots[step * j]);
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                }
            }
        }
        if (invert)
            for (auto &x : a)
                x /= n;
    }

    static vector<long long> multiply_fft(const vector<itn> &a,
                                          const vector<itn> &b) {
        vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        itn n = 1;
        while (n < (itn)a.size() + (itn)b.size())
            n <<= 1;
        fa.resize(n);
        fb.resize(n);
        fft(fa, false);
        fft(fb, false);
        for (itn i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);
        vector<long long> res(n);
        for (itn i = 0; i < n; ++i)
            res[i] = llround(fa[i].real());
        return res;
    }

    // NTT 实现（模 998244353，快速且无浮点误差）
    // NTT 实现（模 998244353，快速且无浮点误差）
    static void ntt(vector<itn> &a, bool invert) {
        itn n = a.size(), root = NTT_ROOT, mod = NTT_MOD;
        static vector<itn> rev_ntt;
        static vector<itn> roots{0, 1};
        if ((itn)rev_ntt.size() != n) {
            rev_ntt.assign(n, 0);
            for (itn i = 0; i < n; i++) {
                rev_ntt[i] = (rev_ntt[i >> 1] >> 1) | ((i & 1) * (n >> 1));
            }
        }
        if ((itn)roots.size() < n) {
            roots.resize(n);
            auto mod_pow = [](itn base, itn exp, itn mod) {
                itn result = 1;
                while (exp > 0) {
                    if (exp & 1)
                        result = itn(1LL * result * base % mod);
                    base = itn(1LL * base * base % mod);
                    exp >>= 1;
                }
                return result;
            };
            for (itn i = 1; i < n; i++) {
                roots[i] = mod_pow(root, (mod - 1) / n * i, mod);
            }
        }
        for (itn i = 0; i < n; i++)
            if (i < rev_ntt[i])
                swap(a[i], a[rev_ntt[i]]);
        for (itn len = 2; len <= n; len <<= 1) {
            itn step = n / len;
            for (itn i = 0; i < n; i += len) {
                for (itn j = 0; j < len / 2; j++) {
                    itn u = a[i + j];
                    itn v =
                        itn(1LL * a[i + j + len / 2] * roots[step * j] % mod);
                    a[i + j] = u + v < mod ? u + v : u + v - mod;
                    a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                }
            }
        }
        if (invert) {
            auto mod_pow = [](itn base, itn exp, itn mod) {
                itn result = 1;
                while (exp > 0) {
                    if (exp & 1)
                        result = itn(1LL * result * base % mod);
                    base = itn(1LL * base * base % mod);
                    exp >>= 1;
                }
                return result;
            };
            itn inv_n = mod_pow(n, mod - 2, mod);
            for (itn &x : a)
                x = itn(1LL * x * inv_n % mod);
        }
    }

    static vector<long long> multiply_ntt(const vector<itn> &a,
                                          const vector<itn> &b) {
        itn n = 1;
        while (n < (itn)a.size() + (itn)b.size())
            n <<= 1;
        vector<itn> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        fa.resize(n);
        fb.resize(n);
        ntt(fa, false);
        ntt(fb, false);
        for (itn i = 0; i < n; i++)
            fa[i] = itn(1LL * fa[i] * fb[i] % NTT_MOD);
        ntt(fa, true);
        vector<long long> res(n);
        for (itn i = 0; i < n; i++)
            res[i] = fa[i];
        return res;
    }

    BIGINT operator*(const BIGINT &v) const {
        BIGINT res;
        res.sign = sign * v.sign;
        size_t na = a.size(), nb = v.a.size();
        vector<long long> c;

        size_t mn = min(na, nb);
        if (mn < KARATSUBA_THRESHOLD) {
            c = multiply_karatsuba(a, v.a);
        } else if (mn < FFT_THRESHOLD) {
            c = multiply_fft(a, v.a);
        } else {
            c = multiply_fft(a, v.a);
        }
        res.a.reserve(c.size());
        long long carry = 0;
        for (size_t i = 0; i < c.size(); ++i) {
            long long t = c[i] + carry;
            res.a.push_back(itn(t % base));
            carry = t / base;
        }
        while (carry) {
            res.a.push_back(itn(carry % base));
            carry /= base;
        }
        return res.trim();
    }

    // 乘以 itn，再 trim
    BIGINT mul_itn(itn m) const {
        if (m < 0)
            return -mul_itn(-m);
        BIGINT res;
        if (!m || isZero())
            return BIGINT(0);
        res.sign = sign;
        long long carry = 0;
        res.a.resize(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            long long cur = carry + 1ll * a[i] * m;
            res.a[i] = itn(cur % base);
            carry = cur / base;
        }
        while (carry) {
            res.a.push_back(itn(carry % base));
            carry /= base;
        }
        return res.trim();
    }

    // 6. 高精度阶乘
    static BIGINT factorial(itn n) {
        BIGINT res = 1;
        for (itn i = 2; i <= n; ++i)
            res = res.mul_itn(i);
        return res;
    }

    // NTT 专用乘法（强制使用 FFT 乘法）
    static BIGINT mul_fft(const BIGINT &x, const BIGINT &y) {
        BIGINT res;
        res.sign = x.sign * y.sign;
        auto c = multiply_fft(x.a, y.a);
        res.a.reserve(c.size());
        long long carry = 0;
        for (size_t i = 0; i < c.size(); ++i) {
            long long t = c[i] + carry;
            res.a.push_back(itn(t % base));
            carry = t / base;
        }
        while (carry) {
            res.a.push_back(itn(carry % base));
            carry /= base;
        }
        return res.trim();
    }

    // 递归分治法高精度幂（NTT 专用）
    static BIGINT pow_ntt(BIGINT a, long long b) {
        if (b == 0)
            return BIGINT(1);
        BIGINT half = pow_ntt(a, b >> 1);
        BIGINT res = mul_fft(half, half);
        if (b & 1)
            res = mul_fft(res, a);
        return res;
    }

    // 高精度幂运算：根据指数大小自动切换
    static BIGINT pow(BIGINT a, long long b) {
        const long long LARGE_EXP_THRESHOLD =
            100000; // 指数阈值，可根据需求调整
        if (b > LARGE_EXP_THRESHOLD) {
            // 指数很大时，用 NTT + 分治
            return pow_ntt(a, b);
        }
        // 否则继续使用原二分幂（默认乘法策略）
        BIGINT res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    // 高精度快速幂：BIGINT 指数
    static BIGINT pow(BIGINT a, const BIGINT &b) {
        BIGINT e = b;
        BIGINT res = 1;
        while (!e.isZero()) {
            if (e.a[0] & 1) // 低位为 1 时乘一次
                res *= a;
            a *= a;       // 平方
            e = e.div2(); // 右移一位
        }
        return res;
    }

    // 高精度快速幂：带模
    static BIGINT pow(BIGINT a, const BIGINT &b, const BIGINT &mod) {
        BIGINT e = b;
        a %= mod;
        BIGINT res = 1;
        while (!e.isZero()) {
            if (e.a[0] & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            e = e.div2();
        }
        return res;
    }

    // 10. 十进制/十六进制字符串构造
    BIGINT(const string &s, itn b) { *this = fromBase(s, b); }

    // 11. 位运算辅助
    static BIGINT bitwiseOp(const BIGINT &u, const BIGINT &v, itn op) {
        string as = u.toBase(2), bs = v.toBase(2);
        itn n = max(as.size(), bs.size());
        string res;
        res.reserve(n);
        for (itn i = 0; i < n; ++i) {
            char ca = i < n - as.size() ? '0' : as[i - (n - as.size())];
            char cb = i < n - bs.size() ? '0' : bs[i - (n - bs.size())];
            itn ba = ca - '0', bb = cb - '0', br = 0;
            if (op == 0)
                br = ba & bb;
            else if (op == 1)
                br = ba | bb;
            else if (op == 2)
                br = ba ^ bb;
            res.push_back(char('0' + br));
        }
        itn pos = 0;
        while (pos + 1 < (itn)res.size() && res[pos] == '0')
            ++pos;
        return fromBase(res.substr(pos), 2);
    }

    friend BIGINT operator&(const BIGINT &u, const BIGINT &v) {
        return bitwiseOp(u, v, 0);
    }
    friend BIGINT operator|(const BIGINT &u, const BIGINT &v) {
        return bitwiseOp(u, v, 1);
    }
    friend BIGINT operator^(const BIGINT &u, const BIGINT &v) {
        return bitwiseOp(u, v, 2);
    }

    // 移位运算：左移相当于乘以 2^k，右移相当于除以 2^k（向下取整）
    BIGINT operator<<(itn k) const {
        BIGINT res = *this;
        for (itn i = 0; i < k; ++i)
            res = res.mul_itn(2);
        return res;
    }
    BIGINT operator>>(itn k) const {
        BIGINT res = *this;
        for (itn i = 0; i < k; ++i)
            res = res.div2();
        return res;
    }
    string toBase(itn b) const {
        static const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        BIGINT tmp = *this;
        if (tmp.isZero())
            return "0";
        string s;
        s.reserve(a.size() * (base_digits + 1));
        BIGINT baseB(b);
        while (!tmp.isZero()) {
            BIGINT r = tmp % baseB;
            itn rem = r.a.empty() ? 0 : r.a[0];
            s.push_back(digits[rem]);
            tmp = tmp / baseB;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    static BIGINT fromBase(const string &s, itn b) {
        BIGINT res = 0, baseB(b);
        res.a.reserve(s.size() / base_digits + 1);
        for (char c : s) {
            itn v = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
            res = res * baseB + BIGINT(v);
        }
        return res;
    }

    // 绝对值
    BIGINT abs() const {
        BIGINT r = *this;
        r.sign = 1;
        return r;
    }

    // 除以 2
    BIGINT div2() const {
        BIGINT res = *this;
        long long carry = 0;
        for (itn i = itn(res.a.size()) - 1; i >= 0; --i) {
            long long cur = res.a[i] + carry * base;
            res.a[i] = itn(cur >> 1);
            carry = cur & 1;
        }
        return res.trim();
    }

    // Knuth‐like 长除法 (O(n·m))
    static pair<BIGINT, BIGINT> divmod(const BIGINT &u, const BIGINT &v) {
        itn norm = base / (v.a.back() + 1);
        BIGINT a = u.abs().mul_itn(norm);
        BIGINT b = v.abs().mul_itn(norm);
        BIGINT q, r;
        q.a.assign(a.a.size(), 0);
        for (itn i = itn(a.a.size()) - 1; i >= 0; --i) {
            r.a.insert(r.a.begin(), a.a[i]);
            r.trim();
            long long qt = 0;
            if (r.a.size() >= b.a.size()) {
                itn j = itn(b.a.size()) - 1;
                long long r_hi = (r.a.size() > j ? r.a[j] : 0);
                long long r_lo = (j > 0 && r.a.size() > j - 1 ? r.a[j - 1] : 0);
                qt = ((long long)base * r_hi + r_lo) / b.a.back();
                if (qt >= base)
                    qt = base - 1;
            }
            r = r - b.mul_itn(itn(qt));
            r.trim();
            while (r.sign < 0) {
                r = r + b;
                r.trim();
                --qt;
            }
            while (r >= b) {
                r = r - b;
                r.trim();
                ++qt;
            }

            q.a[i] = itn(qt);
        }
        q.sign = u.sign * v.sign;
        r.sign = u.sign;
        q.trim();
        if (norm != 1) {
            long long carry2 = 0;
            for (itn i = itn(r.a.size()) - 1; i >= 0; --i) {
                long long cur = r.a[i] + carry2 * base;
                r.a[i] = itn(cur / norm);
                carry2 = cur % norm;
            }
            r.trim();
        }
        return {q, r};
    }

    BIGINT operator/(const BIGINT &v) const { return divmod(*this, v).first; }
    BIGINT operator%(const BIGINT &v) const { return divmod(*this, v).second; }

    // Newton 迭代法求平方根 (向下取整)
    static BIGINT sqrt(const BIGINT &v) {
        if (v.isZero())
            return BIGINT(0);
        BIGINT x = v, last;
        BIGINT two(2);
        do {
            last = x;
            x = (x + v / x) / two;
        } while (x < last);
        return last;
    }
    BIGINT div_itn(itn m) const {
        assert(m != 0);
        BIGINT res;
        res.sign = sign * (m < 0 ? -1 : 1);
        long long carry = 0;
        res.a.assign(a.size(), 0);
        for (int i = (int)a.size() - 1; i >= 0; --i) {
            long long cur = a[i] + carry * base;
            res.a[i] = itn(cur / llabs(m));
            carry = cur % llabs(m);
        }
        return res.trim();
    }

    static BIGINT sqrt(const BIGINT &n, itn m) {
        if (m <= 0 || n.isZero())
            return BIGINT(0);
        if (m == 1)
            return n;
        // 初始猜测：2^(ceil(bitlen(n)/m))
        string bs = n.toBase(2);
        itn bitlen = bs.size();
        BIGINT x = BIGINT(1) << ((bitlen + m - 1) / m);
        BIGINT km1 = BIGINT(m - 1), M = BIGINT(m);
        while (true) {
            // t = x^(m-1)
            BIGINT t = pow(x, m - 1);
            // q = ⌊ n / t ⌋
            BIGINT q = n / t;
            // y = ⌊ ((m-1)*x + q) / m ⌋
            BIGINT y = (km1 * x + q).div_itn(m);
            if (y >= x)
                return x;
            x = y;
        }
    }
    // 二进制 GCD (Stein 算法)
    static BIGINT gcd(BIGINT a, BIGINT b) {
        if (a.isZero())
            return b.abs();
        if (b.isZero())
            return a.abs();
        itn shift = 0;
        while ((a.a[0] & 1) == 0 && (b.a[0] & 1) == 0) {
            a = a.div2();
            b = b.div2();
            ++shift;
        }
        while ((a.a[0] & 1) == 0)
            a = a.div2();
        do {
            while ((b.a[0] & 1) == 0)
                b = b.div2();
            if (a > b)
                swap(a, b);
            b = b - a;
        } while (!b.isZero());
        // 恢复公因子 2^shift
        while (shift--)
            a = a.mul_itn(2);
        return a;
    }

    // 复合赋值运算符
    BIGINT &operator+=(const BIGINT &v) { return *this = *this + v; }
    BIGINT &operator-=(const BIGINT &v) { return *this = *this - v; }
    BIGINT &operator*=(const BIGINT &v) { return *this = *this * v; }
    BIGINT &operator/=(const BIGINT &v) { return *this = *this / v; }
    BIGINT &operator%=(const BIGINT &v) { return *this = *this % v; }

    // 自增、自减
    BIGINT &operator++() { return *this += BIGINT(1); }
    BIGINT operator++(itn) {
        BIGINT t = *this;
        ++*this;
        return t;
    }
    BIGINT &operator--() { return *this -= BIGINT(1); }
    BIGINT operator--(itn) {
        BIGINT t = *this;
        --*this;
        return t;
    }
};

void solve(){
    BIGINT a, b;
    cin >> a >> b;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    auto[q, r] = BIGINT::divmod(a, b);
    cout << q << endl;  
    cout << r << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}