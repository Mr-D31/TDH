
// khai baothu vien 
#include <Stepper.h>
#include <DHT.h>

// cam bien anh sang dieu khien dong co mai 
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);// initialize the stepper library on pins 8 through 11:

//cam bien  nhiet do và độ ẩm
const int DHTPIN = 4;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN,DHTTYPE);

//khai bao bien 
int giatri_quangtro ;//quang tro 
int relay_ctr = 3; 
void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(15);// set the speed at 15 rpm
  dht.begin();// turn on dht sensor
  pinMode(relay_ctr , OUTPUT);

}

void loop() {
  giatri_quangtro = analogRead(A0);
  //Serial.println(giatri_quangtro);
  //delay(500);
  if (giatri_quangtro >= 100 ){
    Serial.println("clockwise");
    myStepper.step(2*stepsPerRevolution);
    delay(2000);
  }
  else if (giatri_quangtro <= 10 ){
    Serial.println("counterclockwise");
    myStepper.step(-2*stepsPerRevolution);
    delay(2000);
  }

  float do_am = dht.readHumidity(); 
  float nhiet_do = dht.readTemperature();
  if (nhiet_do > 30){
    digitalWrite(relay_ctr,LOW);
  }
  Serial.print("Nhiet do: ");
  Serial.println(nhiet_do);
  Serial.print("Do am: ");
  Serial.println(do_am);
  Serial.println(giatri_quangtro);
  delay(1000);

}
