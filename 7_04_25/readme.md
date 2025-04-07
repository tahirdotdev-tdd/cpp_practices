# 🚗 Composition and Aggregation in C++

This is a simple C++ program that demonstrates the concepts of **composition** and **aggregation** using the `Engine`, `Passenger`, and `Car` classes.

---

## 🧠 Concepts Covered

### ✅ Composition
- The `Car` class **contains** an `Engine` object directly.
- The `Engine` is created and destroyed along with the `Car`, meaning it doesn't exist outside of it.
- This demonstrates **composition** — a "has-a" relationship with ownership.

### ✅ Aggregation
- The `Car` class has a **pointer** to a `Passenger` object.
- The `Passenger` is created outside the `Car` and passed in.
- This demonstrates **aggregation** — a "has-a" relationship without ownership.

---

## 📦 Classes Overview

### `Engine`
- Represents the engine of a car.
- Contains an integer `eng_num` to store the engine number.
- Provides a method to display the engine number.

### `Passenger`
- Represents a person riding in the car.
- Contains a string `pass_name`.
- Provides methods to set and display the passenger's name.

### `Car`
- Has an `Engine` object (composition).
- Holds a pointer to a `Passenger` object (aggregation).
- Initializes the engine and interacts with the passenger object.

---

## 🧪 Program Behavior

```cpp
int main()
{
    Passenger p2;    // Create a Passenger object
    Car c1(p2);      // Create a Car object, passing in the Passenger
    return 0;
}
