class Stack{
public :
	// ctor
	Stack();
	Stack(int); // Stack dengan ukuran stack
	Stack(const Stack&); // cctor
	// dtor
	~Stack();

	// getter
	int getTopStack();

	// function
	void Pop(int&);
	void Push(int);
	bool isEmpty();
	void Print();

	// overloading opt
	Stack& operator<<(int);
	Stack& operator>>(int&);
	Stack operator+(const Stack&);
private :
	int topStack;
	int* data;
	int size;
};