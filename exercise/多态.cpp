#include <bits/stdc++.h>
using namespace std;
class zyp{
   public:
       virtual void shaoshui() = 0;
       virtual void chongpao() = 0;
       virtual void daoshui() = 0;
       virtual void jialiao() = 0;

       void play(){
              shaoshui();
              chongpao();
              daoshui();
              jialiao();
       }
};
class ckf:public zyp{
    public:
    void shaoshui(){
        cout<<"烧矿泉水"<<endl;
    }
    void chongpao(){
        cout<<"冲泡咖啡"<<endl;
    }
    void daoshui(){
        cout<<"倒入咖啡杯里"<<endl;
    }
    void jialiao()
    {
        cout << "加牛奶" << endl;
    }
};
class pcy:public zyp{
    public:
    void shaoshui(){
        cout<<"烧山泉水"<<endl;
    }
    void chongpao(){
        cout<<"冲泡茶叶"<<endl;
    }
    void daoshui(){
        cout<<"倒入茶具里"<<endl;
    }
    void jialiao(){
        cout<<"加点枸杞"<<endl;
    }
};
void doDrink(zyp *z){
    z->play();
    delete z;
};
void test01(){
    doDrink(new ckf);
    doDrink(new pcy);
}
int main(void){
    test01();
}