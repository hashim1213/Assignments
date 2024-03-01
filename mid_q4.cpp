#include <simplecpp>
main_program {
    string n;
    cout << "Enter a word to check if it is a palindrome: ";
    cin >> n;

    bool palindrome = true;
    int length = n.length();
    for (int i = 0; i < length / 2; i++) {
        if (n[i] != n[length - i - 1]) {
            palindrome = false;
            break;
        }
    }

    if (palindrome) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }
}

