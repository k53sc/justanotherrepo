#include <iostream>

struct Node
{
  Node* next;
  int data;
};

void insertAtHead( Node* head, int data )
{
  if( head == NULL )
    {
      head = new Node();
      head->next = NULL;
      head->data = data;
    }
}

int main()
{
  Node * head = NULL;
  insertAtHead( head, 10 );
  return 0;
}
