const byte AFsentido1 = 37, AFsentido2 = 35, AFenable =  3, BFsentido1 = 33, BFsentido2 = 31, BFenable = 2;
const byte ATsentido1 = 9, ATsentido2 = 8 , ATenable =  12, BTsentido1 = 10, BTsentido2 = 11, BTenable = 13;
const byte sensorEsq =A2, sensorDir = A0; //adicionar numeros
byte esq, dir;

const byte trigger = 45;
const byte echo = 47;
float duration, distance;

void setup() {
  ///////////////////////////
  //ultrasom
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);


  Serial.begin(9600);
  ///////////////////////////
  //sensor infravermelhos
  pinMode(sensorEsq, INPUT);
  pinMode(sensorDir, INPUT);

  ///////////////////////////
  //motor da frente
  pinMode(AFsentido1, OUTPUT);
  pinMode(AFsentido2, OUTPUT);
  
  pinMode(BFsentido1, OUTPUT);
  pinMode(BFsentido2, OUTPUT);
  
  pinMode(AFenable, OUTPUT);
  
  
  pinMode(BFenable, OUTPUT);


  ////////////////////////////
  //motor de trás
  pinMode(ATsentido1, OUTPUT);
  pinMode(ATsentido2, OUTPUT);
  
  pinMode(BTsentido1, OUTPUT);
  pinMode(BTsentido2, OUTPUT);

  pinMode(ATenable, OUTPUT);
  
  pinMode(BTenable, OUTPUT);

}

void frente(){
  digitalWrite(BFsentido1, HIGH);
  digitalWrite(BFsentido2, LOW);
  analogWrite(BFenable, 60);

  digitalWrite(AFsentido1, LOW);
  digitalWrite(AFsentido2, HIGH);
  analogWrite(AFenable, 65);

  digitalWrite(BTsentido1, LOW);
  digitalWrite(BTsentido2, HIGH);
  analogWrite(BTenable, 80); //ok

  digitalWrite(ATsentido1, HIGH);
  digitalWrite(ATsentido2, LOW);
  analogWrite(ATenable,80); //OK
}

void re(){
  digitalWrite(BFsentido1, LOW);
  digitalWrite(BFsentido2, HIGH);
  analogWrite(BFenable, 64);

  digitalWrite(AFsentido1, HIGH);
  digitalWrite(AFsentido2, LOW);
  analogWrite(AFenable, 76);

  digitalWrite(BTsentido1, HIGH);
  digitalWrite(BTsentido2, LOW);
  analogWrite(BTenable, 85); //ok

  digitalWrite(ATsentido1, LOW);
  digitalWrite(ATsentido2, HIGH);
  analogWrite(ATenable, 80); //OK
}

void esquerda(){

  digitalWrite(BFsentido1, LOW);
  digitalWrite(BFsentido2, HIGH);
  analogWrite(BFenable, 200);

  digitalWrite(BTsentido1, HIGH);
  digitalWrite(BTsentido2, LOW);
  analogWrite(BTenable, 200);

  digitalWrite(AFsentido1, LOW);
  digitalWrite(AFsentido2, HIGH);
  analogWrite(AFenable, 200);

  digitalWrite(ATsentido1, HIGH);
  digitalWrite(ATsentido2, LOW);
  analogWrite(ATenable, 200);

  delay(200);
}

void direita(){
  digitalWrite(AFsentido1, HIGH);
  digitalWrite(AFsentido2, LOW);

  digitalWrite(ATsentido1, LOW);
  digitalWrite(ATsentido2, HIGH);

  analogWrite(AFenable, 200);
  analogWrite(ATenable, 200);

  digitalWrite(BFsentido1, HIGH);
  digitalWrite(BFsentido2, LOW);
  analogWrite(BFenable, 200);

  digitalWrite(BTsentido1, LOW);
  digitalWrite(BTsentido2, HIGH);
  analogWrite(BTenable, 200);

  delay(250);
}

void parar(){
  analogWrite(ATenable, 0);
  analogWrite(AFenable, 0);
  analogWrite(BTenable, 0);
  analogWrite(BFenable, 0);
}

void som(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration*.0343)/2;
  delay(100);

  if(distance<15){
    re();
    delay(500);
    esquerda();
    delay(500);
    direita();
    delay(500);
  }
}

void loop() {
  esq = digitalRead(sensorEsq);
  dir = digitalRead(sensorDir);

  if(esq == LOW && dir == LOW){ //BRANCO BRANCO | RETO
    frente();
  }else if((esq == LOW)&&(dir == HIGH)){ // BRANCO PRETO | CURVA PRA DIREITA
    direita();
  }else if(esq == HIGH && dir == LOW){ // PRETO BRANCO | CURVA PRA ESQUERDA
    esquerda();
  }else{
    parar();
  }

  /*
  Serial.print("esq: ");
  Serial.print(esq);
  Serial.print(" dir: ");
  Serial.println(dir);

  Serial.print("Distancia: ");
  Serial.println(distance);
  */
} 