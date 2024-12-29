Smart Hospital Management System

Description:
The Smart Hospital Management System is a lightweight yet efficient C-based application designed to modernize hospital operations. It enables effective patient record management, doctor assignment, and admission tracking through a clear and intuitive menu-driven interface. This system offers a digital solution to simplify and automate traditional manual processes.
Features
Patient Management

    Add new patients with details such as age, weight, height, and symptoms.
    Automatically generate a unique Patient ID.
    Display comprehensive information, including calculated BMI.

Doctor Management

    Manage a fixed database of 30 doctors with unique IDs and specializations.
    Assign doctors to patients based on their medical needs.

Admission & Quarantine

    Process hospital admissions with random bed assignments.
    Manage quarantine statuses with a 14-day home isolation period.
    Update patient discharge status efficiently.

File Persistence

    Data is saved to patients.txt and reloaded upon startup for continuity.

Interactive Menu Interface

    Easy-to-navigate options for adding patients, assigning doctors, updating statuses, and viewing data.

Usage Requirements

This program requires the following files to work properly:

    save File: Used to store ongoing game progress.
    reset File: Used to reset and initialize the system.
    Ensure these files are present in the program's directory.

Advantages

    Automation: Reduces manual errors and enhances workflow efficiency.
    User-Friendly: Simple, menu-driven interface for ease of use.
    Data Integrity: Persistent storage using file operations.
    Scalability: Designed to support future enhancements like search capabilities or reporting.

Limitations

    Fixed doctor data and a maximum patient count of 100.
    Limited input validation for data like age or weight.
    No search functionality for specific records.
    Relies on a single text file for data storage.

Future Enhancements

    Dynamic Memory Allocation: Use linked lists for flexible data management.
    Enhanced Validation: Stricter checks for user input.
    Search & Reporting: Add search functionality and reporting features.
    Doctor Management: Enable dynamic addition, removal, and editing of doctor records.
    Data Security: Implement encryption for sensitive patient information.

Technical Highlights

    C Programming: Leveraging structures, arrays, and file I/O for robust data handling.
    Random Number Generation: Assigning random bed numbers.
    Mathematical Calculations: Computing BMI.
    Menu-Driven Design: Employing switch-case and conditional statements for smooth navigation.

Contributions and suggestions are welcome to help improve this system further. Feel free to fork and extend its functionality!
