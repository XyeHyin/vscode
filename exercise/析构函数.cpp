// #include <bits/stdc++.h>
// using namespace std;
// class Animal{
//     public:Animal(){
//         cout << "animal的构造函数" << endl;
//     }
//     virtual void speak() = 0;
//     virtual ~Animal(){
//         cout<<"animal的析构函数"<<endl;
//     }
//     virtual ~Animal() = 0;
// };
// Animal::~Animal(){

// }
// class Cat :public Animal{
//     public :
//     Cat(string name){
//         cout<<"cat的构造函数"<<endl;
//         this->name = new string(name);
//     }
//     ~Cat(){
//         if(!name){
//             cout << "Cat的析构函数" << endl;
//             delete name;
//             name = NULL;
//         }
//         cout<<"cat的析构函数"<<endl;
//         string *name;
//     }
// };
// void test01(){
//     Animal* animal=new Cat("Tom");
//     animal->speak();
//     delete animal;
// }
// int main(){
//     test01();
//     return 0;
// }