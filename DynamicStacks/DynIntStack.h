#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DynStack
{
   struct StackNode
   {     
      T value;
      StackNode *next;
      // Constructor

      StackNode(T value1, StackNode *next1 = NULL)
      {
         value = value1;
         next = next1;
      }
   };
   StackNode *top;
public:
   DynStack() { top = nullptr; }
   ~DynStack();
   void push(T);
   void pop(T &);
   bool isEmpty() const;

   // Stack Exception
   class Underflow {};
};



//**************************************************
// Member function push pushes the argument onto   *
// the stack.                                      *
//**************************************************
template <class T>
void DynStack<T>::push(T num)
{
    top = new StackNode(num, top);
}

//*****************************************************
// Member function pop removes the value at the top   *
// of the stack and copies it into the variable       *
// passed as an argument.                             *
//*****************************************************
template <class T>
void DynStack<T>::pop(T& num)
{
    StackNode* temp;

    if (isEmpty()) { throw DynStack::Underflow(); }
    else
    {
        // Pop value off top of stack      
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

//*****************************************************
// Member function isEmpty returns true if the stack  *
// is empty, or false otherwise.                      *
//*****************************************************
template <class T>
bool DynStack<T>::isEmpty() const
{
    return top == nullptr;
}

//*****************************************************
// Destructor.                                        *
//*****************************************************
template <class T>
DynStack<T>::~DynStack()
{
    StackNode* garbage = top;
    while (garbage != nullptr)
    {
        top = top->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = top;
    }

}