#include <iostream>
#include <string>

using namespace std;

class Barang {
private:
    string nama;
    int harga;
    int stok;

public:
    Barang() {
        nama = "";
        harga = 0;
        stok = 0;
    }

    Barang(string n, int h, int s) {
        nama = n;
        harga = h;
        stok = s;
    }

    string getNama() {
        return nama;
    }

    int getHarga() {
        return harga;
    }

    int getStok() {
        return stok;
    }

    void kurangiStok(int jumlah) {
        if (jumlah <= stok) {
            stok -= jumlah;
        }
    }

    void tampilkanInfo(int nomor) {
        cout << nomor << ". " << nama << "\t| Rp " << harga << "\t| Stok: " << stok << endl;
    }
};

class Kasir {
private:
    string namaBarangBeli[20];
    int hargaSatuanBeli[20];
    int jumlahBeli[20];
    int totalHargaBeli[20];
    int jumlahJenisItem;
    int totalBelanja;

public:
    Kasir() {
        jumlahJenisItem = 0;
        totalBelanja = 0;
    }

    void tambahKeKeranjang(string nama, int harga, int qty) {
        namaBarangBeli[jumlahJenisItem] = nama;
        hargaSatuanBeli[jumlahJenisItem] = harga;
        jumlahBeli[jumlahJenisItem] = qty;
        totalHargaBeli[jumlahJenisItem] = harga * qty;

        totalBelanja += totalHargaBeli[jumlahJenisItem];
        jumlahJenisItem++;
    }

    int getTotalBelanja() {
        return totalBelanja;
    }

    int getJumlahJenisItem() {
        return jumlahJenisItem;
    }

    void cetakStruk(int uangBayar) {
        cout << "\n============================================\n";
        cout << "               STRUK BELANJA TOKO           \n";
        cout << "============================================\n";
        
        for (int i = 0; i < jumlahJenisItem; i++) {
            cout << "- " << namaBarangBeli[i] << endl;
            cout << "  " << jumlahBeli[i] << " x Rp " << hargaSatuanBeli[i] 
                 << " = Rp " << totalHargaBeli[i] << endl;
        }

        cout << "--------------------------------------------\n";
        cout << "Total Belanja : Rp " << totalBelanja << endl;
        cout << "Uang Tunai    : Rp " << uangBayar << endl;
        
        int kembalian = uangBayar - totalBelanja;
        cout << "Kembalian     : Rp " << kembalian << endl;
        cout << "============================================\n";
        cout << "          TERIMA KASIH TELAH BERBELANJA     \n";
        cout << "============================================\n";
    }
};

int main() {
    Barang katalog[3] = {
        Barang("Kopi Susu", 15000, 20),
        Barang("Roti Bakar", 12000, 15),
        Barang("Air Mineral", 5000, 50)
    };

    Kasir transaksi;
    int pilihan, qty, uang;
    char lanjut = 'y';

    cout << "=== SELAMAT DATANG DI APLIKASI KASIR ===" << endl;

    // Perulangan Menu Belanja
    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n--- KATALOG BARANG ---" << endl;
        for (int i = 0; i < 3; i++) {
            katalog[i].tampilkanInfo(i + 1);
        }

        cout << "\nPilih nomor barang yang ingin dibeli (1-3): ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 3) {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            continue;
        }

        int indexBarang = pilihan - 1;

        cout << "Masukkan jumlah yang ingin dibeli: ";
        cin >> qty;

        if (qty > katalog[indexBarang].getStok()) {
            cout << "[GAGAL] Stok tidak mencukupi! Sisa stok: " << katalog[indexBarang].getStok() << endl;
        } else if (qty <= 0) {
            cout << "[GAGAL] Jumlah beli harus lebih dari 0!\n";
        } else {

            katalog[indexBarang].kurangiStok(qty);

            transaksi.tambahKeKeranjang(
                katalog[indexBarang].getNama(),
                katalog[indexBarang].getHarga(),
                qty
            );

            cout << "[BERHASIL] " << qty << " " << katalog[indexBarang].getNama() << " ditambahkan ke keranjang.\n";
        }

        cout << "\nMau beli barang lain? (y/n): ";
        cin >> lanjut;
    }

    if (transaksi.getJumlahJenisItem() > 0) {
        cout << "\n--------------------------------------------\n";
        cout << "Total yang harus dibayar: Rp " << transaksi.getTotalBelanja() << endl;
        
        do {
            cout << "Masukkan jumlah uang tunai: Rp ";
            cin >> uang;

            if (uang < transaksi.getTotalBelanja()) {
                cout << "[GAGAL] Uang Anda kurang! Silakan masukkan ulang.\n";
            }
        } while (uang < transaksi.getTotalBelanja());

        transaksi.cetakStruk(uang);
    } else {
        cout << "\nAnda tidak membeli apa pun. Program selesai.\n";
    }

    return 0;
}
