#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_BED_NUMBER_LENGTH 10
#define ADMIN_PASSWORD "admin123" 
int login() {
    char password[50];

    printf("Enter admin password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; 

    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        return 1; 
    } else {
        printf("Incorrect password. Access denied.\n");
        return 0; 
    }
}


typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
    float weight;
    char symptoms[100];
    int isAdmitted;
    int isQuarantined;
    int quarantineDays;
    char bedNumber[MAX_BED_NUMBER_LENGTH];
    int assignedDoctor1;
    int assignedDoctor2;
    int assignedDoctor3;
    int assignedMedicines[3];
} Patient;


Patient patients[MAX_PATIENTS];
int patientCount = 0;
int nextPatientID = 1; 

 
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char degree[10];
    char specialization[MAX_NAME_LENGTH];
} Doctor;

Doctor doctors[] = {
{100001, "Dr. Alice Johnson", "MD", "Cardiology"},
{100002, "Dr. Brian Smith", "MBBS", "Neurology"},
{100003, "Dr. Catherine Lee", "MD", "Pediatrics"},
{100004, "Dr. Daniel Martinez", "MD", "Orthopedics"},
{100005, "Dr. Emily Davis", "MBBS", "Gastroenterology"},
{100006, "Dr. Frank Wilson", "MD", "Oncology"},
{100007, "Dr. Grace Clark", "MBBS", "Dermatology"},
{100008, "Dr. Henry Lopez", "MD", "Anesthesiology"},
{100009, "Dr. Irene Perez", "MBBS", "Endocrinology"},
{100010, "Dr. Jack Taylor", "MD", "Rheumatology"},
{100011, "Dr. Kevin Brown", "MBBS", "Cardiothoracic Surgery"},
{100012, "Dr. Laura Evans", "MD", "Pulmonology"},
{100013, "Dr. Michael White", "MBBS", "Nephrology"},
{100014, "Dr. Nancy Harris", "MD", "Obstetrics and Gynecology"},
{100015, "Dr. Oscar Moore", "MBBS", "Hematology"},
{100016, "Dr. Patricia Thomas", "MD", "Infectious Diseases"},
{100017, "Dr. Quentin Wright", "MBBS", "Pathology"},
{100018, "Dr. Rachel Hall", "MD", "Ophthalmology"},
{100019, "Dr. Steven Lewis", "MBBS", "Otolaryngology"},
{100020, "Dr. Tina Adams", "MD", "General Surgery"},
{100021, "Dr. Ursula Scott", "MD", "Plastic Surgery"},
{100022, "Dr. Victor Hughes", "MBBS", "Family Medicine"},
{100023, "Dr. Wendy Turner", "MD", "Allergy and Immunology"},
{100024, "Dr. Xavier Green", "MD", "Urology"},
{100025, "Dr. Yolanda Nelson", "MBBS", "Internal Medicine"},
{100026, "Dr. Zachary King", "MD", "Psychiatry"},
{100027, "Dr. Abigail Reed", "MBBS", "Geriatrics"},
{100028, "Dr. Benjamin Carter", "MD", "Palliative Care"},
{100029, "Dr. Chloe Mitchell", "MBBS", "Trauma Surgery"},
{100030, "Dr. David Foster", "MD", "Sports Medicine"}
};
const int doctorCount = sizeof(doctors) / sizeof(doctors[0]);

typedef struct{
    int id;
    char name[50];
    char usecase[100];
    int quantity;   
}Item;

