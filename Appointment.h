#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <ctime>

class Appointment {
public:
    std::string patientName;
    std::string doctorName;
    time_t appointmentTime;

    void scheduleAppointment(int pipe[2]) const;
    static void displayAppointment(const Appointment& appointment);
    static Appointment deserialize(const std::string& data);
};

#endif // APPOINTMENT_H
