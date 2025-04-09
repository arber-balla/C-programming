#include <stdio.h>
#include <stdlib.h>

// La matrice ha una grandezza costante di 1024 pixel dunque la conserviamo in una costante globale
#define N 1024

//! Funzione che calcola i valori di massimo e minimo nella diagonale principale
//* matrice[][] => matrice che contiene tutti i dati (intensità dei pixel)
//* *massimo => passaggio per riferimento del valore del massimo
//* *minimo => passagio per riferimento del valore del minimo

void trovaMassimoMinimo(int matrice[N][N], int* massimo, int* minimo) {
    // Inizializziamo il massimo e il minimo nel primo elemento che si trova sulla diagonale
    // Lo facciamo poiche non sappiamo quale sia il valore minimo e quello massimo
    //! Usiamo la notazione *variabile = valore poiche lavoriamo con i puntatori
    *massimo = matrice[0][0];
    *minimo = matrice[0][0];

    // Iteriamo sulla diagonale della matrice, ovvero tutti glie elementi del tipo: matrice[i][i]
    // Lo facciamo a partire dal secondo elemento sulla diagonale poiche le variabili
    // di massimo e minimo sono state inizializzate al primo elemento sulla diagonale
    for (int i = 1; i < N; i++) {
        // Se il valore considerato è maggiore del massimo allora aggiorniamo il valore del massimo
        if (matrice[i][i] > *massimo) {
            *massimo = matrice[0][0];
            //! Usiamo lo statement continue poiche essendo il valore attuale piu grande del massimo non ha senso confrontarlo con il valore minimo
            // Questo è opzionale
            continue;
        }

        // Se il valore considerato è minore del minimo allora aggiorna il valore del minimo
        if (matrice[i][i] < *minimo) {
            *minimo = matrice[i][i];
        }
    }
}

//! Funzione che calcola l'intensità media dei pixel di TUTTA l'immagine.
//* Passioamo come parametro solamente la matrice e riorniamo un valore reale
float valoreMedioPixel(int matrice[N][N]) {
    // Inizializiamo a 0 una variabile reale che conserva il valore finale della media
    // La variabile viene inizializzata a zero perche dobbiamo fare la sommadegli elementi della matrice
    // Prima ancora di entrare dentro non abbiamo informazioni quindi il valore e nullo
    float mediaPixel = 0;

    // Iteriamo tra le righe della matrice
    for (int i = 0; i < N; i++) {
        // Iteriamo tra le colonne della matrice
        for (int j = 0; j < N; j++) {
            // Sommiamo al valore attuale della media quello del pixel che stiamo leggendo in questo momento
            // Ovvero l'elemento che si trova nella righa i e nella colonna j
            mediaPixel += matrice[i][j];
        }
    }

    // Una volta finito di sommare tutti i valori presenti dentro la matrice dividiamo per il numero di pixel totali ovvero N^2 (poiche la matrice è quadrata)
    return mediaPixel / (N * N);
    // In alternativa usando la libreria math.h possiamo scrivere return mediaPixel / pow(N, 2)
}

//! Funzione che calcola la media di ciascuna righa
//* Passiamo come prarametri la matrice e un vettore che conterrà tutte le medie delle singole righe
void mediaRighe(float matrice[N][N], float medieRighe[N]) {
    // Iteriamo le righe della matrice
    for (int i = 0; i < N; i++) {
        // per ciascuna righa iteriamo le singole colonne e ne facciamo la media
        // Ci serve un valore reale inizializzato e zero per conservare la media
        // Dichiariamo dentro il ciclo questo valore in modo da resettarlo a 0 per ogni nuova righa che prendiamo in cosiderazione
        float mediaRiga = 0;

        // Iteriamo le collnne della riga e sommiamo tutti i valori presenti nella riga
        for (int j = 0; j < N; j++) {
            //! Ricordiamo che ci troviamo nella i-esima riga e nella j-esima colonna
            mediaRiga += matrice[i][j];
        }

        // Dividiamo il valore della somma conservato nella variabile media per il numero N di elementi in ciascuan riga per ottenere la media
        mediaRiga = mediaRiga / N;

        // Conserviamo questo valore nella i-esima posizione nel vettore che contiene le medie
        //  Sappiamo che la media presente nella posizione i in quel vettore corrisponde alla i-esima riga della matrice
        medieRighe[i] = mediaRiga;
    }
}

int main() {
    int matrice[N][N];
    int minimo_diagonale, massimo_diagonale;
    float media, medieRighe[N];

    // Popolamento della matrice (qui immaginiamo che sia già stata riempita)
    // Calcolo il valore minimo e massimo sulla diagonale principale

    minMaxDiagonale(matrice, &minimo_diagonale, &massimo_diagonale);

    printf("Valore minimo sulla diagonale principale: %d\n", minimo_diagonale);
    printf("Valore massimo sulla diagonale principale: %d\n", massimo_diagonale);

    // Calcolo dell'intensità media dei pixel dell'immagine
    media = intensitaMedia(matrice);
    printf("Intensita' media dei pixel dell'immagine: %.2f\n", media);

    // Calcolo dell'intensità media dei pixel di ciascuna riga dell'immagine
    intensitaMediaRighe(matrice, medieRighe);
    printf("Intensita' media dei pixel di ciascuna riga dell'immagine:\n");

    for (int i = 0; i < N; i++) {
        printf("Riga %d: %.2f\n", i + 1, medieRighe[i]);
    }
    return 0
}
