/**
 * @file main.c
 * @author Colin Francis
 * @brief A doubly linked list implementation in C
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// linked list struct with pointers to head and tail nodes
struct linkedList {
    struct node *head;
    struct node *tail;
};

// node struct which holds an integer value and pointers to the
// next node and previous node relative to itself
struct node {
    int value;
    struct node *prevNode;
    struct node *nextNode;
};

/**
 * @brief Prints the value of the linked list as they appear from head
 * node to tail node
 * 
 * @param linkedList A pointer to a linked list struct containing pointers
 * to head and tail nodes
 */
void printLinkedListForward(struct linkedList *linkedList) {
    // set current node pointer equal to head node pointer
    struct node *currNode = linkedList->head;

    printf("Linked List Forward: ");
    if (currNode->nextNode) {
        printf("%d <-> ", currNode->value);
        currNode = currNode->nextNode;
    } else {
        printf("%d\n", currNode->value);
        return;
    }

    // iterate through linked list until the last node is found
    while (currNode && currNode->nextNode) {
        // display each linked list node value
        printf("%d - ", currNode->value);
        // point to next node in linked list
        currNode = currNode->nextNode;
    }

    // display final linked list node value
    printf("%d\n", currNode->value);
}

/**
 * @brief Initializes a new linked list
 * 
 * @param value The value of the node to initialize the linked list with
 * @param linkedList A pointer to a linked list struct containing pointers
 * to head and tail nodes
 */
void initLinkedList(int value, struct linkedList *linkedList) {
    // allocate memory on heap for new struct node
    struct node *nodePtr = (struct node*) malloc(sizeof(struct node));
    // create a new struct node
    struct node node = {.value=value, .prevNode=NULL, .nextNode=NULL};

    *nodePtr = node;  // store new struct node on heap

    // set linked list head and tail to point to new struct node
    linkedList->head = nodePtr;
    linkedList->tail = nodePtr;
}

/**
 * @brief Adds a new node to the end of the linked list
 * 
 * @param value The value of the node to be added
 * @param linkedList A pointer to a linked list struct containing pointers
 * to head and tail nodes
 */
void addNode(int value, struct linkedList *linkedList) {
    // allocate memory on heap for new struct node
    struct node *nodePtr = (struct node*) malloc(sizeof(struct node));
    // create a new struct node
    struct node node = {.value=value, .prevNode=NULL, .nextNode=NULL};

    *nodePtr = node;  // stroe new struct node on heap 

    // link current tail node and new node
    (linkedList->tail)->nextNode = nodePtr;
    nodePtr->prevNode = linkedList->tail;

    // set new node to be the new tail
    linkedList->tail = nodePtr;
}

/**
 * @brief Driver code for doubly linked list implementation
 * 
 * @return int 
 */
int main(void) {
    struct linkedList linkedList = {.head=NULL, .tail=NULL};

    initLinkedList(10, &linkedList);
    printLinkedListForward(&linkedList);

    for (int value = 2; value < 11; value++) {
        addNode(value * 10, &linkedList);
    }
    printLinkedListForward(&linkedList);

    return 0;
}
