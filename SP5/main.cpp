#include "Bebek.hpp"
#include "AyamJago.hpp"
int main() {
  Unggas* kumpulan_unggas[3];
  
  Ayam ayam("Parjo");
  Bebek bebek("Donal");
  AyamJago ayamJago("Joni");
  
  kumpulan_unggas[0] = &ayam;
  kumpulan_unggas[1] = &bebek;
  kumpulan_unggas[2] = &ayamJago;

  //Unggas unggasBaru("Tweety");

  Ayam* ayamBaru = new Ayam(ayamJago);
  ayamBaru->bersuara();

  //AyamJago* ayamJagoBaru = new AyamJago(ayam);
  //ayamJagoBaru->bersuara();

  delete ayamBaru;

  for (int i = 2; i >= 0; --i) {
    kumpulan_unggas[i]->bersuara();
  }

  return 0;
}