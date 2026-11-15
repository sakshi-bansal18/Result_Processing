# Result Processing System Using Templates (C++)

A menu-driven console application that processes student results using **C++ function templates and class templates**. The same logic works for integer and floating-point scores without duplicating code

## Problem Statement
Writing separate functions and classes for each data type (int, float, double) causes duplicated, hard-to-maintain code. This project uses C++ templates to write the result-processing logic once and reuse it for multiple numeric types.

## Features
- Function template `largestOfThree<T>` finds the largest of three values (int, double, char)
- Function template `averageOfThree<T>` calculates the average
- Class template `StudentResult<T>` stores a student's name and score
- Templated input validation `readScore<T>` accepts only scores from 0 to 100
- Menu-driven interface with invalid-choice handling

## OOP Concepts Used
| Concept | Where used |
|---|---|
| Function templates | `largestOfThree`, `averageOfThree`, `readScore`, `processStudents` |
| Class template | `StudentResult<T>` |
| Generic programming | Same code works for `int`, `double` and `char` |
| Encapsulation | Private `name` and `score` with public getters and setters |
| Constructor | `StudentResult(string, T)` with default arguments |

## Tools and Requirements
- C++ (standard), compiled with g++ (any C++11 compiler works)

## Project Structure
```
.
├── result_processor.cpp
├── README.md
└── screenshots/
    ├── output1_integer_scores.png
    ├── output2_floating_point_scores.png
    └── output3_invalid_input_validation.png
```

## How to Compile and Run
```bash
g++ result_processor.cpp -o result
./result
```
On Windows, run `result.exe`.

## Sample Output
```
===== RESULT PROCESSING SYSTEM =====
1. Process integer scores
2. Process floating-point scores
3. Largest of three (int / double / char demo)
0. Exit
Choice: 1

--- Processing integer scores ---
Enter name of student 1: Aman
Enter score (0-100): 85
Enter name of student 2: Riya
Enter score (0-100): 92
Enter name of student 3: Karan
Enter score (0-100): 78

Results:
Student: Aman         | Score: 85
Student: Riya         | Score: 92
Student: Karan        | Score: 78
Highest score : 92
Average score : 85.00
```

## Screenshots
**Integer scores**

![Integer scores](screenshots/output1_integer_scores.png)

**Floating-point scores**

![Floating-point scores](screenshots/output2_floating_point_scores.png)

**Input validation**

![Input validation](screenshots/output3_invalid_input_validation.png)

## Test Cases
| # | Input | Expected output |
|---|---|---|
| 1 | int: 85, 92, 78 | Highest 92, Average 85.00 |
| 2 | double: 72.5, 68.25, 90.75 | Highest 90.75, Average 77.17 |
| 3 | all equal: 50, 50, 50 | Highest 50, Average 50.00 |
| 4 | boundary: 0, 100, 50 | Highest 100, Average 50.00 |
| 5 | invalid: "abc", 150 | Error message and re-prompt |

## Limitations
- Records are not saved to a file.
- Only three students are processed per run.

## Future Scope
- Save and load records using file handling
- Support any number of students using `vector<StudentResult<T>>`
- Add grade calculation and sorting of results

## Mapped SDG
- **SDG 4:** Quality Education
- **SDG 9:** Industry, Innovation and Infrastructure
