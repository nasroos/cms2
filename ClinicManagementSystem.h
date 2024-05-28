#ifndef CLINIC_MANAGEMENT_SYSTEM_H
#define CLINIC_MANAGEMENT_SYSTEM_H

#include "Patient.h"
#include "Appointment.h"
#include "Billing.h"

class ClinicManagementSystem {
private:
    int registrationPipe[2], schedulingPipe[2], billingPipe[2];

public:
    ClinicManagementSystem();
    ~ClinicManagementSystem();
    void start();

private:
    void handleRegistration();
    void handleScheduling();
    void handleBilling();
    void displayPatient();
    void displayAppointments();
    void displayBills();
};

#endif // CLINIC_MANAGEMENT_SYSTEM_H
