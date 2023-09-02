# Interview Revision Notes on C Structures and Offset 📚🛠

## Introduction 👋
Before diving into the design and implementation of GL threads, it's crucial to understand the concept of offset in C structures. If you are familiar with this, feel free to skim through. Otherwise, this material is going to be beneficial.

---

## Offset in C Structures 📐
### What is Offset? 🤔
The offset of a field in a C structure is the number of bytes that field is away from the start of the structure.

#### Example 🌟
Let's assume we have a C structure with four fields:

- `name` (30 bytes)
- `salary` (4 bytes)
- `designation` (30 bytes)
- `employee_ID` (4 bytes)

If the starting address of this object is `1000`, then:
- Offset of `salary`: 30 bytes (Starts at 1,030)
- Offset of `designation`: 34 bytes
- Offset of `employee_ID`: 64 bytes

Note that the offset of the first field is always zero.

---

## Writing a C Macro to Compute Offset 📝
One can write a generic C macro to compute the offset of a given field in a given structure.

### Syntax 📚
```c
#define offsetof(structure, field) /* your code here */
```
- `structure`: Name of the structure.
- `field`: Name of the field whose offset is to be calculated.

### Usage 🛠
```c
offsetof(Employee_T, employee_ID);
```

This would return `64` if `employee_ID` starts 64 bytes from the start of `Employee_T`.

> ❗ **Note**: This is often a popular interview question.

---

## Practical Exercise: Printing Employee Details 💻

### The Problem 🤔
- You're given a structure called `Employee_T` with fields: `name`, `salary`, `designation`, `employee_ID`, and `GLNode` (of type `gl_thread_node`).
- You have a function to print employee details.
- The function takes the address of the last field (`GLNode`) as an argument.
  
### The Task ✅
- Your task is to implement this function so that it prints the rest of the fields (`name`, `salary`, `designation`, `employee_ID`).

### The Hint 💡
- The address passed to the function is the address of `GLNode`.
- To find the start address of the `Employee_T` object, subtract the offset of `GLNode`.


Happy Learning! 🌟🚀

# Interview Questions on C Structure Offsets and GL Threads 📘

## Introduction 🌟

Hey folks! Before we jump into designing and implementing GL Threads, understanding the concept of `offset` in C structures is key. Today we're going to dive into some interview questions that will help you nail down this crucial concept.

---

## Core Concepts 🎯

### Offset in C Structures 📐

- **Offset**: It is the distance (in bytes) a particular field is from the start of the structure. 
- **C Macro for Offset**: A C macro can be written to compute the offset of a field in a C structure.

### GL Threads and Offset 🛠️

- **GL Node**: It's one of the members in the `employee` structure in the exercise example.
- **Offset Usage**: Knowing the offset of `GL Node` helps in fetching the starting address of `employee` structure to print all its details.

---

## Interview Questions and Answers 🎤💡

### Q1: Can you explain the concept of 'offset' in C structures? 🤔

**Answer**:  
The offset of a field in a C structure is the number of bytes that field is away from the start of the structure. For example, if a structure starts at address 1000 and a field starts at address 1030, the offset of that field is 30 bytes. The first field always has an offset of 0. 📏

---

### Q2: How would you write a generic C macro to calculate the offset of a field within a structure? 🛠️

**Answer**:  
A common way to write such a macro is using the `offsetof` macro. It generally takes the structure name and the field name as arguments. The macro uses pointer arithmetic to compute the offset of the given field. The code snippet would look something like this in C:

```c
#define offsetof(st, m) ((size_t)&(((st *)0)->m))
```
This macro would return the offset when used like `offsetof(employee_t, employeeID)`. 🖥️

---

### Q3: How does understanding 'offset' become crucial when working with GL threads? 🤷‍♀️

**Answer**:  
In GL Threads, we may have a pointer pointing to one of the fields of the structure (like `GL Node` in `employee_t`). Knowing the offset allows us to calculate the starting address of the entire structure (`employee_t` in this case), so we can access and manipulate all its fields. 🎯

---

### Q4: In the given exercise, how do you obtain the starting address of the `employee_t` object, given the address of its `GL Node` field? 🎯

**Answer**:  
We can subtract the offset of the `GL Node` field from its given address to obtain the starting address of the `employee_t` object. In code, it might look like:

```c
employee_t *emp = (employee_t *)((char *)given_GLNode_address - offsetof(employee_t, GLNode));
```

After obtaining the starting address of the `employee_t` object, we can print all its details as usual. 🖨️

----

Hopefully, these questions helped you prepare for your interviews. Knowing how to manipulate offsets will not only help in interviews but will also be useful in real-world coding. Good luck! 🍀✨
