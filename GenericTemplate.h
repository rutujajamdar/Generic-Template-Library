#include<iostream>
using namespace std;

/////////////////////////////////////////////
//        Singly Linked List Structure     //
/////////////////////////////////////////////
template<class T>
struct nodeS
{
    T data;
    struct nodeS * next;
};

/////////////////////////////////////////////
//        Doubly Linked List Structure     //
/////////////////////////////////////////////

template<class T>
struct nodeD
{
    T data;
    struct nodeD * next;
    struct nodeD *prev;
};

/////////////////////////////////////////////
//        Singly Linear Linked List        //
/////////////////////////////////////////////

template<class T>
class SinglyLL
{
    private :
    struct nodeS<T> *Head;
    int Count;

    public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////////////////////////////////////////////
//        Singly Circular Linked List      //
/////////////////////////////////////////////

template<class T>
class SinglyCL
{
    private :
    struct nodeS<T> *Head;
    struct nodeS<T> *Tail;
    int Count;

    public:
    SinglyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////////////////////////////////////////////
//        Doubly Linear Linked List        //
/////////////////////////////////////////////

template<class T>
class DoublyLL
{
    private :
    struct nodeD<T> *Head;
    int Count;

    public:
    DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////////////////////////////////////////////
//        Doubly Circular Linked List      //
/////////////////////////////////////////////

template<class T>
class DoublyCL
{
    private :
    struct nodeD<T> *Head;
    struct nodeD<T> *Tail;
    int Count;

    public:
    DoublyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

//////////////////////////////////////////////
//               Stack                     //
////////////////////////////////////////////

template<class T>
class Stack
{

    private:
    struct nodeS<T> * Head;
    int Count;

    public:
    Stack();
    void Push(T No);
    void  Pop();
    void Display();
    int CountNode();
};

//////////////////////////////////////////////////////
//                   Queue                          //
/////////////////////////////////////////////////////

template<class T>
class Queue
{

    private:
    struct nodeS<T> * Head;
    int Count;

    public:
    Queue();
    void Enqueue(T No);
    void  Dequeue();
    void Display();
    int CountNode();
};

////////////////////////////////////////////////
// Function Definations Singly Linear Linked  //
///////////////////////////////////////////////
template<class T>
SinglyLL<T> :: SinglyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T value)
{
    struct nodeS<T> *newn=NULL;
    newn=new nodeS<T>;
    newn->data=value;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T value)
{
    struct nodeS<T> *newn=NULL;
    newn=new nodeS<T>;
    newn->data=value;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct nodeS<T> *temp=Head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        
    }
    Count++;
}

template <class T>
void  SinglyLL<T> :: InsertAtPos(T value,int Pos)
{
    if((Pos<1) && (Pos >Count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        InsertFirst(value);
    }
    else if(Pos==Count+1)
    {
        InsertLast(value);
    }
    else
    {
        struct nodeS<T> *newn=NULL;
        struct nodeS<T> *temp=Head;
        newn=new nodeS<T>;
        newn->data=value;
        newn->next=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        Count++;

    }
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct nodeS<T> *temp=Head;
        Head=Head->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct nodeS<T> *temp=Head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
        
    }
    Count--;
}

template <class T>
void  SinglyLL<T> :: DeleteAtPos(int Pos)
{
    if((Pos<1) && (Pos >Count))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        DeleteFirst();
    }
    else if(Pos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *temp=Head;
        struct nodeS<T> *tempdelete=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        tempdelete=temp->next;
        temp->next=tempdelete->next;
        delete tempdelete;
        Count--;

    }
}

template<class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements from Linked List are : "<<endl;
    struct nodeS<T> *temp=Head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
template<class T>
int SinglyLL<T> :: CountNode()
{
  return Count;   
}

template<class T>
SinglyCL<T> :: SinglyCL()
{
    Head=NULL;
    Tail=NULL;
    Count=0;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T value)
{
    struct nodeS<T> *newn=NULL;
    newn=new nodeS<T>;
    newn->data=value;
    newn->next=NULL;

    if(Head==NULL && Tail==NULL)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
        Tail->next=Head;
    }
    Count++;
}

