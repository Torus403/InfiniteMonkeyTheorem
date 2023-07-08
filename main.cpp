// TypingMonkeyTheorem.cpp
// Author: Jack Mcnish
// Date: 08/07/2023
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;


string generate(const string &targetString) {
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string generatedString = "";
    for (int i = 0; i < targetString.length(); i++) {
        int randomIndex = rand() % 26;
        char generatedChar = alphabet[randomIndex];
        generatedString.push_back(generatedChar);
    }
    return generatedString;
}


double score(const string &targetString, const string &testString) {
    int correctCount = 0;
    for (int i = 0; i < targetString.length(); i++) {
        if (targetString[i] == testString[i]) {
            correctCount++;
        }
    }
    return (double) correctCount / targetString.length();
}


void testUntilAcheive(const string &targetString) {
    // Use this if want to run a single run and view generated strings
    double currentScore = 0.0;
    int count = 0;
    while (currentScore < 1.0) {
        string generatedString = generate(targetString);
        double currentScore = score(targetString, generatedString);
        count++;
        cout << "Target String: '" << targetString << "' -> Generated String: '" << generatedString << "' -> Score: " << currentScore * 100 << "% -> Count: " << count << "\n";
        if (currentScore == 1.0) {
            break;
        }
    }
    cout << "----- PROGRAM OUTCOME -----\n";
    cout << "It took " << count << " tries to obtain the target string.\n";
    int expectedTries = pow(26, targetString.length());
    cout << "The expected amount of tries was " << expectedTries << "\n";
}

int countTestUntilAcheive(const string& targetString) {
    // Use this to retrieve only the count of single run
    double currentScore = 0.0;
    int count = 0;
    while (currentScore < 1.0) {
        string generatedString = generate(targetString);
        double currentScore = score(targetString, generatedString);
        count++;
        if (currentScore == 1.0) {
            break;
        }
    }
    return count;
}


double repeatTest(int testRepeats, const string &targetString) {
    int count = countTestUntilAcheive(targetString);
    int countSum = 0;
    for (int i = 0; i < testRepeats; i++) {
        int count = countTestUntilAcheive(targetString);
        countSum += count;
    }
    return (double)countSum / testRepeats;
}




int main()
{
    cout << "----- PROGRAM STARTING -----\n";
    srand((unsigned)time(NULL));
  
    string targetString = "hi";
    testUntilAcheive(targetString);
    cout << countTestUntilAcheive(targetString) << "\n";
    int testRepeats = 1000000;
    cout << repeatTest(testRepeats, targetString);
}

