#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// 定义一个表示学生节点的类
class StudentNode {
  public:
    int number;     // 学号
    string name;    // 姓名
    string sex;     // 性别
    double english; // 英语成绩
    double math;    // 数学成绩

    // 默认构造函数
    StudentNode() : number(0), name(""), sex(""), english(0.0), math(0.0) {}

    // 构造函数，用于创建新的学生节点
    StudentNode(int number, string name, string sex, double english,
                double math)
        : number(number), name(std::move(name)), sex(std::move(sex)),
          english(english), math(math) {}

    // 构造函数，用于从输入流读取并创建新的学生节点
    StudentNode(istream &is) {
        is >> number >> name >> sex >> english >> math;
        if (is.fail()) {
            throw invalid_argument("输入格式错误");
        }
    }
};

// 定义一个表示顺序表的类
class SqList {
  private:
    vector<StudentNode> listElem; // 存储元素的向量

  public:
    // 构造函数，用于创建新的顺序表
    SqList() = default;

    // 清空顺序表
    void clear() { listElem.clear(); }

    // 判断顺序表是否为空
    bool isEmpty() const { return listElem.empty(); }

    // 获取顺序表的长度
    int length() const { return listElem.size(); }

    // 获取指定位置的元素
    const StudentNode &get(int i) const {
        if (i < 0 || i >= length()) {
            throw out_of_range("第" + to_string(i) + "个元素不存在");
        }
        return listElem[i];
    }

    // 在指定位置插入元素
    void insert(int i, const StudentNode &x) {
        if (i < 0 || i > length()) {
            throw out_of_range("插入位置不合法");
        }
        listElem.insert(listElem.begin() + i, x);
    }

    // 删除指定位置的元素
    void remove(int i) {
        if (i < 0 || i >= length()) {
            throw out_of_range("删除位置不合法");
        }
        listElem.erase(listElem.begin() + i);
    }

    // 查找元素的位置
    int indexOf(const StudentNode &x) const {
        for (int i = 0; i < length(); ++i) {
            if (listElem[i].number == x.number) {
                return i;
            }
        }
        return -1;
    }
};

// 定义一个表示学生管理系统的类，继承自SqList
class StudentManagSystem : public SqList {
  public:
    // 构造函数，用于创建新的学生管理系统
    StudentManagSystem(int n) {
        for (int i = 0; i < n; ++i) {
            StudentNode node(cin);
            insert(length(), node);
        }
    }

    // 根据学号获取学生节点
    const StudentNode &getByNumber(int number) const {
        for (int i = 0; i < length(); ++i) {
            const StudentNode &node = SqList::get(i);
            if (node.number == number) {
                return node;
            }
        }
        throw out_of_range("学号" + to_string(number) + "不存在");
    }

    // 插入新的学生节点
    void insert(const StudentNode &node) { SqList::insert(length(), node); }

    // 根据学号删除学生节点
    void removeByNumber(int number) {
        for (int i = 0; i < length(); ++i) {
            const StudentNode &node = SqList::get(i);
            if (node.number == number) {
                SqList::remove(i);
                return;
            }
        }
        throw out_of_range("学号" + to_string(number) + "不存在");
    }

    // 显示所有学生节点
    void display() const {
        for (int i = 0; i < length(); ++i) {
            displayNode(SqList::get(i));
        }
    }

    // 显示单个学生节点
    void displayNode(const StudentNode &node) const {
        cout << "学号: " << node.number << " 姓名: " << node.name
             << " 性别: " << node.sex << " 大学英语成绩: " << node.english
             << " 高等数学成绩: " << node.math << endl;
    }
};

int main() {
    try {
        int n;
        cout << "请输入学生的总数：" << endl;
        cin >> n;
        cout << "请按学号、姓名、性别、大学英语和高等数学的顺序输入学生信息："
             << endl;
        StudentManagSystem L(n);
        L.display();

        cout << "请输入需要查询学生的学号：" << endl;
        int queryNumber;
        cin >> queryNumber;
        L.displayNode(L.getByNumber(queryNumber));

        cout << "请输入需要删除学生的学号：" << endl;
        int deleteNumber;
        cin >> deleteNumber;
        L.removeByNumber(deleteNumber);
        cout << "删除成功!" << endl;
        L.display();

        cout << "请输入需要增加的学生信息：" << endl;
        StudentNode newNode(cin);
        L.insert(newNode);
        L.display();
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}