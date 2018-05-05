#include <iostream>
using namespace std;
class Element
{
    char item;

  public:
    Element *next = NULL;
    Element()
    {
        this->item = '\0';
    }
    Element(char item)
    {
        this->item = item;
    }
    void setItem(int i)
    {
        this->item = i;
    }
    char getItem()
    {
        if (this->item > -1)
            return this->item;
        return '\0';
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
    Element *pop()
    {
        Element *e = new Element();

        if (isEmpty())
        {
            cout << "Stack kosong";
            e = NULL;
            return e;
        }
        else
        {
            Element *tmp = this->top;
            e = tmp;
            this->top = tmp->next;
            delete (tmp);
            return e;
        }
    }
    Element *getTop()
    {
        Element *e = NULL;
        if (isEmpty())
            return e;
        e = this->top;
        return e;
    }
};
int main()
{
    // Element *e = new Element();
    // e->setItem(5);
    // cout<<e->getItem();
    MyStack ms = MyStack();
    ms.push(new Element('5'));
    ms.push(new Element('+'));
    ms.push(new Element('6'));
    ms.push(new Element('5'));
    Element *e = new Element();
    e = ms.pop();
    while (e != NULL)
    {
        cout << e->getItem() << endl;
        e = ms.pop();
    } 
    return 0;
}