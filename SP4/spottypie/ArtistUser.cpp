#include <iostream>
#include "ArtistUser.h"
using namespace std;
#define DEFSIZE 50

int ArtistUser::num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* name) : User(name){
    uploaded_music_list = new char*[DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        uploaded_music_list[i] = new char[DEFSIZE]();
    }
    num_of_music_uploaded = 0;
    num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& A) : User(A){
    uploaded_music_list = new char*[DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        uploaded_music_list[i] = new char[DEFSIZE]();
    }
    num_of_music_uploaded = A.num_of_music_uploaded;
    for (int i = 0; i < num_of_music_uploaded; i++){
        strcpy(uploaded_music_list[i], A.uploaded_music_list[i]);
    }
    num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser(){
    cout << "Artist user " << name << " deleted" << endl;
    for(int i = 0 ; i < DEFSIZE; i++){
        delete uploaded_music_list[i];
    }
    delete[] uploaded_music_list;
    num_of_artist--;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* music){
    strcpy(uploaded_music_list[num_of_music_uploaded], music);
    num_of_music_uploaded++;
}
void ArtistUser::deleteUploadedMusic(char* music){
    bool found = false;
    for(int i = 0;i < num_of_music_uploaded; i++){
        if (found) {
            strcpy(uploaded_music_list[i-1], uploaded_music_list[i]);
        } else if (strcmp(music, uploaded_music_list[i]) == 0){
            found = true;
        }
    }
    if (found){
        num_of_music_uploaded--;
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const{
    if (num_of_music_uploaded == 0){
        cout << "No music uploaded" << endl;
    }
    else{
        for (int i = 0; i < num_of_music_uploaded; i++){
            cout << i+1 << ". " << uploaded_music_list[i] << endl;
        }
    }
}
int ArtistUser::getNumOfMusicUploaded() const{
    return num_of_music_uploaded;
}
int ArtistUser::getNumOfArtist(){
    return num_of_artist;
}