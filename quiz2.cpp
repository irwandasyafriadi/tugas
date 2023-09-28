#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan pertanyaan dan kunci jawaban
struct Question {
    string questionText;
    string choices[4];
    char correctAnswer;
};

// Fungsi untuk menguji jawaban peserta dan menghitung skor
int evaluateAnswer(const Question& q, int attempts) {
    char userAnswer;
    cout << q.questionText << endl;
    for (char option = 'A'; option <= 'D'; option++) {
        cout << option << ". " << q.choices[option - 'A'] << endl;
    }
    cout << "Pilih jawaban (A/B/C/D): ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);

    if (userAnswer == q.correctAnswer) {
        if (attempts == 1) return 2;
        else if (attempts == 2) return 1;
    }
    return 0;
}

int main() {
    // Array pertanyaan untuk masing-masing topik
    Question sejarahQuestions[4] = {
        {"Siapa penemu mesin cetak?", {"A. Johannes Gutenberg", "B. Thomas Edison", "C. Alexander Graham Bell", "D. Isaac Newton"}, 'A'},
        {"Kapan Perang Dunia I dimulai?", {"A. 1914", "B. 1917", "C. 1939", "D. 1945"}, 'A'},
        {"Apa nama faksi yang memenangkan Perang Saudara Amerika?", {"A. Konfederasi", "B. Sekutu", "C. Serikat", "D. Union"}, 'D'},
        {"Siapa presiden pertama Amerika Serikat?", {"A. George Washington", "B. Abraham Lincoln", "C. Thomas Jefferson", "D. Franklin D. Roosevelt"}, 'A'}
    };

    Question musikQuestions[4] = {
        {"Siapa penyanyi legendaris 'The Beatles'?", {"A. John Lennon", "B. Elvis Presley", "C. Michael Jackson", "D. Bob Dylan"}, 'A'},
        {"Apa instrumen yang dimainkan dalam sebuah orkestra?", {"A. Gitar", "B. Drum", "C. Biola", "D. Saxophone"}, 'C'},
        {"Apa nama album terlaris sepanjang masa?", {"A. Thriller", "B. The Wall", "C. Sgt. Pepper's Lonely Hearts Club Band", "D. Dark Side of the Moon"}, 'A'},
        {"Siapa penyanyi 'Thriller'?", {"A. Michael Jackson", "B. Freddie Mercury", "C. Prince", "D. Madonna"}, 'A'}
    };

    Question olahragaQuestions[4] = {
        {"Apa nama bola yang digunakan dalam sepak bola?", {"A. Basket", "B. Baseball", "C. Tenis", "D. Sepak Bola"}, 'D'},
        {"Siapa pemain basket terkenal yang dijuluki 'Air Jordan'?", {"A. Kobe Bryant", "B. LeBron James", "C. Shaquille O'Neal", "D. Michael Jordan"}, 'D'},
        {"Berapa jumlah pemain dalam tim baseball yang bermain secara bersamaan?", {"A. 5", "B. 9", "C. 11", "D. 7"}, 'B'},
        {"Siapa pembalap Formula 1 dengan gelar juara dunia terbanyak?", {"A. Ayrton Senna", "B. Lewis Hamilton", "C. Sebastian Vettel", "D. Michael Schumacher"}, 'B'}
    };

    cout << "Selamat datang di Quiz kita hari ini dengan topik:" << endl;
    cout << "1. Sejarah" << endl;
    cout << "2. Musik" << endl;
    cout << "3. Olahraga" << endl;

    int totalScore = 0;
    int totalQuestions = 0;

    for (int topic = 0; topic < 3; topic++) {
        Question* questions;
        string topicName;

        if (topic == 0) {
            questions = sejarahQuestions;
            topicName = "Sejarah";
        } else if (topic == 1) {
            questions = musikQuestions;
            topicName = "Musik";
        } else {
            questions = olahragaQuestions;
            topicName = "Olahraga";
        }

        cout << "\nTopik: " << topicName << endl;
        int topicScore = 0;

        for (int i = 0; i < 4; i++) {
            int attempts = 0;
            while (attempts < 2) {
                int earnedPoints = evaluateAnswer(questions[i], attempts + 1);
                if (earnedPoints > 0) {
                    topicScore += earnedPoints;
                    break;
                } else {
                    cout << "Jawaban salah. Coba lagi." << endl;
                    attempts++;
                }
            }
            totalQuestions++;
        }

        totalScore += topicScore;
        double percentage = (static_cast<double>(topicScore) / 8.0) * 100.0;
        cout << topicName << ": " << topicScore << "/8 (or " << percentage << "%)" << endl;
    }

    double overallPercentage = (static_cast<double>(totalScore) / static_cast<double>(totalQuestions * 2)) * 100.0;
    cout << "Total: " << totalScore << "/" << totalQuestions * 2 << " (or " << overallPercentage << "%)" << endl;

    return 0;
}
