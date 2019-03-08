#include "PremiumUser.h"
#include <iostream>
using namespace std;

//ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char* name) : User(name){
    num_of_music_downloaded = 0;
    active = true;
}

// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
// Contoh: 
// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
//
// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
void PremiumUser::downloadMusic(char* music){
    if (active){
        cout << "Music Downloaded: " << music << endl;
        num_of_music_downloaded++;
    }
    else{
        cout << "Activate premium account to download music" << endl;
    }
}
void PremiumUser::inactivatePremium(){
    active = false;
}
void PremiumUser::activatePremium(){
    active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const{
    return num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const{
    return active;
}