Item items[] = {
        {1, "Napa", "Paracetamol, Pain Relief", 250},
        {2, "Ace", "Paracetamol, Pain Relief", 300},
        {3, "Ibufen", "Ibuprofen, NSAID", 200},
        {4, "Nurofen", "Ibuprofen, NSAID", 350},
        {5, "Amoxil", "Amoxicillin, Antibiotic", 450},
        {6, "Clamox", "Amoxicillin, Antibiotic", 400},
        {7, "Zithrox", "Azithromycin, Antibiotic", 320},
        {8, "Azith", "Azithromycin, Antibiotic", 280},
        {9, "Suprax", "Cefixime, Antibiotic", 150},
        {10, "Cef-3", "Cefixime, Antibiotic", 180},
        {11, "Metfor", "Metformin, Diabetes", 220},
        {12, "Diabetmin", "Metformin, Diabetes", 350},
        {13, "Lipitor", "Atorvastatin, Cholesterol", 400},
        {14, "Astat", "Atorvastatin, Cholesterol", 100},
        {15, "Seclo", "Omeprazole, Acid Reflux", 450},
        {16, "Omez", "Omeprazole, Acid Reflux", 300},
        {17, "Neoceptin-R", "Ranitidine, Acid Reflux", 150},
        {18, "Raniloc", "Ranitidine, Acid Reflux", 200},
        {19, "Cozaar", "Losartan, Hypertension", 300},
        {20, "Loxarel", "Losartan, Hypertension", 250},
        {21, "Norvasc", "Amlodipine, Hypertension", 400},
        {22, "Amlosafe", "Amlodipine, Hypertension", 150},
        {23, "Cipro", "Ciprofloxacin, Antibiotic", 280},
        {24, "Ciprogen", "Ciprofloxacin, Antibiotic", 320},
        {25, "Hydrodiuril", "Hydrochlorothiazide, Diuretic", 220},
        {26, "Esidrex", "Hydrochlorothiazide, Diuretic", 150},
        {27, "Eltroxin", "Levothyroxine, Thyroid", 400},
        {28, "Thyrox", "Levothyroxine, Thyroid", 350},
        {29, "Plavix", "Clopidogrel, Blood Thinner", 300},
        {30, "Clopivas", "Clopidogrel, Blood Thinner", 250},
        {31, "Coumadin", "Warfarin, Blood Thinner", 100},
        {32, "Marevan", "Warfarin, Blood Thinner", 320},
        {33, "Lantus", "Insulin, Diabetes", 450},
        {34, "Novolin", "Insulin, Diabetes", 400},
        {35, "Ventolin", "Salbutamol, Asthma", 250},
        {36, "Salbair", "Salbutamol, Asthma", 200},
        {37, "Singulair", "Montelukast, Asthma/Allergy", 300},
        {38, "Montelo", "Montelukast, Asthma/Allergy", 280},
        {39, "Zyrtec", "Cetirizine, Antihistamine", 200},
        {40, "Cetrine", "Cetirizine, Antihistamine", 350},
        {41, "Omnacortil", "Prednisolone, Steroid", 450},
        {42, "Predona", "Prednisolone, Steroid", 320},
        {43, "Prozac", "Fluoxetine, Antidepressant", 280},
        {44, "Fluonil", "Fluoxetine, Antidepressant", 400},
        {45, "Zoloft", "Sertraline, Antidepressant", 250},
        {46, "Serta", "Sertraline, Antidepressant", 300},
        {47, "Xanax", "Alprazolam, Anxiolytic", 450},
        {48, "Alplax", "Alprazolam, Anxiolytic", 220},
        {49, "Valium", "Diazepam, Anxiolytic", 200},
        {50, "Sedil", "Diazepam, Anxiolytic", 350},
        {51, "Tavanic", "Levofloxacin, Antibiotic", 280},
        {52, "Levoxin", "Levofloxacin, Antibiotic", 320},
        {53, "Lasix", "Furosemide, Diuretic", 150},
        {54, "Fruselac", "Furosemide, Diuretic", 180},
        {55, "Dexa", "Dexamethasone, Steroid", 320},
        {56, "Decadron", "Dexamethasone, Steroid", 400},
        {57, "Claritin", "Loratadine, Antihistamine", 150},
        {58, "Loramine", "Loratadine, Antihistamine", 220},
        {59, "Pepcid", "Famotidine, Acid Reducer", 300},
        {60, "Famocid", "Famotidine, Acid Reducer", 350}
};

