#include <iostream>

using namespace std;
class Mahasiswa
{
    int id;
    char Nama[50];
};
class Node
{
  public:
    int data;
    Node *next;
};

Node *head;

void init()
{
    head = NULL;
}
bool isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}
void tambahDepan(int databaru)
{
    Node *baru;
    baru = new Node();
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty())
    {
        head = baru;
        head->next = head;
    }
    else
    {
        Node *bantu;
        bantu = head;
        while (bantu->next != head)
        {
            bantu = bantu->next;
        }
        baru->next = head;
        head = baru;
        bantu->next = head;
    }
}
void cetak(){
    if (!isEmpty()){
        Node *bantu;
        bantu = head;
        do{
            cout<<bantu->data<<" ,";
            bantu=bantu->next;
        }while (bantu!=head);
    } else {
        cout<<"List Kosong";
    }
}
int main()
{
    init();
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        tambahDepan(data);
    }
    cetak();
    return 0;
}