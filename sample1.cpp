#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class ComplexNumber{
	double _r, _i;
	public:
	ComplexNumber(double r, double i):_r(r), _i(i)
	{}
	bool operator==(const ComplexNumber& rhs) const {
		return (this->_r == rhs._r) && (this->_i == rhs._i);
	}
	ComplexNumber operator+(const ComplexNumber& rhs) const {
		return ComplexNumber(this->_r + rhs._r, this->_i + rhs._i);
	}
	friend ostream& operator<<(ostream& out, const ComplexNumber& data);
	friend basic_stringstream<char>& operator<<(basic_stringstream<char>& out, const ComplexNumber& data);
};

ostream& operator<<(ostream& out, const ComplexNumber& data){
	out<<data._r<<'\t'<<data._i;
	return out;
}

basic_stringstream<char>& operator<<(basic_stringstream<char>& out, const ComplexNumber& data){
	out<<data._r<<'\t'<<data._i;
	return out;
}

class ComplexNumberTest : public ::testing::Test {
	protected:
	ComplexNumber *c_1_1, *c_1_2, *c_2_3;
	void SetUp() override{
		c_1_1 = new ComplexNumber(1, 1);
#ifdef FAIL_ADD_TEST
		c_1_2 = new ComplexNumber(1, 2.1);
#else
		c_1_2 = new ComplexNumber(1, 2);
#endif
#ifndef CAUSE_SEG_FAULT
		c_2_3 = new ComplexNumber(2, 3);
#endif
	}
	void TearDown() override{
		delete c_1_1;
		delete c_1_2;
		delete c_2_3;
	}

};

TEST_F(ComplexNumberTest, testEquality){
	// Testing assert_eq for user defined classes
	EXPECT_EQ(*c_1_1, *c_1_1);
	EXPECT_TRUE(!(*c_1_1 == *c_1_2));
}

TEST_F(ComplexNumberTest, testAddition){
	EXPECT_EQ(*c_1_1 + *c_1_2, *c_2_3);
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
