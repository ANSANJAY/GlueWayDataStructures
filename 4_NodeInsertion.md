# Interview Revision Notes on GL Threads and Session Management 📚🔗

## Introduction 👋
In this segment, we discuss how to manage sessions in GL threads, specifically how to insert objects into a GL thread linked list. The example continues with the `Employee` structure.

---

## The Role of the GL Thread Node in Structures 🧩
### What is a GL Thread Node? 🤔
It serves as a "glue" that allows an object to stick itself or insert itself into a GL thread linked list.

#### Example 🌟
Our `Employee` structure has a member called `GLThreadNode`. This node acts as the "glue" allowing an `Employee` object to insert itself into a GL thread.

### Developer Insight 🕵️
By declaring a `GLThreadNode` as a member of the `Employee` structure, the developer indicates that objects of this type will be added to a GL thread.

---

## How to Insert Objects into a GL Thread? 🛠
### Object Arrangement 🎯
Assume we have a GL thread consisting of three `Employee` objects (Object 1, Object 2, Object 3). Each object uses its last member, `GLThreadNode`, to attach itself to the thread.

### Pointers and Offsets 📍
- Given a pointer to `GLThreadNode`, subtract the offset of `GLThreadNode` to obtain the starting address of the `Employee` object.
- Once you have the starting address, you can access all the fields of the `Employee` object.

### Writing a Program to Insert Objects 📝
We will write an API called `GLThread_Insert` which allows us to insert an object into a GL thread.

#### API Signature 🖋
```c
void GLThread_Insert(GLThread_List* list, GLThreadNode* node);
```
- `list`: Pointer to the GL thread list.
- `node`: Pointer to the GL thread node.

#### API Implementation 💡
The implementation of this function is relatively simple and straightforward, allowing a new `GLThreadNode` to be added to an existing GL thread.

---

## Summary 📋
1. `GLThreadNode` serves as "glue" for objects to be inserted into GL threads.
2. Having a `GLThreadNode` as a member in a structure indicates the object will be part of a GL thread.
3. To insert objects into a GL thread, we can write an API, and the method involves pointer arithmetic based on offsets.

---

## Key Takeaways 🗝
- Understanding the role of `GLThreadNode` in structures is essential for session management in GL threads.
- Pointers and offsets are crucial in navigating and manipulating data in structures and GL threads.

---

Happy Interview Prepping! 🌟🚀
