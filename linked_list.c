#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void sortedInsert(struct Node** head_ref, int num){
	struct Node* current;
	/*struct Node* new_node = new Node;*/
	struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
	new_node->data = num;
	if (*head_ref == NULL || (*head_ref)->data > num){
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else{
		current = *head_ref;
		while(current->next!=NULL && current->next->data < new_node->data){
			current = current->next;
		}
		if (current->next->data != new_node->data){
			new_node->next = current->next;
			current->next = new_node;
		}
	}
}

void deleteNode(struct Node **head_ref, int key){
	struct Node* temp = *head_ref, *prev;
	if (temp != NULL && temp->data == key){
		*head_ref = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) return;
	prev->next = temp->next;
	free(temp);
}

void push(struct Node** head_ref, int num){
	/*struct Node* new_node = new Node;*/
	struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
	new_node->data = num;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head){
	if (head == NULL){
		printf("EMPTY");
		return;
	}
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d", temp->data);
		if (temp->next != NULL){
			printf(" ");
		}
		temp = temp->next;
	}
}


int main(int argc, char* argv[]) {
	const char *filename = argv[1];
	FILE *file = fopen(filename, "r");
	if (file == NULL){
		printf("error");
	}
	char line[256];

	struct Node *a = NULL;


	while(fgets(line, sizeof(line), file)!=NULL){
		
		char *opt = strtok(line, " ");
		char *num_chr = strtok(NULL, " ");
		int num = atoi(num_chr);

		if (strcmp(opt, "INSERT") == 0){
			sortedInsert(&a, num);
		}
		else{
			deleteNode(&a, num);
		}
		
		printList(a);
		printf("\n");
		
	}


	fclose(file);
	return 0;
}
