#include <SoftwareSerial.h>
#include <EBYTE.h>

// DEFINIÇÕES DE PINOS
#include <SoftwareSerial.h>
#include <EBYTE.h>
 
#define M0_LoRa   11
#define M1_LoRa   12
#define RX_LoRa   2                                                          // Vai no TXD do módulo
#define TX_LoRa   3                                                          // Vai no RXD do módulo
#define AUX_LoRa  4                                                    // É o mesmo pino do LED presente na placa, então não precisa por um externo
 
SoftwareSerial lora(RX_LoRa, TX_LoRa);
EBYTE LoRa(&lora, M0_LoRa, M1_LoRa, AUX_LoRa);
// INSTANCIANDO OBJETOS

void setup() {
  Serial.begin(9600);
  lora.begin(9600);
  LoRa.init();                                                                // Inicializa a comunicação e obtem todos os parâmetros do módulo
  //LoRa.Reset();                                                             // Reseta parâmetros para os de fábrica
  LoRa.SetAirDataRate(ADR_1K);                                                // Define a taxa de dados de transmissão
  LoRa.SetAddress(1);                                                         // Define endereço da rede
  LoRa.SetChannel(23);                                                        // Define canal como 23
  LoRa.SaveParameters(TEMPORARY);                                             // Salva todas as definições de forma temporária
 
  LoRa.PrintParameters();                                                     // Imprime todos os parâmetros (configurações) obtidos do módulo 
  LoRa.SetMode(MODE_NORMAL);      
}

void loop() {

        lora.print("Dário pedro");
        delay(10 00);
}