const int itemscount = sizeof(items) / sizeof(items[0]);
void displayAllMeds() {
    printf("\n--- List of Medications ---\n");
    for (int i = 0; i < itemscount; i++) {
        printf("ID: %d, Name: %s, Type: %s\n",
            items[i].id, items[i].name, items[i].usecase);
    }
    printf("-------------------------\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

void assignUniqueRandomBed(char *bedNumber) {
    int bed;
    srand(time(NULL));
    bed = rand() % 1000 + 1;
    snprintf(bedNumber, MAX_BED_NUMBER_LENGTH, "B-%03d", bed);
     
}

float calculateBMI(float weight, float height) {
    if (height == 0) {
        printf("Height cannot be zero.\n");
        return -1; 
    }
    return weight / (height * height);
}

void loadPatientsFromFile() {
    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        
        return;
    }

    int maxID = 0; 

    while (fscanf(file, "%d,%49[^,],%d,%f,%f,%d,%d,%d,%9[^,],%d,%d,%d,%d,%d,%d,%99[^\n]\n",
                  &patients[patientCount].id,
                  patients[patientCount].name,
                  &patients[patientCount].age,
                  &patients[patientCount].weight,
                  &patients[patientCount].height,
                  &patients[patientCount].isAdmitted,
                  &patients[patientCount].isQuarantined,
                  &patients[patientCount].quarantineDays,
                  patients[patientCount].bedNumber,
                  &patients[patientCount].assignedDoctor1,
                  &patients[patientCount].assignedDoctor2,
                  &patients[patientCount].assignedDoctor3,
                  &patients[patientCount].assignedMedicines[0],  
                  &patients[patientCount].assignedMedicines[1],  
                  &patients[patientCount].assignedMedicines[2],
                   patients[patientCount].symptoms) == 16) {
        if (patients[patientCount].id > maxID) {
            maxID = patients[patientCount].id;
        }
        patientCount++;
    }

    fclose(file);

    nextPatientID = maxID + 1;
}




void viewPatientById() {
    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }

    int id;
    printf("Enter Patient ID to view details: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("\n--- Patient Details ---\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Weight: %.2f kg\n", patients[i].weight);
            printf("Height: %.2f m\n", patients[i].height);

            if (patients[i].weight > 0 && patients[i].height > 0) {
                float bmi = calculateBMI(patients[i].weight, patients[i].height);
                
                if(bmi==0){
                printf("Patient data isn't right. Please check again");
                }else if (bmi < 18.5) {
                    printf("BMI: %.2f (Underweight) - You may need to gain weight. Consider consulting a dietitian.\n", bmi);
                } else if (bmi >= 18.5 && bmi <= 24.9) {
                    printf("BMI: %.2f (Normal weight) - Great! Keep up the good work!\n", bmi);
                } else if (bmi >= 25.0 && bmi <= 29.9) {
                    printf("BMI: %.2f (Overweight) - Consider exercising more and maintaining a balanced diet.\n", bmi);
                } else {
                    printf("BMI: %.2f (Obesity) - It is recommended to consult a doctor or dietitian for a tailored plan.\n", bmi);
                }
            }

            printf("Symptoms/Known Diseases: %s\n", patients[i].symptoms);
            printf("Admission Status: %s\n", patients[i].isAdmitted ? "Admitted" : "Not Admitted");

            if (!patients[i].isAdmitted) {
                printf("Quarantine Status: %s\n", patients[i].isQuarantined ? "Quarantined" : "Not Quarantined");
                if (patients[i].isQuarantined) {
                    printf("Quarantine Days Left: %d\n", patients[i].quarantineDays);
                }
            }

            if (patients[i].isAdmitted) {
                printf("Bed Number: %s\n", patients[i].bedNumber);
            }

            
            printf("Assigned Doctors:\n");
            int doctorAssigned = 0;

            if (patients[i].assignedDoctor1 != 0) {
                doctorAssigned = 1;
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].id == patients[i].assignedDoctor1) {
                        printf("%s (%s, %s)\n", doctors[j].name, doctors[j].degree, doctors[j].specialization);
                        break;
                    }
                }
            }

            if (patients[i].assignedDoctor2 != 0) {
                doctorAssigned = 1;
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].id == patients[i].assignedDoctor2) {
                        printf("%s (%s, %s)\n", doctors[j].name, doctors[j].degree, doctors[j].specialization);
                        break;
                    }
                }
            }

            if (patients[i].assignedDoctor3 != 0) {
                doctorAssigned = 1;
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].id == patients[i].assignedDoctor3) {
                        printf("%s (%s, %s)\n", doctors[j].name, doctors[j].degree, doctors[j].specialization);
                        break;
                    }
                }
            }

            if (!doctorAssigned) {
                printf("  No doctors assigned yet.\n");
            }
            

            for (int j = 0; j < 3; j++) {
                if (patients[i].assignedMedicines[j] != 0) {
                    printf("Assigned Meds: \n");
                    for (int k = 0; k < itemscount; k++) {
                        if (items[k].id == patients[i].assignedMedicines[j]) {
                            printf("  - %s (%s)\n", items[k].name, items[k].usecase);
                            break;
                        }
                    }
                }
                
            }
            

            printf("------------------------\n");
            return;
        }
    }

    printf("Patient with ID %d not found.\n", id);
}



