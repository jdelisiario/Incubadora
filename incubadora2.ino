//Controle da Lâmpada usando sensor LM35


//saida pro controle do triac
const int TRIAC = 4;
//variavel pro controle da luminosidade
volatile long lum = 128;

//função pra detecção da passagem por zero e envio do sinal pro triac
void zeroCross(){
  //formula conseguida no site
  int dimtime = (65*lum);      
  delayMicroseconds(dimtime);
  digitalWrite (TRIAC, HIGH);
  delayMicroseconds (10);
  //digitalWrite (TRIAC, LOW);
}

void setup() {

  pinMode(TRIAC, OUTPUT);
  attachInterrupt(0, zeroCross, RISING);
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(TRIAC,HIGH);
  delayMicroseconds (1000);
  //digitalWrite (TRIAC, LOW);
  lum = 100;
  delay(1000);
  lum=75;
  delay(1000);
  lum=0;
  delay(1000);
  
  
}
