/*
 Sugestões de implementação:
 	+ Construtores com inicialização em valores dados e/ou em zero
	+ Soma/subtração de vetores
	+ Multiplicação de vetor por escalar
	+ Magnitude
	+ Cálculo do vetor normalizado
		- Um vetor normalizado é um vetor unitário (de magnitude 1) com a mesma direção do vetor original
		- Matematicamente, podemos demonstrar que, ao dividir os componentes de um vetor pela magnitude dele, obteremos	um vetor unitário.
	+ Distância entre um ponto e outro
		- Equivalente à magnitude da diferença entre dois vetores
	+ Inclinação de um vetor em relação ao eixo x
		- Atente para a diferença entre atan() e atan2()
	+ Inclinação da reta dada por dois pontos
		- A diferença entre dois vetores tem a mesma inclinação da	reta - note que a ordem na subtração importa!
	+ Rotação em um determinado ângulo
		- O algoritmo para tal é baseado em matrizes de rotação:
			* x’ = x * cosθ - y * sinθ
			* y’ = y * cosθ + x * sinθ
		- Note que, para um eixo y positivo para baixo, um ângulo positivo resulta numa rotação no sentido horário.
	+ Soma de Rect com Vec2
	+ Obter coordenadas do centro de um retângulo
	+ Distância entre o centro de dois Rects
	+ Saber se um ponto está dentro de um Rect
	+ Operadores de atribuição, soma, subtração
		- Isso não é necessário em momento algum, mas é uma feature interessante da linguagem C++ que está descrita na seção 14 do Apoio de C++ e será de grande ajuda.
 */
#ifndef RECT_H_
#define RECT_H_

#include <array>

class Rect {
public:
	float x;
	float y;
	float w;
	float h;
	Rect();
	Rect(float x, float y, float w, float h);
	~Rect();
	bool Contains( std::array<float, 2> arr );
};

#endif /* RECT_H_ */
