#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores {
private:
   string studentName;
   double* testScores;        // points to array of test scores
   int numTestScores;

   // private member functions to create array of test scores.
   void createTestScoresArray(int size) {
      numTestScores = size;
      testScores = new double[size];
      for (int i = 0; i < size; i++) testScores[i] = DEFAULT_SCORE;
   }

public:
   // constructor
   StudentTestScores(string name, int numScores) {
      studentName = name;
      createTestScoresArray(numScores);
   }
   // copy constructor
   StudentTestScores(const StudentTestScores& obj) {
      studentName = obj.studentName;
      numTestScores = obj.numTestScores;
      testScores = new double[numTestScores];
      for (int i = 0; i < numTestScores; i++) testScores[i] = obj.testScores[i];
   }
   ~StudentTestScores() { delete[] testScores; };

   // the setTestScore function sets a specific test score's value.
   void setTestScore(double score, int index) { testScores[index] = score; }

   // set the student's name.
   void setStudentName(string name) { studentName = name; }
   // Get the student's name.
   string getStudentName() const {
      return studentName;
   }

   // Get the number of test scores.
   int getNumTestScores() {
      return numTestScores;
   }
   // Get a specific test score.
   double getTestScore(int index) const {
      return testScores[index];
   }

   // overload = operator
   void operator=(const StudentTestScores& right) {
      delete[] testScores;
      studentName = right.studentName;
      numTestScores = right.numTestScores;
      testScores = new double[numTestScores];
      for (int i = 0; i < numTestScores; i++) testScores[i] = right.testScores[i];
   }
};

#endif