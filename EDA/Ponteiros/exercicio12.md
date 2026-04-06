Exercício 12
O que esta função faz?

int h(char* s,char* t){
    for( ; *s==*t ; s++, t++){
        if(*s == ’\0’)
            return 0;
    }
    return *s - *t;
}

Resposta: Retorna 0 para cada vez que o valor de s for igual a t. Se for diferente retorna a diferença das duas strings.