void savePatientsToFile() {
    FILE *file = fopen("patients.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f,%.2f,%d,%d,%d,%s,%d,%d,%d,%d,%d,%d,%s\n",
                patients[i].id,
                patients[i].name,
                patients[i].age,
                patients[i].weight,
                patients[i].height,
                patients[i].isAdmitted,
                patients[i].isQuarantined,
                patients[i].quarantineDays,
                patients[i].bedNumber,
                patients[i].assignedDoctor1,
                patients[i].assignedDoctor2,
                patients[i].assignedDoctor3,
                patients[i].assignedMedicines[0],  
                patients[i].assignedMedicines[1], 
                patients[i].assignedMedicines[2],  
                patients[i].symptoms);
    }

    fclose(file);
}



void displayAllPatients() {
    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }
    printf("\n--- List of Patients ---\n");
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d\n Name: %s\n Age: %d\n Weight: %.2f kg\n Height: %.2f m\n", 
               patients[i].id, patients[i].name, patients[i].age, 
               patients[i].weight, patients[i].height);

        if (patients[i].weight > 0 && patients[i].height > 0) {
            float bmi = calculateBMI(patients[i].weight, patients[i].height);
        if(bmi==0){
                printf("Patient data isn't right. Please check again");
        }else if (bmi>0 && bmi < 18.5) {
                printf("BMI: %.2f (Underweight) - You may need to gain weight. Consider consulting a dietitian.\n", bmi);
        } else if (bmi >= 18.5 && bmi <= 24.9) {
                printf("BMI: %.2f (Normal weight) - Great! Keep up the good work!\n", bmi);
        } else if (bmi >= 25.0 && bmi <= 29.9) {
                printf("BMI: %.2f (Overweight) - Consider exercising more and maintaining a balanced diet.\n", bmi);
        } else {
                printf("BMI: %.2f (Obesity) - It is recommended to consult a doctor or dietitian for a tailored plan.\n", bmi);
             }
        }

        printf(" Symptoms/Known Diseases: %s\n", patients[i].symptoms);

        if(patients[i].isAdmitted!=1){
            printf("Quarantine Status: %s\n", patients[i].isQuarantined ? "Quarantined" : "Not Quarantined");
        if (patients[i].isQuarantined) {
                printf("Quarantine Days Left: %d\n", patients[i].quarantineDays);
            }
        else if(patients[i].isQuarantined!=1){
            printf("Admission Status: Not Quarantined or Admitted\n");
        }
        
            }
        if(patients[i].isAdmitted){
                printf("Bed Number: %s\n", patients[i].bedNumber);
                }
        
        printf("Assigned Doctors:\n");
            int doctorAssigned = 0;

            if (patients[i].assignedDoctor1 != 0) {
                doctorAssigned = 1;
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].id == patients[i].assignedDoctor1) {
                        printf("%s (%s, %s)\n", doctors[j].name, doctors[j].degree, doctors[j].specialization);
                        break;
                    }
                }
            }

            if (patients[i].assignedDoctor2 != 0) {
                doctorAssigned = 1;
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].id == patients[i].assignedDoctor2) {
                        printf("%s (%s, %s)\n", doctors[j].name, doctors[j].degree, doctors[j].specialization);
                        break;
                    }
                }
            }

            if (patients[i].assignedDoctor3 != 0) {
                doctorAssigned = 1;
                for (int j = 0; j < doctorCount; j++) {
                    if (doctors[j].id == patients[i].assignedDoctor3) {
                        printf("%s (%s, %s)\n", doctors[j].name, doctors[j].degree, doctors[j].specialization);
                        break;
                    }
                }
            }

            if (!doctorAssigned) {
                printf("  No doctors assigned yet.\n");
            }
        printf("\n");

        
        
        for (int j = 0; j < 3; j++) {
                if (patients[i].assignedMedicines[j] != 0) {
                    printf("Assigned Meds: \n");
                    for (int k = 0; k < itemscount; k++) {
                        if (items[k].id == patients[i].assignedMedicines[j]) {
                            printf("  - %s (%s)\n", items[k].name, items[k].usecase);
                            break;
                        }
                    }
                }
                
            }
            
    }
    printf("-------------------------\n");
}



