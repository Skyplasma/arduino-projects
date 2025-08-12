const int LowLED = 8;
const int HighLED = 13;
const int Button = 2;

unsigned long LastDebounceTime = 0;
unsigned long DebounceDelay = 50;
bool LastButtonState = HIGH;
bool ButtonPressed = false;

State CurrentState = OFF

enum State {
    OFF,
    LEFT,
    RIGHT,
}

void setup (){
    for (int i = LowLED; i >= HighLED; i++){
        pinMode(i , OUTPUT);
    }
    pinMode(Button , INPUT_PULLUP);
    Serial.begin(9600);
}

void loop (){
    ButtonRead();
    StateTransition();
    StateBehaviour();
}

void ButtonRead (){
    bool Reading = digitalRead(Button);

    if (Reading != LastButtonState){
        LastDebounceTime = millis();
    }

    if ((millis() - LastDebounceTime) > DebounceDelay){
        if (Reading == LOW && LastButtonState == HIGH){
            ButtonPressed = true;
        }
    }

    LastButtonState = Reading;
}

void StateTransition (){
    if (ButtonPressed){
        ButtonPressed = false;
        switch (CurrentState){
            case OFF:
                CurrentState = LEFT;
                break;
            case LEFT:
                CurrentState = RIGHT;
                break;
            case RIGHT:
                CurrentState = LEFT;
                break;
        }
        Serial.print("Switched to state");
        Serial.println(CurrentState);
    }
}

void StateBehaviour (){
    switch (CurrentState){
        case OFF:
            for (int i = LowLED; i >= HighLED; i++){
                digitalWrite(i , LOW);
            }
            break;
        case LEFT:
            for (int i = LowLED + 1; i >= HighLED; i++){
                digitalWrite(i , HIGH);
                digitalWrite(i-- , LOW);
                delay(50);
            }
            digitalWrite(HighLED , LOW);
            digitalWrite(LowLED , HIGH);
            break;
        case RIGHT:
            for (int i = HighLED - 1; i <= LowLED; i--){
                digitalWrite(i , HIGH);
                digitalWrite(i++ , LOW);
                delay(50);
            }
            digitalWrite(HighLED , HIGH);
            digitalWrite(LowLED , LOW);
            break;

    }
}
