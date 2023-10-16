
// This Program show
// 1.)Creation of stack
// 2.)push and pop function working

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
// define a structure for array
struct stack
{
    int size;
    int top;
    int *arr;
};
// fuction to check wheather stack is empty or not
int check_empty(stack *ptr)
{
    if (ptr->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function to check wheather stack is full or not
int check_full(stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// stack mai push operation ke liye function

void stack_push(stack *ptr, int data)
{
    ptr->arr[(ptr->top) + 1] = data;
    ptr->top = ptr->top + 1;
}
// stack mai pop operation ke liye function
int stack_pop(stack *ptr)
{
    int poped_data;
    if (ptr->top > -1)
    {
        poped_data = ptr->arr[ptr->top];
        ptr->top--;
    }
    return poped_data;
}

void line()

{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    int consoleWidth = consoleInfo.dwSize.X;

    for (int i = 0; i < consoleWidth; i++)
    {
        cout << '*';
    }

    cout << endl;
}

void stack_peek(stack *ptr, int pos)
{
    int arr_index = ptr->top - pos + 1;
    if (arr_index < 0 || arr_index > ptr->top)
    {

        cout << endl
             << "Invalid Position" << endl;
    }
    else
    {
        cout << endl
             << "At Position: " << pos << endl
             << "Data: " << ptr->arr[arr_index] << endl;
    }
}
int stack_top(stack *ptr)
{
    if (ptr->top < 0)
    {
        cout << endl
             << "Stack Is Empty " << endl;
        return 0;
    }
    else
    {
        cout << endl
             << "Top Most Value Of Stack Is: " << ptr->arr[ptr->top] << endl;
        return ptr->arr[ptr->top];
    }
}
int stack_bottom(stack *ptr)
{
    if (ptr->top > -1)
    {
        cout << endl
             << "Bottom Most Value Of Stack Is: " << ptr->arr[0] << endl;
        return ptr->arr[0];
    }
    else
    {
        cout << endl
             << "Stack Is Empty " << endl;
        return 0;
    }
}

//===============================================================================================================================//
// Implementation Of Stack Data Structure Using Link List

struct node
{
    int data;
    node *next;
}; // define the structure of a node
int node_stack_empty(node *ptr)
{
    if (ptr == NULL)
    {
        return 1; /*pointer point to null it means stack is underflow*/
    }
    else
    {
        return 0;
    }
}
int node_stack_full(node *ptr)
{
    node *new_node = new node;
    if (new_node == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // if node is full so when we allocate memory to new node it shows new memory address to null ptr
node *node_stack_push(node *top, int value)
{
    if (node_stack_full(top) == 1)
    {
        cout << endl
             << "Stack Overflow"<<endl;
        return 0;
    }
    else
    {
        node *new_node = new node;
        new_node->data = value;
        new_node->next = top;
        top = new_node;
        return top;
    }
}
int node_stack_pop(node **ptr)
{
    if (node_stack_empty(*ptr) == 1)
    {
        cout << endl
             << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        node *new_node = new node;
        new_node = *ptr;
        *ptr = (*ptr)->next;
        int poped_data = new_node->data;
        new_node->next = *ptr;
        delete new_node;
        return poped_data;
    }
}
void link_list_travel(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data <<"  ";
        ptr = ptr->next;
    }cout<<endl<<endl<<endl<<"Link List Printed Successfully"<<endl;
}

int main()
{
    int i = 0;
    while (i != 3)
    {
        line();
        cout << endl
             << "Press 1 For Implement Stack Using Array" << endl
             << "Press 2 For Implement Stack Using Link List" << endl
             << "Press 3 For Exit"<<endl;
             cout<<"Input Opiton: ";
        cin >> i;
        system("cls");
        if (i == 1)
        {
            stack *s = new stack; // struct ka pointer banaya jisko yek new stack ki taraf point kiya

            s->size = 5; // pointer s jise point kar rha hai us stack ke size naam ke variable ko value assign ki

            s->top = -1; // poointer s jise point kar rha hai us stack ke top naam ke variable ko value assign ki

            // s->arr=(int*)malloc(s->size*sizeof(int));  //ye memory allocation c mai valid  hai c++ mai nahi segmentation fault aa rha hai

            s->arr = new int[s->size]; // pointer s jise point kar rha us stack ke array ko memory allot ki jo integer variable size-1 hai

            int option;
            while (option != 6)
            {
                line();
                cout << endl
                     << "Enter 1 To Push Data In Stack  ";
                cout << endl
                     << "Enter 2 To Pop Data In Stack  ";

                cout << endl
                     << "Enter 3 To Peek In Array";

                cout << endl
                     << "Enter 4 To See Top Most Data";
                cout << endl
                     << "Enter 5 To See Bottom Most Data";
                cout << endl
                     << "Enter 6 To Back To Main Menu" << endl
                     << endl
                     << "Choose Option: ";
                cin >> option;
                system("cls"); // command to clear screen
                if (option == 1)
                {

                    if (check_full(s) == 1)
                    {
                        cout << endl
                             << "stack overflow " << endl;
                    }
                    else
                    {
                        int temp;
                        cout << endl
                             << "Enter data: ";
                        cin >> temp;
                        stack_push(s, temp);
                        cout << endl
                             << "data storerd successfully" << endl;
                    }
                }
                else if (option == 2)
                {
                    if (check_empty(s) == 1)
                    {
                        cout << "Stack Underflow" << endl;
                    }
                    else
                    {
                        int poped_data = stack_pop(s);
                        cout << endl
                             << "stack pop successfully" << endl
                             << "Data " << poped_data << " Poped" << endl;
                    }
                }
                else if (option == 3)
                {
                    cout << endl
                         << "Enter Position On Which Want To Peek In Stack : ";
                    int peek_position;
                    cin >> peek_position;
                    stack_peek(s, peek_position);
                }
                else if (option == 4)
                {
                    stack_top(s);
                }
                else if (option == 5)
                {
                    stack_bottom(s);
                }
            }
        }
        if (i == 2)
        {
            node *top = NULL;
            int option;
            while (option != 6)

            {
                line();
                cout << endl
                     << "Implimentation Of Stack Using Link List" << endl
                     << endl
                     << endl;
                cout << endl
                     << "Press 1 To Push Data In Stack";
                cout << endl
                     << "Press 2 To Pop Data From Stack";
                cout << endl
                     << "Press 3 To Check Node Is Empty";
                cout << endl
                     << "Press 4 To Check Node Is Full";
                cout << endl
                     << "Press 5 TO Print Link List" << endl;
                cout << endl
                     << "Press 6 To Go Back In Main Menu"<<endl;
                     cout<<"Input Option: ";
                cin >> option;
                system("cls");

                if (option == 1)
                {
                    cout << endl
                         << "Enter Data: ";
                    int data;
                    cin >> data;
                    top = node_stack_push(top, data);
                    cout << endl
                         << "Data Store Successfully"<<endl;
                }
                else if (option == 2)
                {
                    if (node_stack_empty(top) == 1)
                    {
                        cout << "Stack Underflow"<<endl;
                    }
                    else
                    {
                        int data = node_stack_pop(&top);
                        cout << endl
                             << data << " Data Poped Successfully "<<endl;
                    }
                }
                else if (option == 3)
                {
                    if (node_stack_empty(top) == 1)
                    {
                        cout << "Stack Under Flow"<<endl;
                    }
                    else
                    {
                        cout << endl
                             << "Stack Not Empty "<<endl;
                    }
                }
                else if (option == 4)
                {
                    if (node_stack_full(top) == 1)
                    {
                        cout << "Stck Overflow"<<endl;
                    }
                    else
                    {
                        cout << endl
                             << "Stack Not Full"<<endl;
                    }
                }
                else if (option == 5)
                {
                    cout << "Link List: ";
                    link_list_travel(top);
                }
            }
        }
    }
    return 0;
}
