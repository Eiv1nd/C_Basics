#include <iostream>
using namespace std;


struct DateStruct
{
	int year;		// members are public by default
	int month;		
	int day;
};


class DateClass
{
	int year;		// members are private by default
	int month;
	int day;
};


// ------ ------------ ------ Inheritance ------ ------------ ------

// Parent/super/base class
// * Functions that can be replaced must be marked as virtual.
// * Non-implemented functions must be virtual and assigned 0.
// * virtual void func() = 0;
// * A virtual class is a class that can not be instantiated.
class Point
{
	public:
		int x, y;
		void calc();
};

// Derived/sub/child class
// * Access specifier
// * public - all member stay the same
// * protected - public members become protected
// * private - all members change to private
class Point3d : public Point
{
	public:
		int z;			// Ads a member
		void calc(); 	// Replaces the original calc() from Point
};

 
int main()
{
	// Pointer type decide which function is called
	Point* p = new Point3d();
	p->calc();

	// Late binding - Mark base class function with virtual ensure child function is allways called.
	
	// Constructors and destructors
	// Child knows about parent, but parent doesnt know about parent.
	// Delete on a base pointer to a child class will leak memory bcs only base destructor is
	// called. Therefore mark destructor as virtual.

	// ------ Casting ------
	double pi = 3.14;
	int i = (int) pi;	// C-style
	int i = int(pi);	// Functional style

	// static_cast
	// Pointers must be related
	// Compile time check only, no runtime check
	// invalid casts will succeed
	// Giraffe* giraffe = static_cast<Giraffe*>(pattedyr);

	// dynamic_cast
	// Pointers must be related, compile time + runtime check
	// Returns nullptr if the cast is invalid
	// Adds runtime overhead
	// Giraffe* giraffe = dynamic_cast<Giraffe*>(pattedyr);
	// Example will always build if the pointers are related.
	// It dynamic_cast will return nullptr if pattedyr is not a Giraffe.
	// Recommended because it is safer (even if it slightly slower)

	return 0;
}