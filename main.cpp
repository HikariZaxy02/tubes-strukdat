#include <iostream>
#include "anime.h"

using namespace std;

int main() {
    adrUser ListU;
    adrAnime ListA;

    createListUser(ListU);
    createListAnime(ListA);

    InfotypeU u1 = {1, "AhmadZaky", "zaky@mail.com"};
    insertUser(ListU, createElementUser(u1));
    InfotypeU u2 = {2, "SabilFairus", "sabil@mail.com"};
    insertUser(ListU, createElementUser(u2));

    InfotypeA a1 = {101, "Naruto_Shippuden", "Pierrot", "Action", 500, 8.7f, 2007};
    insertAnime(ListA, createElementAnime(a1));
    InfotypeA a2 = {102, "Attack_On_Titan", "MAPPA", "Fantasy", 80, 9.0f, 2013};
    insertAnime(ListA, createElementAnime(a2));

    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. ADMIN: Kelola User & Anime" << endl;
        cout << "2. USER: Buat Review" << endl;
        cout << "3. REPORT: Lihat Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: "; cin >> pilihan;

        if (pilihan == 1) {
            int pAdm;
            cout << "\n--- ADMIN MENU ---" << endl;
            cout << "1. Tambah User" << endl;
            cout << "2. Tambah Anime" << endl;
            cout << "3. Hapus User" << endl;
            cout << "4. Hapus Anime" << endl;
            cout << "Pilih: "; cin >> pAdm;

            if (pAdm == 1) {
                InfotypeU data;
                cout << "ID: "; cin >> data.idUser;
                cout << "Username: "; cin >> data.username;
                cout << "Email: "; cin >> data.email;
                insertUser(ListU, createElementUser(data));
                cout << "User berhasil ditambahkan!" << endl;
            } else if (pAdm == 2) {
                InfotypeA data;
                cout << "ID Anime: "; cin >> data.idAnime;
                cout << "Judul (Gunakan_Underscore): "; cin >> data.judul;
                cout << "Studio: "; cin >> data.studio;
                cout << "Genre: "; cin >> data.genre;           // TAMBAH
                cout << "Total Episode: "; cin >> data.total_eps; // TAMBAH
                cout << "Rating Global: "; cin >> data.rating_global; // TAMBAH
                cout << "Tahun: "; cin >> data.tahun_rilis;
                insertAnime(ListA, createElementAnime(data));
                cout << "Anime berhasil ditambahkan!" << endl;
            } else if (pAdm == 3) {
                string nm; cout << "Username dihapus: " << endl;
                cin >> nm;
                deleteUser(ListU, nm);
            } else if (pAdm == 4) {
                string jd; cout << "Judul Anime dihapus: " << endl;
                cin >> jd;
                deleteAnime(ListA, ListU, jd);
            }
        } else if (pilihan == 2) {
            string loginName;
            cout << "Login Username: "; cin >> loginName;
            adrUser P = findUser(ListU, loginName);

            if (P != NULL) {
                cout << "Login berhasil: " << P->info.username << endl;
                string jdl;
                cout << "Masukkan Judul Anime yang akan di-review: "; cin >> jdl;
                adrAnime A = findAnime(ListA, jdl);

                if (A != NULL) {
                    InfotypeR rev;
                    cout << "Rating (1-10): ";
                    cin >> rev.rating;
                    cout << "Komentar (Satu_Kata): ";
                    cin >> rev.komentar;
                    rev.tanggal_review = "2024-01-01";
                    rev.likes = 0;
                    rev.sentiment = "Neutral";
                    addReview(P, A, rev);
                } else {
                    cout << "Anime tidak ditemukan!" << endl;
                }
            } else {
                cout << "User tidak terdaftar!" << endl;
            }
        } else if (pilihan == 3) {
             showAllUsers(ListU);
            showAllAnime(ListA);

            cout << "\n--- LIHAT REVIEW ---" << endl;
            string target;
            cout << "Ketik judul anime untuk lihat review: "; cin >> target;
            showReviewsForAnime(ListU, target);

            cout << "\n--- STATISTIK ---" << endl;
            cout << "Jumlah user pasif (No review): " << countPassiveUsers(ListU) << endl;
        }
    }
    cout << "Program Selesai." << endl;
    return 0;
}
