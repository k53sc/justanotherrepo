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

int listSize( Node* head )
{
  if( head == NULL )
    {
      return 0;
    }
  int size = 1;
  while( head->next != NULL )
    {
      size = size + 1;
      head = head->next;
    }
  return size;
}


void swap( int first, int second, Node* head )
{
  // Check size, if any of the funny things among below happens, return
  int size = listSize( head );
  if( first > size || second > size || first < 1 || second < 1 )
    {
      std::cout << "Can't swap, either index argument is out of bounds" << std::endl;
      return;
    }

  Node* firstE = head;

  // pre increment is required as 1 means look for data at head, not goto next
  while(  --first )
    firstE = firstE->next;

  Node* secondE = head;
  while( --secondE )
    secondE = secondE->next;

  std::cout << "first element " << firstE->data << std::endl;
  std::cout << "second element " << secondE->data << std::endl;
}


int main()
{
  Node * head = NULL;
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 10 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 20 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 30 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 40 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  printList( head );

  while( 1 )
    {
      int first, second = 0;
      std::cin >> first >> second;
      swap( first, second, head );
    }
  
  return 0;
}
