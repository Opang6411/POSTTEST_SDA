#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

#define MAX 100

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

Hewan animals[MAX];
int jumlah = 0;

// Queue
Hewan antrian[MAX];
int front = -1, rear = -1;

// Stack
Hewan riwayat[MAX];
int top = -1;

// Swap
void swapData(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// Data awal
void dataAwal() {
    animals[0] = {1, "Kucing Persia", "Kucing", 1500000};
    animals[1] = {2, "Anjing Husky", "Anjing", 5000000};
    animals[2] = {3, "Kelinci", "Mamalia", 300000};
    animals[3] = {4, "Hamster", "Mamalia", 100000};
    animals[4] = {5, "Lovebird", "Burung", 250000};
    jumlah = 5;
}

// Tampil data
void tampilData() {
    Hewan *ptr = animals;

    if (jumlah == 0) {
        cout << "Data kosong\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << (ptr + i)->id << " | "
            << (ptr + i)->nama << " | "
            << (ptr + i)->jenis << " | "
            << (ptr + i)->harga << endl;
    }
}

// Sorting nama
void bubbleSortNama() {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (animals[j].nama > animals[j + 1].nama) {
                swapData(&animals[j], &animals[j + 1]);
            }
        }
    }
    cout << "Data diurutkan berdasarkan nama\n";
}

// Sorting harga
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
    cout << "Data diurutkan berdasarkan harga\n";
}

// Sorting ID
void sortByID() {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (animals[j].id > animals[j + 1].id) {
                swapData(&animals[j], &animals[j + 1]);
            }
        }
    }
}

// Linear search
void linearSearch() {
    cin.ignore();
    string cari;

    cout << "Masukkan nama: ";
    getline(cin, cari);

    for (int i = 0; i < jumlah; i++) {
        if (animals[i].nama == cari) {
            cout << "Data ditemukan\n";

            if (i != 0)
                swapData(&animals[i], &animals[0]);

            return;
        }
    }

    cout << "Data tidak ditemukan\n";
}

// Fibonacci search
int fibonacciSearch(int key) {
    int fibMMm2 = 0, fibMMm1 = 1;
    int fibM = fibMMm1 + fibMMm2;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        if (animals[i].id < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (animals[i].id > key) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && animals[offset + 1].id == key)
        return offset + 1;

    return -1;
}

// Enqueue
void enqueue(Hewan h) {
    if (rear == MAX - 1) {
        cout << "Antrian penuh\n";
        return;
    }

    if (front == -1) front = 0;

    antrian[++rear] = h;
    cout << "Masuk antrian\n";
}

// Dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong\n";
        return;
    }

    Hewan h = antrian[front++];

    cout << "Dipanggil: " << h.nama << " (" << h.id << ")\n";

    if (top == MAX - 1) {
        cout << "Riwayat penuh\n";
    } else {
        riwayat[++top] = h;
    }
}

// Tampil antrian
void tampilAntrian() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong\n";
        return;
    }

    Hewan *ptr = antrian;

    for (int i = front; i <= rear; i++) {
        cout << (ptr + i)->id << " | " << (ptr + i)->nama << endl;
    }
}

// Tampil riwayat
void tampilRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }

    Hewan *ptr = riwayat;

    for (int i = top; i >= 0; i--) {
        cout << (ptr + i)->id << " | " << (ptr + i)->nama << endl;
    }
}

// Pop riwayat
void popRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "Hapus: " << riwayat[top].nama << endl;
    top--;
}

// Peek
void peek() {
    if (front != -1 && front <= rear)
        cout << "Antrian depan: " << antrian[front].nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != -1)
        cout << "Riwayat terakhir: " << riwayat[top].nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// Pilih ke antrian
void pilihKeAntrian() {
    int id;
    cout << "Masukkan ID: ";
    cin >> id;

    for (int i = 0; i < jumlah; i++) {
        if (animals[i].id == id) {
            enqueue(animals[i]);
            return;
        }
    }

    cout << "Data tidak ditemukan\n";
}

// Main
int main() {
    int pilih;
    dataAwal();

    do {
        cout << "\nMenu\n";
        cout << "1. Tampil Data\n";
        cout << "2. Sort Nama\n";
        cout << "3. Sort Harga\n";
        cout << "4. Cari Nama\n";
        cout << "5. Cari ID\n";
        cout << "6. Masuk Antrian\n";
        cout << "7. Panggil\n";
        cout << "8. Tampil Antrian\n";
        cout << "9. Tampil Riwayat\n";
        cout << "10. Hapus Riwayat\n";
        cout << "11. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tampilData(); break;
            case 2: bubbleSortNama(); break;
            case 3: selectionSortHarga(); break;
            case 4: linearSearch(); break;

            case 5: {
                sortByID();
                int key;
                cout << "Masukkan ID: ";
                cin >> key;

                int idx = fibonacciSearch(key);

                if (idx != -1)
                    cout << "Data ditemukan: " << animals[idx].nama << endl;
                else
                    cout << "Data tidak ditemukan\n";
                break;
            }

            case 6: pilihKeAntrian(); break;
            case 7: dequeue(); break;
            case 8: tampilAntrian(); break;
            case 9: tampilRiwayat(); break;
            case 10: popRiwayat(); break;
            case 11: peek(); break;
        }

    } while (pilih != 0);

    return 0;
}