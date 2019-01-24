#include <iostream>
using namespace std;

template <class T> class Stack{
public :
	// ctor
	Stack();
	Stack(int); // Stack dengan ukuran stack
	Stack(const Stack&); // cctor
	// dtor
	~Stack();

	// getter
	T getTopStack();

	// function
	void Pop(T&);
	void Push(T);
	bool isEmpty();
	bool isFull();
	void Print();

	// overloading opt
	Stack& operator<<(T);
	Stack& operator>>(T&);
	Stack operator+(const Stack&);
protected :
	int topStack;
	T* data;
	int size;
};

template <class T> class GStack : public Stack<T> {
public:
	// ctor, cctor, dtor, oper= (tidak dituliskan)
	// redefinition of Push & Pop
	void Push (T);
	void Pop (T&);
private:
	int gs_unit;
	// fungsi untuk mengubah kapasitas
	void Grow();
	void Shrink();
};


/* ------------------------ */
/* ------------------------ */
/* ------------------------ */
template <class T> Stack<T>::Stack(){
	topStack=0;
	size=0;
	data=new T;
}
template <class T> Stack<T>::Stack(int size){
	topStack=0;
	this->size=size;	
	data=new T[size];
}
template <class T> Stack<T>::Stack(const Stack& s){
	size = s.size;
	topStack = s.topStack;
	data = new T[size];
	for(int i=0;i<topStack;i++)
		data[i] = s.data[i];
}
template <class T> Stack<T>::~Stack(){
	cout << "Destuktor aktif" << endl;
}
template <class T> T Stack<T>::getTopStack(){
	return topStack;
}

template <class T> void Stack<T>::Pop(T& item){
	if(isEmpty())
		cout << "Error : Stack kosong" << endl;
	else{
		item=data[--topStack];
		size=topStack;
	}
}
template <class T> void Stack<T>::Push(T item){
	data[topStack++]=item;
	size=topStack;
}
template <class T> bool Stack<T>::isEmpty(){
	return topStack==0;
}
template <class T> bool Stack<T>::isFull(){
	return topStack==size;
}
template <class T> void Stack<T>::Print(){
	Stack s(*this);
	while(!s.isEmpty()){
		T x;
		s.Pop(x);
		cout << x << " ";
	}
	cout << endl;
}
template <class T> Stack<T>& Stack<T>::operator<<(T x){
	this->Push(x);
}
template <class T> Stack<T>& Stack<T>::operator>>(T& x){
	this->Pop(x);
}
template <class T> Stack<T> Stack<T>::operator+(const Stack& s){
	Stack sc(*this);
	int i=0;
	while(i<s.size){
		sc << s.data[i++];
	}
	return sc;
}

/* ------------------------ */
/* ------------------------ */
/* ------------------------ */
template <class T> void GStack<T>::Push(T x){
	if(Stack<T>::isFull()) Grow();
	Stack<T>::Push(x);
}
template <class T> void GStack<T>::Pop(T& x){
	Stack<T>::Pop(x);
	if(Stack<T>::size-Stack<T>::topStack > gs_unit) Shrink();
}
template <class T> void GStack<T>::Grow(){
	Stack<T>::size++;
}
template <class T> void GStack<T>::Shrink(){
	Stack<T>::size--;
}