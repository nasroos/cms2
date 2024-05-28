#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>

class Patient {
public:
    std::string name;
    int age;
    std::string gender;

    void registerPatient(int pipe[2]) const;
    static void displayPatient(const Patient& patient);
    static Patient deserialize(const std::string& data);
};

#endif // PATIENT_H
