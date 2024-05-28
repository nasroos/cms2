cmake_minimum_required(VERSION 3.10)
project(ClinicManagementSystem)

# Add executable
add_executable(clinic_management_system
        main.cpp
        ClinicManagementSystem.cpp
        Patient.cpp
        Appointment.cpp
        Billing.cpp)

# Optionally set C++ standard
#set(CMAKE_CXX_STANDARD 11)

# Include current directory for header files
target_include_directories(clinic_management_system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
