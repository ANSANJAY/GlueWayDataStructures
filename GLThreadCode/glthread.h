// Define the header guards to prevent double inclusion
#ifndef __GLTHREADS__
#define __GLTHREADS__

// Define the glthread_node_ structure to be used as a node in the glthread list
typedef struct glthread_node_ {
    struct glthread_node_ *left;  // Pointer to the previous node in the list
    struct glthread_node_ *right; // Pointer to the next node in the list
} glthread_node_t;

// Define the glthread_ structure to represent the glthread list
typedef struct glthread_ {
    glthread_node_t *head;  // Pointer to the head node of the list
    unsigned int offset;    // Offset of the glthread node in the application-defined data structure
} glthread_t;

// Function to add a new node to the glthread list
// lst: The glthread list to which the node will be added
// glnode: The node to be added to the glthread list
void
glthread_add (glthread_t *lst, glthread_node_t *glnode);

// Function to remove a node from the glthread list
// lst: The glthread list from which the node will be removed
// glnode: The node to be removed from the glthread list
void
glthread_remove(glthread_t *lst, glthread_node_t *glnode);

// Macro to iterate over all nodes in a glthread list
// lstptr: Pointer to the glthread list to be iterated over
// struct_type: Type of the application-defined data structure
// ptr: Pointer to hold each data structure during iteration
#define ITERATE_GL_THREADS_BEGIN(lstptr, struct_type, ptr)      \
{                                                               \
    glthread_node_t *_glnode = NULL, *_next = NULL;             \
    for(_glnode = lstptr->head; _glnode; _glnode = _next){      \
        _next = _glnode->right;                                 \
        ptr = (struct_type *)((char *)_glnode - lstptr->offset);

#define ITERATE_GL_THREADS_ENDS }}

// Macro to initialize a glthread node
#define glthread_node_init(glnode)  \
    glnode->left = NULL;            \
    glnode->right = NULL;

// Function to initialize a glthread list
// glthread: The glthread list to be initialized
// offset: Offset of the glthread node in the application-defined data structure
void
init_glthread(glthread_t *glthread, unsigned int offset);

// Macro to calculate the offset of a field within a structure
#define offsetof(struct_name, field_name)   \
    ((unsigned int)&((struct_name *)0)->field_name)

#endif /* __GLTHREADS__ */
