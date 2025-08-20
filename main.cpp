#include <iostream>
#include <limits>
#include <iomanip>
#include "InvestmentCalculator.h"

int main() {
    double initialInvestment = 0.0;
    double monthlyDeposit = 0.0;
    double annualInterest = 0.0;
    int numberOfYears = 0;

    std::cout << "===========================================\n";
    std::cout << "   Welcome to the Airgead Banking App\n";
    std::cout << "===========================================\n\n";

    // ---- Input collection with validation ----
    std::cout << "Please enter the following:\n\n";

    // Initial Investment
    std::cout << "Initial Investment Amount: $";
    while (!(std::cin >> initialInvestment) || initialInvestment <= 0) {
        std::cout << "Please enter a positive number: $";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Monthly Deposit
    std::cout << "Monthly Deposit: $";
    while (!(std::cin >> monthlyDeposit) || monthlyDeposit < 0) {
        std::cout << "Please enter a valid amount (0 or higher): $";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Annual Interest Rate
    std::cout << "Annual Interest (%): ";
    while (!(std::cin >> annualInterest) || annualInterest <= 0) {
        std::cout << "Please enter a positive interest rate: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Number of Years
    std::cout << "Number of Years: ";
    while (!(std::cin >> numberOfYears) || numberOfYears <= 0) {
        std::cout << "Please enter a valid number of years: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // ---- Display input summary ----
    std::cout << "\n\n===========================================\n";
    std::cout << "          Investment Input Summary\n";
    std::cout << "===========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Initial Investment Amount:    $" << initialInvestment << "\n";
    std::cout << "Monthly Deposit:              $" << monthlyDeposit << "\n";
    std::cout << "Annual Interest Rate:         " << annualInterest << "%\n";
    std::cout << "Number of Years:              " << numberOfYears << "\n";

    std::cin.ignore(); // clear leftover newline
    std::cin.get();    // wait for Enter

    // ---- Run Reports ----
    InvestmentCalculator calc(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    calc.printReportWithoutMonthlyDeposit();
    calc.printReportWithMonthlyDeposit();

    return 0;
}
