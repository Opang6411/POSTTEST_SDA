#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main() {
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array sebelum dibalik:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *(arr + i)
            << " | Alamat: " << (arr + i) << endl;
    }

    reverseArray(arr, n);

    cout << "\nArray setelah dibalik:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *(arr + i)
            << " | Alamat: " << (arr + i) << endl;
    }

    return 0;
}