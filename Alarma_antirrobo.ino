#define trig 7 // Emisor de pulso o señal
#define echo 6 // Receptor "del eco" del pulso
#define buzzer 12 // Zumbador

void setup()
{
 pinMode (trig,OUTPUT); // Emisor

 pinMode (echo,INPUT); // Receptor

 pinMode (buzzer,OUTPUT); // Emisor

}

void loop()
{
 long duracion, distancia; //Establecemos duracion y distancia como variables numericas extensas
 
 digitalWrite (trig, LOW); //Para tener un pulso limpio empezamos con 2 microsegundos en apagado

 delay (2);

 digitalWrite (trig, HIGH); // Mandamos un pulso de 5 microsegundos 

 delay (5);

 digitalWrite (trig, LOW); // Apagamos

 duracion = pulseIn(echo, HIGH); //Medimos el tiempo que la señal tarda en volver al sensor en microsegundos 

 distancia = (duracion/2)*0.0343; // La distancia es el tiempo por la velocidad del sonido (343 m/s = 0.0343 cm/microseg)

 if (distancia < 150) // Si la distancia es menor a metro y medio 

 {
  tone(buzzer, 1000); // Suena el zumbador con una frecuencia de 1000Hz
  
  delay(5000); // Suena durante 5 segundos
 
 }

 else // de lo contrario
 {
  noTone(buzzer); // no suena
  
 }
 
}
