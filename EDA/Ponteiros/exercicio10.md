Exercício 10
O que esta função faz?
int f(char* s){
    char* p = s;
    while(*p != ’\0’)
    p++;
    return p-s;
}

Resposta: Retorna o tamanho de uma string.