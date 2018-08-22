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
      // Head is present, hence size is atleast 1
      int count = 1;

      // We have already stored a copy of head as 'headToReturn'
      // All we need to do now is to go the last element of the list
      // This is done by creating a loop which runs till it finds a Node elemnt which has 'NULL' next element
      // Then we create a new element and wrie it to be the last in the list
      while( head->next != NULL )
	{
	  head = head->next;
	  count = count + 1;
	}
      Node* newNode = new Node();
      newNode->next = NULL;
      newNode->data = data;

      head->next = newNode;

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
  head = insertAtEnd( head, 30 );
  head = insertAtEnd( head, 40 );
  printList( head );
  return 0;
}