void displayAllDoctors() {
    printf("\n--- List of Doctors ---\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("ID: %d, Name: %s, Degree: %s, Specialization: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].degree, doctors[i].specialization);
    }
    printf("-------------------------\n");
}

void addPatient() {
    if (patientCount == MAX_PATIENTS) {
        printf("Maximum patient limit reached.\n");
        return;
    }

    Patient newPatient;
    newPatient.id = patientCount + 1;

    printf("Enter Patient Name: ");
    fgets(newPatient.name, MAX_NAME_LENGTH, stdin);
    newPatient.name[strcspn(newPatient.name, "\n")] = 0;

    printf("Enter Patient Age: ");
    scanf("%d", &newPatient.age);
    clearInputBuffer();

    printf("Enter Patient Weight (in kg): ");
    scanf("%f", &newPatient.weight);
    clearInputBuffer();

    printf("Enter Patient Height (in meters): ");
    scanf("%f", &newPatient.height);
    clearInputBuffer();

    printf("Enter Symptoms/Known Diseases: ");
    fgets(newPatient.symptoms, sizeof(newPatient.symptoms), stdin);
    newPatient.symptoms[strcspn(newPatient.symptoms, "\n")] = 0;
    newPatient.isAdmitted = 0;
    newPatient.isQuarantined = 0;
    newPatient.quarantineDays = 0;
    strcpy(newPatient.bedNumber, "None");
    newPatient.assignedDoctor1 = 0;  
    newPatient.assignedDoctor2 = 0;
    newPatient.assignedDoctor3 = 0;
    newPatient.assignedMedicines[0] = 0; 
    newPatient.assignedMedicines[1] = 0; 
    newPatient.assignedMedicines[2] = 0;

    patients[patientCount++] = newPatient;
    
    savePatientsToFile();

    printf("Patient added successfully with ID %d.\n", newPatient.id);
}



void assignDoctor(int patientId) {
    displayAllPatients(); 
    printf("Enter Patient ID to assign a doctor: ");
    scanf("%d", &patientId);
    clearInputBuffer();

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == patientId) {
            displayAllDoctors(); 

            int doctorId;
            printf("Enter Doctor ID to assign: ");
            scanf("%d", &doctorId);
            clearInputBuffer();

            
            if (patients[i].assignedDoctor1 == doctorId || 
                patients[i].assignedDoctor2 == doctorId || 
                patients[i].assignedDoctor3 == doctorId) {
                printf("Doctor ID %d is already assigned to this patient.\n", doctorId);
                return;
            }

            if (patients[i].assignedDoctor1 == 0) {
                patients[i].assignedDoctor1 = doctorId;
            } else if (patients[i].assignedDoctor2 == 0) {
                patients[i].assignedDoctor2 = doctorId;
            } else if (patients[i].assignedDoctor3 == 0) {
                patients[i].assignedDoctor3 = doctorId;
            } else {
                printf("This patient already has 3 doctors assigned. Cannot assign more.\n");
                return;
            }

            savePatientsToFile();
            printf("Doctor ID %d assigned successfully to Patient ID %d.\n", doctorId, patientId);
            return;
        }
    }

    printf("Patient not found.\n");
}

void assignmeds(int patientId) {
    printf("Enter Patient ID to assign medicines: ");
    scanf("%d", &patientId);
    clearInputBuffer();

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == patientId) {
            displayAllMeds();
            int medId;
            printf("Enter Medicine ID to assign (or Enter 0 to stop): ");
            for (int j = 0; j < 3; j++) {
                printf("\nAssign medicine #%d: ", j + 1);
                scanf("%d", &medId);
                clearInputBuffer();

                if (medId == 0) break;

                int validMed = 0;
                for (int k = 0; k < itemscount; k++) {
                    if (items[k].id == medId) {
                        validMed = 1;
                        break;
                    }
                }

                if (!validMed) {
                    printf("Invalid Medicine ID. Please try again.\n");
                    j--;
                    continue;
                }

                patients[i].assignedMedicines[j] = medId;
                printf("Medicine ID %d assigned successfully.\n", medId);
            }

            printf("Medicine assignment complete for Patient ID %d.\n", patientId);
            return;
        }
    }

    printf("Patient not found.\n");
}




