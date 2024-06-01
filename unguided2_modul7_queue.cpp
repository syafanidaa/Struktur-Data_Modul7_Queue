#include <iostream>
using namespace std;

// Struktur untuk merepresentasikan setiap elemen dalam linked list
struct Node {
    string nama;
    string nim;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer ke depan antrian
    Node* back;  // Pointer ke belakang antrian
public:
    Queue() {
        front = NULL;
        back = NULL;
    }

    // Fungsi menambahkan elemen ke belakang antrian (enqueue)
    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = NULL;
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        cout << "Antrian ditambahkan: Nama: " << nama << ", NIM: " << nim << endl;
    }

    // Fungsi menghapus elemen dari depan antrian (dequeue)
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "Antrian dihapus: Nama: " << front->nama << ", NIM: " << front->nim << endl;
        front = front->next;
        delete temp;
    }

    // Fungsi menghitung banyak elemen dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi menghapus semua elemen dari antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
        cout << "Antrian dikosongkan" << endl;
    }

    // Fungsi untuk melihat antrian
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int position = 1;
        while (current != NULL) {
            cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            position++;
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue antrian;
    antrian.enqueueAntrian("SYAFANIDA KHAKIKI", "2311102005");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    return 0;
}