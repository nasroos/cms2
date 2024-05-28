#include "Billing.h"

void Billing::generateBill(int pipe[2]) const {
    std::stringstream ss;
    ss << patientName << "," << amount << "\n";
    std::string data = ss.str();
    write(pipe[1], data.c_str(), data.size());
}

void Billing::displayBill(const Billing& bill) {
    std::cout << "Patient Name: " << bill.patientName << std::endl;
    std::cout << "Amount: " << bill.amount << std::endl;
}

Billing Billing::deserialize(const std::string& data) {
    Billing bill;
    std::stringstream ss(data);
    std::getline(ss, bill.patientName, ',');
    ss >> bill.amount;
    return bill;
}
