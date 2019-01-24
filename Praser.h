#include "Stack.h"
#include <string.h>

class Praser {
public :
	Praser(int);
private :
	Stack sym_stack, op_stack;
	string s;
}