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
void lihatKatalog(vector<Kue>& katalog) {
    system("clear");
    cout << "Katalog Kue:" << endl;
    for (auto& kue : katalog) {
        kue.tampilkanDeskripsi();
    }
    cin.ignore(); 
    cin.get();   
}

Pengguna* loginPengguna(vector<Pengguna>& pengguna) {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    for (auto& pengguna : pengguna) {
        if (pengguna.getUsername() == username && pengguna.getPassword() == password) {
            cout << "Login berhasil!" << endl;
            return &pengguna;
        }
    }

    cout << "Username atau password Salah. Silakan coba lagi." << endl;
    return nullptr;
}

void tampilkanKatalog(vector<Kue>& katalog) {
    cout << "Menu Kue:" << endl;
    for (auto& kue : katalog) {
        kue.tampilkanDeskripsi();
    }
}

void pesanKue(Pengguna* pengguna, vector<Kue>& katalog, stack<Kue>& tumpukanPesan) {
    if (pengguna == nullptr) {
        cout << "Silakan login terlebih dahulu!" << endl;
        return;
    }

    tampilkanKatalog(katalog);

    string rasa, ukuran;
    cout << "Masukkan kue: ";
    cin >> rasa;

  
    auto it = find_if(katalog.begin(), katalog.end(), [&rasa](Kue& kue) {
        return kue.getRasa() == rasa;
    });

    if (it != katalog.end()) {
        cout << "Masukkan ukuran kue Tersedia ( ";
        for (const auto& u : it->getUkuranTersedia()) {
            cout << u << " ";
        }
        cout << "): ";
        cin >> ukuran;

        if (it->ukuranValid(ukuran)) {
            Kue kueDipilih = *it;
            kueDipilih.setUkuran(ukuran);
            tumpukanPesan.push(kueDipilih);
            cout << "Pemesanan berhasil!" << endl;
        } else {
            cout << "Ukuran tidak tersedia. Pemesanan gagal." << endl;
        }
    } else {
        cout << "Kue tersebut tidak ditemukan. Pemesanan gagal." << endl;
        
    }
    cin.ignore(); 
    cin.get();   
}

void tampilkanStruk(stack<Kue>& tumpukanPesan) {
    cout << "Struk Pembelian:" << endl;
    while (!tumpukanPesan.empty()) {
        tumpukanPesan.top().tampilkan();
        tumpukanPesan.pop();
    }
}

