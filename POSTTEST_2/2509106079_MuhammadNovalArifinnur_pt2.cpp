#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

Hewan animals[100];
int jumlah = 0;

void swapData(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambahData() {
    cout << "\n=== Tambah Data Hewan ===\n";

    cout << "ID: ";
    cin >> animals[jumlah].id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nama: ";
    getline(cin, animals[jumlah].nama);

    cout << "Jenis: ";
    getline(cin, animals[jumlah].jenis);

    cout << "Harga: ";
    cin >> animals[jumlah].harga;

    jumlah++;
    cout << "✔ Data berhasil ditambahkan!\n";
}

void tampilData() {
    Hewan *ptr = animals;

    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== Data Hewan ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID    : " << (ptr + i)->id << endl;
        cout << "Nama  : " << (ptr + i)->nama << endl;
        cout << "Jenis : " << (ptr + i)->jenis << endl;
        cout << "Harga : " << (ptr + i)->harga << endl;
        cout << "------------------------\n";
    }
}

void bubbleSortNama() {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (animals[j].nama > animals[j + 1].nama) {
                swapData(&animals[j], &animals[j + 1]);
            }
        }
    }
    cout << "✔ Data diurutkan berdasarkan nama!\n";
}

void selectionSortHarga() {
    for (int i = 0; i < jumlah - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (animals[j].harga < animals[minIndex].harga) {
                minIndex = j;
            }
        }
        swapData(&animals[i], &animals[minIndex]);
    }
    cout << "Data diurutkan berdasarkan harga!\n";
}

void sortByID() {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (animals[j].id > animals[j + 1].id) {
                swapData(&animals[j], &animals[j + 1]);
            }
        }
    }
}

void linearSearch() {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    string cari;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan nama hewan: ";
    getline(cin, cari);

    bool ketemu = false;

    for (int i = 0; i < jumlah; i++) {
        if (animals[i].nama == cari) {
            cout << "\nData ditemukan!\n";
            cout << "ID    : " << animals[i].id << endl;
            cout << "Nama  : " << animals[i].nama << endl;
            cout << "Jenis : " << animals[i].jenis << endl;
            cout << "Harga : " << animals[i].harga << endl;

            if (i != 0) {
                swapData(&animals[i], &animals[0]);
            }

            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
    }
}

int fibonacciSearch(int key) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        if (animals[i].id < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (animals[i].id > key) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            return i;
        }
    }

    if (fibMMm1 && offset + 1 < jumlah && animals[offset + 1].id == key)
        return offset + 1;

    return -1;
}

int main() {
    int pilihan;

    do {
        cout << "\n===== PAWCARE PETSHOP =====\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Nama (Linear Search)\n";
        cout << "4. Cari ID (Fibonacci Search)\n";
        cout << "5. Urutkan Nama (Bubble Sort)\n";
        cout << "6. Urutkan Harga (Selection Sort)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: linearSearch(); break;

            case 4: {
                if (jumlah == 0) {
                    cout << "Data kosong!\n";
                    break;
                }

                sortByID();

                int key;
                cout << "Masukkan ID: ";
                cin >> key;

                int index = fibonacciSearch(key);

                if (index != -1) {
                    cout << "\n✔ Data ditemukan!\n";
                    cout << "Nama  : " << animals[index].nama << endl;
                    cout << "Jenis : " << animals[index].jenis << endl;
                    cout << "Harga : " << animals[index].harga << endl;

                    if (index != 0) {
                        swapData(&animals[index], &animals[0]);
                    }
                } else {
                    cout << "Data tidak ditemukan!\n";
                }
                break;
            }

            case 5: bubbleSortNama(); break;
            case 6: selectionSortHarga(); break;

            case 0: cout << "Keluar program...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}