#include <iostream>

struct Node
{
  Node* next;
  int data;
};

/*
This function is expected to 

 */
Node* insertAtEnd( Node* head, int data )
{
  Node* headToReturn = head;
  
  // Head is empty, there is no element in the list
  if( head == NULL )
    {
      head = new Node();
      head->next = NULL;
      head->data = data;

      std::cout << "Inserted " << data << " at head, fist elment in list inserted" << std::endl;
      return head;
    }
  
  // There are already some elements in the List, so let's find out the end of list
  // Then we add the new element at the end of the list

  // We are going to modify the head, as we traverse it
  // So we store the orignal <head> pointer so we can return it back
  else
    {
      int count = 0;
      while( head != NULL )
	{
	  head = head->next;
	  count = count + 1;
	}
      head = new Node();
      head->next = NULL;
      head->data = data;

      std::cout << "Inserted " << data << " at head, size of List is " << count + 1 << std::endl;
    }
  
  return headToReturn;
}

void printList( Node* head )
{
  while( head != NULL )
    {
      std::cout << head->data << "->";
      head = head->next;
    }
  std::cout << "--|" << std::endl; 
}

int main()
{
  Node * head = NULL;
  head = insertAtEnd( head, 10 );
  head = insertAtEnd( head, 20 );
  printList( head );
  return 0;
}
