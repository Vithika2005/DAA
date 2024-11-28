#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

// Function to calculate SPI for a semester
double calculateSPI(const vector<double>& grades, const vector<int>& credits){
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
}

// Function to calculate CPI from multiple semesters
double calculateCPI(const vector<double>& spiList, const vector<int>& creditsPerSemester) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < spiList.size(); ++i) {
        totalGradePoints += spiList[i] * creditsPerSemester[i];
        totalCredits += creditsPerSemester[i];
    }

    return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
}

int main() {
    const int numSemesters = 5; // Fixed number of semesters
    vector<double> spiList(numSemesters);
    vector<int> creditsPerSemester(numSemesters);

    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "Enter the number of courses in semester " << (i + 1) << ": ";
        cin >> numCourses;

        vector<double> grades(numCourses);
        vector<int> credits(numCourses);

        cout << "Enter grades (0.0 to 4.0 scale) and corresponding credits for each course:\n";
        for (int j = 0; j < numCourses; ++j) {
            cout << "Course " << (j + 1) << " - Grade: ";
            cin >> grades[j];
            cout << "Course " << (j + 1) << " - Credits: ";
            cin >> credits[j];
        }

        double spi = calculateSPI(grades, credits);
        spiList[i] = spi;
        creditsPerSemester[i] = accumulate(credits.begin(), credits.end(), 0);

        cout << fixed << setprecision(2);
        cout << "SPI for Semester " << (i + 1) << ": " << spi << endl;
    }

    double cpi = calculateCPI(spiList, creditsPerSemester);
    cout << "Cumulative Performance Index (CPI): " << fixed << setprecision(2) << cpi << endl;

    return 0;
}
