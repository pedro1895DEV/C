Exercício 4

Detalhe a organização da memória de um programa. Qual é a porção da memória que persiste entre chamadas de funções e qual a que não persiste?

Reposta: A memória do programa é organizada em 4 segmentos:
1. Código, contendo o binário
2. Heap, contendo a parte das variáveis de alocação de memória do programa
3. Stack, contendo as variáveis locais utilizadas no momento da execução do programa e depois descartadas
4. Dados estáticos, contendo as variáveis globais

Apenas a pilha não persiste entre as chamadas de funções. Os demais segmentos persistem.