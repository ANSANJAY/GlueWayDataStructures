
# 📚 GL Threads vs Traditional Doubly Linked Lists - The Detailed Guide


### 🖼 Traditional Doubly Linked Lists in Memory
- Each node has `left`, `right`, and `data` members.
- The `data` member holds the address of the application data.
  
### 🖼 GL Threads in Memory
- Each GL Node (a node in GL Threads) only contains `left` and `right` pointers.
- There is no separate `data` member pointing to the application data.

---

## 🎭 Terminology Clarification

- **Thread**: Refers to glue-based doubly linked lists.
- **GL Node**: Refers to a node in a thread.
  
---

## 🎈 The "Glue" Concept

### 🤝 Application Data in GL Threads
- In GL Threads, the application data is "glued" directly to the GL Node.
  
### 🍬 The Sticky Gum Analogy
- Think of the application data as having "sticky gum" that allows it to stick itself to GL Nodes.
  
### 📎 The Glue Member
- The application data contains a member which is a GL Node.
- This member, often termed as "glue," allows the application data to adhere itself to a thread.

## 🤓 High-Level Significance of "Glue"

- The term "glue" signifies a mechanism that allows an object (here, application data) to stick to another object (here, GL Nodes in a thread).

