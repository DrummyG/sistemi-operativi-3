#include <stdio.h>
#include <unistd.h> // Unix Standard Library
#include <sys/wait.h>
#include "somma.h"
#include "prodotto.h"

int main() {
    pid_t pid;
    int status;

    //ESERCIZIO 1
    printf("esercizio 1\n");
    pid=fork(); // Generazione nuovo processo con duplicazione chiamante
    wait(&status);
    if(pid == 0)
        printf("HELLO WORLD\n");
    else if(pid > 0){
        printf("GOODBYE: %d\n", (int)getpid());
    }

    //ESERCIZIO 2
    printf("esercizio 2\n");
    pid = fork();

    if (pid == 0){ // Processo figlio
        execl("/bin/pwd", "pwd", NULL); // Sostituisce il processo con /bin/pwd
    }else if (pid > 0) { // Processo padre
        wait(&status);
        if (WIFEXITED(status)) {
            printf("pwd OK\n");
        } else {
            printf("Errore nel figlio\n");
        }
    } else {
        perror("Errore creando il processo figlio\n"); // Errore nel fork
    }

    pid = fork();

    if (pid == 0){ // Processo figlio
        execl("/bin/ls", "-l", NULL); // Sostituisce il processo con /bin/ls
    }else if (pid > 0) { // Processo padre
        wait(&status); // Aspetta il figlio
        if (WIFEXITED(status)) {
            printf("ls -l OK\n");
        } else {
            printf("Errore nel figlio\n");
        }
    } else {
        perror("Errore creando il processo figlio\n"); // Errore nel fork
    }

    //ESERCIZO 3
    printf("esercizo 3\n");
    int array[6], somma, molt;

    for(int i = 0; i < 6; i++){
        printf("inserisci numero %d: ", i+1);
        scanf("%d", &array[i]); //popolo array
    }

    pid=fork();

    if(pid == 0){ //se sono nel processo figlio
        molt = prodotto(array); //richiamo la funzione del prodotto di soli numeri pari
        printf("prodotto: %d\n", molt);
    }else{ //se sono nel processo padre
        somma = sommatoria(array); //richiamo la funzione della somma di soli numeri pari
        printf("sommatoria: %d\n", somma);
    }

}
