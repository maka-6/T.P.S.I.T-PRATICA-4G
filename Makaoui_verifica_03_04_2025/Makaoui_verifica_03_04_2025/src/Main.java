/*
* Autore: Makaoui Youness
* Classe: 4G
* Luogo: Lab 53bis
* Descrizione: verifica sui Thread
*/

public class Main {
    public static void main(String[] args) {

        Producer produttore = new Producer();
        Consumer alienoDaRifornire = new Consumer();

        SpaceMagazine astronave = new SpaceMagazine(produttore, alienoDaRifornire);

        astronave.start();
    }
}