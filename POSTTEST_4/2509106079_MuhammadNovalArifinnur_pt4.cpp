#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
};

// Node Linked List
struct Node {
    Hewan data;
    Node* next;
};

// ===== QUEUE =====
Node *front = NULL, *rear = NULL;

// ===== STACK =====
Node *top = NULL;

// ================= QUEUE =================

// Enqueue
void enqueue(Hewan h) {
    Node* baru = new Node;
    baru->data = h;
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Masuk antrian\n";
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* hapus = front;
    Hewan h = hapus->data;

    cout << "Dipanggil: " << h.nama << " (" << h.id << ")\n";

    front = front->next;
    if (front == NULL) rear = NULL;

    delete hapus;

    // Masuk ke stack (riwayat)
    Node* baru = new Node;
    baru->data = h;
    baru->next = top;
    top = baru;
}

// Tampil Antrian
void tampilAntrian() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data.id << " | " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// ================= STACK =================

// Push (manual kalau mau)
void push(Hewan h) {
    Node* baru = new Node;
    baru->data = h;
    baru->next = top;
    top = baru;
}

// Pop
void pop() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* hapus = top;
    cout << "Hapus: " << hapus->data.nama << endl;

    top = top->next;
    delete hapus;
}

// Peek
void peek() {
    if (front != NULL)
        cout << "Antrian depan: " << front->data.nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != NULL)
        cout << "Riwayat terakhir: " << top->data.nama << endl;
    else
        cout << "Riwayat kosong\n";
}

// Tampil Riwayat
void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data.id << " | " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// MAIN

int main() {
    int pilih;

    // contoh data
    Hewan h1 = {1, "Kucing"};
    Hewan h2 = {2, "Anjing"};
    Hewan h3 = {3, "Kelinci"};

    do {
        cout << "\nMenu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat\n";
        cout << "5. Pop Riwayat\n";
        cout << "6. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                enqueue(h1);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilAntrian();
                break;
            case 4:
                tampilRiwayat();
                break;
            case 5:
                pop();
                break;
            case 6:
                peek();
                break;
        }

    } while (pilih != 0);

    return 0;
}