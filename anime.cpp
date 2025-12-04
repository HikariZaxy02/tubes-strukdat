#include "anime.h"
#include <iostream>

using namespace std;

void createListUser(adrUser &L) {
    L = NULL;
}

void createListAnime(adrAnime &L) {
    L = NULL;
}

adrUser createElementUser(InfotypeU data) {
    adrUser P = new UserElm;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    P->FirstReview = NULL;
    return P;
}

void insertUser(adrUser &L, adrUser P) {
    if (L == NULL) {
        L = P;
    } else {
        adrUser last = L;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
        P->prev = last;
    }
}

void deleteUser(adrUser &L, string username) {
    if (L == NULL) {
        cout << "List user kosong!" << endl;
        return;
    }

    adrUser P = L;

    while (P != NULL && P->info.username != username) {
        P = P->next;
    }

    if (P == NULL) {
        cout << "User '" << username << "' tidak ditemukan!" << endl;
        return;
    }

    adrReview R = P->FirstReview;
    while (R != NULL) {
        adrReview temp = R;
        R = R->next;
        delete temp;
    }

    if (P->prev == NULL) {
        L = P->next;
        if (L != NULL) {
            L->prev = NULL;
        }
    } else if (P->next == NULL) {
        P->prev->next = NULL;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
    cout << "User '" << username << "' berhasil dihapus!" << endl;
}

void showAllUsers(adrUser L) {
    cout << "\n === DAFTAR USER ===" << endl;
    if (L == NULL) {
        cout << "Tidak ada user terdaftar." << endl;
        return;
    }

    adrUser P = L;
    int i = 1;
    while (P != NULL) {
        cout << i << ". ID: " << P->info.idUser
             << " | Username: " << P->info.username
             << " | Email: " << P->info.email
             << " | Jumlah Review: " << countReviewsByUser(P) << endl;
        P = P->next;
        i++;
    }
}

adrUser findUser(adrUser L, string username) {
    adrUser P = L;
    while (P != NULL) {
        if (P->info.username == username) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrAnime createElementAnime(InfotypeA data) {
    adrAnime P = new AnimeElm;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertAnime(adrAnime &L, adrAnime P) {
    if (L == NULL) {
        L = P;
    } else {
        adrAnime last = L;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
        P->prev = last;
    }
}

void deleteAnime(adrAnime &L, adrUser ListU, string judul) {
    if (L == NULL) {
        cout << "List anime kosong!" << endl;
        return;
    }

    adrAnime A = L;

    while (A != NULL && A->info.judul != judul) {
        A = A->next;
    }

    if (A == NULL) {
        cout << "Anime '" << judul << "' tidak ditemukan!" << endl;
        return;
    }

    adrUser U = ListU;
    while (U != NULL) {
        adrReview R = U->FirstReview;
        adrReview prev = NULL;

        while (R != NULL) {
            prev = R;
            R = R->next;
        }
        U = U->next;
    }

    if (A->prev == NULL) {
        L = A->next;
        if (L != NULL) {
            L->prev = NULL;
        }
    } else if (A->next == NULL) {
        A->prev->next = NULL;
    } else {
        A->prev->next = A->next;
        A->next->prev = A->prev;
    }

    delete A;
    cout << "Anime '" << judul << "' berhasil dihapus!" << endl;
}

void showAllAnime(adrAnime L) {
    cout << "\n=== DAFTAR ANIME ===" << endl;
    if (L == NULL) {
        cout << "Tidak ada anime terdaftar." << endl;
        return;
    }

    adrAnime P = L;
    int i = 1;
    while (P != NULL) {
        cout << i << ". ID: " << P->info.idAnime
             << " | Judul: " << P->info.judul
             << " | Studio: " << P->info.studio
             << " | Genre: " << P->info.genre
             << " | Episode: " << P->info.total_eps
             << " | Rating Global: " << P->info.rating_global
             << " | Tahun: " << P->info.tahun_rilis << endl;
        P = P->next;
        i++;
    }
}

adrAnime findAnime(adrAnime L, string judul) {
    adrAnime P = L;
    while (P != NULL) {
        if (P->info.judul == judul) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrReview createElementReview(InfotypeR data) {
    adrReview P = new ReviewElm;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    P->nextAnime = NULL;
    P->prevAnime = NULL;
    return P;
}

void addReview(adrUser PUser, adrAnime PAnime, InfotypeR data) {
    adrReview newReview = createElementReview(data);
    newReview->nextAnime = PAnime;

    if (PUser->FirstReview == NULL) {
        PUser->FirstReview = newReview;
    } else {
        adrReview last = PUser->FirstReview;
        while (last->next != NULL) {
               last = last->next;
        }
        last->next = newReview;
        newReview->prev = last;
    }

    cout << "\n=== REVIEW BERHASIL DITAMBAHKAN ===" << endl;
    cout << "User: " << PUser->info.username << endl;
    cout << "Anime: " << PAnime->info.judul << endl;
    cout << "Rating: " << data.rating << "/10" << endl;
    cout << "Komentar: " << data.komentar << endl;
}

void deleteReview(adrUser PUser, string judulAnime) {
    cout << "Fungsi deleteReview belum diimplementasikan." << endl;
}

void showReviewsByUser(adrUser PUser) {
    cout << "\n=== REVIEW OLEH USER: " << PUser->info.username << " ===" << endl;
    adrReview R = PUser->FirstReview;

    if (R == NULL) {
        cout << "User ini belum memberikan review." << endl;
        return;
    }

    int i = 1;
    while (R != NULL) {
        cout << i << ". Anime: ";
        if (R->nextAnime != NULL) {
            cout << R->nextAnime->info.judul;
        } else {
            cout << "(Unknown)";
        }
        cout << " | Rating: " << R->info.rating
             << " | Komentar: " << R->info.komentar
             << " | Tanggal: " << R->info.tanggal_review << endl;
        R = R->next;
        i++;
    }
}

void showReviewsForAnime(adrUser LUser, string judulAnime) {
    cout << "\n=== REVIEW UNTUK ANIME: " << judulAnime << " ===" << endl;

    bool found = false;
    adrUser U = LUser;

    while (U != NULL) {
        adrReview R = U->FirstReview;
        while (R != NULL) {
            if (R->nextAnime != NULL && R->nextAnime->info.judul == judulAnime) {
                cout << "User: " << U->info.username
                     << " | Rating: " << R->info.rating << "/10"
                     << " | Komentar: " << R->info.komentar
                     << " | Tanggal: " << R->info.tanggal_review
                     << " | Likes: " << R->info.likes << endl;
                found = true;
            }
            R = R->next;
        }
        U = U->next;
    }

    if (!found) {
        cout << "Belum ada review untuk anime ini." << endl;
    }
}

int countReviewsByUser(adrUser PUser) {
    int count = 0;
    adrReview R = PUser->FirstReview;
    while (R != NULL) {
        count++;
        R = R->next;
    }
    return count;
}

int countPassiveUsers(adrUser L) {
    int count = 0;
    adrUser U = L;
    while (U != NULL) {
        if (U->FirstReview == NULL) {
            count++;
        }
        U = U->next;
    }
    return count;
}
