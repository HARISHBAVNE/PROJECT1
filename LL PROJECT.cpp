////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Project name:Various operations on Sequesnce collection using Linked List
//Functions :  InsertFirst,InsertLast,InsertAtPosition,DeleteFirst,DeleteLast,DeleteAtPosition,Display & Count
//Input: 	   int,double,char.
//Output:	   Depends on which function called.
//Description: It is used to check whther number is even or odd
//Date:		   26-05-2021
//Author nmae: HARISH VIJAY BAVNE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////
// Header
////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////
// Structure Tempalate.
////////////////////////////////////////////
template <class T >
struct node
{
	T data;
	struct node *next;
};

//////////////////////////////////////////////////
// Class Tempalate of Singly Linear linked List.
/////////////////////////////////////////////////
template <class T >
class SinglyLL
{
private:
	struct node <T>*Head;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	SinglyLL();
	~SinglyLL();
 	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	
	void Display();
	int Count();
};
////////////////////////////////////////////
// Functions defination.
////////////////////////////////////////////


////////////////////////////////////////////////
//Singly Linear Linked list.
//Constructor.
////////////////////////////////////////////////
template <class T >
SinglyLL < T > :: SinglyLL()
{
	Head = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Singly Linear Linked list.
//Destructor.
////////////////////////////////////////////////
SinglyLL < T > :: ~SinglyLL()
{
	cout<<"Inside Destructor\n";
}


////////////////////////////////////////////////
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void SinglyLL <T> :: InsertFirst(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	
	newn->next = Head;
	Head = newn;
	iSize ++;
}

////////////////////////////////////////////////
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyLL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	struct node <T> *temp = Head;
	
	if (Head == NULL)
	{
		Head = newn;
		iSize ++;
	}
	else if (Head->next == NULL)
	{
		Head->next = newn;
		iSize ++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		iSize++;
	}
	
}

