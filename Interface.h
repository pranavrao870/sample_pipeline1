#pragma once
#include <iostream>
#include <string>

class OrderManager;

using namespace std;

class Interface{
	public:
	string _name;
	Interface(){};
	virtual void setName(string name){
		_name = name;
	}
	virtual string getName(){
		return _name;
	}
	virtual void SendOrder(double number){
		OnORSUpdate(number);
	}
	virtual void OnORSUpdate(double number);
};

extern Interface* _interface;
