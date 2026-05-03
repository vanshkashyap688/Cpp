# Employee Management System

## Project Overview

The **Employee Management System** is a simple C++ console-based application developed using **Object-Oriented Programming (OOP)** and **File Handling** concepts.

This project helps manage employee records by allowing the user to:

* Add new employee records
* Display all employee records
* Search employee by ID
* Update employee details
* Delete employee records

Employee data is stored permanently in a text file named **employees.txt**.

---

## Features

### 1. Add Employee

Allows the user to enter:

* Employee ID
* Employee Name
* Employee Salary

The entered details are saved to the file.

---

### 2. Display All Employees

Displays all employee records stored in the file.

---

### 3. Search Employee

Searches for an employee using Employee ID.

---

### 4. Update Employee

Updates employee details by searching through Employee ID.

---

### 5. Delete Employee

Deletes a specific employee record.

---

### 6. Exit

Closes the program.

---

## Technologies Used

* **Programming Language:** C++
* **Concepts Used:**

  * Classes and Objects
  * Encapsulation
  * File Handling
  * Functions
  * Menu-driven Programming

---

## File Used

### employees.txt

Stores employee records permanently.

Example:

```txt
101 Vansh 50000
102 Rahul 45000
103 Aman 60000
```

---

## Class Used

### Employee Class

#### Data Members

* `id`
* `name`
* `salary`

#### Member Functions

* `getData()`
* `showData()`
* `getID()`
* `writeToFile()`
* `readFromFile()`

---

## Functions Used

### addEmployee()

Adds employee data to file.

### displayAll()

Displays all employee records.

### searchEmployee()

Searches employee by ID.

### updateEmployee()

Updates employee details.

### deleteEmployee()

Deletes employee record.

---

## How to Run

### Step 1

Save the code as:
`employee.cpp`

### Step 2

Compile:

```bash
g++ employee.cpp -o employee
```

### Step 3

Run:

```bash
./employee
```

(For Windows)

```bash
employee.exe
```

---

## Sample Output

```txt
===== Employee Management System =====
1. Add Employee
2. Display All Employees
3. Search Employee
4. Delete Employee
5. Update Employee
6. Exit
Enter your choice:
```

---

## Advantages

* Easy to use
* Stores data permanently
* Simple menu-driven interface
* Demonstrates file handling

---

## Limitations

* Uses text file storage
* No password protection
* No graphical user interface

---

## Future Improvements

* Add login system
* Use binary files
* Add employee department details
* Develop graphical interface

---

## Conclusion

This project demonstrates the practical implementation of **C++ OOP and File Handling** for managing employee records efficiently.

It is useful for understanding real-world applications of file-based data management systems.
