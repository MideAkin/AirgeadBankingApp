#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

class InvestmentCalculator {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

public:
    InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit,
                         double t_annualInterest, int t_numberOfYears);

    void printReportWithoutMonthlyDeposit() const;
    void printReportWithMonthlyDeposit() const;
};

#endif
