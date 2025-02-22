# 📚 Trainee Management System 📚

## ⭐ INTRODUCTION ⭐

Welcome to the **Trainee Management System**!

This is a simple yet powerful program developed in C that allows you to manage trainees' details such as name, surname, phone number, and exam grade. The system offers a set of basic functionalities to:

- Add new trainees to the list.
- Delete trainees from the list.
- Display all trainees.
- Apply a discount (based on exam grade) to eligible trainees.

The program is based on a **stack** data structure (linked list) to store and manage the trainees' information efficiently.

## ✒️ FEATURES ✒️

### 1. Add Trainee:
- Allows you to add a new trainee to the system with the following details:
  - Name
  - Surname
  - Phone number
  - Computer exam grade

### 2. Delete Trainee:
- Deletes the top trainee from the stack and displays a confirmation message.

### 3. Show Trainees:
- Displays a list of all the current trainees in the system, showing their details (name, surname, phone number, and grade).

### 4. Apply Discount:
- Trainees with a grade of 67.5 or above are eligible for a discount.
- Displays the names of trainees who are eligible for the discount.

### 5. Exit:
- Safely exits the program and frees allocated memory.

### 6. Error Handling:
- Checks if the list is empty before performing operations like deleting a trainee or applying the discount.
- Provides user feedback on the success or failure of operations.

## 🔧 HOW TO USE 🔧

### Step-by-Step Guide:

1. **Start the Program**:  
   After running the program, you will be presented with a menu of options to choose from.

2. **Select Operation**:  
   The program supports the following operations:
   - **1**: Add trainee
   - **2**: Delete trainee
   - **3**: Show trainees
   - **4**: Apply discount
   - **5**: Exit the program

3. **Enter Trainee Details**:  
   If you select the "Add trainee" option, you will be prompted to enter:
   - Trainee's name
   - Trainee's surname
   - Trainee's phone number
   - Trainee's exam grade

4. **View All Trainees**:  
   If you choose the "Show trainees" option, a list of all the trainees will be displayed, including their details.

5. **Apply Discount**:  
   Selecting "Apply discount" will display the names of trainees who are eligible for the discount (grade ≥ 67.5).

6. **Exit the Program**:  
   To exit, select the "Exit" option, and the program will close after freeing any dynamically allocated memory.

## ⚙️ SYSTEM REQUIREMENTS ⚙️

- A **C compiler** (e.g., GCC, MinGW, or any compatible C compiler).
- Standard **C libraries** (`stdio.h`, `stdlib.h`).

### Installation Instructions:
1. Clone or download the repository to your local machine.
2. Open the terminal and navigate to the folder containing the `trainee_management.c` file.
3. Compile the program using the following command:

🛠️ CONTACT 🛠️
For further queries, suggestions, or issues, feel free to open an issue in the repository or contact me at [dogubey2112@gmail.com].

