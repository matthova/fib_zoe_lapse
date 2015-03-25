// Calculate rotation
const float golden_ratio = 0.61803398874684;
const int steps_per_revolution = 1600;
const int one_rotation = floor(steps_per_revolution * (1 - golden_ratio));
const unsigned long step_duration = 4;

// Calculate time between photos
const unsigned long video_length = 20; //In seconds. Will cancel out FPS units
const unsigned long video_fps = 24;
const unsigned long lapse_duration = 24 * 60 * 60 * 1000; // one day worth of photos (in ms)
const unsigned long ms_between_photos = floor(lapse_duration / (video_length * video_fps));
const unsigned long pause = 1000;

// Setup which pins you will use
const int direction_pin = 8;
const boolean clockwise = true;
const int step_pin = 9;
const int photo_pin = 10;

void setup()
{
  if(!clockwise){
    pinMode(direction_pin, OUTPUT);
    digitalWrite(direction_pin, HIGH);
  }
  
  pinMode(step_pin, OUTPUT);
  pinMode(photo_pin, OUTPUT);
}

void loop()
{
  unsigned long time_left = ms_between_photos * 1000;
  
  // Turn the motor
  for(int i = 0; i < one_rotation; i++){
    digitalWrite(9, HIGH);
    delay(step_duration / 2);
    digitalWrite(9, LOW);
    delay(step_duration / 2);
    time_left -= step_duration;
  }
  
  // Take a photo
  delay(1000);
  time_left -= 1000;
  digitalWrite(10, HIGH);
  delay(1000);
  time_left -= 1000;
  digitalWrite(10, LOW);
  delay(time_left);
  
}

