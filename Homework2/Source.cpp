#include<iostream>
#include<memory>
using namespace std;
struct Base
{
	int a;
	virtual void f() const
	{
		std::cout << " I am a base!\n ";
	}
	virtual ~Base() {}
};
struct Derived : Base
{
	virtual void f() const
	{
		std::cout << " I am derived!\n ";
	}
	virtual ~Derived() {}
};


int main() {
	auto basePtr = std::make_unique<Base>();
	std::cout << "Base pointer say: ";
	basePtr->f();
	auto derivedPtr = std::make_unique<Derived>();
	std::cout << "Derived pointer say: ";
	derivedPtr->f();
	Base* ptr = basePtr.get();
	std::cout << "Base pointer say: ";
	ptr->f();
	Derived* ptr2 = derivedPtr.get();
	std::cout << "Derived pointer say: ";
	ptr2->f();
	ptr = ptr2;
	std::cout << "Base pointer say: ";
	ptr->f();
	auto ptr4 = derivedPtr.release();
	auto basePtr2 = unique_ptr<Base>(ptr);

	basePtr2->f();



	





	


	// static_pointer_cast to go up class hierarchy
	/*auto basetoDerived = std::static_pointer_cast<Derived>(basePtr);
	std::cout << "Base pointer to derived says: ";
	basetoDerived->f(); */

	// dynamic_pointer_cast to go down/across class hierarchy
	/*auto downcastedPtr = std::dynamic_pointer_cast<Derived>(basePtr);
	if (downcastedPtr)
	{
		std::cout << "Downcasted pointer says: ";
		downcastedPtr->f();
	}

	// All pointers to derived share ownership
	std::cout << "Pointers to underlying derived: "
		<< derivedPtr.use_count()
		<< "\n";*/
	system("pause");

}