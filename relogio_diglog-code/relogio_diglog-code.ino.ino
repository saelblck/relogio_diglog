// relogio analogico digital
// feito por: Samuel A. @saelblck
// em: 18/07/22

#define col1 2
#define col2 3
#define col3 4
#define linhaA 5
#define linhaB 6
#define linhaC 7
#define linhaD 8
#define botao 11

int tempo = 4000;

// prototipos de funções
void offAll();                        // apaga todos os leds
void horas(int val);                  //liga o led correspondente ao seu valor
void minutos(int val);                //liga o led correspondente ao seu valor
void relogio(int hora, int minutos);  // função principal onde voce passa os parametros de hora e minutos
void espera(int val);                 // substitui o delay()

void setup() {
  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(linhaA, OUTPUT);
  pinMode(linhaB, OUTPUT);
  pinMode(linhaC, OUTPUT);
  pinMode(linhaD, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(botao)) {
    // verifica se o botão foi clicado

    relogio(2, 15);
    while (!digitalRead(botao)) {
      //evita varios cliques segurando o botão
    }
  }
}

void offAll() {
  digitalWrite(col1, LOW);
  digitalWrite(col2, LOW);
  digitalWrite(col3, LOW);
  digitalWrite(linhaA, LOW);
  digitalWrite(linhaB, LOW);
  digitalWrite(linhaC, LOW);
  digitalWrite(linhaD, LOW);
}  // END offAll

void horas(int val) {
  switch (val) {
    // horas
    case 1:
      digitalWrite(linhaA, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 2:
      digitalWrite(linhaA, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 3:
      digitalWrite(linhaA, HIGH);
      digitalWrite(col3, HIGH);
      break;

    case 4:
      digitalWrite(linhaB, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 5:
      digitalWrite(linhaB, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 6:
      digitalWrite(linhaB, HIGH);
      digitalWrite(col3, HIGH);
      break;

    case 7:
      digitalWrite(linhaC, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 8:
      digitalWrite(linhaC, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 9:
      digitalWrite(linhaC, HIGH);
      digitalWrite(col3, HIGH);
      break;

    case 10:
      digitalWrite(linhaD, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 11:
      digitalWrite(linhaD, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 12:
      digitalWrite(linhaD, HIGH);
      digitalWrite(col3, HIGH);
      break;
  }
}  // END horas

void minutos(int val) {
  switch (val) {
    // minutos
    case 5:
      digitalWrite(linhaA, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 10:
      digitalWrite(linhaA, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 15:
      digitalWrite(linhaA, HIGH);
      digitalWrite(col3, HIGH);
      break;

    case 20:
      digitalWrite(linhaB, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 25:
      digitalWrite(linhaB, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 30:
      digitalWrite(linhaB, HIGH);
      digitalWrite(col3, HIGH);
      break;

    case 35:
      digitalWrite(linhaC, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 40:
      digitalWrite(linhaC, HIGH);
      digitalWrite(col2, HIGH);
      break;
    case 45:
      digitalWrite(linhaC, HIGH);
      digitalWrite(col3, HIGH);
      break;

    case 50:
      digitalWrite(linhaD, HIGH);
      digitalWrite(col1, HIGH);
      break;
    case 55:
      digitalWrite(linhaD, HIGH);
      digitalWrite(col2, HIGH);
      break;
  }
}  // END minutos

void relogio(int hora, int minuto) {
  int timer = millis(), timer2 = millis();
  while ((millis() - timer) <= tempo) {
    horas(hora);
    espera(10);
    offAll();

    if ((millis() - timer2) <= tempo / 8) {
      minutos(minuto);
      espera(10);
      offAll();
    } else if ((millis() - timer2) >= tempo / 4) {
      timer2 = millis();
    }
  }
}  // END relogio

void espera(int val) {
  int timer = millis();

  while ((millis() - timer) <= val) {
    // mantem o programa preso até o tempo acabar
  }
}  // END espera