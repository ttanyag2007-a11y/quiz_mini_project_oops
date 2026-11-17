# C++ Console Quiz Application (OOP Mini Project)

An interactive console-based multiple-choice quiz application developed in **C++** implementing key **Object-Oriented Programming (OOP)** concepts.

## 📌 Project Overview
This project is an educational quiz system designed to test knowledge of Object-Oriented Programming in C++. It features a dynamic question management system, real-time score calculation, robust input validation with exception handling, and persistent score logging to an external file.

---

## 🚀 Features
- **Multiple-Choice Questions (MCQs)**: Interactive questions covering fundamental OOP principles.
- **Instant Feedback**: Provides immediate validation and reveals the correct answer upon incorrect attempts.
- **Score & Percentage Calculation**: Displays final score and formatted percentage at the end of the quiz.
- **File Persistence (`scores.txt`)**: Automatically records the user's name, final score, and percentage into a text file for future reference.
- **Robust Exception Handling**: Validates user inputs and handles exceptions gracefully (preventing crashes on non-numeric or out-of-range input).

---

## 🛠️ OOP Concepts Implemented
1. **Classes and Objects**:
   - `Question`: Represents an individual MCQ with its question text, four options, and the correct option index.
   - `Quiz`: Manages the collection of questions, tracks the score, controls the quiz flow, and handles file logging.
2. **Encapsulation**:
   - Data members (such as question details, correct answers, and score) are kept `private`.
   - Access and modifications are restricted to `public` member functions (e.g., `checkAnswer()`, `updateScore()`).
3. **Data Abstraction**:
   - Internal quiz logic and scoring mechanisms are hidden behind clean interfaces like `start()`, `showResult()`, and `saveResult()`.
4. **Standard Template Library (STL)**:
   - Utilizes `std::vector` to dynamically store and manage the list of `Question` objects.
5. **File Handling**:
   - Uses `std::ofstream` in append mode (`ios::app`) to persistently save quiz results in `scores.txt`.
6. **Exception Handling**:
   - Implements `try-catch` blocks with `std::runtime_error` to catch and manage invalid input errors (e.g., invalid data types, numbers outside the 1–4 range) without crashing the program.

---

## 💻 How to Compile and Run

### Prerequisites
- A C++ compiler supporting C++11 or higher (e.g., `g++`, `clang++`, or MinGW).

### Compilation
Open your terminal/command prompt in the project directory and run:

```bash
g++ -o quiz quiz.cpp
```

### Execution

**Windows:**
```cmd
quiz.exe
```

**Linux / macOS:**
```bash
./quiz
```

---

## 📝 Sample Output

```text
===== C++ QUIZ =====
Enter your name: Tanya
Hello Tanya! There are 8 questions. Type the option number as your answer.

Q1. Which keyword is used to define a class in C++?
   1) object
   2) class
   3) define
   4) new
Enter your choice (1-4): 2
Correct!

...

===== RESULT =====
Score      : 8/8
Percentage : 100.0%
Result saved in scores.txt
```

---

## 📁 Project Structure
```text
quiz_mini_project_oops/
│
├── quiz.cpp         # Main C++ source code containing Question & Quiz classes
├── README.md        # Project documentation
├── .gitignore       # Git ignore file for binaries and output logs
└── scores.txt       # Generated file containing user scores (created at runtime)
```

---

## 👤 Author
- **Tanya** ([@ttanyag2007-a11y](https://github.com/ttanyag2007-a11y))
