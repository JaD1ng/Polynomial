#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<vector>
#include<cmath>
#include<map>
#include"Node.h"

template<typename T>
class Polynomial
{
private:
	std::vector<Node<T>> terms;

public:
	void addTerm(T coeff, int exp);	//添加项

	Polynomial<T> derivative();	//求导

	T evaluate(T x);	//求值

	void printTerm(const Node<T>& term);	//打印项

	void display();	//显示多项式

	Polynomial<T> operator+(const Polynomial<T>& other) const;	//重载加法运算符

	Polynomial<T> operator-(const Polynomial<T>& other) const;	//重载减法运算符

	Polynomial<T> operator*(const Polynomial<T>& other) const;	//重载乘法运算符

	void normalize();	//简化多项式
};

template<typename T>
void Polynomial<T>::addTerm(T coeff, int exp)
{
	terms.emplace_back(coeff, exp);
}

template<typename T>
Polynomial<T> Polynomial<T>::derivative()
{
	Polynomial<T> result;
	for (const auto& term : terms) {
		if (term.exponent > 0) {
			result.addTerm(term.coefficient * term.exponent, term.exponent - 1);
		}
	}
	return result;
}

template<typename T>
T Polynomial<T>::evaluate(T x)
{
	T result = 0;
	for (const auto& term : terms) {
		result += term.coefficient * std::pow(x, term.exponent);
	}
	return result;
}

template<typename T>
inline void Polynomial<T>::printTerm(const Node<T>& term)
{
	if (term.exponent == 0) {
		std::cout << term.coefficient;
	}
	else {
		if (term.exponent == 1) {
			std::cout << term.coefficient << "x";
		}
		else {
			std::cout << term.coefficient << "x^" << term.exponent;
		}
	}
}

template <typename T>
void Polynomial<T>::display() {
	if (terms.empty()) {
		std::cout << "0" << std::endl;
		return;
	}

	bool firstTerm = true;
	for (const auto& term : terms) {
		if (!firstTerm) {
			if (term.coefficient >= 0) {
				std::cout << " + ";
			}
			else {
				std::cout << " - ";
			}
		}
		else {
			firstTerm = false;
			if (term.coefficient < 0) {
				std::cout << "-";
			}
		}

		// Print the term
		Node<T> absTerm(std::abs(term.coefficient), term.exponent);
		printTerm(absTerm);
	}
	std::cout << std::endl;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const
{
	Polynomial<T> result = *this;
	for (const auto& term : other.terms) {
		result.addTerm(term.coefficient, term.exponent);
	}
	result.normalize();
	return result;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& other) const
{
	Polynomial<T> result = *this;
	for (const auto& term : other.terms) {
		result.addTerm(-term.coefficient, term.exponent);
	}
	result.normalize();
	return result;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& other) const
{
	Polynomial<T> result;
	for (const auto& term1 : terms) {
		for (const auto& term2 : other.terms) {
			result.addTerm(term1.coefficient * term2.coefficient, term1.exponent + term2.exponent);
		}
	}
	result.normalize();
	return result;
}

template<typename T>
void Polynomial<T>::normalize() {
	std::map<int, T, std::greater<>> termMap;
	for (const auto& term : terms) {
		termMap[term.exponent] += term.coefficient;
	}

	terms.clear();
	for (const auto& pair : termMap) {
		if (pair.second != 0) {
			terms.emplace_back(pair.second, pair.first);
		}
	}
}

#endif //POLYNOMIAL_H