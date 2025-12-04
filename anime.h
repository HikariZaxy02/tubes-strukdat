#ifndef anime_H_INCLUDED
#define H_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct User {
    int idUser;
    string username;
    string email;
};

struct Anime{
    int idAnime;
    string judul;
    string studio;
    string genre;
    int total_eps;
    float rating_global;
    int tahun_rilis;
};

struct Review{
    int rating;
    string komentar;
    string tanggal_review;
    int likes;
    string sentiment;
};

typedef User InfotypeU;
typedef Anime InfotypeA;
typedef Review InfotypeR;

typedef struct UserElm *adrUser;
typedef struct AnimeElm *adrAnime;
typedef struct ReviewElm *adrReview;

struct UserElm {
    InfotypeU info;
    adrUser next;
    adrUser prev;
    adrReview FirstReview;
};

struct AnimeElm{
    InfotypeA info;
    adrAnime next;
    adrAnime prev;
};

struct ReviewElm{
    InfotypeR info;
    adrReview next;
    adrReview prev;
    adrAnime nextAnime;
    adrAnime prevAnime;
};

void createListUser(adrUser &L);
adrUser createElementUser(InfotypeU data);
void insertUser(adrUser &L, adrUser P);
void deleteUser(adrUser &L, string username);
void showAllUsers(adrUser L);
adrUser findUser(adrUser L, string username);

void createListAnime(adrAnime &L);
adrAnime createElementAnime(InfotypeA data);
void insertAnime(adrAnime &L, adrAnime P);
void deleteAnime(adrAnime &L, adrUser ListU, string judul);
void showAllAnime(adrAnime L);
adrAnime findAnime(adrAnime L, string judul);

adrReview createElementReview(InfotypeR data);
void addReview(adrUser PUser, adrAnime PAnime, InfotypeR data);
void deleteReview(adrUser PUser, string judulAnime);
void showReviewsByUser(adrUser PUser);
void showReviewsForAnime(adrUser LUser, string judulAnime);

int countReviewsByUser(adrUser PUser);
int countPassiveUsers(adrUser L);

#endif
