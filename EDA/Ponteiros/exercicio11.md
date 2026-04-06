Exercício 11
O que esta função faz?

void g(char* s,char* t){
    int i = 0;
    do {
        *t = *s;
        s++;
        t++;
    } while(*s != );
}

Resposta: Essa função usa dois ponteiros para percorrer uma string e copiá-la para o segundo ponteiro até chegar ao caracter ’\0’. Após isso ela para.