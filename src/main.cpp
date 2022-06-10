#include <iostream>
#include <vector>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

void addMahasiswa();
void addDosen();
void addTendik();

vector<mahasiswa> recMhs;
vector<dosen> recDosen;
vector<tendik> recTendik;

//int argc, char** argv
int main()
{
	int menu_terpilih;
	int choice;

	while(1) {
	menu:
		cout << "Selamat datang di Narindrans University" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tenaga kependidikan" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  0. Tutup Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cout << endl;

		switch (menu_terpilih) {
			case 0:
				return 0;
				break;
				
			case 1:
				choice = 0;

				menumhs:
				cout << "1. Tambah Mahasiswa" << endl;
				cout << "2. Kembali ke menu" << endl;
				cout << "Pilihan: ";
				cin >> choice;
				cout << endl;

				switch(choice) {
					case 1:
						addMahasiswa();
						cout << endl;
						goto menu;
						break;
					case 2:
						goto menu;
						break;
					default:
						cout << "Input salah!" << endl;
						goto menumhs;
						break;
				}
				break;

			case 2:
				choice = 0;

				menudosen:
				cout << "1. Tambah Dosen" << endl;
				cout << "2. Kembali ke menu" << endl;
				cout << "Pilihan: ";
				cin >> choice;
				cout << endl;

				switch(choice){
					case 1:
						addDosen();
						cout << endl;
						goto menu;
						break;
					case 2:
						goto menu;
						break;
					default:
						cout << "Input Salah!" << endl;
						goto menudosen;
						break;
				}
				break;

			case 3:
				choice = 0;

				menutendik:
				cout << "1. Tambah Tenaga Pendidik" << endl;
				cout << "2. Kembali ke menu" << endl;
				cout << "Pilihan; ";
				cin >> choice;
				cout << endl;

				switch(choice){
					case 1:
						addTendik();
						cout << endl;
						goto menu;
						break;
					case 2:
						goto menu;
						break;
					default:
						cout << "Input Salah!" << endl;
						goto menutendik;
						break;
				}
				break;

			case 4:
				if (recMhs.empty() == true){
					choice = 0;
					cout << "Tidak ada mahasiswa terdaftar! Tambahkan mahasiswa?" << endl;
					cout << "1. Tambahkan Mahasiswa" << endl;
					cout << "2. Kembali ke menu" << endl;
					cout << "Pilihan: ";
					cin >> choice;
					cout << endl;

					switch(choice){
						case 1:
							addMahasiswa();
							cout << endl;
							goto menu;
							break;
						case 2:
							goto menu;
							break;
						default:
							goto menu;
							break;
					}
				}
				else{
					cout << "===============================================================" << endl;
					cout << "Semua Mahasiswa:" << endl;
					for (long unsigned int i = 0; i < recMhs.size(); i++){
						cout << "Mahasiswa ke-" << i+1 << ": " << endl;
						cout << "ID		: " << recMhs[i].getId() << endl;
						cout << "Nama		: " << recMhs[i].getNama() << endl;
						cout << "Tanggal Lahir	: " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
						cout << "NRP		: " << recMhs[i].getNRP() << endl;
						cout << "Tahun Masuk	: " << recMhs[i].getTahun() << endl;
						cout << "Semester ke-	: " << recMhs[i].getSemester() << endl;
						cout << "Mata Kuliah	: " << endl;
						vector<string> temp_matkul = recMhs[i].getMatkul();
						for (long unsigned int j = 0; j < temp_matkul.size(); j++){
							cout << j+1 << ". " << temp_matkul[j] << endl;
						}
						cout << "SKS Lulus	: " << recMhs[i].getSKSLulus() << endl;
						cout << endl;
					}
					cout << "===============================================================" << endl;
					cout << endl;
					goto menu;
				}
				break;

			case 5:
				if (recDosen.empty() == true){
					choice = 0;
					cout << "Tidak ada dosen terdaftar! Tambahkan dosen?" << endl;
					cout << "1. Tambahkan Dosen" << endl;
					cout << "2. Kembali ke menu" << endl;
					cout << "Pilihan: ";
					cin >> choice;
					cout << endl;

					switch(choice){
						case 1:
							addDosen();
							cout << endl;
							goto menu;
							break;
						case 2:
							goto menu;
							break;
					}
				}
				else{
					cout << "===============================================================" << endl;
					cout << "Semua Dosen: " << endl;
					for (long unsigned int i = 0; i < recDosen.size(); i++){
						cout << "Dosen ke-" << i+1 << ": " << endl;
						cout << "ID		: " << recDosen[i].getId() << endl;
						cout << "Nama		: " << recDosen[i].getNama() << endl;
						cout << "Tanggal Lahir	: " << recDosen[i].getTglLahir() << "/" << recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
						cout << "NPP		: " << recDosen[i].getNPP() << endl;
						cout << "Departemen	: " << recDosen[i].getDepartemen() << endl;
						cout << "Mata Kuliah	: " << recDosen[i].getMatkulAjar() << endl;
						cout << "Pendidikan	: " << recDosen[i].getPendidikan() << endl;
						cout << endl;
					}
					cout << "===============================================================" << endl;
					cout << endl;
					goto menu;
				}
				break;

			case 6:
				if (recTendik.empty() == true){
					choice = 0;
					cout << "Tidak ada Tenaga Didik terdaftar! Tambahkan tendik?" << endl;
					cout << "1. Tambahkan Tendik" << endl;
					cout << "2. Kembali ke menu" << endl;
					cout << "Pilihan: ";
					cin >> choice;
					cout << endl;

					switch(choice){
						case 1:
							addTendik();
							cout << endl;
							goto menu;
							break;
						case 2:
							goto menu;
							break;
					}
				}
				else{
					cout << "===============================================================" << endl;
					cout << "Semua Tenaga Pendidikan: " << endl;
					for (long unsigned int i = 0; i < recTendik.size(); i++){
						cout << "Tendik ke-" << i+1 << ": " << endl;
						cout << "ID		: " << recTendik[i].getId() << endl;
						cout << "Nama		: " << recTendik[i].getNama() << endl;
						cout << "Tanggal Lahir	: " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
						cout << "NPP		: " << recTendik[i].getNPP() << endl;
						cout << "Unit		: " << recTendik[i].getUnit() << endl;
						cout << endl;
					}
					cout << "===============================================================" << endl;
					cout << endl;
					goto menu;
				}
				break;
		}
	}

	return 0;
}

