#include<iostream>
#include"Polynomial.h"

using namespace std;

void test()
{
    cout << "常规数据：" << endl;
    // 创建多项式 P1(x) = 3x^3 + 2x^2 + 5x + 7
    Polynomial<int> poly1;
    poly1.addTerm(3, 3);
    poly1.addTerm(2, 2);
    poly1.addTerm(5, 1);
    poly1.addTerm(7, 0);

    std::cout << "多项式 P1(x) = ";
    poly1.display();

    // 显示多项式的导数
    Polynomial<int> derivative = poly1.derivative();
    std::cout << "P1(x) 的导数为: ";
    derivative.display();

    // 求 P1(x) 在 x = 2 处的值
    int evalResult = poly1.evaluate(2);
    std::cout << "P1(x) 在 x = 2 处的值为: " << evalResult << std::endl;

    // 创建另一个多项式 Q1(x) = 4x^2 - 6x + 1
    Polynomial<int> poly2;
    poly2.addTerm(4, 2);
    poly2.addTerm(-6, 1);
    poly2.addTerm(1, 0);

    std::cout << "另一个多项式 Q1(x) = ";
    poly2.display();

    // P1(x) + Q1(x)
    Polynomial<int> sum1 = poly1 + poly2;
    std::cout << "P1(x) + Q1(x) = ";
    sum1.display();

    // P1(x) - Q1(x)
    Polynomial<int> diff1 = poly1 - poly2;
    std::cout << "P1(x) - Q1(x) = ";
    diff1.display();

    // P1(x) * Q1(x)
    Polynomial<int> product = poly1 * poly2;
    std::cout << "P1(x) * Q1(x) = ";
    product.display();

    cout << endl << "特殊数据：" << endl;

    // 创建多项式 P2(x) = 7
    Polynomial<int> poly3;
    poly3.addTerm(7, 0);
    std::cout << "多项式 P2(x) = ";
    poly3.display();

    std::cout << "P2(x) 的导数为: ";
    Polynomial<int> deriv = poly3.derivative();
    deriv.display();

    int evalResult2 = poly3.evaluate(2);
    std::cout << "P2(x) 在 x = 2 处的值为: " << evalResult2 << std::endl;

    // 创建另一个多项式 Q2(x) = 3x^3
    Polynomial<int> poly4;
    poly4.addTerm(3, 3);
    std::cout << "多项式 Q2(x) = ";
    poly4.display();

    // P1(x) + Q1(x)
    std::cout << "P2(x) + Q2(x) = ";
    Polynomial<int> sum2 = poly3 + poly4;
    sum2.display();

    // P1(x) - Q1(x)
    std::cout << "P2(x) - Q2(x) = ";
    Polynomial<int> diff2 = poly3 - poly4;
    diff2.display();

    // P1(x) * Q1(x)
    std::cout << "P2(x) * Q2(x) = ";
    Polynomial<int> prod = poly3 * poly4;
    prod.display();
}

int main()
{
    test();
    system("pause");
    return 0;
}