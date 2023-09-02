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
