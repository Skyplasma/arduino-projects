//int i;
int current = 1;
int increment = 1;
int ledShift = 3;
int digit = 1;
float difference = 0;
int foo2;


void setup() {
  Serial.begin(9600);
  // Set all pins from 4 to 13 as OUTPUT (LEDs)
  for (int i = 4; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);  // Make sure all LEDs are OFF initially
  }
  pinMode(2, INPUT);  // Button for decrement
  pinMode(3, INPUT);  // Button for increment
}


void loop() {
  // Debugging variable monitoring
  Serial.print("Current: ");
  Serial.print(current);
  Serial.print("  Increment: ");
  Serial.print(increment);
  Serial.print("  Digit: ");
  Serial.print(digit);
  Serial.print(" Difference: ");
  Serial.println(foo2);
  
  
  sensorUp();
  SensorDown();
}

void incrementDown(){
   // Adjust LEDs based on difference
  foo2 = diffCalc();
  if (foo2 > (digit-1)) {
    // Turn off the corresponding LED
    int ledToTurnOff = (increment / digit) + ledShift;
    if (ledToTurnOff >= 4 && ledToTurnOff <= 13) {
      digitalWrite(ledToTurnOff, LOW);
    }
    increment = increment - digit;  // Decrease increment by the digit value
  }
}

void incrementUp(){
   // When current equals increment, turn on the corresponding LED and increment the value
  if (current >= increment) {
    int ledToTurnOn = ((increment / digit) + ledShift);
    if (ledToTurnOn >= 4 && ledToTurnOn <= 13) { // checks if valid LED valuex
      digitalWrite(ledToTurnOn, HIGH);  // Turn on the LED
    }
    increment += digit;  // Increase increment by the digit value
  }
}

void digitUp(){
    // Change digit up if current reaches the next level (e.g., from 9 to 10)
  if (current == (digit * 10)+1) {
    for (int a = 4; a <= 13; a++) {
      digitalWrite(a, LOW);  // Turn off all LEDs first
    }
    digit *= 10;   // Increase the digit value
    increment = digit;  // Reset increment to the new digit
  }
}

void digitDown(){
    // Change digit down if current goes back below the current digit (e.g., from 100 to 10)
    if (current == digit && digit > 1) {
    for (int b = 4; b <= 13; b++) {
      digitalWrite(b, HIGH);  // Turn on all LEDs when going back down
    }
    digit /= 10;   // Decrease the digit value
    increment = digit * 10;  // Reset increment to the lower level
  }
}

void sensorUp(){
    // Check if the increment button is pressed
  if (digitalRead(3) == HIGH) {
    current++;
    incrementUp();
    digitUp();
    delay(250);  // Debounce delay for button press
  }

}
void SensorDown(){
    // Check if the decrement button is pressed
    if ((digitalRead(2) == HIGH)&&(current != 1)) {
    current--;
    incrementDown();
    digitDown();
    delay(250);  // Debounce delay for button press
  }
}
 // Calculate the difference between increment and current
int diffCalc() {
  int currentUp = current;
  int currentDown = current;
  float difference = 0;
  while ((increment - currentUp) != 0 || (increment + currentDown) != 0) {
    if ((increment - currentUp) != 0) {
      currentUp++;
    } else {
      return difference;
    }
    if ((increment + currentDown) != 0) {
      currentDown--;
    } else {
      return difference;
    }
    difference++;
  }
  return difference;
}