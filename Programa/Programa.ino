#include <Servo.h>

#define pinServo 9 // define o pino 7 como o de comando do servo motor
#define S0 2 // Atribui ao pino 8 o nome de SO, referente ao pino SO do sensor de cor
#define S1 3// Atribui ao pino 9 o nome de S1, referente ao pino S1 do sensor de cor
#define S2 4 // Atribui ao pino 12 o nome de S2, referente ao pino S2 do sensor de cor
#define S3 5 // Atribui ao pino 11 o nome de S3, referente ao pino S3 do sensor de cor
#define OutSensor 6 // Atribui ao pino 10 o nome de OutSensor, referente ao pino

int red = 0; // declara uma variavel int de nome red_frequency
int green = 0; // declara uma variavel int de nome green_frequency
int blue = 0;// declara uma variavel int de nome blue_frequency

Servo s;
  
void setup(){
  pinMode(S0, OUTPUT); // define o pino denominado SO como saída 
  pinMode(S1, OUTPUT); // define o pino denominado S1 como saída 
  pinMode(S2, OUTPUT); // define o pino denominado S2 como saída 
  pinMode(S3, OUTPUT); // define o pino denominado S3 como saída 
  pinMode(OutSensor, INPUT); // define o pino denominado OutSensor como saída 
  Serial.begin(9600); // Inicia a comunicação serial
  digitalWrite(S0, HIGH); // configura a escala de frequência do sensor para 20%
  digitalWrite(S1, LOW); // configura a escala de frequência do sensor para 20%

  s.attach(pinServo);
  
}
  
void loop(){
 
// leitura da cor vermelha
digitalWrite(S2,LOW); // configuração para os Fotodiodos red serem lidos
digitalWrite(S3,LOW); // configuração para os Fotodiodos red serem lidos
red = pulseIn (OutSensor, LOW); // armazena na variável red a frequência lida em OutSensor
Serial.print ("R= "); // escreve a letra R no monitor serial
Serial.print (red); // apresenta os valores armazenados na variável red no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
 
// leitura da cor verde
digitalWrite(S2,HIGH); // configuração para os Fotodiodos green serem lidos
digitalWrite(S3,HIGH); // configuração para os Fotodiodos green serem lidos
green = pulseIn (OutSensor, LOW); // armazena na variável green a frequência lida em OutSensor
Serial.print ("G= "); // escreve a letra G no monitor serial
Serial.print (green); // apresenta os valores armazenados na variável green no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
 
// leitura da cor azul
digitalWrite(S2,LOW); // configuração para os Fotodiodos blue serem lidos
digitalWrite(S3,HIGH); // configuração para os Fotodiodos blue serem lidos
blue = pulseIn (OutSensor, LOW); // armazena na variável blue a frequência lida em OutSensor
Serial.print ("B= "); // escreve a letra B no monitor serial
Serial.print (blue); // apresenta os valores armazenados na variável blue no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial

  Serial.print("\n");
  s.write(25);
  

 // if(130<red&&red<150&&green<165&&blue>43)
  //{
    //Serial.println("| Vermelho"); 
  //}
  if(160<red&&red<173&&165<green&&green<175&&blue>40)
  {
       Serial.println("| Azul"); 
  }
  if(red>145&&165<green&&green<179&&blue>46)
  {
    Serial.println("| Verde"); 
  }
   Serial.print("\n");
  
  
 /* // condiçoes para detecção das cores e atuação do servo motor
  if (47 < red && red < 70 &&  140 < green && green < 180 && 110 < blue && blue < 130){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Vermelho"); }
  else if (140 < red && red < 160 && 85 < green < green < 115 && 45< blue && blue < 65){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul");}
  else if (150 < red && red < 175 &&  130< green && green < 155 && 120< blue && blue < 140){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Verde");}
  else if (30<red&&red<55 &&  110 < green && green < 135 && 105 < blue && blue < 125){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Laranja");}
  else if (25 < red && red < 45 &&  35 < green && green < 55 && 55 < blue && blue < 76){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Amarelo");}
  else if (65 < red && red < 90 &&  100 < green && green < 120 && 50 < blue && blue < 77){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Roxo");}
  else if (115 < red && red < 135 &&  155 < green && green < 170 && 110 < blue && blue < 140){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Marron");}
  else if (80 < red && red < 95 &&  55 < green && green < 70 && 35 < blue && blue < 50){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul Claro");}
  else if (74 < red && red < 90 &&  45 < green && green < 75 && 60 < blue && blue < 90){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo 
  Serial.println("| Verde Claro");} 
  else if (red > 240 && green > 270 && blue > 200){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Preto");}
  else if (red < 50 && green < 50 && blue < 50){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Branco");}
    Serial.println(); // quebra um linha no texto do serial monitor
    delay(300); // atraso de 300 milisegundos*/
}
