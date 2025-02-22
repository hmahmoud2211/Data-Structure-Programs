#include <Arduino.h>
#include <LiquidCrystal.h>

// تعريف المتغيرات
int players[2] = {0, 0}; // لاعبين
int positions[2][2] = {
  {0, 0},
  {0, 0}
}; // مواقف اللاعبين
int dice = 0; // النرد

// وظيفة لتحريك اللاعب
void movePlayer(int player, int position) {
  positions[player][positions[player][0]] = 0; // حذف اللاعب من موقعه الحالي
  positions[player][0] = position; // وضع اللاعب في موقع جديد
}

// وظيفة لرمي النرد
void rollDice() {
  dice = random(1, 7); // توليد رقم عشوائي بين 1 و 6
}

// وظيفة لعرض قيمة النرد
void showDice(int player) {
  // تحديد لون النرد بناءً على اللاعب
  switch (player) {
    case 0:
      // الأحمر
      lcd.setCursor(0, 0);
      lcd.print("R:");
      lcd.setCursor(3, 0);
      lcd.print(dice);
      break;
    case 1:
      // الأخضر
      lcd.setCursor(0, 1);
      lcd.print("G:");
      lcd.setCursor(3, 1);
      lcd.print(dice);
      break;
  }
}

// وظيفة لتحريك اللاعب الأول
void movePlayer1() {
  movePlayer(0, positions[0][0] + dice);
}

// وظيفة لتحريك اللاعب الثاني
void movePlayer2() {
  movePlayer(1, positions[1][0] + dice);
}

// وظيفة لبدء اللعبة
void setup() {
  // تعريف المدخلات والمخرجات
  pinMode(A0, INPUT); // زر رمي النرد
  for (int i = 0; i < 4; i++) {
    pinMode(i + 1, OUTPUT); // مصابيح LED لمواقف اللاعبين
  }
  pinMode(13, OUTPUT); // مصباح النرد
  pinMode(12, OUTPUT); // مصباح النرد
  pinMode(11, OUTPUT); // مصباح النرد
  pinMode(4, INPUT); // زر اللاعب الأول
  pinMode(5, INPUT); // زر اللاعب الثاني

  // تعيين مواقع اللاعبين الأولية
  positions[0][0] = 0;
  positions[1][0] = 1;

  // تعريف شاشة LCD
  lcd.begin(16, 2);
}

// وظيفة لتشغيل اللعبة
void loop() {
  // انتظار الضغط على زر رمي النرد
  while (digitalRead(A0) == LOW);

  // رمي النرد
  rollDice();

  // عرض قيمة النرد لكل لاعب
  showDice(0);
  showDice(1);

  // تحريك اللاعبين
  if (digitalRead(4) == HIGH) {
    movePlayer1();
  }
  if (digitalRead(5) == HIGH) {
    movePlayer2();
  }
}#include <Arduino.h>
#include <LiquidCrystal.h>

// تعريف المتغيرات
int players[2] = {0, 0}; // لاعبين
int positions[2][2] = {
  {0, 0},
  {0, 0}
}; // مواقف اللاعبين
int dice = 0; // النرد

// وظيفة لتحريك اللاعب
void movePlayer(int player, int position) {
  positions[player][positions[player][0]] = 0; // حذف اللاعب من موقعه الحالي
  positions[player][0] = position; // وضع اللاعب في موقع جديد
}

// وظيفة لرمي النرد
void rollDice() {
  dice = random(1, 7); // توليد رقم عشوائي بين 1 و 6
}

// وظيفة لعرض قيمة النرد
void showDice(int player) {
  // تحديد لون النرد بناءً على اللاعب
  switch (player) {
    case 0:
      // الأحمر
      lcd.setCursor(0, 0);
      lcd.print("R:");
      lcd.setCursor(3, 0);
      lcd.print(dice);
      break;
    case 1:
      // الأخضر
      lcd.setCursor(0, 1);
      lcd.print("G:");
      lcd.setCursor(3, 1);
      lcd.print(dice);
      break;
  }
}

// وظيفة لتحريك اللاعب الأول
void movePlayer1() {
  movePlayer(0, positions[0][0] + dice);
}

// وظيفة لتحريك اللاعب الثاني
void movePlayer2() {
  movePlayer(1, positions[1][0] + dice);
}

// وظيفة لبدء اللعبة
void setup() {
  // تعريف المدخلات والمخرجات
  pinMode(A0, INPUT); // زر رمي النرد
  for (int i = 0; i < 4; i++) {
    pinMode(i + 1, OUTPUT); // مصابيح LED لمواقف اللاعبين
  }
  pinMode(13, OUTPUT); // مصباح النرد
  pinMode(12, OUTPUT); // مصباح النرد
  pinMode(11, OUTPUT); // مصباح النرد
  pinMode(4, INPUT); // زر اللاعب الأول
  pinMode(5, INPUT); // زر اللاعب الثاني

  // تعيين مواقع اللاعبين الأولية
  positions[0][0] = 0;
  positions[1][0] = 1;

  // تعريف شاشة LCD
  lcd.begin(16, 2);
}

// وظيفة لتشغيل اللعبة
void loop() {
  // انتظار الضغط على زر رمي النرد
  while (digitalRead(A0) == LOW);

  // رمي النرد
  rollDice();

  // عرض قيمة النرد لكل لاعب
  showDice(0);
  showDice(1);

  // تحريك اللاعبين
  if (digitalRead(4) == HIGH) {
    movePlayer1();
  }
  if (digitalRead(5) == HIGH) {
    movePlayer2();
  }
}