template<class T>
void SinglyCL<T> :: InsertLast(T value)
{
    struct nodeS<T> *newn=NULL;
    newn=new nodeS<T>;
    newn->data=value;
    newn->next=NULL;

    if(Head==NULL && Tail==NULL)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {  
       Tail->next=newn;
       Tail=newn;
       Tail->next=Head;    
    }
    Count++;
}

template <class T>
void  SinglyCL<T> :: InsertAtPos(T value,int Pos)
{
    if((Pos<1) && (Pos >Count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        InsertFirst(value);
    }
    else if(Pos==Count+1)
    {
        InsertLast(value);
    }
    else
    {
        struct nodeS<T> *newn=NULL;
        struct nodeS<T> *temp=Head;
        newn=new nodeS<T>;
        newn->data=value;
        newn->next=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        Count++;

    }
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
    if(Head==NULL && Tail==NULL)
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete Tail->next;
        Tail->next=Head;
    }
    Count--;
}

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Tail;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        struct nodeS<T> *temp=Head;
        while (temp->next!=Tail)
        {
            temp=temp->next;
        }
        delete temp->next;
        Tail=temp;
        Tail->next=Head;
        
    }
    Count--;
}

template <class T>
void  SinglyCL<T> :: DeleteAtPos(int Pos)
{
    if((Pos<1) && (Pos >Count))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        DeleteFirst();
    }
    else if(Pos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> *temp=Head;
        struct nodeS<T> *tempdelete=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        tempdelete=temp->next;
        temp->next=tempdelete->next;
        delete tempdelete;
        Count--;

    }
}

template<class T>
void SinglyCL<T> :: Display()
{
    cout<<"Elements from Linked List are : "<<endl;
    struct nodeS<T> *temp=Head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while (temp!=Head);
    cout<<endl;
    
}
template<class T>
int SinglyCL<T> :: CountNode()
{
  return Count;   
}

////////////////////////////////////////////////
// Function Definations Doubly Linear Linked  //
///////////////////////////////////////////////

template<class T>
DoublyLL<T> :: DoublyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T value)
{
    struct nodeD<T> *newn=NULL;
    newn=new nodeD<T>;
    newn->data=value;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T> :: InsertLast(T value)
{
    struct nodeD<T> *newn=NULL;
    newn=new nodeD<T>;
    newn->data=value;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct nodeD<T> *temp=Head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
        
    }
    Count++;
}

template <class T>
void  DoublyLL<T> :: InsertAtPos(T value,int Pos)
{
    if((Pos<1) && (Pos >Count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        InsertFirst(value);
    }
    else if(Pos==Count+1)
    {
        InsertLast(value);
    }
    else
    {
        struct nodeD<T> *newn=NULL;
        struct nodeD<T> *temp=Head;
        newn=new nodeD<T>;
        newn->data=value;
        newn->next=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        Count++;

    }
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        Head=Head->next;
        delete Head->prev;
        Head->prev=NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct nodeD<T> *temp=Head;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
        
    }
    Count--;
}

template <class T>
void  DoublyLL<T> :: DeleteAtPos(int Pos)
{
    if((Pos<1) && (Pos >Count))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        DeleteFirst();
    }
    else if(Pos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *temp=Head;
        struct nodeD<T> *tempdelete=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        Count--;

    }
}

template<class T>
void DoublyLL<T> :: Display()
{
    cout<<"Elements from Linked List are : "<<endl;
    struct nodeD<T> *temp=Head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
template<class T>
int DoublyLL<T> :: CountNode()
{
  return Count;   
}


template<class T>
DoublyCL<T> :: DoublyCL()
{
    Head=NULL;
    Tail=NULL;
    Count=0;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T value)
{
    struct nodeD<T> *newn=NULL;
    newn=new nodeD<T>;
    newn->data=value;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL && Tail==NULL)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }
    Head->prev=Tail;
    Tail->next=Head;
    Count++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T value)
{
    struct nodeD<T> *newn=NULL;
    newn=new nodeD<T>;
    newn->data=value;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL && Tail==NULL)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        Tail->next=newn;
        newn->prev=Tail;
        Tail=newn;
        
    }
    Head->prev=Tail;
    Tail->next=Head;
    Count++;
}

