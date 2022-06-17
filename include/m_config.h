#pragma once
// #if !defined(M_CONFIG_H)

// #ifndef M_CONFIG_H
// #define M_CONFIG_H
#include <stdio.h>
#include <Arduino.h>
#include "Wire.h"
#include "SHT2x.h"

SHT2x sht;
#define MODEM_TX 27       //SIM800LTX引脚GPIO27
#define MODEM_RX 26       //SIM800LRX引脚GPIO26


void hardware_init();
void test(float i);

// #endif