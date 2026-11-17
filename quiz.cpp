// Console Quiz Project
// Features: MCQ questions, score + percentage, saves name and score in a file
// Concepts: classes and objects, arrays, vectors, strings, file handling, functions, exception handling

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
using namespace std;

// ---------- Question class ----------
class Question {
private:
    string text;
    string options[4];
    int correct;            // correct option number (1 to 4)

public:
    Question(string t, string a, string b, string c, string d, int ans) {
        text = t;
        options[0] = a;
        options[1] = b;
        options[2] = c;
        options[3] = d;
        correct = ans;
    }

    void show(int number) {
        cout << endl << "Q" << number << ". " << text << endl;
        for (int i = 0; i < 4; i++) {
            cout << "   " << i + 1 << ") " << options[i] << endl;
        }
    }

    bool checkAnswer(int choice) {
        return choice == correct;
    }

    string getCorrectOption() {
        return options[correct - 1];
    }
};

// ---------- Function to read the user's choice ----------
// throws an exception if the input is not valid
int getChoice() {
    int choice;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (cin.eof()) {
        cout << endl << "Input ended. Quiz stopped." << endl;
        exit(1);
    }
    if (cin.fail()) {               // user typed letters or symbols
        cin.clear();
        cin.ignore(1000, '\n');
        throw runtime_error("Please enter a number only.");
    }
    cin.ignore(1000, '\n');         // remove the rest of the line

    if (choice < 1 || choice > 4) {
        throw runtime_error("Choice must be between 1 and 4.");
    }
    return choice;
}

// ---------- Quiz class ----------
class Quiz {
private:
    vector<Question> questions;
    int score;

    void updateScore() {            // score is changed only in this function
        score++;
    }

public:
    Quiz() {
        score = 0;
    }

    void addQuestion(Question q) {
        questions.push_back(q);
    }

    int totalQuestions() {
        return questions.size();
    }

    int getScore() {
        return score;
    }

    double getPercentage() {
        return (score * 100.0) / totalQuestions();
    }

    void start() {
        int total = totalQuestions();
        for (int i = 0; i < total; i++) {
            questions[i].show(i + 1);

            int choice = 0;
            while (true) {
                try {
                    choice = getChoice();
                    break;                      // valid input, leave the loop
                }
                catch (runtime_error &e) {
                    cout << "Error: " << e.what() << endl;
                }
            }

            if (questions[i].checkAnswer(choice)) {
                cout << "Correct!" << endl;
                updateScore();
            } else {
                cout << "Wrong! Correct answer: " << questions[i].getCorrectOption() << endl;
            }
        }
    }

    void showResult() {
        cout << endl << "===== RESULT =====" << endl;
        cout << "Score      : " << score << "/" << totalQuestions() << endl;
        cout << "Percentage : " << fixed << setprecision(1) << getPercentage() << "%" << endl;
    }

    void saveResult(string name) {
        ofstream file("scores.txt", ios::app);      // app = add at the end of the file
        if (!file) {
            throw runtime_error("Could not open scores.txt");
        }
        file << name << " | " << score << "/" << totalQuestions()
             << " | " << fixed << setprecision(1) << getPercentage() << "%" << endl;
        file.close();
    }
};

// ---------- main ----------
int main() {
    Quiz quiz;

    quiz.addQuestion(Question("Which keyword is used to define a class in C++?",
                              "object", "class", "define", "new", 2));
    quiz.addQuestion(Question("Which OOP concept lets one class acquire the properties of another?",
                              "Encapsulation", "Polymorphism", "Inheritance", "Abstraction", 3));
    quiz.addQuestion(Question("Which special function runs automatically when an object is created?",
                              "Destructor", "Constructor", "Friend function", "Operator function", 2));
    quiz.addQuestion(Question("Which standard container behaves like a dynamic array?",
                              "std::map", "std::set", "std::stack", "std::vector", 4));
    quiz.addQuestion(Question("Which header file is needed for ofstream and ifstream?",
                              "<iostream>", "<string>", "<fstream>", "<vector>", 3));
    quiz.addQuestion(Question("Which block handles an exception thrown inside a try block?",
                              "catch", "finally", "except", "handle", 1));
    quiz.addQuestion(Question("What is the default access level of members in a C++ class?",
                              "public", "protected", "global", "private", 4));
    quiz.addQuestion(Question("Which operator accesses a member through a pointer to an object?",
                              "::", "->", ".", "&", 2));

    cout << "===== C++ QUIZ =====" << endl;
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    while (name.empty()) {
        if (cin.eof()) {
            return 1;
        }
        cout << "Name cannot be empty. Enter your name: ";
        getline(cin, name);
    }

    cout << "Hello " << name << "! There are " << quiz.totalQuestions()
         << " questions. Type the option number as your answer." << endl;

    quiz.start();
    quiz.showResult();

    try {
        quiz.saveResult(name);
        cout << "Result saved in scores.txt" << endl;
    }
    catch (runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
