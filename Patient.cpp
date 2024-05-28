#include "Patient.h"

void Patient::registerPatient(int pipe[2]) const {
    std::stringstream ss;
    ss << name << "," << age << "," << gender << "\n";
    std::string data = ss.str();
    write(pipe[1], data.c_str(), data.size());
}

void Patient::displayPatient(const Patient& patient) {
    std::cout << "Name: " << patient.name << std::endl;
    std::cout << "Age: " << patient.age << std::endl;
    std::cout << "Gender: " << patient.gender << std::endl;
}

Patient Patient::deserialize(const std::string& data) {
    Patient patient;
    std::stringstream ss(data);
    std::getline(ss, patient.name, ',');
    ss >> patient.age;
    ss.ignore(1); // ignore the comma
    std::getline(ss, patient.gender);
    return patient;
}
