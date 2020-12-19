int val;                                         //Declaramos variable de tipo entero val

void setup() {
Serial.begin (9600);                             //Inicializamos la comunicacion serial a 9600bps
pinMode(A1,INPUT);                               //Asignamos el pin A1 como entrada (Sensor de Temperatura)
pinMode(6,OUTPUT);                               //Asignamos el pin 6 como salida (Led Azul)
pinMode(7,OUTPUT);                               //Asignamos el pin 7 como salida (Ventilador)
}

void loop() {
val = analogRead (A1);                           //Realiza la lectura del pin A1 (Sensor) y el valor lo guarda en la variable val
float mv = (val/1024.0)*5000;                    //Declaramos variable de tipo float y operamos para obtener el resultado en celsius (grados centigrados)
float temp = mv/10;                              //Declaramos variable de tipo float y operamos para obtener el resultado en celsius (grados centigrados)

Serial.print ("TEMPERATURE = ");                 //Imprimimos en pantalla TEMPERATURE =
Serial.print (temp);                             //Imprimimos el valor de la variable temp
Serial.print ("*C");                             //Imprimimos en pantalla *C
Serial.println ();                               //Salto de linea

if(temp>20){                                   //Si temp es mayor que 20
    digitalWrite(6,LOW);                         //Apaga el Led Azul
    digitalWrite(7,HIGH);                        //Prende el Ventilador
}
else{                                            //Si temp NO es mayor que 20
  digitalWrite(6,HIGH);                          //Prende el Led Azul
  digitalWrite(7,LOW);                           //Apaga el Ventilador
  }
delay(1000);                                     //Espera de 1 segundo
}
