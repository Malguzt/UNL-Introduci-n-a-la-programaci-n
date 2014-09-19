#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio2.h>
using namespace std;

class Animal
{
protected:
  void ubicarTexto();
  char cara[3][6];
  int x;
  int y;
public:
  Animal(int xx, int yy);
  void imprimirCara();
  virtual void hablar();
  virtual void comer();
};

class Chancho: public Animal
{
public:
  Chancho(int xx, int yy);
  void comer();
  void hablar();
};

class Vaca: public Animal
{
public:
  Vaca(int xx, int yy);
  void hablar();
};

class Pato: public Animal
{
public:
  Pato(int xx, int yy);
  void hablar();
};

int main(int argc, char const *argv[])
{
  Animal* animales[3] = {new Vaca(10, 3), new Chancho(30, 3), new Pato(50, 3)};

  char tecla;
  while(tecla != 'q')
  {
    clrscr();
    switch (tecla) {
      case '1': 
        animales[0] = new Vaca(10, 3);
        animales[1] = new Chancho(30, 3);
        animales[2] = new Pato(50, 3);
        break;
      case '2': 
        animales[0] = new Pato(10, 3);
        animales[1] = new Vaca(30, 3);
        animales[2] = new Chancho(50, 3);
        break;
      case '3': 
        animales[0] = new Chancho(10, 3);
        animales[1] = new Pato(30, 3);
        animales[2] = new Vaca(50, 3);
        break;
    }
    for (int i = 0; i < 3; ++i)
    {
      animales[i]->imprimirCara();
      if (tecla == '4')
      {
        animales[i]->comer();
      }
      if (tecla == '5')
      {
        animales[i]->hablar();
      }
    }
    tecla = getch();
  }

  return 0;
}

Animal::Animal(int xx, int yy) 
{
  x = xx;
  y = yy;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 6; ++j)
    {
      cara[i][j] = ' ';
    }
  }
}

void Animal::imprimirCara()
{
  for (int i = 0; i < 3; ++i)
  {
    gotoxy(x, y + i);
    for (int j = 0; j < 6; ++j)
    {
      cout << cara[i][j];
    }
  }
}

void Animal::ubicarTexto()
{
  gotoxy(x, y + 4);
}

void Animal::hablar()
{
  ubicarTexto();
  cout << "Grrr!!";
}

void Animal::comer()
{
  ubicarTexto();
  cout << "NIAM NIAM!";
}

Chancho::Chancho(int xx, int yy): Animal(xx, yy)
{
  cara[0][1] = '^'; cara[0][2] = '.'; cara[0][3] = '.'; cara[0][4] = '^';
  cara[1][1] = '('; cara[1][2] = 186; cara[1][3] = 186; cara[1][4] = ')';
}

void Chancho::comer(){
  ubicarTexto();
  cout << "RGRAM RGRAM!";
}

void Chancho::hablar(){
  ubicarTexto();
  cout << "OINK OINK!";
}

Vaca::Vaca(int xx, int yy): Animal(xx, yy)
{
  cara[0][1] = '('; cara[0][2] = '_'; cara[0][3] = '_'; cara[0][4] = ')';
  cara[1][1] = '('; cara[1][2] = 'o'; cara[1][3] = 'o'; cara[1][4] = ')';
  cara[2][2] = '\\'; cara[2][3] = '/';
}

void Vaca::hablar(){
  ubicarTexto();
  cout << "MUU MUU!";
}

Pato::Pato(int xx, int yy): Animal(xx, yy)
{
  cara[0][3] = '_'; cara[0][4] = '_';
  cara[1][1] = '>'; cara[1][2] = '('; cara[1][3] = '\''; cara[1][4] = ')';
  cara[2][2] = ')'; cara[2][3] = '/';
}

void Pato::hablar(){
  ubicarTexto();
  cout << "CUAC CUAC!";
}