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

// ===== QUEUE =====
Hewan antrian[100];
int front = -1, rear = -1;

// ===== STACK =====
Hewan riwayat[100];
int top = -1;

// ===== SWAP =====
void swapData(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// ===== TAMBAH DATA =====
void tambahData() {
    if (jumlah >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\n=== Tambah Data Hewan ===\n";

    cout << "ID: ";
    cin >> animals[jumlah].id;
    cin.ignore();

    cout << "Nama: ";
    getline(cin, animals[jumlah].nama);

    cout << "Jenis: ";
    getline(cin, animals[jumlah].jenis);

    cout << "Harga: ";
    cin >> animals[jumlah].harga;

    jumlah++;
    cout << "Data berhasil ditambahkan!\n";
}

// ===== TAMPIL DATA =====
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
        cout << "----------------------\n";
    }
}

// ===== QUEUE =====
void enqueue() {
    if (rear == 99) {
        cout << "Antrian penuh!\n";
        return;
    }

    int id;
    cout << "Masukkan ID hewan: ";
    cin >> id;

    for (int i = 0; i < jumlah; i++) {
        if (animals[i].id == id) {
            if (front == -1) front = 0;
            rear++;
            antrian[rear] = animals[i];

            cout << "Hewan masuk antrian!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan!\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan pasien = antrian[front];
    cout << "Memanggil: " << pasien.nama << " (ID: " << pasien.id << ")\n";

    // push ke stack (riwayat)
    if (top < 99) {
        top++;
        riwayat[top] = pasien;
    }

    front++;
}

void tampilAntrian() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan *ptr = antrian;

    cout << "\n=== Antrian ===\n";
    for (int i = front; i <= rear; i++) {
        cout << (ptr + i)->nama << " (ID: " << (ptr + i)->id << ")\n";
    }
}

// ===== STACK =====
void pushRiwayat(Hewan data) {
    if (top == 99) {
        cout << "Stack penuh!\n";
        return;
    }
    top++;
    riwayat[top] = data;
}

void popRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Menghapus riwayat: " << riwayat[top].nama << endl;
    top--;
}

void tampilRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *ptr = riwayat;

    cout << "\n=== Riwayat Tindakan ===\n";
    for (int i = top; i >= 0; i--) {
        cout << (ptr + i)->nama << " (ID: " << (ptr + i)->id << ")\n";
    }
}

// ===== PEEK =====
void peek() {
    cout << "\n=== PEEK ===\n";

    if (front != -1 && front <= rear) {
        cout << "Antrian depan: " << antrian[front].nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (top != -1) {
        cout << "Riwayat terakhir: " << riwayat[top].nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

// ===== MAIN =====
int main() {
    int pilihan;

    do {
        cout << "\n===== PAWCARE PETSHOP =====\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Masuk Antrian (Enqueue)\n";
        cout << "4. Panggil Pasien (Dequeue)\n";
        cout << "5. Tampilkan Antrian\n";
        cout << "6. Tampilkan Riwayat\n";
        cout << "7. Hapus Riwayat (Pop)\n";
        cout << "8. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: tampilAntrian(); break;
            case 6: tampilRiwayat(); break;
            case 7: popRiwayat(); break;
            case 8: peek(); break;
            case 0: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}