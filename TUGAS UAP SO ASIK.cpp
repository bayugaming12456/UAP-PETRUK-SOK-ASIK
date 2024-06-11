#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <ncurses.h>
using namespace std;

class Kue {
private:
    string rasa;
    string ukuran;
    string deskripsi;
    double harga;
    vector<string> ukuranTersedia;

public:
    Kue(string _rasa, vector<string> _ukuranTersedia, string _deskripsi, double _harga)
        : rasa(_rasa), ukuran(""), deskripsi(_deskripsi), harga(_harga), ukuranTersedia(_ukuranTersedia) {

    }
    string getRasa() { return rasa; }
    vector<string> getUkuranTersedia() { return ukuranTersedia; }
    string getDeskripsi() { return deskripsi; }
    double getHarga() { return harga; }
    void setUkuran(string _ukuran) { ukuran = _ukuran; }
    string getUkuran() { return ukuran; }

    void tampilkan() {
        cout << "Item : " << rasa << ", Ukuran: " << ukuran << ", Deskripsi: " << deskripsi << ", Harga:Rp " << harga << endl;
    }

    void tampilkanDeskripsi() {
        cout << "Item : " << rasa << "";
        for (const auto& u : ukuranTersedia) {
            cout << u << " ";
        }
        cout << "" << deskripsi << "Harga:Rp " << harga << endl;
    }

    bool ukuranValid(string ukuran) {
        return find(ukuranTersedia.begin(), ukuranTersedia.end(), ukuran) != ukuranTersedia.end();
    }
    
};

class Pengguna {
private:
    string username;
    string password;

public:
    Pengguna(string _username, string _password) : username(_username), password(_password) {}

    string getUsername() { return username; }
    string getPassword() { return password; }
};

void daftarPengguna(vector<Pengguna>& pengguna) {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    pengguna.push_back(Pengguna(username, password));
    cout << "Pengguna berhasil didaftarkan!" << endl;
}
void tampilkanMenu(bool sudahDaftar, bool sudahLogin) {
    cout << "======= Menu =======\n";
    if (!sudahDaftar) {
        cout << "1. Daftar\n";
    }
    if (!sudahLogin) {
        cout << "2. Login\n";
    }
    cout << "3. Lihat Katalog Kue\n";
    cout << "4. Pesan Kue\n";
    cout << "5. Lihat Struk\n";
    cout << "6. Logout\n";
    cout << "0. Keluar\n";
    cout << "====================\n";
    cout << "Masukkan pilihan Anda: ";
}
