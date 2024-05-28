#include "Appointment.h"

void Appointment::scheduleAppointment(int pipe[2]) const {
    std::stringstream ss;
    ss << patientName << "," << doctorName << "," << appointmentTime << "\n";
    std::string data = ss.str();
    write(pipe[1], data.c_str(), data.size());
}

void Appointment::displayAppointment(const Appointment& appointment) {
    std::cout << "Patient Name: " << appointment.patientName << std::endl;
    std::cout << "Doctor Name: " << appointment.doctorName << std::endl;
    std::cout << "Appointment Time: " << appointment.appointmentTime << std::endl;
}

Appointment Appointment::deserialize(const std::string& data) {
    Appointment appointment;
    std::stringstream ss(data);
    std::getline(ss, appointment.patientName, ',');
    std::getline(ss, appointment.doctorName, ',');
    ss >> appointment.appointmentTime;
    return appointment;
}
