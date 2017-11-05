// Gordon Mosher / Yichao Chen
// SID: 861266106 / 861303577
// Email: gordon.mosher@email.ucr.edu / ychen177@ucr.edu

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include<bits/stdc++.h> //string
#include <string>
#include <iostream>

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() {}

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual int parse() = 0;
        virtual int execute() = 0;
        
        
        // DESTRUCTOR
        virtual ~Base() {};
};

class Base2 {
    public:
        /* Constructors */
        Base2() {}

        /* Pure Virtual Functions */
        virtual int parse() = 0;
        virtual int execute() = 0;
};

class Operator: public Base {
	protected:
		Base* left, *right;
	public:
		Operator() : Base() {};
		Operator(Base* l, Base* r) : left(l), right(r) {};
		
		Base* get_left() { return left; };
		Base* get_right() { return right; };
		
		virtual double evaluate() = 0;
    virtual int parse() = 0;
    virtual int execute() = 0;
    
    
    // DESTRUCTOR, might not be needed
    ~Operator() {};
};

class Operator2: public Base2 {
	protected:
		Base2* left, *right;
	public:
		Operator2() : Base2() {};
		Operator2(Base2* l, Base2* r) : left(l), right(r) {};
		
		Base2* get_left() { return left; };
		Base2* get_right() { return right; };
		
    virtual int parse() = 0;
    virtual int execute() = 0;
};

//Leaf Class
class Op: public Base {
	private:
		double value;
		
	public:
		Op() : Base(), value(0){};
		Op(double val) : Base(), value(val){};
		double evaluate() { return this->value; }
};

int lsh_execute(char**);
class ShellComponent;
//int ShellComponent::my_execute(std::string);
class Op2: public Base {
	public:
		double value; // not used
    std::string cmd;
    char** args;
    char line[255];
		
	public:
		Op2() : Base(), value(0){}
		Op2(string str) : Base(), cmd(str){}
    double evaluate() { return 0; }
    int parse() {return 0;}
    int execute() {
//      return ShellComponent::my_execute(cmd);
	return 0;
    }
    char* get_line() {
      strcpy(line, cmd.c_str());
      return line;
// std::string x = "hello world";
// char *y = new char[x.length() + 1]; // or
// char y[100];
//
// std::strcpy(y, x.c_str());
// delete[] y;
// //      return (char *)cmd.c_str();
    }
    
    // DESTRUCTOR
    ~Op2() {};
    
};

class Add: public Operator {
  public:
    Add() : Operator() { };
    ~Add();
    Add (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		  return this->left->evaluate() + this->right->evaluate();
	  };
    int parse() {return 0;}
    int execute() {return 0;}
};

class Sub: public Operator {
  public:
    Sub() : Operator() { };
    ~Sub();
    Sub (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() - this->right->evaluate();
	};
    int parse() {return 0;}
    int execute() {return 0;}
};

class Mult: public Operator {
  public:
    Mult() : Operator(){ };
    ~Mult();
    Mult (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() * this->right->evaluate();
	};
    int parse() {return 0;}
    int execute() {return 0;}
};

class Div: public Operator {
  public:
    Div() : Operator(){ };
    ~Div();
    Div (Base* left, Base* right) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() / this->right->evaluate();
	};
    int parse() {return 0;}
    int execute() {return 0;}
};

class Sqr: public Operator {
  public:
    Sqr() : Operator(){ };
    ~Sqr();
    Sqr (Base* left) : Operator(left, right) {};
    double evaluate() {
		return this->left->evaluate() * this->left->evaluate();
	};
    int parse() {return 0;}
    int execute() {return 0;}
};

#endif // __COMPONENT_H__
