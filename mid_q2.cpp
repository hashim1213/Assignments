#include <simplecpp>

bool isPrime(int n) {
    if (n<= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

main_program {
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) {
        cout << "Input not validPlease enter an integer." << endl;
        return 0;
    }
    if (n < 2) {
        cout << "There are no prime numbers up to " << n << endl;
        return 0;
    }
    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout <<endl;
    return 0;
}
