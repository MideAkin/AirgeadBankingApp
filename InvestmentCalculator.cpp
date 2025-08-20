#include <iostream>
#include <iomanip>
#include "InvestmentCalculator.h"

InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit,
                                           double t_annualInterest, int t_numberOfYears) {
    m_initialInvestment = t_initialInvestment;
    m_monthlyDeposit = t_monthlyDeposit;
    m_annualInterest = t_annualInterest;
    m_numberOfYears = t_numberOfYears;
}

void InvestmentCalculator::printReportWithoutMonthlyDeposit() const {
    double balance = m_initialInvestment;
    double interest;

    std::cout << "\n\n   Balance and Interest Without Additional Monthly Deposits\n";
    std::cout << "===============================================================\n";
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    std::cout << "---------------------------------------------------------------\n";

    for (int year = 1; year <= m_numberOfYears; ++year) {
        interest = balance * (m_annualInterest / 100);
        balance += interest;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << year << "\t$" << balance << "\t\t$" << interest << "\n";
    }
}

void InvestmentCalculator::printReportWithMonthlyDeposit() const {
    double balance = m_initialInvestment;
    double monthlyInterestRate = m_annualInterest / 100 / 12;
    double interest, yearlyInterest;

    std::cout << "\n\n   Balance and Interest With Additional Monthly Deposits\n";
    std::cout << "================================================================\n";
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    std::cout << "----------------------------------------------------------------\n";

    for (int year = 1; year <= m_numberOfYears; ++year) {
        yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month) {
            balance += m_monthlyDeposit;
            interest = balance * monthlyInterestRate;
            balance += interest;
            yearlyInterest += interest;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << year << "\t$" << balance << "\t\t$" << yearlyInterest << "\n";
    }
}
