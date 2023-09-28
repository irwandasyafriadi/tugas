#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    char playAgain;

    cout << "Selamat datang di game melempar dadu!" << endl;

    do {
        int userGuess, computerGuess, attempts = 0;

        cout << "Masukkan angka tebakan anda (1-6): ";
        cin >> userGuess;

        if (userGuess < 1 || userGuess > 6) {
            cout << "Angka tebakan harus berada di antara 1 dan 6." << endl;
            continue;
        }

        do {
            computerGuess = rand() % 6 + 1;
            attempts++;
            cout << "Lemparan " << attempts << " adalah " << computerGuess << endl;
        } while (computerGuess != userGuess);

        cout << "Komputer mencoba " << attempts << " kali untuk menebak angka " << userGuess << endl;

        cout << "Apakah anda mau bermain lagi? 'Y' atau 'N'? ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Goodbye" << endl;

    return 0;
}
