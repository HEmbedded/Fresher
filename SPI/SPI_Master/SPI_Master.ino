//Master
#define SS_pin 7    //Slave select
#define SCK_pin 8   //Xung clock
#define MISO_pin 9    //Master input
#define MOSI_pin 10   //Master output
#define SPEED 200     //Tốc độ truyền
#define datasend 0b10101010


//Cấu hình master
void spi_init()
{
  pinMode(MOSI_pin, OUTPUT);
  digitalWrite(MOSI_pin, LOW);
  pinMode(MISO_pin, INPUT);
  pinMode(SCK_pin, OUTPUT);
  digitalWrite(SCK_pin, LOW);
  pinMode(SS_pin, OUTPUT);
  digitalWrite(SS_pin, HIGH);
  delay(10);
}

uint8_t spi_master(uint8_t data_out)
{
  uint8_t i=0, x=0;
  uint8_t data_in = 0b00000000;
  digitalWrite(SS_pin,LOW);
  for (i=0; i<8 ; i++)
  {
    x = data_out & 0b10000000;
    if(x>0)
    {
      digitalWrite(MOSI_pin, HIGH);
    }else
    {
      digitalWrite(MOSI_pin, LOW);
    }
    delay(SPEED);
    digitalWrite(SCK_pin, HIGH);
    data_out = data_out<<1;
    if((digitalRead(MISO_pin))== HIGH)
    {
      data_in = data_in | (0b10000000>>i);
    }
    delay(SPEED);
    digitalWrite(SCK_pin, LOW);
    
  }
  digitalWrite(SCK_pin, LOW);
  digitalWrite(SS_pin,HIGH);
  return data_in;
}
void setup()
{
  spi_init();
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(13,LOW);
}
void loop()
{
  for(int i = 0; i<3 ; i++)
  {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }
  delay(500);
  uint8_t data=0, x = 0;
  
  data = spi_master(datasend);
  //Xuất dữ liệu đọc được
  //Nếu 1 thì chân 2 sáng, 0 thì chân 3 sáng
  
  for (int j = 0 ; j < 8 ; j++)
  {
    x = data & 0b10000000;
    if(x>0)
    {
      digitalWrite(2,HIGH);
      delay(300);
      digitalWrite(2,LOW);
      delay(300);
    }
    else
    {
      digitalWrite(3,HIGH);
      delay(300);
      digitalWrite(3,LOW);
      delay(300);
    }
    data = data<<1;
  }
  delay(3000);
}
