// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;





//2.5 Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
//beginning of the loop.
//DEFINITION
//Circular linked list : A(corrupt) linked list in which a node's next pointer points to an earlier node, so
//as to make a loop in the linked list.
//EXAMPLE
//Input : A->B->C - > D->E->C[the same C as earlier]
//Output: C
//Hints : #50, #69, #83, #90

//2.6 Palindrome: Implement a function to check if a linked list is a palindrome.
//Hints : #5, #13, #29, #61, #101

//2.7 Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
//node.Note that the intersection is defined based on reference, not value.That is, if the kth
//node of the first linked list is the exact same node(by reference) as the jth node of the second
//linked list, then they are intersecting.
//Hints:#20, #45, #55, #65, #76, #93, #111, #120, #129

//2.4 Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
//before all nodes greater than or equal to x.If x is contained within the list, the values of x only need
//to be after the elements less than x(see below).The partition element x can appear anywhere in the
//"right partition"; it does not need to appear between the left and right partitions.
//EXAMPLE
//Input :
//Output :
//3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1[partition = 5]
//3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
//Hints : #3, #24

struct Node
{
	int data;
	Node* next;
};

void PrintList(Node* head)
{
	Node* node = head;
	while (node!=NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

//2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed ?
//Hints : #9, #40
void RemoveDups(Node* head)
{
	if (head == NULL)
		return;
	else if (head->next == NULL)
		return;

	Node* current = head->next;
	Node* previous = head;
	Node* p;
	while (current != NULL)
	{
		p = head;
		while ((p != current))
		{
			if (p->data == current->data)
			{
				previous->next = current->next; //delete current
				current = previous;  //shift one node backwards
				break;
			}
			p = p->next;
		}
		previous = current;
		current = current->next;
	}

	PrintList(head);
}


//2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
//Hints:#8, #25, #41, #67, #126

Node* FindKtoLastNode(Node* head, int k)
{
	Node* node2 = head;
	Node* node1 = head;
	int count = 0;
	while (node2 != NULL)
	{
		count++;
		node2 = node2->next;
		if (count > k)
		{
			node1 = node1->next;
		}
	}
	return node1;
}

//2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
//the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
//that node.
//EXAMPLE
//lnput : the node c from the linked list a->b->c->d->e->f
//Result : nothing is returned, but the new linked list looks like a->b->d->e - >f
//Hints : #72
bool DeleteMiddleNode(Node* node)
{
	if ((node != NULL) || (node->next != NULL))
	{
		node->data = node->next->data;
		node->next = node->next->next;
		return true;
	}
	else
		return false;
}

//2.4 Sum Lists : You have two numbers represented by a linked list, where each node contains a single
//digit.The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
//function that adds the two numbers and returns the sum as a linked list.
//EXAMPLE
//Input : (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
//Output : 2 -> 1 -> 9. That is, 912.
//FOLLOW UP
//Suppose the digits are stored in forward order.Repeat the above problem.
//EXAMPLE
//lnput : (6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295.
//Output : 9 - > 1 -> 2. That is, 912.
//Hints: #7, #30, #71, #95, #109

Node* SumList(Node* head1, Node* head2)
{
	int carrier = 0;
	int value = 0;
	Node* node1 = head1;
	Node* node2 = head2;
	Node* head = new Node;
	Node* node = head;

	int num1 = node1->data;
	int num2 = node2->data;

	if ((node1 == NULL) && (node2 == NULL))
		return NULL;

	while ((node1 != NULL) || (node2 != NULL) || (carrier != 0))
	{
		value = carrier;
		if (node1 != NULL)
		{
			value += node1->data;
			node1 = node1->next;
		}

		if (node2 != NULL)
		{
			value += node2->data;
			node2 = node2->next;
		}

		carrier = value / 10;
		value = value % 10;
		node->data = value;
		if ((node1 == NULL) && (node2 == NULL) && (carrier == 0))
		{
			node->next = NULL;
			return head;
		}
		Node* nextnode = new Node;
		node->next = nextnode;
		node = nextnode;
	}
}

int main()
{
	Node* t;
	Node* head = new Node;
	head->data = 5;
	t = head;

	Node* n = new Node;
	n->data = 5;
	t->next = n;
	t = n;

	n = new Node;
	n->data = 7;
	t->next = n;
	t = n;
	Node* middlenode = n;

	n = new Node;
	n->data = 5;
	t->next = n;
	t = n;

	n = new Node;
	n->data = 6;
	t->next = n;
	t = n;

	n = new Node;
	n->data = 7;
	t->next = n;
	t = n;
	
	t->next = NULL;

	PrintList(head);



	//RemoveDups(head);
	//Node* node1 = FindKtoLastNode(head, 4);
	//DeleteMiddleNode(middlenode);
	//PrintList(head);



	Node* head1 = new Node;
	Node* head2 = new Node;
	Node* node;
	Node* previous;


	head1->data = 5;
	previous = head1;

	node = new Node;
	node->data = 3;
	previous->next = node;
	previous = node;

	node = new Node;
	node->data = 6;
	previous->next = node;
	previous = node;

	previous->next = NULL;


	head2->data = 2;
	previous = head2;

	node = new Node;
	node->data = 7;
	previous->next = node;
	previous = node;

	node = new Node;
	node->data = 8;
	previous->next = node;
	previous = node;

	previous->next = NULL;




	PrintList(head1);
	PrintList(head2);

	Node* result = SumList(head1, head2);
	PrintList(result);


	getchar();

	return 0;
}

