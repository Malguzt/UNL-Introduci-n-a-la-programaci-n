#ifndef GANADORES_H
#define GANADORES_H

class Ganadores {
private:
	char ganadores[5][20];
	int puntos[5];
protected:
public:
	Ganadores();
	~Ganadores();
	bool haceMerito(int puntos);
	void agregarGanador(int puntos, char nombre[20]);
	void dibujar();
	void guardar();
};

#endif

