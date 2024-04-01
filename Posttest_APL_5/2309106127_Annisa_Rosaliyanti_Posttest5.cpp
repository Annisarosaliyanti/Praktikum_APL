#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur untuk data login
struct LoginData {
    string username;
    string password;
};

// Struktur untuk perabotan rumah tangga
struct Perabotan {
    string nama;
    string harga;
};

// Inisialisasi data login
vector<LoginData> data_login = {{"ocha", "127"}, {"ferdy", "122"}, {"ani", "134"}};

// Fungsi untuk melakukan login
bool login(int login_attempts = 3) {
    if (login_attempts == 0) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti." << endl;
        return false;
    }

    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Memeriksa apakah username dan password cocok dengan data login
    for (const auto& login : data_login) {
        if (login.username == username && login.password == password) {
            cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
            return true;
        }    }

    cout << "Login gagal. Silakan coba lagi." << endl;
    return login(login_attempts - 1);
}

// Prosedur untuk menampilkan menu utama
void showMainMenu() {
    cout << "\n=== PROGRAM CRUD PERABOTAN RUMAH TANGGA ===" << endl;
    cout << "1. Tambah Perabotan" << endl;
    cout << "2. Tampilkan Daftar Perabotan" << endl;
    cout << "3. Ubah Perabotan" << endl;
    cout << "4. Hapus Perabotan" << endl;
    cout << "5. Keluar" << endl;
}

// Fungsi untuk menambah perabotan
void addPerabotan(vector<Perabotan>& perabotan_rumah_tangga) {
    Perabotan perabotan;
    cout << "Masukkan nama perabotan: ";
    cin >> perabotan.nama;
    cout << "Masukkan harga perabotan: ";
    cin >> perabotan.harga;
    perabotan_rumah_tangga.push_back(perabotan);
    cout << "Perabotan berhasil ditambahkan." << endl;
}

// Prosedur untuk menampilkan daftar perabotan
void showPerabotan(const vector<Perabotan>& perabotan_rumah_tangga) {
    if (!perabotan_rumah_tangga.empty()) {
        cout << "\n=== DAFTAR PERABOTAN RUMAH TANGGA ===" << endl;
        for (size_t i = 0; i < perabotan_rumah_tangga.size(); ++i) {
            cout << i + 1 << ". Nama: " << perabotan_rumah_tangga[i].nama << ", Harga: " << perabotan_rumah_tangga[i].harga << endl;
        }
    } else {
        cout << "Belum ada perabotan yang ditambahkan." << endl;
    }
}

// Prosedur untuk mengubah perabotan
void editPerabotan(vector<Perabotan>& perabotan_rumah_tangga) {
    if (!perabotan_rumah_tangga.empty()) {
        int index;
        cout << "Masukkan nomor perabotan yang akan diubah: ";
        cin >> index;
        index--;

        if (index >= 0 && index < perabotan_rumah_tangga.size()) {
            Perabotan* perabotan = &perabotan_rumah_tangga[index];
            cout << "Masukkan nama perabotan baru: ";
            cin >> perabotan->nama;
            cout << "Masukkan harga perabotan baru: ";
            cin >> perabotan->harga;
            cout << "Perabotan berhasil diubah." << endl;
        } else {
            cout << "Nomor perabotan tidak valid." << endl;
        }
    } else {
        cout << "Belum ada perabotan yang ditambahkan." << endl;
    }
}

// Prosedur untuk menghapus perabotan
void deletePerabotan(vector<Perabotan>& perabotan_rumah_tangga) {
    if (!perabotan_rumah_tangga.empty()) {
        int index;
        cout << "Masukkan nomor perabotan yang akan dihapus: ";
        cin >> index;
        index--;

        if (index >= 0 && index < perabotan_rumah_tangga.size()) {
            cout << perabotan_rumah_tangga[index].nama << " telah dihapus dari daftar." << endl;
            perabotan_rumah_tangga.erase(perabotan_rumah_tangga.begin() + index);
        } else {
            cout << "Nomor perabotan tidak valid." << endl;
        }
    } else {
        cout << "Belum ada perabotan yang ditambahkan." << endl;
    }
}

int main() {
    cout << "SELAMAT DATANG" << endl;
    cout << "===================" << endl;

    bool logged_in = login();

    if (!logged_in) {
        return 0;
    }

    vector<Perabotan> perabotan_rumah_tangga;

    // Loop utama program setelah login
    while (true) {
        showMainMenu();

        int pilihan;
        cout << "Masukkan pilihan (1/2/3/4/5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                addPerabotan(perabotan_rumah_tangga);
                break;
            case 2:
                showPerabotan(perabotan_rumah_tangga);
                break;
            case 3:
                editPerabotan(perabotan_rumah_tangga);
                break;
            case 4:
                deletePerabotan(perabotan_rumah_tangga);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    }

    return 0;
}
