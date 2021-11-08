
// recive charchters from the monitor
char rx_byte = 0;
String rx_str = "";

// varible for vibrator motor
int vibrator = 0;

const byte PanicPin = 2;            // button is connected to pin 2 and GND
int Panic_confirm_Status = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, OUTPUT);

  digitalWrite(A0, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

}

void loop() {



  Panic_confirm_Status  =  digitalRead(2);
  Serial.println(Panic_confirm_Status);



  if (Serial.available() > 0)
  {
    rx_byte = Serial.read();

    if (rx_byte != '\n') {
      rx_str += rx_byte;
    }
    else {
      vibrator = rx_str.toInt();
      rx_str = "";
    }
  }





  if (vibrator == 1)
  {
    vibrator_on(A0);
  }
  if (vibrator == 2)
  {
    vibrator_on(7);
  }
  if (vibrator == 3)
  {
    vibrator_on(4);
  }
  if (vibrator == 4)
  {
    vibrator_on(6);
  }
  if (vibrator == 5)
  {
    vibrator_on(3);
  }
  if (vibrator == 6)
  {
    vibrator_on(5);
  }
  if (vibrator == 7)
  {
    vibrator_on(8);
  }
  if (vibrator == 8)
  {
    vibrator_on(9);
  }
  if (vibrator == 9)
  {
    vibrator_on(10);
  }
  if (vibrator == 10)
  {
    vibrator_on(11);
  }
  if (vibrator == 11)
  {
    vibrate_all(3, 4, 5, 6, 7, 8, 9, 10, 11, A0 );
  }
  if (vibrator == 12)
  {
    vibrate_off(3, 4, 5, 6, 7, 8, 9, 10, 11, A0 );
  }
  vibrator = 0;
}
void vibrate_all(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10 )
{
  digitalWrite(n1, HIGH);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, HIGH);
  digitalWrite(n5, HIGH);
  digitalWrite(n6, HIGH);
  digitalWrite(n7, HIGH);
  digitalWrite(n8, HIGH);
  digitalWrite(n9, HIGH);
  digitalWrite(n10, HIGH);
}

void vibrate_off(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10 )
{
  digitalWrite(n1, LOW);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, LOW);
  digitalWrite(n5, LOW);
  digitalWrite(n6, LOW);
  digitalWrite(n7, LOW);
  digitalWrite(n8, LOW);
  digitalWrite(n9, LOW);
  digitalWrite(n10, LOW);
}

void vibrator_on(int pinnumber)
{

  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(pinnumber, HIGH);
  delay(500);
  digitalWrite(pinnumber, LOW);

}
