#include <iostream>
#include <fstream>
using namespace std;

struct KTP {
    string nik;
    string nama;
    string tempatLahir;
    string tanggalLahir;
    string jenisKelamin;
    string alamat;
    string rt;
    string rw;
    string kelurahan;
    string kecamatan;
    string agama;
    string statusPerkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string berlakuHingga;
};

struct Pelanggan {
    string nik;
    string nama;
    string waktuKedatangan;
};

struct Barang {
    string kodeItem;
    string namaItem;
    string tanggalMasuk;
};

struct NodeBarang {
    Barang data;
    NodeBarang* next;
};

struct NodePelanggan {
    Pelanggan dataPelanggan;
    NodePelanggan* next;
};

KTP masukkanDataKTP() {
    KTP ktp;
    cout << "Masukkan Data Admin (KTP)\n";
    cout << "NIK              : ";
    cin >> ktp.nik;
    cin.ignore();
    cout << "Nama             : ";
    getline(cin, ktp.nama);
    cout << "Tempat Lahir     : ";
    getline(cin, ktp.tempatLahir);
    cout << "Tanggal Lahir    : ";
    getline(cin, ktp.tanggalLahir);
    cout << "Jenis Kelamin    : ";
    getline(cin, ktp.jenisKelamin);
    cout << "Alamat           : ";
    getline(cin, ktp.alamat);
    cout << "RT               : ";
    cin >> ktp.rt;
    cout << "RW               : ";
    cin >> ktp.rw;
    cin.ignore();
    cout << "Kelurahan        : ";
    getline(cin, ktp.kelurahan);
    cout << "Kecamatan        : ";
    getline(cin, ktp.kecamatan);
    cout << "Agama            : ";
    getline(cin, ktp.agama);
    cout << "Status Perkawinan: ";
    getline(cin, ktp.statusPerkawinan);
    cout << "Pekerjaan        : ";
    getline(cin, ktp.pekerjaan);
    cout << "Kewarganegaraan  : ";
    getline(cin, ktp.kewarganegaraan);
    cout << "Berlaku Hingga   : ";
    getline(cin, ktp.berlakuHingga);
    return ktp;
}

void simpanKeFileKTP(KTP ktp) {
    ofstream file("data_ktp.txt", ios::app);
    file << "====DATA ADMIN====\n";
    file << "nik              : " << ktp.nik << "\n";
    file << "nama             : " << ktp.nama << "\n";
    file << "tempat lahir     : " << ktp.tempatLahir << "\n";
    file << "tanggal lahir    : " << ktp.tanggalLahir << "\n";
    file << "jenis kelamin    : " << ktp.jenisKelamin << "\n";
    file << "alamat           : " << ktp.alamat << "\n";
    file << "RT               : " << ktp.rt << "\n";
    file << "RW               : " << ktp.rw << "\n";
    file << "kelurahan        : " << ktp.kelurahan << "\n";
    file << "kecamatan        : " << ktp.kecamatan << "\n";
    file << "agama            : " << ktp.agama << "\n";
    file << "status perkawinan: " << ktp.statusPerkawinan << "\n";
    file << "pekerjaan        : " << ktp.pekerjaan << "\n";
    file << "kewarganegaraan  : " << ktp.kewarganegaraan << "\n";
    file << "berlaku hingga   : " << ktp.berlakuHingga << "\n";
    file << "========================\n";
    file.close();
    cout << "Data KTP berhasil disimpan!" << endl;
}

void tampilkanDataKTP(KTP* daftarKTP, int jumlah) {
    for (int i = 0; i < jumlah; ++i) {
        cout << "====DATA ADMIN KE-" << i + 1 << "====\n";
        cout << "nik              : " << daftarKTP[i].nik << "\n";
        cout << "nama             : " << daftarKTP[i].nama << "\n";
        cout << "tempat lahir     : " << daftarKTP[i].tempatLahir << "\n";
        cout << "tanggal lahir    : " << daftarKTP[i].tanggalLahir << "\n";
        cout << "jenis kelamin    : " << daftarKTP[i].jenisKelamin << "\n";
        cout << "alamat           : " << daftarKTP[i].alamat << "\n";
        cout << "RT               : " << daftarKTP[i].rt << "\n";
        cout << "RW               : " << daftarKTP[i].rw << "\n";
        cout << "kelurahan        : " << daftarKTP[i].kelurahan << "\n";
        cout << "kecamatan        : " << daftarKTP[i].kecamatan << "\n";
        cout << "agama            : " << daftarKTP[i].agama << "\n";
        cout << "status perkawinan: " << daftarKTP[i].statusPerkawinan << "\n";
        cout << "pekerjaan        : " << daftarKTP[i].pekerjaan << "\n";
        cout << "kewarganegaraan  : " << daftarKTP[i].kewarganegaraan << "\n";
        cout << "berlaku hingga   : " << daftarKTP[i].berlakuHingga << "\n";
        cout << "========================\n";
        cout << endl;
    }
}

NodeBarang* top = NULL;
void tambahKeBarang(Barang brg) {
    NodeBarang* nodeBaru = new NodeBarang;
    nodeBaru->data = brg;
    nodeBaru->next = top;
    top = nodeBaru;
}

bool apakahBarangKosong() {
    return top == NULL;
}

Barang ambilDariBarang() {
    if (!apakahBarangKosong()) {
        NodeBarang* temp = top;
        Barang data = temp->data;
        top = top->next;
        delete temp;	
        return data;
    }
    Barang kosong;
    return kosong;
}

