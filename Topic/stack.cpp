
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
int main()
{
    stack *s = new stack; // struct ka pointer banaya jisko yek new stack ki taraf point kiya

    s->size = 5; // pointer s jise point kar rha hai us stack ke size naam ke variable ko value assign ki

    s->top = -1; // poointer s jise point kar rha hai us stack ke top naam ke variable ko value assign ki

    // s->arr=(int*)malloc(s->size*sizeof(int));  //ye memory allocation c mai valid  hai c++ mai nahi segmentation fault aa rha hai

    s->arr = new int[s->size]; // pointer s jise point kar rha us stack ke array ko memory allot ki jo integer variable size-1 hai

    int option;
    while (option != 4)
    {
        line();
        cout << endl
             << "Enter 1 To Push Data In Stack  ";
        cout << endl
             << "Enter 2 To Pop Data In Stack  ";

        cout << endl
             << "Enter 3 To Peek In Array";

        cout << endl
             << "Enter 4 To Exit From Program" << endl
             << endl
             << "Choose Option: ";
        cin >> option;
        system("cls");
        if (option == 1)
        {

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
    }
}
