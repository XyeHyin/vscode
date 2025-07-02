#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// 多项式节点类
class PolynNode {
  public:
    double coef; // 系数
    int exp;     // 指数

    PolynNode(int exp, double coef) : exp(exp), coef(coef) {}
};

// 链表节点类
class Node {
  public:
    std::shared_ptr<PolynNode> data;
    std::shared_ptr<Node> next;

    Node() : data(nullptr), next(nullptr) {}
    Node(std::shared_ptr<PolynNode> data) : data(data), next(nullptr) {}
};

// 抽象链表接口
class IList {
  public:
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual int length() = 0;
    virtual std::shared_ptr<PolynNode> get(int i) = 0;
    virtual void insert(int i, std::shared_ptr<PolynNode> x) = 0;
    virtual void remove(int i) = 0;
    virtual int indexOf(std::shared_ptr<PolynNode> x) = 0;
    virtual void display() = 0;
};

// 单链表类
class LinkList : public IList {
  public:
    std::shared_ptr<Node> head; // 单链表的头指针

    LinkList() {
        head = std::make_shared<Node>(); // 初始化头结点
    }

    void clear() override {
        head->data = nullptr;
        head->next = nullptr;
    }

    bool isEmpty() override {
        return head->next == nullptr; // 判断首结点是否为空
    }

    int length() override {
        auto p = head->next; // 初始化,p指向首结点,length为计数器
        int length = 0;
        while (p != nullptr) { // 从首结点向后查找，直到p为空
            p = p->next;       // 指向后继结点
            ++length;          // 长度增1
        }
        return length;
    }

    std::shared_ptr<PolynNode> get(int i) override {
        auto p = head->next; // 初始化,p指向首结点,j为计数器
        int j = 0;
        while (p != nullptr &&
               j < i) { // 从首结点向后查找，直到p指向第i个元素或p为空
            p = p->next; // 指向后继结点
            ++j;         // 计数器的值增1
        }
        if (j > i || p == nullptr) { // i小于0或者大于表长减1
            throw std::out_of_range("第" + std::to_string(i) +
                                    "个元素不存在"); // 输出异常
        }
        return p->data; // 返回元素p
    }

    void insert(int i, std::shared_ptr<PolynNode> x) override {
        auto p = head; // 初始化p为头结点,j为计数器
        int j = -1;    // 第i个结点前驱的位置
        while (p != nullptr && j < i - 1) { // 寻找i个结点的前驱
            p = p->next;
            ++j; // 计数器的值增1
        }
        if (j > i - 1 || p == nullptr)                 // i不合法
            throw std::out_of_range("插入位置不合理"); // 输出异常

        auto s = std::make_shared<Node>(x); // 生成新结点
        s->next = p->next;                  // 插入单链表中
        p->next = s;
    }

    void remove(int i) override {
        auto p = head; // p指向要删除结点的前驱结点
        int j = -1;
        while (p->next != nullptr && j < i - 1) { // 寻找i个结点的前驱
            p = p->next;
            ++j; // 计数器的值增1
        }
        if (j > i - 1 || p->next == nullptr) { // i小于0或者大于表长减1
            throw std::out_of_range("删除位置不合理"); // 输出异常
        }
        p->next = p->next->next; // 删除结点
    }

    int indexOf(std::shared_ptr<PolynNode> x) override {
        auto p = head->next; // 初始化,p指向首结点,j为计数器
        int j = 0;
        while (
            p != nullptr &&
            !(p->data->exp == x->exp &&
              p->data->coef ==
                  x->coef)) { // 从单链表中的首结点元素开始查找，直到p.data指向元素x或到达单链表的表尾
            p = p->next;      // 指向下一个元素
            ++j;              // 计数器的值增1
        }
        if (p != nullptr) // 如果p指向表中的某一元素
            return j;     // 返回x元素在顺序表中的位置
        else
            return -1; // x元素不在顺序表中
    }

    void display() override {
        for (int i = 0; i < length(); i++) {
            try {
                auto e = get(i);
                std::cout << "系数为：" << e->coef << " 指数为：" << e->exp
                          << std::endl;
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
};

// 多项式链表类
class PolynList : public LinkList {
  public:
    PolynList(int n) {
        head->data = std::make_shared<PolynNode>(0, -1);
        for (int i = 0; i < n; i++) {
            double coef;
            int expn;
            std::cin >> coef >> expn;
            insert(std::make_shared<PolynNode>(expn, coef));
        }
    }

    void insert(std::shared_ptr<PolynNode> e) {
        int j = 0;
        while (j < length()) {
            auto t = get(j);
            if (t->exp > e->exp)
                break;
            j++;
        }
        LinkList::insert(j, e);
    }

    int cmp(std::shared_ptr<PolynNode> a, std::shared_ptr<PolynNode> b) {
        if (a->exp > b->exp) {
            return 1;
        } else if (a->exp < b->exp) {
            return -1;
        } else {
            return 0;
        }
    }

    std::shared_ptr<PolynList> addPloy(std::shared_ptr<PolynList> LA,
                                       std::shared_ptr<PolynList> LB) {
        auto ha = LA->head;
        auto qa = LA->head->next;
        auto qb = LB->head->next;
        while (qa != nullptr && qb != nullptr) {
            auto a = qa->data;
            auto b = qb->data;
            switch (cmp(a, b)) {
            case -1:
                ha->next = qa;
                ha = qa;
                qa = qa->next;
                break;
            case 0: {
                double sum = a->coef + b->coef;
                if (sum != 0.0) {
                    a->coef = sum;
                    ha->next = qa;
                    ha = qa;
                    qa = qa->next;
                    qb = qb->next;
                } else {
                    qa = qa->next;
                    qb = qb->next;
                }
                break;
            }
            case 1:
                ha->next = qb;
                ha = qb;
                qb = qb->next;
                break;
            }
            ha->next = (qa == nullptr) ? qb : qa;
        }
        return LA;
    }
};

int main() {
    try {
        std::cout << "请输入A多项式的长度:" << std::endl;
        int m;
        std::cin >> m;
        std::cout << "请输入A多项式各项的系数和指数:" << std::endl;
        auto LA = std::make_shared<PolynList>(m);
        std::cout << "请输入B多项式的长度:" << std::endl;
        int n;
        std::cin >> n;
        std::cout << "请输入B多项式各项的系数和指数:" << std::endl;
        auto LB = std::make_shared<PolynList>(n);
        LA = LA->addPloy(LA, LB);
        std::cout << "求和后的多项式各项为：" << std::endl;
        auto head = LA->head;
        while (head->next != nullptr) {
            auto p = head->next->data;
            std::cout << "指数为：" << p->exp << " 系数为：" << p->coef
                      << std::endl;
            head = head->next;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}