////////////////////////////////////////////////
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void SinglyLL < T >::InsertAtPosition(T No,int Pos)
{
	struct node < T > *newn = NULL;
	newn = new (struct node < T > );
	newn->data = No;
	newn->next = NULL;
	
	struct node < T > *temp = Head;
	
	if ((Pos < 0) || (Pos > iSize+1))
	{
		cout<<"Invalid position\n";
		return ;
	}
	if (Pos == 1)
	{
		InsertFirst(No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		for (int i = 1;i < (Pos-1); i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		iSize ++;
	}
	
	
}

////////////////////////////////////////////////
//Function for Delete Element at First.
////////////////////////////////////////////////
template <class T >
void SinglyLL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		return ;
	}
	else
	{
		Head = Head->next;
		delete(temp);
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyLL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		return ;
	}
	if (Head->next == NULL)
	{
		delete(temp);
		Head = NULL;
		iSize --;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = NULL;
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at given position
////////////////////////////////////////////////
template <class T>
void SinglyLL < T >::DeleteAtPosition(int Pos)
{
	struct node < T > *temp = Head;
	struct node < T > *Target = NULL;
	
	if ((Pos < 0) || (Pos > iSize))
	{
		cout<<"Invalid position\n";
		return ;
	}
	if (Pos == 1)
	{
		DeleteFirst();
	}
	else if (Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		for (int i = 1; i< (Pos-1);i++)
		{
			temp = temp->next;
		}
		Target = temp->next;
		temp->next = Target->next;
		delete(Target);
		iSize --;
	}
	
	
	
}

////////////////////////////////////////////////
//Function for Display Elements in Linked List.
////////////////////////////////////////////////
template <class T >
void SinglyLL<T>:: Display()
{
	struct node <T> *temp = Head;
	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}

////////////////////////////////////////////////
//Function for Number of Element in Linked List.
////////////////////////////////////////////////
template <class T >
int SinglyLL<T>::Count()
{
	return iSize;
}
///////////////////////////////////////////////////
// Project Stage 2.(Singly circular linked list )
///////////////////////////////////////////////////
// Class Tempalate of Singly Circular Linked List
//////////////////////////////////////////////////
template <class T >
class SinglyCL
{
private:
	struct node <T>*Head;
	struct node <T>*Tail;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	SinglyCL();
	~SinglyCL();
 	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	
	void Display();
	int Count();
};
////////////////////////////////////////////
// Functions defination.
////////////////////////////////////////////


////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////
template <class T >
SinglyCL < T > :: SinglyCL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Destructor.
////////////////////////////////////////////////
SinglyCL<T>::~SinglyCL()
{
	cout<<"Inside Destructor.\n";
}

////////////////////////////////////////////////
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void SinglyCL <T> :: InsertFirst(T No)
{
	struct node <T> *temp = Head;
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else  if (Head == Tail)
	{
		newn->next = Head;
		Tail = newn->next;
		Head = newn;
		Tail->next = Head;
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		Tail->next = Head;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyCL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	struct node <T> *temp = Head;
	
	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else if (Head == Tail)
	{
		Tail->next = newn;
		Tail = newn;
		Tail->next = Head;
		iSize ++;
	}
	else
	{
		Tail->next = newn;
		Tail = newn;
		Tail->next = Head;
		iSize++;
	}
}

////////////////////////////////////////////////
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void SinglyCL < T >::InsertAtPosition(T No,int Pos)
{
	struct node < T > *newn = NULL;
	newn = new (struct node < T > );
	newn->data = No;
	newn->next = NULL;
	
	struct node < T > *temp = Head;
	
	if ((Pos < 0) || (Pos > iSize+1))
	{
		cout<<"Invalid position\n";
		return ;
	}
	if (Pos == 1)
	{
		InsertFirst(No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		for (int i = 1;i < (Pos-1); i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		iSize ++;
	}
	
	
}

////////////////////////////////////////////////
//Function for Delete Element at first.
////////////////////////////////////////////////
template <class T >
void SinglyCL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		cout<<"Linked list is empty\n";
		return ;
	}
	if (Head == Tail)
	{
		delete(Head);
		Head = NULL;
		Tail = NULL;
		iSize --;
	}
	else
	{
		Head = temp->next;
		delete(temp);
		Tail->next = Head;
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void SinglyCL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (Head == NULL)
	{
		return ;
	}
	if (Head == Tail)
	{
		delete(temp);
		Head = NULL;
		Tail = NULL;
		iSize --;
	}
	else
	{
		while(temp->next->next != Head)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp = Tail;
		Tail->next = Head;
		iSize --;
	}
}

////////////////////////////////////////////////
//Function for Delete Element at given position.
////////////////////////////////////////////////
template <class T>
void SinglyCL < T >::DeleteAtPosition(int Pos)
{
	struct node < T > *temp = Head;
	struct node < T > *Target = NULL;
	
	if ((Pos < 0) || (Pos > iSize))
	{
		cout<<"Invalid position\n";
		return ;
	}
	if (Pos == 1)
	{
		DeleteFirst();
	}
	else if (Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		for (int i = 1; i< (Pos-1);i++)
		{
			temp = temp->next;
		}
		Target = temp->next;
		temp->next = Target->next;
		delete(Target);
		iSize --;
	}
	
	
	
}

////////////////////////////////////////////////
//Function for Display Elements in Linked list.
////////////////////////////////////////////////
template <class T >
void SinglyCL<T>:: Display()
{
	struct node <T> *temp = Head;
	for (int i = 1;i<=iSize;i++)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
	
}

////////////////////////////////////////////////////////
//Function for Count Number of elements in Linked list.
///////////////////////////////////////////////////////
template <class T >
int SinglyCL<T>::Count()
{
	return iSize;
}



////////////////////////////////////////////
// Structure Tempalate.
////////////////////////////////////////////
template <class T >
struct node
{
	T data;
	struct node *next;
	struct node *prev;
};

///////////////////////////////////////////////////
// Class Tempalate of Doubly Linear Linked List
//////////////////////////////////////////////////
template <class T >
class DoublyLL
{
private:
	struct node <T>*Head;
	struct node <T>*Tail;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	DoublyLL();
	~DoublyLL();
 	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	
	void Display();
	int Count();
};
////////////////////////////////////////////
// Functions defination.
////////////////////////////////////////////


////////////////////////////////////////////////
//Constructor
////////////////////////////////////////////////
template <class T >
DoublyLL < T > :: DoublyLL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Destructor.
////////////////////////////////////////////////
DoublyLL<T>::~DoublyLL()
{
	cout<<"Inside Destructor\n";
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyLL <T> :: InsertFirst(T No)
{
	struct node <T> *temp = Head;
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (iSize == 0)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		iSize ++;
	}
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyLL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (iSize == 0)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyLL < T >::InsertAtPosition(T No,int Pos)
{
	struct node < T > *newn = NULL;
	newn = new (struct node < T > );
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	struct node < T > *temp = Head;
	if ((Pos <0 ) ||(Pos > iSize+1))
	{
		cout<<"Invalid position\n";
		return;
	}
	if (Pos == 1)
	{
		InsertFirst(No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		for (int i = 1;i< Pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Delete Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyLL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (iSize == 0)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	if (Head == Tail)
	{
		delete(Head);
		Head = NULL;
		Tail = NULL;
		iSize --;
	}
	else
	{
		// Head = temp->next;
		// temp->next->prev = NULL;
		// delete(temp);
		Head = Head->next;
		delete(Head->next->prev);
		
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyLL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (iSize == 0)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	if (Head == Tail)
	{
		delete(Head);
		Head = NULL;
		Tail = NULL;
		iSize --;
	}
	else
	{
		for (int i = 1;i<iSize;i++)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = NULL;
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Delete Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyLL < T >::DeleteAtPosition(int Pos)
{
	struct node < T > *temp = Head;
	struct node < T > *Target = Head;
	if ((Pos < 0)||(Pos > iSize))
	{
		cout<<"Invalid Position\n";
		return ;
	}
	if (Pos == 1)
	{
		DeleteFirst();
	}
	else if (Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		for (int i = 1;i<Pos-1;i++)
		{
			temp = temp->next;
		}
		Target = temp->next;
		temp->next = Target->next;
		Target->next->prev = temp;
		delete(Target);
		iSize --;
	}
	
	
}

////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Display Elements in Linked list.
////////////////////////////////////////////////
template <class T >
void DoublyLL<T>:: Display()
{
	struct node <T> *temp = Head;
	cout<<"NULL<=>";
	for (int i = 1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|"<<"<=>"<<"\t";
		temp = temp->next;
	}
	cout<<"NULL\n";
	
}

////////////////////////////////////////////////////////
//Doubly Linear Linked
//Function for Count Number of elements in Linked list.
///////////////////////////////////////////////////////
template <class T >
int DoublyLL<T>::Count()
{
	return iSize;
}



////////////////////////////////////////////
// Structure Tempalate.
////////////////////////////////////////////
template <class T >
struct node
{
	T data;
	struct node *next;
	struct node *prev;
};

///////////////////////////////////////////////////
//Doubly Circular Linked List.
// Class Tempalate of Doubly Circular Linked List
//////////////////////////////////////////////////
template <class T >
class DoublyCL
{
private:
	struct node <T>*Head;
	struct node <T>*Tail;
	int iSize;
	
public:
	/////////////////////////////////////
	//Function declartion
	////////////////////////////////////
	DoublyCL();
	~DoublyCL();
 	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int Pos);
	
	void Display();
	int Count();
};
////////////////////////////////////////////
// Functions defination.
////////////////////////////////////////////

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Constructor
////////////////////////////////////////////////
template <class T >
DoublyCL < T > :: DoublyCL()
{
	Head = NULL;
	Tail = NULL;
	iSize = 0;
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Destructor.
////////////////////////////////////////////////
template <class T >
DoublyCL < T > :: ~DoublyCL()
{
	cout<<"Inside Destructor\n";
}


////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Insert Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyCL <T> :: InsertFirst(T No)
{
	struct node <T> *temp = Head;
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (iSize == 0)
	{
		Head = newn;
		Tail = newn;
		Tail->next = Head;
		Head->prev = Tail;
		iSize ++;
	}
	else
	{
		newn->next = Head;
		Head = newn;
		Tail->next = Head;
		Head->prev = Tail;
		iSize ++;
	}
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Insert Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyCL < T > ::InsertLast(T No)
{
	struct node <T> *newn = NULL;
	newn = new struct node <T>;
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	if (iSize == 0)
	{
		Head = newn;
		Tail = newn;
		iSize ++;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
		
		Tail->next = Head;
		Head->prev = Tail;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Insert Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyCL < T >::InsertAtPosition(T No,int Pos)
{
	struct node < T > *newn = NULL;
	newn = new (struct node < T > );
	newn->data = No;
	newn->next = NULL;
	newn->prev = NULL;
	
	struct node < T > *temp = Head;
	if ((Pos <0 ) ||(Pos > iSize+1))
	{
		cout<<"Invalid position\n";
		return;
	}
	if (Pos == 1)
	{
		InsertFirst(No);
	}
	else if(Pos == iSize+1)
	{
		InsertLast(No);
	}
	else
	{
		for (int i = 1;i< Pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize ++;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Delete Element at first.
////////////////////////////////////////////////
template <class T >
void DoublyCL < T > :: DeleteFirst()
{
	struct node <T> *temp = Head;
	if (iSize == 0)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	if (Head == Tail)
	{
		delete(Head);
		Head = NULL;
		Tail = NULL;

		iSize --;
	}
	else
	{
		Head = temp->next;
		Tail->next = Head;
		Head->prev = Tail;
		delete(temp);
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Delete Element at Last.
////////////////////////////////////////////////
template <class T >
void DoublyCL < T > :: DeleteLast()
{
	struct node <T> *temp = Head;
	if (iSize == 0)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	if (Head == Tail)
	{
		delete(Head);
		Head = NULL;
		Tail = NULL;
		
		iSize --;
	}
	else
	{
		while (temp->next!=Tail)
		{
			temp = temp->next;
		}
		delete(Tail);
		Tail = temp;
		Tail->next = Head;
		Head->prev = Tail;
		iSize --;
	}
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Delete Element at given position.
////////////////////////////////////////////////
template <class T>
void DoublyCL < T >::DeleteAtPosition(int Pos)
{
	struct node < T > *temp = Head;
	struct node < T > *Target = Head;
	if ((Pos < 0)||(Pos > iSize))
	{
		cout<<"Invalid Position\n";
		return ;
	}
	if (Pos == 1)
	{
		DeleteFirst();
	}
	else if (Pos == iSize)
	{
		DeleteLast();
	}
	else
	{
		for (int i = 1;i<Pos-1;i++)
		{
			temp = temp->next;
		}
		Target = temp->next;
		temp->next = Target->next;
		Target->next->prev = temp;
		delete(Target);
		iSize --;
	}
	
	
}

////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Display Elements in Linked list.
////////////////////////////////////////////////
template <class T >
void DoublyCL<T>:: Display()
{
	struct node <T> *temp = Head;
	;
	for (int i = 1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|"<<"<=>"<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
	
}

////////////////////////////////////////////////////////
//Doubly Circular Linked List.
//Function for Count Number of elements in Linked list.
///////////////////////////////////////////////////////
template <class T >
int DoublyCL<T>::Count()
{
	return iSize;
}



/////////////////////////////////////////
//  Main Satrter
////////////////////////////////////////
int main()
{
	
	int iRet = 0;
	///////////////////////////////////
	//Singly Linear Linked List.
	///////////////////////////////////
	SinglyLL <int> obj;
	obj.InsertFirst(40);
	obj.InsertFirst(30);
	obj.InsertFirst(20);
	obj.InsertFirst(10);
	
	obj.InsertLast(50);
	
	// obj.DeleteFirst();
	// obj.DeleteLast();
	
	// obj.InsertAtPosition(70,5);
	
	//obj.DeleteAtPosition(3);
	
	obj.Display();
	iRet = obj.Count();
	cout<<iRet<<"\n";
	cout<<"\n";
	cout<<"\n";
	
	///////////////////////////////////
	//Singly Circular Linked List.
	///////////////////////////////////
	SinglyCL <int> obj1;
	obj1.InsertFirst(40);
	obj1.InsertFirst(30);
	obj1.InsertFirst(20);
	obj1.InsertFirst(10);
	
	obj1.InsertLast(50);
	
	obj1.DeleteFirst();
	obj1.DeleteLast();
	
	obj1.InsertAtPosition(70,5);
	
	obj1.DeleteAtPosition(7);
	
	obj1.Display();
	iRet = obj1.Count();
	cout<<iRet<<"\n";
	
	///////////////////////////////////
	//Doubly Linear Linked List.
	///////////////////////////////////
	int iRet = 0;
	DoublyLL <int> obj3;
	obj3.InsertFirst(40);
	obj3.InsertFirst(30);
	obj3.InsertFirst(20);
	obj3.InsertFirst(10);
	
	// obj3.InsertLast(50);
	
	// obj3.DeleteFirst();
	// obj3.DeleteLast();
	
	// obj3.InsertAtPosition(70,6);
	
	// obj3.DeleteAtPosition(5);
	
	obj3.Display();
	iRet = obj3.Count();
	cout<<iRet<<"\n";
	
	///////////////////////////////////////////
	//Doubly Circular Linked List.
	///////////////////////////////////////////
	DoublyCL <int> obj3;
	// obj3.InsertFirst(40);
	// obj3.InsertFirst(30);
	// obj3.InsertFirst(20);
	obj3.InsertFirst(10);
	
	// obj3.InsertLast(50);
	
	// obj3.DeleteFirst();
	// obj3.DeleteLast();
	
	// obj3.InsertAtPosition(70,6);
	
	obj3.DeleteAtPosition(3);
	
	obj3.Display();
	iRet = obj3.Count();
	cout<<iRet<<"\n";
	
	return 0;
}