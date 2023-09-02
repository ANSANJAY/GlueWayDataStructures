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
