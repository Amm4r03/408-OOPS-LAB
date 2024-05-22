// AIM : Write a program to design a student class representing student roll number and a test class (derived class of student) representing the scores of the student in various subjects and sports class representing the score in sports. The sports and test class should be inherited by a result class having the functionality to add the scores and display the final result for a student

#include <iostream>
using namespace std;

class Student {
    private : 
        int roll_number;
    public : 
        Student (int student_roll_number) {
            roll_number = student_roll_number;
        }

        void showRollNumber(void) {
            cout << "Roll number : " << roll_number << endl;
        }
};

class Test : virtual public Student {
    private : 
        int subject_1_score;
        int subject_2_score;
        int subject_3_score;
    public : 
        Test(int sub1, int sub2, int sub3, int roll_number) : Student(roll_number) {
            subject_1_score = sub1;
            subject_2_score = sub2;
            subject_3_score = sub3;
        }

        int getTestScores() {
            return subject_1_score + subject_2_score + subject_3_score;
        }
};

class Sport : virtual public Student {
    private :
        int sport_1_score;
        int sport_2_score;
    public :
        Sport(int sport1Score, int sport2Score, int roll_number) : Student(roll_number) {
            sport_1_score = sport1Score;
            sport_2_score = sport2Score;
        }

        int getSportScore() {
            return sport_1_score + sport_2_score;
        }
};

class Result : public Sport, public Test {
    private : 
        int test_total;
        int sport_total;
    public :
        Result(int roll_number, int s1_score, int s2_score, int s3_score, int sport1_score, int sport2_score) : Test(s1_score, s2_score, s3_score, roll_number), Sport(sport1_score, sport2_score, roll_number), Student(roll_number) {}

        void calcTotal(void) {
            test_total = getTestScores();
            sport_total = getSportScore();
        }

        void showResult(void) {
            cout << "total" << endl;
            cout << "test : " << test_total << "/ 300" << endl;
            cout << "sport : " << sport_total << " / 200" << endl;
        }
};

int main() {
    Result r(12, 90, 89, 75, 75, 81);
    r.calcTotal();
    r.showRollNumber();
    r.showResult();
    return 0;
}