template <class T>
void  DoublyCL<T> :: InsertAtPos(T value,int Pos)
{
    if((Pos<1) && (Pos >Count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        InsertFirst(value);
    }
    else if(Pos==Count+1)
    {
        InsertLast(value);
    }
    else
    {
        struct nodeD<T> *newn=NULL;
        struct nodeD<T> *temp=Head;
        newn=new nodeD<T>;
        newn->data=value;
        newn->next=NULL;
        newn->prev=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        Count++;

    }
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(Head==NULL && Tail==NULL)
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete Head->prev;
    }
    Head->prev=Tail;
    Tail->next=Head;
    Count--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if(Head==NULL && Tail==NULL)
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Tail;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Tail=Tail->prev;
        delete Head->prev;
    }
    Head->prev=Tail;
    Tail->next=Head;
    Count--;
}

template <class T>
void  DoublyCL<T> :: DeleteAtPos(int Pos)
{
    if((Pos<1) && (Pos >Count))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(Pos==1)
    {
        DeleteFirst();
    }
    else if(Pos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *temp=Head;
        struct nodeD<T> *tempdelete=NULL;
        for (int i = 1; i < Pos-1; i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        Count--;

    }
}

template<class T>
void DoublyCL<T> :: Display()
{
    cout<<"Elements from Linked List are : "<<endl;
    struct nodeD<T> *temp=Head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while (temp!=Head);
    cout<<endl;
    
}
template<class T>
int DoublyCL<T> :: CountNode()
{
  return Count;   
}
////////////////////////////////////////////////////////
//                  Searching Techniques              //
///////////////////////////////////////////////////////
template <class T>
int Linear_Search(T Arr[], int Size, T Value)
{
    int index = 0;
    for (int i = 0; i < Size; i++)
    {
        if (Arr[i] == Value)
        {
            index = i;
            break;
        }
    }
    return index;
}
template <class T>
int Binary_Search(T Arr[], int Size, T Value)
{
    int index = 0, middle = 0;
    int Start = 0;
    int End = Size - 1;
    if ((Arr[0] < Arr[1]) && (Arr[End - 1] < Arr[End])) // sorted in Increasing order
    {
        while (Start < End)
        {
            middle = (Start + End) / 2;
            if (Arr[middle] == Value)
            {
                index = middle;
                break;
            }
            else if (Arr[Start] == Value)
            {
                index = Start;
                break;
            }
            else if (Arr[End] == Value)
            {
                index = End;
                break;
            }
            else if (Value < Arr[middle])
            {
                End = middle - 1;
            }
            else
            {
                Start = middle + 1;
            }
        }
    }
    else if (Arr[0] > Arr[1] && Arr[End - 1] > Arr[End]) // sorted in decreasing order
    {
        while (Start < End)
        {
            middle = (Start + End) / 2;
           if (Arr[middle] == Value)
            {
                index = middle;
                break;
            }
            else if (Arr[Start] == Value)
            {
                index = Start;
                break;
            }
            else if (Arr[End] == Value)
            {
                index = End;
                break;
            }
            else if (Value > Arr[middle])
            {
                End = middle - 1;
            }
            else
            {
                Start = middle + 1;
            }
        }
    }
    else // Unsorted
    {
        index=Linear_Search(Arr, Size, Value);
    }

    return index;
}

////////////////////////////////////////////////////////
//                  Sorting Techniques                //
///////////////////////////////////////////////////////

template <class T>
void BubbleSort(T Arr[], int Size, char order)
{
    bool swaped = false;
    if (order == 'i' || order == 'I')
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size - 1 - i; j++)
            {
                if (Arr[j] > Arr[j + 1])
                {
                    T temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                    swaped = true;
                }
            }
            if (swaped == false)
            {
                break;
            }
        }
    }
    else if ((order == 'd') || (order == 'D'))
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size - 1 - i; j++)
            {
                if (Arr[j] < Arr[j + 1])
                {
                    T temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;
                    swaped = true;
                }
            }
            if (swaped == false)
            {
                break;
            }
        }
    }
}