void tampilkanBarang() {
    NodeBarang* current = top;
    cout << "\nDaftar Barang dalam Gudang (LIFO):\n";
    cout << "Kode Item\tNama Item\tTanggal Masuk\n";
    while (current != NULL) {
        cout << current->data.kodeItem << "\t\t";
        cout << current->data.namaItem << "\t\t";
        cout << current->data.tanggalMasuk << endl;
        current = current->next;
    }
}

NodePelanggan* head = NULL;
NodePelanggan* tail = NULL;
void tambahkanKeAntrian(Pelanggan pelanggan) {
    NodePelanggan* nodeBaru = new NodePelanggan;
    nodeBaru->dataPelanggan = pelanggan;
    nodeBaru->next = NULL;

    if (head == NULL) {
        head = tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
    }
}

bool apakahAntrianKosong() {
    return head == NULL;
}

Pelanggan ambilDariAntrian() {
    if (!apakahAntrianKosong()) {
        NodePelanggan* temp = head;
        Pelanggan data = temp->dataPelanggan;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        return data;
    }
    Pelanggan kosong;
    return kosong;
}

void tampilkanAntrian() {
    NodePelanggan* current = head;
    cout << "\nDaftar Antrian Pembeli:\n";
    while (current != NULL) {
        cout << "NIK: " << current->dataPelanggan.nik << endl;
        cout << "Nama: " << current->dataPelanggan.nama << endl;
        cout << "Waktu Kedatangan: " << current->dataPelanggan.waktuKedatangan << endl;
        cout << "------------------------" << endl;
        current = current->next;
    }
}


bool periksaKTP(const string& username) {
    ifstream file("data_ktp.txt");
    if (!file.is_open()) {
        cerr << "File data_ktp.txt tidak ditemukan" << endl;
        return false;
    }

    string line;
    bool ditemukan = false;

    while (getline(file, line)) {
        if (line.find("nama             : ") == 0) {
            string name = line.substr(19);  // Mengambil nama setelah "nama             : "
            if (name == username) {
                ditemukan = true;
                break;
            }
        }
    }

    file.close();
    return ditemukan;
}

int main() {
    string nik, nama;
    int pilihan, banyak;
    bool sudahLogin = false;
    int jumlahKTP = 0;
    KTP* daftarKTP = new KTP[100]; 

    cout << "Masukan Jumlah Admin : ";
    cin >> banyak;
    cin.ignore(); 

    for (int i = 0; i < banyak; i++) {
        cout << "DATA KE " << i + 1 << endl;
        KTP ktp = masukkanDataKTP();  
        simpanKeFileKTP(ktp); 
        daftarKTP[jumlahKTP++] = ktp;  
        cout << endl;
    }
    
    tampilkanDataKTP(daftarKTP, jumlahKTP);
    cout << endl;
    
    

    while (!sudahLogin) {
        cout << "=== Login Admin ===\n";
        cout << "Masukkan Nama: ";
        getline(cin, nama); 

        if (periksaKTP(nama)) {
            cout << "Login berhasil!\n";
            sudahLogin = true;
        } else {
            cout << "Data KTP tidak ditemukan.\n";
            cout << "Silakan daftar terlebih dahulu.\n";
            
            KTP ktpBaru = masukkanDataKTP(); 
            simpanKeFileKTP(ktpBaru); 

            cout << "Registrasi berhasil! Silakan login kembali.\n";
        }
    }

    do {
        cout << "\nMenu Sistem Inventori dan Antrian\n";
        cout << "1. Entri Item Barang\n";
        cout << "2. Catat Pembeli\n";
        cout << "3. Jual Item Barang\n";
        cout << "4. Cetak Daftar Barang\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Barang brg;
                int input;
                cout <<"Masukan jumlah barang : ";
                cin >> input;
                for(int i =1 ; i <= input ; i++){
                    cout << "\nMasukkan Data Barang ke- "<<i<<endl;
                    cout << "Kode Item: ";
                    cin >> brg.kodeItem;
                    cin.ignore();
                    cout << "Nama Item: ";
                    getline(cin, brg.namaItem);
                    cout << "Tanggal Masuk (YYYY-MM-DD): ";
                    getline(cin, brg.tanggalMasuk);
                    tambahKeBarang(brg);
                    cout << "Barang berhasil ditambahkan ke inventori.\n";
                }
                break;
            }
            case 2: {
                Pelanggan pelanggan;  
                cout << "Masukkan Data Pembeli\n";
                cout << "NIK: ";
                cin >> pelanggan.nik;
                cin.ignore();
                cout << "Nama: ";
                getline(cin, pelanggan.nama);
                cout << "Waktu Kedatangan (jam:menit): ";
                getline(cin, pelanggan.waktuKedatangan); 
                tambahkanKeAntrian(pelanggan);
                cout << "Pembeli berhasil dicatat dan masuk antrian.\n";
                break;
            }
            case 3: {
                if (!apakahAntrianKosong() && !apakahBarangKosong()) {
                    Pelanggan pelanggan = ambilDariAntrian(); 
                    Barang barang = ambilDariBarang(); 
                    cout << "\nTransaksi Penjualan\n";
                    cout << "Pembeli: " << pelanggan.nama << endl;
                    cout << "Barang: " << barang.kodeItem << " - " << barang.namaItem << endl;
                    cout << "Transaksi berhasil.\n";
                } else {
                    cout << "Antrian kosong atau tidak ada barang tersedia.\n";
                }
                break;
            }
            case 4: {
                tampilkanBarang();
                break;
            }
            case 5: {
                cout << "Terima kasih telah menggunakan sistem.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid.\n";
                break;
            }
        }
    } while (pilihan != 5);

    delete[] daftarKTP;
    return 0;
}
