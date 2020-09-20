#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QNode{
	int data;
	struct QNode* next;
};

struct Queue{
	struct QNode* head;
	struct QNode* tail;
};

void enQueue(struct Queue* q, int data){
	struct QNode * newNode = (struct QNode*)malloc(sizeof(struct QNode));
	newNode->data = data;
	newNode->next = NULL;
	if (q->tail == NULL){
		q->head = newNode;
		q->tail = newNode;
		return;
	}
	q->tail->next = newNode;
	q->tail = newNode;
}

void push(struct Queue* q, int data){
	struct QNode * newNode = (struct QNode*)malloc(sizeof(struct QNode));
	newNode->data = data;
	newNode->next = q->head;
	q->head = newNode;
}

void pop(struct Queue* q){
	if (q->head == NULL)return;
	struct QNode* headNode = q->head;
	q->head = q->head->next;
	if (q->head == NULL)q->tail = NULL;
	free(headNode);
}

void print(struct Queue* q){
	if (q->head == NULL){
		printf("Empty");
		return;
	}
	struct QNode * temp = q->head;
	while(temp != NULL){
		printf("%d", temp->data);
		if (temp->next != NULL){
			printf(" ");
		}
		temp = temp->next;
	}
}

int main(int argc, char* argv[]){
	const char *fileName = argv[1];
	FILE *f = fopen(fileName, "r");
	char line[256];

	struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
	q->head = NULL;
	q->tail = NULL;


	while(fgets(line, sizeof(line), f)!=NULL){
		char * opt = strtok(line, " ");
		char * data_str = strtok(NULL, " ");

		if (data_str != NULL){
			int data = atoi(data_str);
			if (strcmp(opt, "ENQUEUE") == 0){
				enQueue(q, data);
			}
			if (strcmp(opt, "PUSH") == 0){
				push(q, data);
			}
		}
		else{
			
			pop(q);

		}
		print(q);
		printf("\n");

	}
	return 0;
}