#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *data;
    struct Node *next;
};

void append(struct Node **head, char *str) {
    struct Node *new_node;
    struct Node *current;

    new_node = malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    new_node->data = malloc(strlen(str) + 1);

    if (new_node->data == NULL) {
        printf("Memory allocation error\n");
        free(new_node);
        return;
    }

    strcpy(new_node->data, str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void free_list(struct Node *head) {
    struct Node *next;

 	   while (head != NULL) {
        next = head->next;

        free(head->data);
        free(head);

        head = next;
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *current;

    char buffer[1024];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);

        if (buffer[0] == '.') {
            break;
        }

        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        if (strlen(buffer) > 0) {
            append(&head, buffer);
        }
    }

    current = head;

    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }

    free_list(head);

    return 0;
}
