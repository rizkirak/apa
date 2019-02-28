#include "User.h"
#include <iostream>
#include <cstring>
using namespace std;
#define DEFSIZE 50

int User::n_user = 0;
// ctor, parameter: nama pengguna
User::User(char* _name){
    name = new char[DEFSIZE]();
    strcpy(name, _name);
    music_list = new char*[DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        music_list[i] = new char[DEFSIZE]();
    }
    num_of_favourite_music = 0;
    n_user++;
}

// cctor
User::User(const User& U){
    name = new char[DEFSIZE]();
    strcpy(name, U.name);
    music_list = new char*[DEFSIZE];
    for (int i = 0; i < DEFSIZE; i++){
        music_list[i] = new char[DEFSIZE]();
    }
    for (int i = 0; i < U.num_of_favourite_music; i++){
        strcpy(music_list[i], U.music_list[i]);
    }
    num_of_favourite_music = U.num_of_favourite_music;
    n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User(){
    cout << "User " << name << " deleted" << endl;
    delete name;
    for(int i = 0 ; i < DEFSIZE; i++){
        delete music_list[i];
    }
    delete[] music_list;
    n_user--;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* music){
    strcpy(music_list[num_of_favourite_music], music);
    num_of_favourite_music++;
}
void User::deleteFavouriteMusic(char* music){
    bool found = false;
    for(int i = 0;(i < num_of_favourite_music); i++){
        if (found) {
            strcpy(music_list[i-1], music_list[i]);
        } else if (strcmp(music, music_list[i]) == 0){
            found = true;
        }
    }
    if (found){
        --num_of_favourite_music;
    }
}

void User::setName(char* _name){
    strcpy(name, _name);
}
char* User::getName() const{
    return name;
}
int User::getNumOfFavouriteMusic() const{
    return num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const{
    if (num_of_favourite_music == 0){
        cout << "No music in your favourite list" << endl;
    }
    else{
        for (int i = 0; i < num_of_favourite_music; i++){
            cout << i+1 << ". " << music_list[i] << endl;
        }
    }
}

int User::getNumOfUser(){
    return n_user;
}