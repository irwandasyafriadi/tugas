#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Untuk menghasilkan angka acak yang berbeda setiap kali program dijalankan
    int numSegments;

    cout << "Berapa jumlah segmen garis yang diinginkan? ";
    cin >> numSegments;

    if (numSegments <= 0) {
        cout << "Jumlah segmen garis harus lebih dari 0." << endl;
        return 1;
    }

    int totalSegments = 0;
    double totalLength = 0.0;
    double x1, y1, x2, y2;

    while (totalSegments < numSegments) {
        // Meminta pengguna untuk memasukkan koordinat titik pertama
        cout << "\nMasukkan koordinat titik pertama (x1 y1): ";
        cin >> x1 >> y1;

        // Bangkitkan koordinat titik kedua secara acak dalam rentang -10 hingga 10
        x2 = -10 + rand() % 21;
        y2 = -10 + rand() % 21;

        // Menghindari kasus ketika kedua titik berada di titik yang sama
        if (x1 == x2 && y1 == y2) continue;

        // Menghitung panjang segmen garis
        double length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        // Menampilkan informasi tentang segmen garis
        cout << "\nSegmen Garis #" << totalSegments + 1 << ":" << endl;
        cout << "Titik Pertama: (" << x1 << ", " << y1 << ")" << endl;
        cout << "Titik Kedua: (" << x2 << ", " << y2 << ")" << endl;
        cout << "Panjang: " << length << endl;

        // Menghitung kemiringan (slope) jika x1 dan x2 tidak sama
        if (x1 != x2) {
            double slope = (y2 - y1) / (x2 - x1);
            cout << "Kemiringan (Slope): " << slope << endl;
        } else {
            cout << "Kemiringan (Slope) adalah undefined (x1 == x2)." << endl;
        }

        totalLength += length;
        totalSegments++;
    }

    if (totalSegments > 0) {
        double averageLength = totalLength / totalSegments;
        cout << "\nPanjang Rata-rata dari Seluruh Segmen Garis: " << averageLength << endl;
    } else {
        cout << "\nTidak ada segmen garis yang dihitung." << endl;
    }

    return 0;
}
