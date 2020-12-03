#pragma once
#include "Interface.h"

using namespace std;

class OrderManager{
	public:
		OrderManager(){
			_interface->setName("SampleInterface");
		}
		void SendNewOrder(double number){
			_interface->SendOrder(number);
		}
		void OnOrderConfirm(double number){
			cout<<"Received the number "<<number<<" from the Interface"<<endl;
			if(number < 16){
				SendNewOrder(2 * number);
			}
		}
		void Start(){
			SendNewOrder(1);
		}
};

extern OrderManager* _om;
