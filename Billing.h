#ifndef BILLING_H
#define BILLING_H

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>

class Billing {
public:
    std::string patientName;
    float amount;

    void generateBill(int pipe[2]) const;
    static void displayBill(const Billing& bill);
    static Billing deserialize(const std::string& data);
};

#endif // BILLING_H
