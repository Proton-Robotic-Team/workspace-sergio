#ifndef SENSORES_H
#define SENSORES_H

const short PIN_D1 = 34;
const short PIN_D2 = 35;
const short PIN_D3 = 32;
const short PIN_D4 = 33;
const short PIN_D5 = 25;
const short PIN_D6 = 26;
const short PIN_D7 = 27;
const short PIN_D8 = 13;

extern short valorD1;
extern short valorD2;
extern short valorD3;
extern short valorD4;
extern short valorD5;
extern short valorD6;
extern short valorD7;
extern short valorD8;

void lerSensores();
void printarValorDosSensores(bool debugAtivo);

#endif
