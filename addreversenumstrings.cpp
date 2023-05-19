#include<iostream>
#include<cmath>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
  Node(int d)
  {
    this->data=d;
    this->next=NULL;
  }
};

class LinkedList
{
public:
  Node* head;

  LinkedList()
  {
    head=NULL;
  }

  void Insert(int d)
  {
    Node* n=new Node(d);
    if(head==NULL)
    {
      head=n;
      return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=n;
    return;
  }

  void output()
  {
    Node* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"->";
      temp=temp->next;
    }
  }
};

LinkedList sum(LinkedList l1,LinkedList l2)
{
  int n1=0,n2=0;
  Node* temp1=l1.head;
  Node* temp2=l2.head;
  int i=0;

  while(temp1!=NULL || temp2!=NULL)
  {
    n1+=((temp1->data)*pow(10,i));
    temp1=temp1->next;
    n2+=((temp2->data)*pow(10,i));
    temp2=temp2->next;
    i++;
  }

  i=1;
  int sum=n1+n2;
  LinkedList l;
  int rem;
  while(sum>0)
  {
    int e=0;
    e=(sum%int(pow(10,i)));
    sum-=e;
    e=e/int(pow(10,i-1));
    i++;
    l.Insert(e);
  }
  return l;
}

main()
{
  LinkedList l1;
  LinkedList l2;

  l1.Insert(7);
  l1.Insert(1);
  l1.Insert(5);
  cout<<"List l1: ";
  l1.output();

  l2.Insert(5);
  l2.Insert(9);
  l2.Insert(2);
  cout<<endl<<"List l2: ";
  l2.output();

  cout<<endl;
  LinkedList l3;
  l3=sum(l1,l2);
  cout<<"Sum of list in reverse: ";
  l3.output();
}
