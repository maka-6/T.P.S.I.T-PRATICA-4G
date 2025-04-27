/*
 * Autore: Makaoui Youness
 * Classe: 4G
 * Luogo: Lab 53bis
 * Descrizione: verifica sui Thread
 */

public class Consumer extends Thread{

    private int consumed;
    public Consumer(){
        this.consumed = 100;
    }

    int Consume(int pump){
        return pump -= consumed;
    }

    @Override
    public void run() {

        Consume(100);
        System.out.println("Prelievo di L: 100" + "N: ");
    }
}