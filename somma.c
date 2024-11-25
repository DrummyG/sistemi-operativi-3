//
// Created by Davide Balestrino on 18/11/24.
//

int sommatoria(int array[]){
    int sommatoria = 0;
    for(int i = 0; i < 6; i++){
        if(array[i] % 2 == 0){
            sommatoria += array[i];
        }
    }

    return sommatoria;
}