void addMahasiswa(){
	string id, nama;
	int dd, mm, yy;

	vector<string> matkul;
	string nrp, departemen;
	int tahunmasuk, semester, skslulus, jmatkul;
	float ipk, ips;

	cout << "Masukkan ID: ";
	cin >> id;
	cout << "Masukkan Nama: ";
	cin.ignore();
	getline(cin, nama);
	cout << "Masukkan Tanggal Lahir: ";
	cin >> dd;
	cout << "Masukkan Bulan Lahir: ";
	cin >> mm;
	cout << "Masukkan Tahun Lahir: ";
	cin >> yy;

	cout << "Masukkan NRP: ";
	cin >> nrp;
	cout << "Masukkan Departemen: ";
	cin.ignore();
	getline(cin, departemen);
	cout << "Masukkan Jumlah Mata Kuliah Terdaftar: ";
	cin >> jmatkul;
	cin.ignore();
	for (int i = 0; i < jmatkul; i++){
		string temp;
		cout << "Mata Kuliah ke-" << i+1 << ": ";
		getline(cin, temp);
		matkul.push_back(temp);
	}
	cout << "Masukkan Tahun Masuk: ";
	cin >> tahunmasuk;
	cout << "Masukkan Semester Sekarang: ";
	cin >> semester;
	cout << "Masukkan SKS Lulus: ";
	cin >> skslulus;
	cout << "Masukkan IPK: ";
	cin >> ipk;
	cout << "Masukkan IPS: ";
	cin >> ips;

	mahasiswa newMahasiswa(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, matkul);
	recMhs.push_back(newMahasiswa);

	cout << "Mahasiswa berhasil ditambahkan!" << endl;
}

void addDosen(){
	string id, nama;
	int dd, mm, yy;

	string npp, departemen, pendidikan, matkulajar;

	cout << "Masukkan ID: ";
	cin >> id;
	cout << "Masukkan Nama: ";
	cin.ignore();
	getline(cin, nama);
	cout << "Masukkan Tanggal Lahir: ";
	cin >> dd;
	cout << "Masukkan Bulan Lahir: ";
	cin >> mm;
	cout << "Masukkan Tahun Lahir: ";
	cin >> yy;

	cout << "Masukkan NPP: ";	
	cin >> npp;
	cout << "Masukkan Departemen: ";
	cin.ignore();
	getline(cin, departemen);
	cout << "Masukan Mata Kuliah Diajarkan: ";
	getline(cin, matkulajar);
	cout << "Masukkan Pendidikan: ";
	getline(cin, pendidikan);

	dosen newDosen(id, nama, dd, mm, yy, npp, departemen, pendidikan, matkulajar);
	recDosen.push_back(newDosen);

	cout << "Dosen berhasil ditambahkan!" << endl;
}

void addTendik(){
	string id, nama;
	int dd, mm, yy;

	string npp, unit;

	cout << "Masukkan ID: ";
	cin >> id;
	cout << "Masukkan Nama: ";
	cin.ignore();
	getline(cin, nama);
	cout << "Masukkan Tanggal Lahir: ";
	cin >> dd;
	cout << "Masukkan Bulan Lahir: ";
	cin >> mm;
	cout << "Masukkan Tahun Lahir: ";
	cin >> yy;

	cout << "Masukkan NPP: ";
	cin >> npp;
	cout << "Masukkan Unit: ";
	cin.ignore();
	getline(cin, unit);

	tendik newTendik(id, nama, dd, mm, yy, npp, unit);
	recTendik.push_back(newTendik);

	cout << "Tenaga pendidik berhasil ditambahkan!" << endl;
}