#include "pch.h"

/*
* lvalues are basically variables that have some kind of storage back in them
* rvalues are temporary values 
* 
* lvalue references can only take in lvalues unless they're const
* rvalue references only take in these temporary rvalues
*/

namespace ns85
{
	int GetValueR() { return 10; }

	int& GetValueL()
	{
		static int value = 10;
		return value;
	}


	void SetValue(int value) {}

	void SetValueL(int& value) {}

	void SetValueC(const int& value) {}


	void PrintName(std::string& name) { std::cout << name << std::endl; }

	void PrintNameC(const std::string& name) { std::cout << name << std::endl; }

	void PrintNameR(std::string&& name) { std::cout << name << std::endl; }


	void Print(const std::string& name) { std::cout << "[lvalue] " << name << std::endl; }

	void Print(std::string&& name) { std::cout << "[rvalue] " << name << std::endl; }
}

void test_85()
{
	using namespace ns85;

	int i = 10; // i: lvalue, 10: rvalue
	//10 = i;	// i: lvalue, 10: rvalue  [error: expression must be a modifiable lvalue]
	int a = i;  // a: lvalue, i: lvalue

	int j = GetValueR(); // GetValueR returns an rvalue
	//GetValueR() = 5;   // GetValueR returns an rvalue  [error: expression must be a modifiable lvalue]
	GetValueL() = 5;     // GetValueL returns an lvalue
	
	int k = 10;
	SetValue(k);      // call SetValue with an lvalue
	SetValue(10);     // call SetValue with an rvalue

	SetValueL(k);     // call SetValueL with an lvalue
	//SetValueL(10);  // call SetValueL with an rvalue  [error: initial value of reference to non-const must be an lvalue]

	//int& a = 10;        // [error: initial value of reference to non-const must be an lvalue]
	//const int& a = 10;  // this works?
	/*
	* this is just a special rule,
	* realistically what happens is that the compiler will properly 
	* create like a temporary variable with your actual storage and then assign it to that reference 
	* 
	* int temp = 10;
	* const int& a = temp;
	*/

	SetValueC(k);     // call SetValueC with an lvalue  [param: const reference]
	SetValueC(10);    // call SetValueC with an rvalue  [param: const reference]


	
	std::string firstName = "Yan";                // lvalue = rvalue
	std::string lastName = "Chernikov";           // lvalue = rvalue

	std::string fullName = firstName + lastName;  // lvalue = rvalue  [firstName + lastName: a temporary string gets constructed from these two]

	PrintName(fullName);
	//PrintName(firstName + lastName); // [error: initial value of reference to non-const must be an lvalue]
	
	PrintNameC(fullName);
	PrintNameC(firstName + lastName);

	//PrintNameR(fullName);            // [error: an rvalue reference cannot be bound to an lvalue] 
	PrintNameR(firstName + lastName);

	Print(fullName);
	Print(firstName + lastName);
	/*
	* with rlvaue reference we now have a way to actually detect temporary values 
	* and do something special to them
	* it's very useful especially with move semantics
	*/

	std::cin.get();

}