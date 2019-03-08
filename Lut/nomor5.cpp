#include <iostream>


class X
{
	public :
		X():value(0)
		{
			std::cout<<"X::ctor"<<std::endl;
		}
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		
		
		~X()
		{
			std::cout<<"X::dtor"<<std::endl;
		}
		
		
		
		
		
		
		
		X& operator =(const X& s)
		{
			this->value=s.value;
			return *this;
		}
		
		
		
		
		
		
		
		
		
		
		void setValue(int x)
		{
			this->value=x;
		}
		
		
		
		
		
		/*
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		
		
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		
		
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		
		
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		
		
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		
		
		X(const X& x) : value(x.value)
		{
			std::cout<<"X::cctor"<<std::endl;
		}
		*/
	private :
		int value;
	
};

X f1(X x)
{
	std::cout<<"f1()"<<std::endl;
}

X f2(X &x)
{
	std::cout<<"f2()"<<std::endl;
}


X f3(X &x)
{
	std::cout<<"f3()"<<std::endl;
}


X f4(X *x)
{
	std::cout<<"f4()"<<std::endl;
}

/*
X(const X& x) : value(x.value)
{
	std::cout<<"X::cctor"<<std::endl;
}


X(const X& x) : value(x.value)
{
	std::cout<<"X::cctor"<<std::endl;
}


X(const X& x) : value(x.value)
{
	std::cout<<"X::cctor"<<std::endl;
}


X(const X& x) : value(x.value)
{
	std::cout<<"X::cctor"<<std::endl;
}


X(const X& x) : value(x.value)
{
	std::cout<<"X::cctor"<<std::endl;
}


X(const X& x) : value(x.value)
{
	std::cout<<"X::cctor"<<std::endl;
}		
*/


int main()
{
	X x;
	X y;
	y=f1(x);
	y=f2(x);
	y=f3(x);
	y=f4(&x);
	//y=f1(x);
	
	
}




