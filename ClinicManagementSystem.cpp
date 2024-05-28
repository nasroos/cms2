#include "ClinicManagementSystem.h"
#include <iostream>

ClinicManagementSystem::ClinicManagementSystem() {
    // Create pipes
    if (pipe(registrationPipe) < 0 || pipe(schedulingPipe) < 0 || pipe(billingPipe) < 0) {
        std::cerr << "Error: Unable to create pipes.\n";
        return;
    }
}

ClinicManagementSystem::~ClinicManagementSystem() {
    // Close pipes
    close(registrationPipe[0]);
    close(registrationPipe[1]);
    close(schedulingPipe[0]);
    close(schedulingPipe[1]);
    close(billingPipe[0]);
    close(billingPipe[1]);
}

void ClinicManagementSystem::start() {
    int choice;

    do {
        // Display menu
        std::cout << "\nClinic Management System Menu\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Schedule Appointment\n";
        std::cout << "3. Generate Bill\n";
        std::cout << "4. Display Patient\n";
        std::cout << "5. Display Scheduled Appointments\n";
        std::cout << "6. Display Generated Bills\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleRegistration();
                break;
            case 2:
                handleScheduling();
                break;
            case 3:
                handleBilling();
                break;
            case 4:
                displayPatient();
                break;
            case 5:
                displayAppointments();
                break;
            case 6:
                displayBills();
                break;
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void ClinicManagementSystem::handleRegistration() {
    Patient patient;
    std::cout << "\nEnter patient details:\n";
    std::cout << "Name: ";
    std::cin >> patient.name;
    std::cout << "Age: ";
    std::cin >> patient.age;
    std::cout << "Gender: ";
    std::cin >> patient.gender;
    patient.registerPatient(registrationPipe);
}

void ClinicManagementSystem::handleScheduling() {
    Appointment appointment;
    std::cout << "\nEnter appointment details:\n";
    std::cout << "Patient Name: ";
    std::cin >> appointment.patientName;
    std::cout << "Doctor Name: ";
    std::cin >> appointment.doctorName;
    // Assume appointment time is a UNIX timestamp
    std::cout << "Appointment Time (Unix Timestamp): ";
    std::cin >> appointment.appointmentTime;
    appointment.scheduleAppointment(schedulingPipe);
}

void ClinicManagementSystem::handleBilling() {
    Billing bill;
    std::cout << "\nEnter billing details:\n";
    std::cout << "Patient Name: ";
    std::cin >> bill.patientName;
    std::cout << "Amount: ";
    std::cin >> bill.amount;
    bill.generateBill(billingPipe);
}

void ClinicManagementSystem::displayPatient() {
    // Read patient data from pipe and display
    char buffer[256];
    ssize_t bytesRead = read(registrationPipe[0], buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    std::string data(buffer);
    Patient patient = Patient::deserialize(data);
    std::cout << "\nPatient Information:\n";
    Patient::displayPatient(patient);
}

void ClinicManagementSystem::displayAppointments() {
    // Read appointment data from pipe and display
    char buffer[256];
    ssize_t bytesRead = read(schedulingPipe[0], buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    std::string data(buffer);
    Appointment appointment = Appointment::deserialize(data);
    std::cout << "\nScheduled Appointment Information:\n";
    Appointment::displayAppointment(appointment);
}

void ClinicManagementSystem::displayBills() {
    // Read bill data from pipe and display
    char buffer[256];
    ssize_t bytesRead = read(billingPipe[0], buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    std::string data(buffer);
    Billing bill = Billing::deserialize(data);
    std::cout << "\nGenerated Bill Information:\n";
    Billing::displayBill(bill);
}
