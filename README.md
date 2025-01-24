# Simple Hospital Patient Management System

## Overview
This project is a simple patient management system designed for a hospital with 20 different medical specializations. The system allows for adding patients to waiting lists, displaying patients in queues, and managing patient admissions to doctors.

## Features
- **Add a New Patient**: Add patients to a specific specialization with their name and status (regular or urgent).
- **Display All Patients**: View all patients in the waiting lists for each specialization.
- **Call the Next Patient**: Call the next patient from a specific specialization's waiting list and remove them from the queue.

## Requirements
- C++ compiler (e.g., g++)

## How to Use
1. **Add a New Patient**:
   - Choose option 1 from the menu.
   - Enter the specialization (1-20), patient's name, and status (0 for regular, 1 for urgent).
   - The patient will be added to the queue based on their status.

2. **Display All Patients**:
   - Choose option 2 from the menu.
   - The system will display all patients in the waiting lists for each specialization.

3. **Call the Next Patient**:
   - Choose option 3 from the menu.
   - Enter the specialization.
   - The next patient in the queue will be called and removed from the list.

4. **Exit**:
   - Choose option 4 to exit the system.

## Code Structure
- **Main Variables**:
  - `names[Specialization+1][Max_queue]`: Stores patient names for each specialization.
  - `status[Specialization+1][Max_queue]`: Stores patient statuses (regular or urgent).
  - `Len_queue[Specialization+1]`: Stores the length of the waiting queue for each specialization.

- **Main Functions**:
  - `menu()`: Displays the menu and reads the user's choice.
  - `shift_left()` and `shift_right()`: Manage shifting patients in the queues.
  - `Add_Patient()`: Adds a new patient to the queue.
  - `Print_Patient()` and `Print_All_Patients()`: Print the patients in the waiting queues.
  - `Get_Next_Patient()`: Calls the next patient and removes them from the queue.
  - `Hospital_system()`: Manages the system's operation.
