#include <LiquidCrystal.h>
#include <Keypad.h>
const byte ROWS = 4;
//four rows
const byte COLS = 3;
//four columns//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 1, 13}; //connect to the column pinouts of the keypad
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int period = 2000;
unsigned long time_now = 0;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup()
{
  lcd.begin(16, 2);
  lcd.print("   KALKULATOR");
}

void userClick()
{
  time_now = millis();
  while (millis() < time_now + period)
  {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY)
    {
      if (customKey == '1')
      {
        odejmowanie();
      }
      else if (customKey == '0')
      {
        dodawanie();
      }
      else if (customKey == '2')
      {
        mnozenie();
      }
      else if (customKey == '3')
      {
        dzielenie();
      }
      else if (customKey == '4')
      {
        potegowanie();
      }
      else if (customKey == '5')
      {
        pierwiastek();
      }
      else if (customKey == '6')
      {
        sinus();
      }
      else if (customKey == '7')
      {
        cosinus();
      }
      else if (customKey == '8')
      {
        tangens();
      }
      else if (customKey == '9')
      {
        tworca();
      }
    }
  }
}

void odejmowanie()
{
  double number1 = 0;
  double number2 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Odej # - enter");
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);
   while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Odej # - enter");
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number2 = number2 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number2);
      }
      else{
        if (customKey != NO_KEY)
        {
          number2 = number2 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number2);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(number1 - number2);
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void sinus()
{
  double number1 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sin # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(sin(number1 * M_PI / 180));
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void cosinus()
{
  double number1 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cos # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(cos(number1 * M_PI / 180));
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void tangens()
{
  double number1 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tan # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(tan(number1 * M_PI / 180));
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void dodawanie()
{
  double number1 = 0;
  double number2 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dodaw # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dodaw # - enter");
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number2 = number2 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number2);
      }
      else{
        if (customKey != NO_KEY)
        {
          number2 = number2 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number2);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(number1 + number2);
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void dzielenie()
{
  double number1 = 0;
  double number2 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dziel # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dziel # - enter");
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number2 = number2 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number2);
      }
      else{
        if (customKey != NO_KEY)
        {
          number2 = number2 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number2);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  double wynik = (number1 / number2);
  lcd.print(wynik);
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void potegowanie()
{
  double number1 = 0;
  double number2 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Poteg # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Poteg # - enter");
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number2 = number2 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number2);
      }
      else{
        if (customKey != NO_KEY)
        {
          number2 = number2 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number2);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(pow(number1, number2));
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void pierwiastek()
{
  double number1 = 0;
  double number2 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pierw # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pierw # - enter");
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number2 = number2 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number2);
      }
      else{
        if (customKey != NO_KEY)
        {
          number2 = number2 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number2);
        }
      }
    }
    else
    {
      break;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(pow(number1, 1 / number2));
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void mnozenie()
{
  double number1 = 0;
  double number2 = 0;
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mnoz # - enter");
  lcd.setCursor(0, 0);
  while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number1 = number1 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number1);
      }
      else{
        if (customKey != NO_KEY)
        {
          number1 = number1 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number1);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mnoz # - enter");
   while (customKey != '#')
  {
    char customKey = customKeypad.getKey();
    if (customKey != '#')
    {
      if (customKey == '*')
      {
        number2 = number2 / 10;
        lcd.setCursor(0, 1);
        lcd.print(number2);
      }
      else{
        if (customKey != NO_KEY)
        {
          number2 = number2 * 10 + (customKey - 48);
          lcd.setCursor(0, 1);
          lcd.print(number2);
        }
      }
    }
    else
    {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WYNIK TO:");
  lcd.setCursor(0, 1);
  lcd.print(number1 *number2);
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("KLIKNIJ # ");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void tworca()
{
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PIOTR JANASZAK");
  lcd.setCursor(0, 1);
  lcd.print("LO SREM");
  delay(3000);
  lcd.setCursor(0, 1);
  lcd.print("LO SREM KLIKNIJ#");
  customKey = customKeypad.getKey();
  while (customKey != '#')
  {
    customKey = customKeypad.getKey();
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" KALKULATOR");
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print("0 = dodawanie   ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("1 = odejmowanie ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("2 = mnozenie   ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("3 = dzielenie  ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("4 = potegowanie");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("4 = potegowanie");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("5 = pierwiastek");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("6 = sinus      ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("7 = cosinus    ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("8 = tangens    ");
  userClick();
  lcd.setCursor(0, 1);
  lcd.print("9 = tworca     ");
  userClick();
}
