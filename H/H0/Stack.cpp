#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(){
	topStack=0;
	size=0;
	data=new int;
}
Stack::Stack(int size){
	topStack=0;
	this->size=size;	
	data=new int(size);
}
Stack::Stack(const Stack& s){
	size = s.size;
	topStack = s.topStack;
	data = new int[size];
	for(int i=0;i<topStack;i++)
		data[i] = s.data[i];
}
Stack::~Stack(){
	cout << "Destuktor aktif" << endl;
}


int Stack::getTopStack(){
	return topStack;
}

void Stack::Pop(int& item){
	if(isEmpty())
		cout << "Error : Stack kosong" << endl;
	else{
		item=data[--topStack];
		size=topStack;
	}
}
void Stack::Push(int item){
	data[topStack++]=item;
	size=topStack;
}
bool Stack::isEmpty(){
	return topStack==0;
}
void Stack::Print(){
	Stack s(*this);
	while(!s.isEmpty()){
		int x;
		s.Pop(x);
		cout << x << " ";
	}
	cout << endl;
}

Stack& Stack::operator<<(int x){
	this->Push(x);
}
Stack& Stack::operator>>(int& x){
	this->Pop(x);
}
Stack Stack::operator+(const Stack& s){
	Stack sc(*this);
	int i=0;
	while(i<s.size){
		sc << s.data[i++];
	}
	return sc;
}