//Sensor de Luminosidade

int ledVerde1 = 13;
int ledVerde2 = 12;
int ledAmarelo = 11;
int ledVermelho = 10;
int pinoSensor = A0;
int valorSensor = 0;
 
void setup(){
   Serial.begin(9600);
    //Definição dos pinos com Saídas e Entradas
    
     pinMode(ledVerde1,OUTPUT);
     pinMode(ledVerde2,OUTPUT);
     pinMode(ledAmarelo,OUTPUT);
     pinMode(ledVermelho,OUTPUT);
     pinMode(pinoSensor, INPUT);
}

void loop(){
  //"analogRead" diz respeito ao valor lido na porta analógica A0

  valorSensor = analogRead(pinoSensor);
  Serial.println(valorSensor);

  //"Se o valor lido no pino analógico for menor que..."

  if(valorSensor < 640){
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
    
  else if(valorSensor < 768){
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  
  else if(valorSensor < 896){
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  }
   
  else{
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, HIGH);
  }

  return;
}
