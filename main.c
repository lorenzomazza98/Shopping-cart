// PROGETTO DI MAZZA LORENZO



/*TESTO DEL PROGETTO :
Si vuole simulare la gestione automatica del carrello della spesa. Un utente può
acquistare prodotti e automaticamente metterli nel carrello della spesa. Ogni prodotto
è identificato da un codice, nome, descrizione, costo ed eventuale offerta.
Permettere all’utente di:
• Effettuare degli acquisti aggiungendo al carrello della spesa. Il sistema
visualizza il conto parziale con gli eventuali sconti.
• Ordinare e visualizzare i prodotti per nome (usare l’algoritmo di ordinamento
per inserimento).
• Eliminare un acquisto dato il nome.
Effettuare almeno un test per ogni opzione richiesta. */





//MAIN
#include "header.h"

int main()
{
    // Ho creatol'inventario all'interno del main, per non avere variabili
    // globali
    benvenuto();
    Prodotto prodotti[PROD_LEN] = {
        {1,  "Our Magic", "Libro Teorico", 30, 10, 24},
        {2,  "Bicycle Standard", "Mazzo di carte standard", 4, 0, 750},
        {3,  "Card College", "Corso di Cartomagia", 175, 20, 10},
        {4,  "Okito Box", "Portamonete in ottone", 14.99, 0, 30},
        {5,  "FoulardMulticolor", "Foulard per prestigiatori", 15, 10, 40},
        {6,  "Z Wallet", "Portafoglio per scambi", 20, 0, 5},
        {7,  "Loops", "Fili sottili per telecinesi", 10, 0, 74},
        {8,  "Chinese Rings", "Anelli cinesi da close-up", 40, 5, 7},
        {9,  "Half Dollar", "Mezzo Dollaro Americano", 3, 0, 223},
        {10, "Prediction", "Effetto di magia con predizione", 19.99, 0, 4},
        {11, "Later Magic", "Libro Teorico sulla prestigiazione", 29.99, 5, 7},
        {12, "Magic of Ascanio", "Libro sulla magia di Ascanio", 40, 0, 2},
        {13, "Magic Wand", "Bacchetta magica da close-up", 19.99, 0, 12},
        {14, "Invisible Deck", "Mazzo di carte truccato", 10, 0, 56},
        {15, "Close-up Pad", "Tappetino in velluto", 50, 15, 5},
        {16, "Magic Mirror", "Specchio da allenamento", 39.99, 5, 3},
        {17, "Rattle Box", "Scatola da sparizione per monete", 19.99, 0, 20},
        {18, "ModernCoinMagic", "Libro sulla monetomagia", 69.99, 0, 13},
        {19, "Chop Cup", "Bicchiere per routine con pallina", 23, 0, 22},
        {20, "Cups and balls", "Bussolotti in rame raffinato", 150, 0, 1},
    };

    int scelta;
    Carrello C;
    C.num_prodotti = 0; //inizializzo a 0 per non avere valori strani in caso di mancata assegnazione

    system("CLS");
    while (scelta = menu())
    {
        switch (scelta)
        {
        case 1: //visualizza prodotti
            system("CLS");
            Stampa_Prodotti(prodotti, PROD_LEN);
            system("PAUSE");
            break;
        case 2: //acquista nel carrello
            system("CLS");
            Inserimento_Prodotto(&C, prodotti, PROD_LEN);
            system("PAUSE");
            break;
        case 3: //ord_inser
            system("CLS");
            Ordina_Prodotti(prodotti, PROD_LEN);
            Stampa_Prodotti(prodotti, PROD_LEN);
            system("PAUSE");
            break;
        case 4: //visualizza carrello
            system("CLS");
            Stampa_Carrello(&C);
            system("PAUSE");
            break;
        case 5: //elimina dal carrello
            system("CLS");
            Elimina_Prodotto(&C);//passiamo solo il carrello
            system("PAUSE");
            break;
        case 6:
            printf("Speriamo di rivederti presto nel nostro negozio di magia! Saluti da Lorenzo.");//esci
            return 0;
            break;

        default:
            printf("Scelta non corretta!!");
            break;
        }
    }

    return 0;
}
