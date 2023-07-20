// we need to set the next pointer of the tail node to the head pointer
#include<stdio.h>

struct Node{
	int val;
	Node *next;
};


Node* convertToCircular(Node *head){
	Node* start = head;

	while(head->next != NULL){
		head = head->next;
	}

	head->next = start;
	return start;
}
