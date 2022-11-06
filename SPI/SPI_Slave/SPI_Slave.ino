//Slave
#define SSs_pin 7
#define SCKs_pin 8
#define MISOs_pin 9
#define MOSIs_pin 10
#define datasend 0b01010101 
//Cấu hình slave
void slave_init()
{
  pinMode(SCKs_pin, INPUT);
  pinMode(MOSIs_pin, INPUT);
  pinMode(SSs_pin, INPUT);
  pinMode(MISOs_pin, OUTPUT);
  digitalWrite(MISOs_pin, LOW);
}

uint8_t spi_slave(uint8_t data_out)
{
  uint8_t i = 0, x = 0;
  uint8_t data_in = 0b00000000;
  
  // Đợi chân Slave select xuống thấp để chọn slave
  while(digitalRead(SSs_pin) == HIGH);
  
  for (i = 0 ; i < 8 ; i++)
  {
    x = data_out & 0b10000000;
    if(x>0)
    {
      digitalWrite(MISOs_pin, HIGH);
    }else
    {
      digitalWrite(MISOs_pin, LOW);
    }
    while(digitalRead(SCKs_pin) == LOW);

    if (digitalRead(MOSIs_pin) == HIGH)
    {
      data_in = data_in | (0b10000000>>i);
    }
    data_out = data_out<<1;
    //Đợi xung clock xuống
    while (digitalRead(SCKs_pin) == HIGH);  
  }
  digitalWrite(MISOs_pin, LOW);
  return data_in;
}
void setup() {
  // put your setup code here, to run once:
  slave_init();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  uint8_t data=0,x=0;
  data = spi_slave(datasend);
  //Xuất dữ liệu đọc được
  //Nếu 1 thì chân 2 sáng, 0 thì chân 3 sáng
  
  for (int i = 0 ; i < 8 ; i++)
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

}
