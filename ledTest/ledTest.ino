int pins_LED[] = {2, 3};  // LED 연결 핀
boolean isCatInside = 1;
boolean isFull = 1;

void setup() {
  Serial.begin(9600);

  pinMode(pins_LED[0], OUTPUT);
  pinMode(pins_LED[1], OUTPUT);
  
}

void loop() { //RGB LED? 
  // 초음파 센서
  if ( isCatInside == 1 ) // 고양이가 화장실을 이용
    digitalWrite(pins_LED[0], HIGH); // 녹색 LED ON

  // 무게 센서
  if ( isFull == 1 ) // 배변통 가득 참
    digitalWrite(pins_LED[1], HIGH); // 적색 LED ON

}