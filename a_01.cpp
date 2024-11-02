#include <iostream>

using std::cout, std::endl;

/*
4                           ==> Ausdruck ==> 4, int
1 + 2                       ==> Ausdruck ==> 3, int
1 + 2;                      ==> Anweisung ==> Anweisungen geben keinen Wert zurück
1 , 2                       ==> Ausdruck ==> Komma evaluiert zuerst 1 (dessen Wert verworfen wird) und dann 2 ==> Wert des Ausdrucks ist 2, int
x << " foo " << " bar "  //x ist vom Typ ofstream  ==> Ausdruck, std::ostream& (Referenz da Verkettung möglich)
x << 1 << 2    //x ist vom Typ int   ==> Ausdruck, Bitverschiebung von x, x um 3 Bits nach links verschoben
if ( x < y ) ;              ==> Anweisung, keiner da Anweisungen keinen Wert zurückgeben
*/
