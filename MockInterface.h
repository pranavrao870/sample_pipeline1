#include "gmock/gmock.h"
#include "Interface.h"
#include "OrderManager.h"

class MockInterface : public Interface {
	public:
	MockInterface(){
		ON_CALL(*this, SendOrder).WillByDefault([this](double number){this->Interface::SendOrder(number);});
		ON_CALL(*this, OnORSUpdate).WillByDefault([this](double number){this->Interface::OnORSUpdate(number);});
	}
	MOCK_METHOD(void, SendOrder, (double number), (override));
	MOCK_METHOD(void, OnORSUpdate, (double number), (override));
};
