# Interview Revision Notes on Advantages of GL Threads Over Traditional Doubly Linked Lists 🌟🔗

## Introduction 📢
Why consider GL Threads when traditional doubly-linked lists can accomplish the same goals? This is the million-dollar question. This discussion aims to elaborate on why GL Threads (GL stands for Glue-Based) offer certain benefits over traditional doubly-linked lists.

---

## Problem Statement 🤔
Let's consider an application that maintains **three different linked lists** for the following:
1. **List 1**: All employees in an organization 🏢
2. **List 2**: Employees above manager level 👨‍💼
3. **List 3**: Employees whose promotions are due 📈

What happens when an employee object (let's call him Arun) qualifies for all three lists?

---

## Scenario 1: Using Traditional Doubly Linked Lists 😵
### Insertion 📥
- Each list would have a node pointing to the same employee object, Arun.
- Three separate `mallocs` would be required—one for each list's node.

### Deletion 🗑️
- Suppose Arun leaves the company.
- Each of the three lists must be iterated to find the node pointing to Arun and then delete it.
  
### Time Complexity ⏳
- Deletion would be \(O(3N)\), which is quite expensive.

---

## Scenario 2: Using GL Threads 🤩
### Insertion 📥
- Arun's employee object has built-in GL nodes (`N1, N2, N3`), which are part of the object itself.
- Zero `mallocs` required. 😲

### Deletion 🗑️
- Only need to iterate through one of the lists to find Arun.
- Use the `GL thread_remove API` to remove nodes `N2` and `N3` from lists `L2` and `L3`.

### Time Complexity ⏳
- Deletion would be \(O(N) + O(N) + O(1)\), which is much more efficient.

---

## Key Advantages of Using GL Threads 🌈
1. **Zero Additional Memory Allocation**: The GL nodes are part of the object itself.
2. **Efficient Deletions**: Deletion time complexity is significantly reduced.
  
---

## When to Use What? 🤷‍♂️
- Use **traditional doubly linked lists** when an object does not need to be part of multiple data structures.
- Use **GL threads** when an object needs to be referenced by multiple data structures (linked lists, trees, queues, etc.)

---

## Summary 🎁
- GL Threads significantly outperform traditional doubly linked lists when an object must be part of multiple data structures.
- They require no extra memory allocation for nodes and offer a more efficient deletion process.

---

## Key Takeaways 🎓
- If your application involves objects that need to be part of multiple data structures, consider using GL Threads.

---

Good luck with your interviews! 🍀👨‍💻

# Technical Interview Questions on Generalized Linked List (GLThread) vs Traditional Doubly Linked List (DLL) 🤓

Welcome back, everyone! Today, we'll be talking about the advantages of using a Generalized Linked List (GLThread) over a traditional Doubly Linked List (DLL). We'll go over some technical interview questions on this topic. Let's get started!

## Context 

In a hypothetical scenario, your application is maintaining three different doubly linked lists:

1. A list of all employees in an organization.
2. A list of employees who are above the manager level.
3. A list of employees whose promotions are due.

The challenge here is inserting and deleting the same object (`emp_t`, an employee object) into these multiple lists efficiently.

### Questions

1. **Question**: What are the drawbacks of using traditional doubly linked lists for maintaining multiple related lists like the three lists in our example?
    **Answer**: When using traditional doubly linked lists, you have to allocate a separate node for each list to reference the same object. This implies three separate `malloc` calls if the object needs to be in three lists. Also, deleting an object requires searching each list and removing the node, resulting in a time complexity of \(O(n \times 3)\) in our example.

2. **Question**: How does using GLThread address the problem of inserting the same object into multiple lists?
    **Answer**: In the case of GLThread, the object itself contains the linked list node information (`glthread_node_t`). Hence, you don't need to allocate separate nodes. The same object can be part of multiple lists without extra allocations, making the insertion process more memory-efficient.

3. **Question**: What is the time complexity for deleting an object from all lists when using traditional doubly linked lists? How does it compare with using GLThreads?
    **Answer**: For traditional doubly linked lists, the time complexity for deleting an object from all the lists is \(O(n \times 3)\) in our example. With GLThreads, the time complexity would still depend on the size of the lists, but you only have to deallocate the object once, making it generally more time-efficient.

4. **Question**: Describe a real-world scenario where GLThreads would be more beneficial compared to traditional doubly linked lists.
    **Answer**: GLThreads would be particularly useful in database systems where an object needs to be part of multiple indexing lists, or in a resource-constrained embedded system where memory efficiency is crucial.

5. **Question**: Are there any specific disadvantages to using GLThreads over traditional doubly linked lists?
    **Answer**: One potential downside of using GLThreads is that the objects themselves have to be aware of their list membership, which might couple data structures that are otherwise unrelated. This could be a violation of the separation of concerns principle in software design.

6. **Question**: How does using GLThreads affect memory allocation in contrast to traditional doubly linked lists?
    **Answer**: With GLThreads, the object itself includes the node information, eliminating the need for additional memory allocations to insert the object into multiple lists. This results in better memory efficiency compared to traditional doubly linked lists, where separate nodes must be allocated for each list.

# Technical Interview Questions on Generalized Linked List (GLThread) in Application Scenarios 🧠🛠

Welcome back to this technical deep-dive! Today we are discussing the advantages of using Generalized Linked List (GLThread) as compared to traditional Doubly Linked List (DLL) in specific application scenarios. Let's get into some technical interview questions about this intriguing topic!

## Context 

You're working on an application where an employee object needs to be inserted into three different lists:

1. A list (`L1`) maintaining records of all employees.
2. A list (`L2`) maintaining records of all managers and above.
3. A list (`L3`) maintaining records of employees due for promotions.

You choose to implement this using GLThreads, where the GLThread nodes (`N1`, `N2`, `N3`) are part of the employee object's structure. 

### Questions

1. **Question**: How many `mallocs` are required to insert an employee object into all three lists (`L1`, `L2`, `L3`) when using GLThreads?
    **Answer**: Zero `mallocs` are needed because the GLThread nodes (`N1`, `N2`, `N3`) are part of the employee object's structure. Allocating memory for the employee object itself takes care of the nodes as well, removing the need for separate `mallocs`.

2. **Question**: What is the time complexity for deleting an employee object from all three lists (`L1`, `L2`, `L3`) when using GLThreads?
    **Answer**: The time complexity for deleting an employee object from all lists is \(O(n) + O(n) + O(1)\), which is much more efficient compared to the \(O(3n)\) in the case of traditional DLLs. 

3. **Question**: How does using GLThreads improve efficiency in deletion operations compared to traditional DLLs?
    **Answer**: With GLThreads, you only need to locate the employee object in one list (say `L1`). Since you have pointers to the GLThread nodes (`N1`, `N2`, `N3`) that are part of the object's structure, you can remove the object from the other lists (`L2`, `L3`) with \(O(1)\) complexity for each. This improves the overall efficiency of the deletion operation.

4. **Question**: When should you choose GLThreads over traditional DLLs?
    **Answer**: If your application involves objects that need to be part of multiple data structures (linked lists, queues, trees, etc.), GLThreads are preferable. They offer better memory and time efficiency for such multi-list scenarios.

5. **Question**: What are the API calls needed to remove an employee object from all lists (`L1`, `L2`, `L3`)?
    **Answer**: First, you'd iterate over one list (like `L1`) to locate the node that points to the employee object. Once you find it, you can invoke `GLThread_Remove` API to remove `N1` from `L1`, `N2` from `L2`, and `N3` from `L3`. These operations are \(O(1)\) complexity.

6. **Question**: Are there any downsides to using GLThreads over traditional DLLs?
    **Answer**: One downside is that the objects themselves must contain the GLThread nodes, potentially mixing concerns of list membership with the object's inherent properties. This could complicate the object's design or lead to tightly-coupled code.

Tackle these questions to reinforce your understanding of why and when to use GLThreads over traditional Doubly Linked Lists. Good luck! 🍀

