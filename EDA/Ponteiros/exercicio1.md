Exercício 1
Quais os valores de x, y e p ao final do seguinte código:

int x, y, *p;  
y = 0;  
p = &y;  
x = *p;  
x = 4;  
(*p)++;  
--x;  
(*p) += x;  

Resposta: x = 3, y = 4, p = Valor da posição + 3.