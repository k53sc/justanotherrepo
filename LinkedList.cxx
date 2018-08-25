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


Node* swap( int first, int second, Node* head )
{
  if( head == NULL )
    {
      std::cout << "swap: NULL head passed" << std::endl;
      return NULL;
    }
  
  // Check size, if any of the funny things among below happens, return
  int size = listSize( head );
  std::cout << "swap: size of list is  " << size << std::endl;
  if( first > size || second > size || first < 1 || second < 1 )
    {
      std::cout << "Can't swap, either index argument is out of bounds" << std::endl;
      return head;
    }

  // we will like to store the the prev pointer as well
  Node* firstE = head;
  Node* firstE_prev = NULL;

  // pre increment is required
  while(  --first && firstE != NULL )
    {
      firstE_prev = firstE;
      firstE = firstE->next;
    }

  Node* secondE = head;
  Node* secondE_prev = NULL;
  while( --second && secondE != NULL )
    {
      secondE_prev = secondE;
      secondE = secondE->next;
    }

  // fix head first
  if( firstE_prev != NULL )
    {
      firstE_prev->next = secondE;
    }
  else
    {
      head = secondE;
    }

  if( secondE_prev != NULL )
    {
      secondE_prev->next = firstE;
    }
  else
    {
      head = firstE;
    }

  Node* temp = firstE->next;
  firstE->next = secondE->next;
  secondE->next = temp;
  
  // https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/

  // we have to return the new head as well
  return head;
}

Node* reverse( Node* head )
{
  int size = listSize( head );
  int first = 1;
  int second = size;

  while( first < second )
    {
      std::cout << "reverse: swappig " << first << " " << second << std::endl;
      head = swap( first, second, head );
      first = first + 1;
      second = second - 1;	
    }
  return head;
}

Node* addList( Node* head1, Node* head2 )
{

  std::cout << "addlist list 1 " << std::endl;
  printList( head1 );
  std::cout << "addlist list 2 " << std::endl;
  printList( head2 );
  
  head1 = reverse( head1 );
  head2 = reverse( head2 );

  int size_l1 = listSize( head1 );
  int size_l2 = listSize( head2 );

  if( size_l1 > size_l2 )
    {
      int diff = size_l1 - size_l2;
      while( diff > 0 )
	{
	  head2 = insertAtEnd( head2, 0 );
	}
    }
  else
    {
      int diff = size_l2 - size_l1;
      while( diff > 0 )
	{
	  head1 = insertAtEnd( head1, 0 );
	}
    }

  // Now we are sure both list are of same size
  
  Node* head3 = NULL;
  int carry = 0;
  while( head1->next != NULL || head2->next != NULL )
    {
      int sum = head1->data + head2->data + carry;
      if( sum > 9 )
	{
	  head3 = insertAtEnd( head3, sum % 10 );
	  carry = 1;
	}

      else
	{
	  head3 = insertAtEnd( head3, sum );
	  carry = 0;
	}
      head1 = head1->next;
      head2 = head2->next;
    }

  // final element
  int final = head1->data + head2->data + carry;
  if( final > 9 )
    {
      head3 = insertAtEnd( head3, final % 10 );
      carry = 1;
    }
  
  else
    {
      head3 = insertAtEnd( head3, final );
      carry = 0;
    }
  
  if( carry )
    head3 = insertAtEnd( head3, 1 );

  head3 = reverse( head3 );

  printList( head3 );
  // std::cout << "addlist result" << printList( head3 ) << std::endl;
  return head3;
}

int main()
{
  Node * head = NULL;
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 5 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 5 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 5 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  head = insertAtEnd( head, 5 );
  std::cout << "List size: " << listSize( head ) << std::endl;
  printList( head );

  head = reverse( head );
  printList( head );

  Node * head2 = NULL;
  head2 = insertAtEnd( head2, 5 );
  head2 = insertAtEnd( head2, 5 );
  head2 = insertAtEnd( head2, 5 );
  head2 = insertAtEnd( head2, 5 );
  printList( head2 );

  Node* head3 = addList( head, head2 );
  printList( head3 );

  /*
  while( 1 )
    {
      int first, second = 0;
      std::cin >> first >> second;
      head = swap( first, second, head );
      printList( head );
    }
  */
  
  return 0;
}
