/*
 * Autore: Makaoui Youness
 * Classe: 4G
 * Luogo: Lab 53bis
 * Descrizione: verifica sui Thread
 */

import java.util.Random;
public class Producer extends Thread{

    private Random refuel = new Random();
    private int produced;
    public Producer(){
        produced = 0;
    }

    int getProduced(){
        return produced;
    }

    int ProduceFuel(){
        return produced = refuel.nextInt(101);
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {

            ProduceFuel();
            System.out.println("Rifornimento di L: " + getProduced() + "N: " + i+1);
        }
    }
}