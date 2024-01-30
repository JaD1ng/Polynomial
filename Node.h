#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T coefficient;	//系数
    int exponent;	//指数

    Node(T coef, int exp) : coefficient(coef), exponent(exp) {}
};

#endif //NODE_H