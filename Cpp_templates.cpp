#include <iostream>


// -----------------------------------------------------------------------------------
// Template function inside template class
// -----------------------------------------------------------------------------------
template <class C>
class Number
{
	private:
		C number = 0;
    public:
        template <class F>
        void add(F num);
        void print();
};


template <class C>
template <class F>
void Number<C>::add(F num)
{
	number+= (C) num;
}


template <class C>
void Number<C>::print()
{
	std::cout << number << std::endl;
}
// -----------------------------------------------------------------------------------



int main()
{

	// Template function inside template class
	Number<int> number;
	number.add(12);
	number.print();
}