template <class T>
void SelectionSort(T Arr[], int Size, char Order)
{
    int Min_index = 0, i = 0, j = 0;
    T temp;
    int Max_index = 0;
    if (Order == 'i' || Order == 'I')
    {
        for (i = 0; i < Size; i++)
        {
            Min_index = i;
            for (j = i + 1; j < Size; j++)
            {
                if (Arr[j] < Arr[Min_index])
                {
                    Min_index = j;
                }
            }
            if (i != Min_index)
            {
                temp = Arr[Min_index];
                Arr[Min_index] = Arr[i];
                Arr[i] = temp;
            }
        }
    }
    else if (Order == 'd' || Order == 'D')
    {
        for (i = 0; i < Size; i++)
        {
            Max_index = i;
            for (j = i + 1; j < Size; j++)
            {
                if (Arr[j] > Arr[Max_index])
                {
                    Max_index = j;
                }
            }
            if (i != Max_index)
            {
                temp = Arr[Max_index];
                Arr[Max_index] = Arr[i];
                Arr[i] = temp;
            }
        }
    }
}

template <class T>
void InsertionSort(T Arr[], int Size, char Order)
{
    int i = 0, j = 0;
    T selected;
    if (Order == 'i' || Order == 'I')
    {
        for (i = 1; i < Size; i++)
        {
            for (j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
            {
                Arr[j + 1] = Arr[j];
            }
            Arr[j + 1] = selected;
        }
    }
    else if (Order == 'd' || Order == 'D')
    {
        for (i = 1; i < Size; i++)
        {
            for (j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] < selected); j--)
            {
                Arr[j + 1] = Arr[j];
            }
            Arr[j + 1] = selected;
        }
    }
}

//////////////////////////////////////////////
//             Function of Stack           //
////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
{
    Head=NULL;
    Count=0;
}

template<class T>
void Stack<T> :: Push(T No)
{
    struct nodeS<T> * newn=NULL;
    newn=new nodeS<T>;
    newn->data=No;
    newn->next=NULL;

    newn->next=Head;
    Head=newn;

    Count++;

}

template<class T>
void Stack<T> :: Pop()
{
    T No;
    if(Head==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    else if(Head->next==NULL)
    {
        No=Head->data;
        delete Head;
        Head=NULL;
    }
    else
    {
        struct nodeS<T> * temp=Head;
        No=Head->data;
        Head=Head->next;
        delete temp;
    }
    Count--;
    cout<<"Removed Element is : "<<No<<endl;

}

template<class T>
void Stack<T> :: Display()
{
    struct nodeS<T> * temp=Head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
int Stack<T> :: CountNode()
{
    return Count;
}

//////////////////////////////////////////////////////
//                  Function of Queue               //
/////////////////////////////////////////////////////


template<class T>
Queue<T> :: Queue()
{
    Head=NULL;
    Count=0;
}

template<class T>
void Queue<T> :: Enqueue(T No)
{
    struct nodeS<T> * newn=NULL;
    newn=new nodeS<T>;
    newn->data=No;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else if(Head->next==NULL)
    {
        Head->next=newn;
    }
    else
    {
        struct nodeS<T> *temp=Head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        
    }

    Count++;

}

template<class T>
void Queue<T> :: Dequeue()
{
    T No;
    if(Head==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else if(Head->next==NULL)
    {
        No=Head->data;
        delete Head;
        Head=NULL;
    }
    else
    {
        struct nodeS<T> * temp=Head;
        No=Head->data;
        Head=Head->next;
        delete temp;
    }
    Count--;
    cout<<"Removed Element is : "<<No<<endl;

}

template<class T>
void Queue<T> :: Display()
{
    struct nodeS<T> * temp=Head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
int Queue<T> :: CountNode()
{
    return Count;
}
