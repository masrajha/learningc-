#include <iostream>
using namespace std;
class Element
{
    char item;

  public:
    Element *next;
    void setItem(int i)
    {
        this->item = i;
    }
    char getItem()
    {
        return this->item;
    }
};

class MyStack
{
    Element *top;

  public:
    MyStack()
    {
        this->top = NULL;
    }
    bool isEmpty()
    {
        if (this->top == NULL)
            return true;
        return false;
    }
    bool isFull()
    {
        Element *tmp = new Element();
        if (tmp)
            return false;
        return true;
    }
    void push(Element *e)
    {
        if (!isFull())
        {
            if (isEmpty())
            {
                this->top = e;
                this->top->next = NULL;
            }
            else
            {
                e->next = this->top;
                this->top = e;
            }
        }
        else
        {
            cout << "Stack Penuh";
        }
    }
    Element pop()
    {
        Element *e = new Element();
        if (isEmpty())
        {
            cout << "Stack kosong";
             return *e;
        }
        else
        {
            e = this->top;
            this->top = this->top->next;
            return *e;
        }
    }
    Element getTop()
    {
        Element *e = NULL;
        if (isEmpty())
            return *e;
        e = this->top;
        return *e;
    }
};
int main()
{
    // Element *e = new Element();
    // e->setItem(5);
    // cout<<e->getItem();
    MyStack ms = MyStack();
    Element *e = new Element();
    e->setItem('5');
    ms.push(e);
    e = new Element();
    e->setItem('+');
    ms.push(e);
    e = new Element();
    e->setItem('2');
    ms.push(e);
    cout << ms.pop().getItem() << endl;
    cout << ms.pop().getItem() << endl;
    cout << ms.pop().getItem() << endl;
    cout << ms.pop().getItem() << endl;
    return 0;
}