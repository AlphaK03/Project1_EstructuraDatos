//
// Created by keylo on 14/9/2022.
//

#include "Integer.h"

#include <utility>


bool Integer::operator==(const Integer &rhs) const {
    return integerChars == rhs.integerChars;
}

bool Integer::operator!=(const Integer &rhs) const {
    return !(rhs == *this);
}

bool Integer::operator<(const Integer &rhs) const {
    return integerChars < rhs.integerChars;
}

bool Integer::operator>(const Integer &rhs) const {
    return rhs < *this;
}

bool Integer::operator<=(const Integer &rhs) const {
    return !(rhs < *this);
}

bool Integer::operator>=(const Integer &rhs) const {
    return !(*this < rhs);
}



Integer::Integer(string ss){
    this->integerChars.clear();
    this->integerChars = std::move(ss);
}

Integer &operator+(Integer &a, const Integer &b) {
    a += b;
    return a;
}

int Integer::length(Integer a) {
    int iterator = 0;
    for(auto charElement : a.integerChars){
        iterator++;
    }
    return iterator;
}

Integer &operator+=(Integer &a, const Integer &b) {
    int i = 0;
    string cero = "0";
    string aux;

    string ss = a.integerChars;
    string ss2 = b.integerChars;

    if(ss.size() > ss2.size()){
        while (i < (ss.size() - ss2.size())){
            aux += cero;
            i++;
        }
        aux = aux + ss2;
        ss2 = aux;
    }
    if(ss.size() < ss2.size()){
        while (i < (ss2.size() - ss.size())){
            aux += cero;
            i++;
        }
        aux = aux + ss;
        ss = aux;
    }

    auto* list = new Lista<int>;
    auto* list2 = new Lista<int>;

    list = MyStdLib::strToList(ss);
    list2 = MyStdLib::strToList(ss2);

    auto *resultado = new string();
    resultado = MyStdLib::resultadoFinal(list, list2);

    a.integerChars.clear();
    a.integerChars = *resultado;

    int  auxNum;
    if(ss.size() == 1 and ss2.size() == 1){
        auxNum = (int)MyStdLib::strToInt(ss.substr(0,1)) + (int)MyStdLib::strToInt(ss2.substr(0,1));
            a.integerChars = MyStdLib::intToString(auxNum);
            return a;
    }

    return a;
}

ostream &operator<<(ostream &out, const Integer &a) {
    string charString;
    for (int i = 0; a.integerChars[i] != '\0'; i++){
        charString.push_back(a.integerChars[i]);
    }
    out << charString;
    return out;
}

Integer &Integer::operator=(const Integer &b){
    if(this != &b){
        this->integerChars = b.integerChars;
    }
    return *this;
};


istream &operator>>(istream &in, Integer&a) {
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw runtime_error("INVALID NUMBER");
        a.integerChars[n - i - 1] = s[i];
    }
    return in;
}

Integer &operator+=(Integer &a, const char *&b) {
    int s = 0;
    MyStdLib myStdLib;
    Integer temp(b);

    s = (MyStdLib::strToInt(a.integerChars) + MyStdLib::strToInt(temp.integerChars));
    a.integerChars = MyStdLib::intToString(s);
    return a;
}


Lista<int> *Integer::getValue() const {
    return value;
}

void Integer::setValue(int *value) {
    this->value->insertar(value);
}

Integer::Integer(string integerChars, Lista<int> *value) : integerChars(std::move(integerChars)), value(value) {}

const string &Integer::getIntegerChars() const {
    return integerChars;
}

void Integer::setIntegerChars(const string &integerChars) {
    Integer::integerChars = integerChars;
}

Integer &operator*(Integer &a, const Integer &b) {
    a *= b;
    return a;
}

Integer &operator*=(Integer &a, const Integer &b) {
    Integer temp=a;
    int n=MyStdLib::strToInt(b.integerChars);
    for(int i=2;i<=n;i++){
        temp+=a;
    }
    return a=temp;
}

Integer &operator-(Integer &a, const Integer &b) {
    a -= b;
    return a;
}

Integer &operator-=(Integer &a, const Integer &b) {
    int i = 0;
    string cero = "0";
    string aux;

    string ss = a.integerChars;
    string ss2 = b.integerChars;

    if(ss.size() > ss2.size()){
        while (i < (ss.size() - ss2.size())){
            aux += cero;
            i++;
        }
        aux = aux + ss2;
        ss2 = aux;
    }
    if(ss.size() < ss2.size()){
        while (i < (ss2.size() - ss.size())){
            aux += cero;
            i++;
        }
        aux = aux + ss;
        ss = aux;
    }

    auto* list = new Lista<int>;
    auto* list2 = new Lista<int>;

    list = MyStdLib::strToList(ss);
    list2 = MyStdLib::strToList(ss2);

    auto *resultado = new string();
    resultado = MyStdLib::resultadoFinalResta(list, list2);

    a.integerChars.clear();
    a.integerChars = *resultado;

    return a;
}

Integer &operator/(Integer &a, const Integer &b) {
    if(b.integerChars.size() == 1 && b.integerChars[0] == '0'){
        throw runtime_error("Division entre 0");
    }
    a /= b;
    return a;
}

Integer &operator/=(Integer &a, const Integer &b) {
    int s = 0;
    MyStdLib myStdLib;
    Integer temp(b);

    s = (MyStdLib::strToInt(a.integerChars) / MyStdLib::strToInt(temp.integerChars));
    a.integerChars = MyStdLib::intToString(s);
    return a;
}

Integer::Integer() = default;


Integer::~Integer() = default;

Integer Integer::fibonacciIterative(Integer n) {
    Integer aux("1");
    if (n <= aux) {
        return n;
    }
    Integer fib = Integer("1");
    Integer prevFib = Integer("1");

    Integer i("2");

    while (i != n) {
        Integer temp = fib;
        fib += prevFib;
        prevFib = temp;
        i += aux;
    }
    return fib;
}

Integer Integer::factorial(Integer num){
    Integer f("1");
    Integer i("2");
    Integer numberOne("1");
    while (i != num){
        f *= i;
        i = i + numberOne;
    }

    return f;
}
