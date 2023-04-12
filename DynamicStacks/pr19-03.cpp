// This program demonstrates the dynamic stack
// class DynIntStack.
#include <iostream>
#include "DynIntStack.h" 
#include <Vector>
using namespace std;

int main()
{
   DynStack<string> stack; 
   string popped_value;
   //int operation = 1,size=1000;
   // Push values 5, 10, and 15 on the stack
   vector<string> values = { "hi","howdy","hello","hey","how's it going?" };
   string value;
    cout << "Pushing...\n";
    for (int k = 0; k < 5; k++)
    {
        cout << values[k] << "  ";
        stack.push(values[k]);
    }
    cout << endl;

    cout << "Popping...\n";
    for (int j = 0; j < 5; j++)
    {
        cout << values[j] << "  ";
        stack.pop(value);
    }
   cout << "\n";


   // Stack is now empty, a pop will cause an exception
   try
   {
      cout << "\nAttempting to pop again... ";
      stack.pop(popped_value);
   }
   catch (DynStack<string>::Underflow)
   {
      cout << "Underflow exception occured.\n";
   }
   return 0;
}