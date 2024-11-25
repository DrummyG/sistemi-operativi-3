//
// Created by Davide Balestrino on 18/11/24.
//

int prodotto(int array[]){
    int prodotto = 1;
    for(int i = 0; i < 6; i++){
        if(array[i] % 2 == 0){
            prodotto *= array[i];
        }
    }

    return prodotto;
}