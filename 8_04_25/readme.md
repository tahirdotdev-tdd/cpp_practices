# 💻 Computer Configuration Simulation – C++

This is a simple C++ program that simulates a computer setup by combining a **Processor** and a **User** using Object-Oriented Programming concepts like **classes**, **objects**, **constructors**, and **encapsulation**.

---

## 📂 Overview

The program consists of three main classes:

- **Processor** – Represents a CPU with a model name.
- **User** – Represents a person using the computer.
- **Computer** – Combines both a Processor and a User to simulate a personalized computer system.

---

## 🧠 Key Concepts Used

- Classes and Objects  
- Constructors (Default and Parameterized)  
- Encapsulation  
- Object Composition  
- Function Calling between Classes  

---

## 🔧 How It Works

1. A `Processor` object is created with a custom model: `"AMD Ryzen 7"`.
2. A `User` object is created and the name `"Tahir Hassan"` is set.
3. A `Computer` object is initialized using the above Processor and User.
4. The `showDetails()` method is called to display the full computer configuration.

---

## 🧾 Output

```
Processor model is: AMD Ryzen 7  
User name is: Tahir Hassan
```

---

## 🗂 Code Structure

```cpp
class Processor {
    string processor_model;
    // Handles CPU model data
};

class User {
    string user_name;
    // Stores the user's name
};

class Computer {
    Processor processor;
    User user;
    // Combines Processor and User
};
```

---

## 🚀 How to Run

1. Copy the code into a file named `main.cpp`.
2. Compile the code:

```bash
g++ main.cpp -o computer_app
```

3. Run the executable:

```bash
./computer_app
```

---

## 🙌 Author

**Tahir Hassan**  
_This program is part of my OOP practice journey._
