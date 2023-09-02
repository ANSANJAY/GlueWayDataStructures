# Interview Revision Notes on Iterating Over GL Threads and Data Object Management 🔄📚

## Introduction 🎉
This segment discusses iterating over a GL thread to print all the data objects it holds. We continue with our example using the `Employee` structure and explore how GL threads differ from traditional doubly linked lists.

---

## Objective 🎯
- To write a function `print_employee_database` that takes a pointer to the first node of a GL thread as its argument.
- This function will iterate over the GL thread and print each of the `Employee` objects.

---

## Implementation 🛠

### Steps 👣
1. The function argument is a pointer to the first node in the GL thread.
2. You use a loop to iterate through the thread, much like you would with a traditional doubly linked list.

### Key Differentiator 🤔
- **Pointer Arithmetic and Offsets**: In GL threads, you get a pointer to the object by subtracting the offset of the node from the node's address.
  ```c
  Employee *employee = (Employee *)((char *)(node) - OFFSET);
  ```
  Where `OFFSET` is the offset of the node field within the `Employee` structure.

---

## Comparison with Traditional Doubly Linked Lists 🔍

### In Doubly Linked Lists 👇
- The `node->data` provides a pointer to the data object.
  
### In GL Threads 👇
- Pointer arithmetic is needed to obtain the starting address of the object. This is done by subtracting the offset of the node in the structure.
  
### Why GL Threads? 🌟
- GL Threads offer benefits that traditional libraries don't, mainly in flexibility and adaptability.

---

## Summary 🌟
1. To iterate through GL threads, use the function `print_employee_database` with a similar loop structure to that of a doubly linked list.
2. The key differentiator is in how you get the pointer to the data object: by subtracting the offset.
3. GL threads offer benefits in flexibility and problem-solving that traditional doubly linked lists cannot.

---

## Key Takeaways 🔑
- Understanding the role of offsets and pointer arithmetic is crucial in GL Threads.
- GL Threads offer a more flexible way to manage linked data structures, solving issues that traditional doubly linked lists cannot.
  
---

Happy Interview Prepping! 📈👍
