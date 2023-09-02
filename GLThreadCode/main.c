#include "glthread.h"
#include <stdlib.h>
#include <stdio.h>

// Private helper function to add a new_node right after curr_node in the thread
static void _glthread_add_next(glthread_node_t *curr_node, glthread_node_t *new_node){

    // If the current node's right is NULL, insert new_node to the right of it
    if(!curr_node->right){
        curr_node->right = new_node;
        new_node->left = curr_node;
        return;
    }

    // Save the node originally to the right of curr_node
    glthread_node_t *temp = curr_node->right;
    
    // Update the right of curr_node to point to new_node
    curr_node->right = new_node;
    
    // Update new_node's left and right pointers
    new_node->left = curr_node;
    new_node->right = temp;
    
    // Update the 'left' of the node originally to the right of curr_node
    temp->left = new_node;
}

// Public API function to add a node to the beginning of a GL thread
void glthread_add (glthread_t *lst, glthread_node_t *glnode){

    // Initialize the left and right pointers of the new node to NULL
    glnode->left = NULL;
    glnode->right = NULL;

    // If the list is empty, set the head to the new node
    if(!lst->head){
        lst->head = glnode;
        return;
    }
    
    // Save current head node
    glthread_node_t *head = lst->head;
    
    // Insert new_node before current head
    _glthread_add_next(glnode, head);
    
    // Update the head of the list to point to the new node
    lst->head = glnode;
}

// Private helper function to remove a node from a GL thread
static void _remove_glthread(glthread_node_t *glnode){

    // Case 1: Node to be removed is at the beginning
    if(!glnode->left){
        if(glnode->right){
            glnode->right->left = NULL;
            glnode->right = 0;
            return;
        }
        return;
    }
    
    // Case 2: Node to be removed is at the end
    if(!glnode->right){
        glnode->left->right = NULL;
        glnode->left = NULL;
        return;
    }

    // Case 3: Node to be removed is in the middle
    glnode->left->right = glnode->right;
    glnode->right->left = glnode->left;
    glnode->left = 0;
    glnode->right = 0;
}

// Public API function to remove a node from a GL thread
void glthread_remove(glthread_t *lst, glthread_node_t *glnode){

    glthread_node_t *head = lst->head;

    // If node to be removed is the head, update the head of the list
    if(head == glnode){
        lst->head = head->right;
    }
    
    // Use the helper function to remove the node
    _remove_glthread(glnode);
}

// Initialize a GL thread with an offset for the node
void init_glthread(glthread_t *glthread, unsigned int offset){
    
    // Initialize the head to NULL and set the offset
    glthread->head = NULL;
    glthread->offset = offset;
}
