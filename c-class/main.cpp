#include <iostream>

using namespace std;
class Buku{
private:
  char judul[40];
  int jmlHal;
public: 
  void print(){
      cout<<jmlHal<<endl;
  }
  void setJmlHal(int x){
      jmlHal=(x<0)?0:x;
  }
};

class Node {
public:
    int data;
    Node  *next;
};

int main()
{  
   Node *head, *baru;
   Node *tmp;

   baru = new Node();
   baru->data =5;
   baru->next = NULL;

   head = baru;

   baru = new Node();
   (*baru).data =15;
   baru->next = NULL;

   head->next = baru;

   baru = new Node();
   baru->data =25;
   baru->next = NULL;

   head->next->next = baru;



   tmp = head;   
   while (tmp !=NULL){
       cout<<tmp->data<<endl;
       tmp = tmp->next;
   }

   return 0;
}




