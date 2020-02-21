int first_LED = 2; 
int second_LED = 3;
int third_LED = 4;
int state;
int flag=0; //makes sure that the serial only prints once the state
 
void setup() {
 // sets the pins as outputs:
 pinMode(third_LED, OUTPUT);
 pinMode(second_LED, OUTPUT);
 pinMode(first_LED, OUTPUT);
 Serial.begin(9600);
 Serial.println("OK!!!");
} 
void loop() {
 //if some date is sent, reads it and saves in state
 if(Serial.available() > 0){ 
 state = Serial.read(); 
 Serial.println(state);
 flag=0;
 } 
 
 if (state == '1') {
 digitalWrite(first_LED, HIGH); 
 if(flag == 0){
 Serial.println("First LED ON");
 flag=1;
 }
 }
 
 else if (state == '2') {
 digitalWrite(second_LED, HIGH);
 if(flag == 0){
 Serial.println("Second LED ON");
 flag=1;
 }
 }
 
 else if (state == '3') {
 digitalWrite(third_LED, HIGH); 
 if(flag == 0){
 Serial.println("Third LED ON");
 flag=1;
 }
 }
 else if (state == '0') {
 digitalWrite(third_LED, LOW);
 digitalWrite(second_LED, LOW);
 digitalWrite(first_LED, LOW); 
 if(flag == 0){
 Serial.println("LED: off");
 flag=1;
 }
 }
}
