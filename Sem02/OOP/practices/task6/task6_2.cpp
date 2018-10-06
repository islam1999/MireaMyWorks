//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 28.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

//base class
class Expression {
public:
    double value;
    
    Expression() {}
    ~ Expression() {}
    
    // copy expression value
    virtual Expression* clone() const {
        return new Expression(*this);
    }
    // evaluate expression
    virtual double evaluate() {
        return value;
    }
	
};

// I do not understand wich difference between variable and constant ¯\_(ツ)_/¯
// so I desided not to create such a class as Constant 
class Variable : public Expression {
public:
	Variable(double value) {
		this->value = value;
	}
	~ Variable() {}
    
    Variable* clone() const override {
        return new Variable(*this);
    }
};

class Add : public Expression {
public:
	 Add(Expression* left, Expression* right) {
		value = left->evaluate() + right->evaluate();
	 }
	~ Add() {}
    
    Add* clone() const override {
        return new Add(*this);
    }
};

class Subtract : public Expression {
public:
	 Subtract(Expression* left, Expression* right) {
	 	value = left -> evaluate() - right -> evaluate();
	 }
	~ Subtract() {}
    
    Subtract* clone() const override {
        return new Subtract(*this);
    }
};

class Multiplay : public Expression {
public:
	Multiplay(Expression* left, Expression* right) {
		value = left->evaluate() * right->evaluate();
	}
	~ Multiplay() {}
    
    Multiplay* clone() const override {
        return new Multiplay(*this);
    }
};

class Divide : public Expression {
public:
	Divide(Expression* left, Expression* right) {
		value = left->evaluate() / right->evaluate();
	}
	~ Divide() {}
    
    Divide* clone() const override {
        return new Divide(*this);
    }
};

class Sin : public Expression {
public:
	Sin(double value) {
		this->value = value;
	}
	~ Sin() {}

	double evaluate() override {
		return sin(value);
	}
    Sin* clone() const override {
        return new Sin(*this);
    }
};

class Cos : public Expression {
public:
	Cos(double value) {
		this->value = value;
	}
	~Cos() {}
	
	double evaluate() override {
		return cos(value);
	}
    Cos* clone() const override {
        return new Cos(*this);
    }
};

class Ln : public Expression {
public:
	Ln(double value) {
		this->value = value;
	}
	~ Ln();

	double evaluate() override {
		return log(value);
	}
    Ln* clone() const override {
        return new Ln(*this);
    }
};

class Exp : public Expression {
public:
	Exp(double value) {
		this->value = value;
	}
	~ Exp();
	
	double evaluate() override {
		return exp(value);
	}
    Exp* clone() const override {
        return new Exp(*this);
    }
};

int main() {
    // create fisrt expression
    Add expr1(new Variable(5), new Variable(5));
    cout << "5 + 5 = " << expr1.evaluate() << endl;
    
    // copy first expression value
    Expression* ex1 = &expr1;
    Expression* ex2 = ex1->clone();
    
    // use last expression value
    Subtract expr2(ex2, new Variable(2));
    cout << "10 - 2 = " << expr2.evaluate() << endl;

	return 0;
}











