#include <simplecpp>

main_program{
    int score = 0;
    // Question 1
    cout << "What is the capital of France?" << endl;
    cout << "a) Berlin" << endl;
    cout << "b) Paris" << endl;
    cout << "c) Rome" << endl;
    cout << "d) Madrid" << endl;

    char answer;
    cin >> answer;

    if (answer == 'b') {
        cout << "Correct!" << endl;
        score++;
    } else {
        cout << "Incorrect!" << endl;
    }

    cout << "Score: " << score << endl;

    // Question 2
    cout << "How many continents are there?" << endl;
    cout << "a) 5" << endl;
    cout << "b) 6" << endl;
    cout << "c) 7" << endl;
    cout << "d) 8" << endl;

    char answer2;
    cin >> answer2;

    if (answer2 == 'c') {
        cout << "Correct!" << endl;
        score++;
    } else {
        cout << "Incorrect!" << endl;
    }
        cout << "Final Score: " << score <<"/2"<< endl;
        return 0;
}
