Smart Hospital Management System

The Smart Hospital Management System is a menu-driven application developed in C, designed to streamline hospital operations such as managing patient records, assigning doctors, and tracking admission and quarantine statuses. It offers a modernized approach to hospital record management with persistent file-based storage and an intuitive interface.
Features

    Patient Management:
        Add new patients with details such as age, weight, height, and symptoms.
        Automatically generate a unique patient ID.
        Calculate and display the Body Mass Index (BMI) for each patient.
        Search by Patient ID: Quickly locate a patient's record using their unique ID.

    Doctor Management:
        Maintain a static database of 30 physicians with unique IDs, qualifications, and specializations.
        Assign doctors to patients based on their medical needs.

    Admission and Quarantine:
        Randomly assign hospital beds to admitted patients.
        Support for a 14-day quarantine tracking system.
        Discharge management for both hospital and quarantine scenarios.

    File Persistence:
        Save patient data to a file (patients.txt) to ensure records are retained across sessions.
        Automatically load patient data on program startup.

    User-Friendly Menu:
        Provides options to add patients, assign doctors, update patient statuses, and display records through a clear menu interface.

How It Works
Initialization

    On startup, the system initializes patient data from patients.txt if available. Otherwise, it starts with an empty dataset.

Menu Options

    Add New Patient: Input patient details, including their name, age, weight, height, and symptoms.
    Assign Doctor: Match patients with appropriate doctors based on their unique IDs.
    Update Status: Modify admission, quarantine, or discharge details.
    View Records: Access detailed patient and doctor records.

File Operations

    Patient data is saved in patients.txt upon updates or exiting the program, ensuring data persistence.

Follow the menu-driven interface to interact with the system.
File Structure

    patients.txt: Stores patient details for persistent record-keeping.
    (Optional) Additional files for future extensions.

Sample Interaction

Welcome to the Smart Hospital Management System
Please choose an option:
1. Add New Patient
2. Assign Doctor
3. Update Status
4. Display Patient Details
5. Exit

Requirements

    A C compiler (e.g., GCC).
    Basic knowledge of terminal/command-line usage.

Limitations

    Static database of doctors and patient capacity (100 patients, 30 doctors).
    Basic input validation (e.g., no checks for invalid age/weight).
    No search functionality for specific doctors.
    Relies on a single text file for data storage.

Future Enhancements

    Implement dynamic memory allocation using linked lists for scalability.
    Add search functionality for patients and doctors.
    Improve data validation for robust error handling.
    Encrypt sensitive patient data for enhanced security.
    Extend functionality for dynamic doctor management.

Contributions

Feel free to contribute to this project by submitting issues or pull requests. Suggestions for enhancements or optimizations are welcome!