void updateStatus(int id) {
    displayAllPatients();
    printf("Enter Patient ID to update status: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            int choice;
            printf("1. Admit to Hospital\n");
            printf("2. Quarantine at Home\n");
            printf("3. Update Patient Detail\n");
            printf("4. Remove Assigned Doctor\n");
            printf("5. Assign Medicines\n");
            printf("6. Remove Assign Medicines\n");
            printf("7. Release From Admission/Quarantine\n");
            printf("Press 0 to cancel\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            clearInputBuffer();
            if (choice == 0){
                break;
            } else if (choice == 1) {
                patients[i].isAdmitted = 1;
                patients[i].isQuarantined = 0;
                assignUniqueRandomBed(patients[i].bedNumber);
                printf("Patient admitted to hospital. Assigned bed: %s\n", patients[i].bedNumber);
            } else if (choice == 2) {
                patients[i].isAdmitted = 0;
                patients[i].isQuarantined = 1;
                patients[i].quarantineDays = 14;
                strcpy(patients[i].bedNumber, "Home");
                printf("Patient quarantined at home for 14 days.\n");
            } else if (choice == 3) {
                printf("\nWhat would you like to update?\n");
                printf("1. Height\n");
                printf("2. Weight\n");
                printf("3. Known diseases or symptoms\n");
                printf("Enter choice: ");

                int updateChoice;
                scanf("%d", &updateChoice);

                if (updateChoice == 1) {
                    printf("\nEnter new height (in meters): ");
                    scanf("%f", &patients[i].height);
                    printf("Height updated successfully.\n");
                } else if (updateChoice == 2) {
                    printf("\nEnter new weight (in kilograms): ");
                    scanf("%f", &patients[i].weight);
                    printf("Weight updated successfully.\n");
                } else if (updateChoice == 3) {
                    printf("\nEnter new known diseases or symptoms: ");
                    getchar();
                    fgets(patients[i].symptoms, sizeof(patients[i].symptoms), stdin);
                    patients[i].symptoms[strcspn(patients[i].symptoms, "\n")] = 0;
                    printf("Known diseases or symptoms updated successfully.\n");
                } else {
                    printf("\nInvalid choice.\n");
                }
            } 
            else if (choice == 5){
                displayAllMeds();
            int medId;
            printf("Enter Medicine ID to assign (or Enter 0 to stop): ");
            for (int j = 0; j < 3; j++) {
                printf("\nAssign medicine #%d: ", j + 1);
                scanf("%d", &medId);
                clearInputBuffer();

                if (medId == 0) break;

                int validMed = 0;
                for (int k = 0; k < itemscount; k++) {
                    if (items[k].id == medId) {
                        validMed = 1;
                        break;
                    }
                }

                if (!validMed) {
                    printf("Invalid Medicine ID. Please try again.\n");
                    j--;
                    continue;
                }

                patients[i].assignedMedicines[j] = medId;
                printf("Medicine ID %d assigned successfully.\n", medId);
            }

            printf("Medicine assignment complete for Patient ID %d.\n", patients[i].id);
            return;
            } else if(choice == 6){
                int medId;
                    printf("Currently assigned medicines for Patient ID %d:\n", patients[i].id);


                for (int j = 0; j < 3; j++) {
                if (patients[i].assignedMedicines[j] != 0) {
                printf("Medicine #%d: ID %d\n", j + 1, patients[i].assignedMedicines[j]);
        }
    }

                printf("Enter Medicine ID to remove (or Enter 0 to stop): ");
                for (int j = 0; j < 3; j++) {
                printf("\nRemove medicine #%d: ", j + 1);
                scanf("%d", &medId);
                clearInputBuffer();

                if (medId == 0) break;

                int foundMed = 0;
        for (int k = 0; k < 3; k++) {
        if (patients[i].assignedMedicines[k] == medId) {
            patients[i].assignedMedicines[k] = 0; 
            foundMed = 1;
            printf("Medicine ID %d removed successfully.\n", medId);
            break;
        }
    }

    if (!foundMed) {
        printf("Medicine ID %d is not currently assigned. Please try again.\n", medId);
        j--;
        continue;
    }
}

printf("Medicine removal complete for Patient ID %d.\n", patients[i].id);
return;

            } else if (choice == 6) {
                int medId;
printf("Currently assigned medicines for Patient ID %d:\n", patients[i].id);


for (int j = 0; j < 3; j++) {
    if (patients[i].assignedMedicines[j] != 0) {
        printf("Medicine #%d: ID %d\n", j + 1, patients[i].assignedMedicines[j]);
    }
}

printf("Enter Medicine ID to remove (or Enter 0 to stop): ");
for (int j = 0; j < 3; j++) {
    printf("\nRemove medicine #%d: ", j + 1);
    scanf("%d", &medId);
    clearInputBuffer();

    if (medId == 0) break;

    int foundMed = 0;
    for (int k = 0; k < 3; k++) {
        if (patients[i].assignedMedicines[k] == medId) {
            patients[i].assignedMedicines[k] = 0; 
            foundMed = 1;
            printf("Medicine ID %d removed successfully.\n", medId);
            break;
        }
    }

    if (!foundMed) {
        printf("Medicine ID %d is not currently assigned. Please try again.\n", medId);
        j--;
        continue;
    }
}

printf("Medicine removal complete for Patient ID %d.\n", patients[i].id);
return;

            }else if (choice == 7) {
                patients[i].isAdmitted = 0;
                patients[i].isQuarantined = 0;
                strcpy(patients[i].bedNumber, "None");
                printf("Patient released from hospital/quarantine.\n");
            } else if (choice == 4) {
                printf("\nWhich assigned doctor would you like to remove?\n");
                printf("1. Doctor 1\n");
                printf("2. Doctor 2\n");
                printf("3. Doctor 3\n");
                printf("Enter choice: ");
                int removeDoctorChoice;
                scanf("%d", &removeDoctorChoice);

                if (removeDoctorChoice == 1 && patients[i].assignedDoctor1 != 0) {
                    patients[i].assignedDoctor1 = 0;
                    printf("Doctor 1 removed successfully.\n");
                } else if (removeDoctorChoice == 2 && patients[i].assignedDoctor2 != 0) {
                    patients[i].assignedDoctor2 = 0;
                    printf("Doctor 2 removed successfully.\n");
                } else if (removeDoctorChoice == 3 && patients[i].assignedDoctor3 != 0) {
                    patients[i].assignedDoctor3 = 0;
                    printf("Doctor 3 removed successfully.\n");
                } else {
                    printf("Invalid choice or no doctor assigned in the selected slot.\n");
                }
            } else {
                printf("Invalid choice.\n");
            }
            savePatientsToFile();  
            return;
        }
    }
    printf("Patient not found.\n");
}



