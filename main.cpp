#include <iostream>
#include <string>
#include <vector>
#include <cassert> // Used for testing logic

using namespace std;

// Base Class: Loan
class Loan {
protected:
    string loanID;
    double leAmount; 
    double cdAmount; 

public:
    Loan(string id, double le, double cd) : loanID(id), leAmount(le), cdAmount(cd) {}
    virtual bool isCompliant() = 0; // Returns true if compliant, false otherwise
    virtual ~Loan() {}
};

// Zero Tolerance Logic
class ZeroToleranceLoan : public Loan {
public:
    ZeroToleranceLoan(string id, double le, double cd) : Loan(id, le, cd) {}

    bool isCompliant() override {
        // TRID Rule: CD cannot be greater than LE (0% tolerance)
        return cdAmount <= leAmount;
    }
};

// Unit Testing Function: This proves your code is "Testable"
void runUnitTests() {
    cout << "--- Running Automated Unit Tests ---" << endl;

    // Test 1: Should Pass (CD is equal to LE)
    ZeroToleranceLoan test1("T-001", 1000.00, 1000.00);
    if(test1.isCompliant()) cout << "[PASS] Test 1: Equal amounts are compliant." << endl;
    else cout << "[FAIL] Test 1 failed." << endl;

    // Test 2: Should Fail (CD is greater than LE)
    ZeroToleranceLoan test2("T-002", 1000.00, 1050.00);
    if(!test2.isCompliant()) cout << "[PASS] Test 2: Over-limit detected correctly." << endl;
    else cout << "[FAIL] Test 2 failed." << endl;

    cout << "--- Unit Tests Completed ---\n" << endl;
}

int main() {
    // 1. Run Automated Tests first to ensure quality
    runUnitTests();

    // 2. Main Application Logic
    cout << "Processing Real-Time Loan Data..." << endl;
    ZeroToleranceLoan activeLoan("FHA-2024", 1500.00, 1550.00);
    
    if (activeLoan.isCompliant()) {
        cout << "Loan FHA-2024: Ready for Funding." << endl;
    } else {
        cout << "Loan FHA-2024: !! COMPLIANCE ERROR !! Review Fee Variance." << endl;
    }

    return 0;
}
