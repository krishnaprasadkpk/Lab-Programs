

GEEKSFORGEEKS
How to Sort a Stack using Recursion
Given a stack, the task is to sort it using recursion.

Example: 

Input: elements present in stack from top to bottom -3 14 18 -5 30
Output: 30 18 14 -3 -5
Explanation: The given stack is sorted know 30 > 18 > 14 > -3 > -5

Input: elements present in stack from top to bottom 1 2 3
Output: 3 2 1
Explanation: The given stack is sorted know 3 > 2 > 1

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
How to Sort a Stack Using Stack
The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one in sorted order. and then print the stack

Illustration: 



Below is the illustration of above approach

Let given stack be
         -3         

         14
         18
         -5
         30
Let us illustrate sorting of stack using the above example:
First pop all the elements from the stack and store popped element in the variable ‘temp’. After popping all the elements function’s stack frame will look like this:
 
-3	stack frame 1 
14	stack frame 2
18	stack frame 3
-5	stack frame 4
30	stack frame 5
Now stack is empty so function insert in sorted order is called and it inserts 30 (from stack frame 5) at the bottom of the stack. Now stack looks like the below:
         30         
Now next element  -5 (from stack frame 4) is picked. Since -5 < 30, -5 is inserted at the bottom of the stack. Now stack becomes: 
         30         
         -5
Next 18 (from stack frame 3) is picked. Since 18 < 30, 18 is inserted below 30. Now stack becomes:
         30         
         18
         -5
Next 14 (from stack frame 2) is picked. Since 14 < 30 and 14 < 18, it is inserted below 18. Now stack becomes: 
         30
         18
         14
         -5         
Now -3 (from stack frame 1) is picked, as -3 < 30 and -3 < 18 and -3 < 14, it is inserted below 14. Now stack becomes:
         30          
         18
         14
         -3
         -5
Follow the steps mentioned below to implement the idea:

Create a stack and push all the elements in it.
Call sortStack(), which will pop an element from the stack and pass the popped element to function sortInserted(), then it will keep calling itself until the stack is empty.
Whenever sortInserted() is called it will insert the passed element in stack in sorted order.
Print the stack                             
Below is the implementation of the above approach:

// C++ program to sort a stack using recursion
#include <iostream>

using namespace std;
 
// Stack is represented using linked list

struct stack {

    int data;

    struct stack* next;
};
 
// Utility function to initialize stack

void initStack(struct stack** s) { *s = NULL; }
 
// Utility function to check if stack is empty

int isEmpty(struct stack* s)
{

    if (s == NULL)

        return 1;

    return 0;
}
 
// Utility function to push an item to stack

void push(struct stack** s, int x)
{

    struct stack* p = (struct stack*)malloc(sizeof(*p));
 

    if (p == NULL) {

        fprintf(stderr, "Memory allocation failed.\n");

        return;

    }
 

    p->data = x;

    p->next = *s;

    *s = p;
}
 
// Utility function to remove an item from stack

int pop(struct stack** s)
{

    int x;

    struct stack* temp;
 

    x = (*s)->data;

    temp = *s;

    (*s) = (*s)->next;

    free(temp);
 

    return x;
}
 
// Function to find top item

int top(struct stack* s) { return (s->data); }
 
// Recursive function to insert an item x in sorted way

void sortedInsert(struct stack** s, int x)
{

    // Base case: Either stack is empty or newly inserted

    // item is greater than top (more than all existing)

    if (isEmpty(*s) or x > top(*s)) {

        push(s, x);

        return;

    }
 

    // If top is greater, remove the top item and recur

    int temp = pop(s);

    sortedInsert(s, x);
 

    // Put back the top item removed earlier

    push(s, temp);
}
 
// Function to sort stack

void sortStack(struct stack** s)
{

    // If stack is not empty

    if (!isEmpty(*s)) {

        // Remove the top item

        int x = pop(s);
 

        // Sort remaining stack

        sortStack(s);
 

        // Push the top item back in sorted stack

        sortedInsert(s, x);

    }
}
 
// Utility function to print contents of stack

void printStack(struct stack* s)
{

    while (s) {

        cout << s->data << " ";

        s = s->next;

    }

    cout << "\n";
}
 
// Driver code

int main(void)
{

    struct stack* top;
 

    initStack(&top);

    push(&top, 30);

    push(&top, -5);

    push(&top, 18);

    push(&top, 14);

    push(&top, -3);
 

    cout << "Stack elements before sorting:\n";

    printStack(top);
 

    sortStack(&top);

    cout << "\n";
 

    cout << "Stack elements after sorting:\n";

    printStack(top);
 

    return 0;
}
