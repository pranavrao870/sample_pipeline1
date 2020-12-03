#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "MockInterface.h"
#include "OrderManager.h"

using namespace std;

Interface* _interface;
OrderManager* _om;
MockInterface* _mock_interface;

void Interface::OnORSUpdate(double number){
	_om->OnOrderConfirm(number);
}

class InterfaceTest : public ::testing::Test{
	public:
		void SetUp() override{
			_mock_interface = new MockInterface();
			_interface = _mock_interface;
			_om = new OrderManager();
		}
		void TearDown() override{
			delete _interface;
			delete _om;
		}
};

#ifdef FAIL_TEST
vector<double> expected_orders({1.0, 2.0, 4.0, 8.0});
#else
vector<double> expected_orders({1.0, 2.0, 4.0, 8.0, 16.0});
#endif

TEST_F(InterfaceTest, Test1){
	{
		::testing::InSequence seq;
		for(double order : expected_orders){
			EXPECT_CALL(*_mock_interface, SendOrder(order)).Times(1).RetiresOnSaturation();
			EXPECT_CALL(*_mock_interface, OnORSUpdate(order)).Times(1).RetiresOnSaturation();
		}
	}
	//EXPECT_TRUE(_om->Start());
	_om->Start();
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	const auto& result = RUN_ALL_TESTS();
	return result;
}
