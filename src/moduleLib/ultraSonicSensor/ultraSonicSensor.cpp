#include

int trig = 7;
int echo = 6;
 
int led1 = 3; //실시간 초음파 인식 결과 램프
int led2 = 4; //고양이 사용 여부 램프
int enable_count = 0;
int enable_fail_count = 0;
int disable_count = 0;
bool cat_state = false; 
unsigned long past_time, current_time;
bool pre_sense = false, cur_sense;

int interval (bool state, int enable_count) const {
  return state || enable_count > 0 ? 200 : 2000 ;
}

float measureDistance() const {
  digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
   
    unsigned long duration = pulseIn(echo, HIGH);
   
    // 초음파의 속도는 초당 340미터를 이동하거나, 29마이크로초 당 1센치를 이동합니다.
    // 따라서, 초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2 입니다.
    return (duration / 29.0 / 2.0);
}

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  past_time = millis();
}
 
void loop() {
  current_time = millis();

  if(current_time - past_time > interval(cat_state, enable_count)) {
    float distance = measureDistance();  
    cur_sense = distance < 8 ? true : false;
    
    Serial.print("Cat: ");
    Serial.print(cat_state);
    Serial.print("\t");
    Serial.print(distance);
    Serial.print("cm");
   
    if (cat_state == false) {
      if(cur_sense) {
        if(enable_count < 20) {
          enable_count++;
        } else {
          enable_count = 0;
          cat_state = !cat_state;
        }
      } else {
        enable_count = 0;
      }
    } else {
      if(!cur_sense) {
        if(disable_count < 30) {
          disable_count++;
        } else {
          disable_count = 0;
          cat_state = !cat_state;
        }
      } else {
        disable_count = 0;
      }
    }
    Serial.println();
    past_time = current_time;
  }
}