void displayCredits() {
    printf("\n------------------ CREDITS ------------------\n");
    printf("1) Sourov Kumar Saha Shetu\n   ID: 2421662642\n");
    printf("2) Tahmid Abdullah\n   ID: 24214136423\n");
    printf("3) Md rafshan Hossain\n   ID: 2421934642\n");
    printf("Course: CSE 115L(Programming Language-1) \n");
    printf("     North South University\n");
    printf("---------------------------------------------\n\n");
}


void displayMenu() {
    printf("\n--- Smart Hospital Management System ---\n");
    printf("1. Add New Patient\n");
    printf("2. Assign Doctor\n");
    printf("3. Update Patient Status\n");
    printf("4. Display All Patients\n");
    printf("5. Display All Doctors\n");
    printf("6. View Patient by ID\n"); 
    printf("7. View Credits\n");
    printf("8. Exit\n");
    printf("What would you like to do today?\n");
    printf("Enter your choice: ");
}


int main() {
loadPatientsFromFile();

printf("Welcome to Hospital Management System\n");

    if (!login()) {
        return 0; 
    }
    else{
    printf("Login successful! Access granted.\n");
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                assignDoctor(0);
                break;
            case 3:
                updateStatus(0);
                break;
            case 4:
                displayAllPatients();
                break;
            case 5:
                displayAllDoctors();
                break;
            case 6:
                viewPatientById(); 
                break;
            case 7:
                displayCredits(); 
                break;
            case 8:
                savePatientsToFile();
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);}

    return 0;
}

