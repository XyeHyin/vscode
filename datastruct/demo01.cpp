#include <bits/stdc++.h>
using namespace std;
#define int long long
class FuShu {
  public:
    FuShu() : shi(0), xu(0) {}
    FuShu(double shiBu) : shi(shiBu), xu(0) {}
    FuShu(double shiBu, double xuBu) : shi(shiBu), xu(xuBu) {}
    double getShi() const { return shi; }
    void setShi(double shiBu) { shi = shiBu; }
    double getXu() const { return xu; }
    void setXu(double xuBu) { xu = xuBu; }
    FuShu operator-(const FuShu &f) const {
        return FuShu(shi - f.shi, xu - f.xu);
    }
    FuShu operator*(const FuShu &f) const {
        return FuShu(shi * f.shi - xu * f.xu, shi * f.xu + xu * f.shi);
    }
  private:
    double shi;
    double xu;
};

signed main() {
    FuShu f1(3, 4);
    FuShu f2(1, 2);

    cout << "复数1: " << f1.getShi() << "+" << f1.getXu() << "i" << endl;
    cout << "复数2: " << f2.getShi() << "+" << f2.getXu() << "i" << endl;

    FuShu f3 = f1 - f2;
    cout << "复数1-复数2: " << f3.getShi() << "+" << f3.getXu() << "i" << endl;

    FuShu f4 = f1 * f2;
    cout << "复数1*复数2: " << f4.getShi() << "+" << f4.getXu() << "i" << endl;

    return 0;
}