/*
 * Autore: Makaoui Youness
 * Classe: 4G
 * Luogo: Lab 53bis
 * Descrizione: verifica sui Thread
 */

import java.util.concurrent.SynchronousQueue;

public class SpaceMagazine extends Thread{
    private int pumpSize;
    private int pump;

    public SpaceMagazine(Thread producer, Thread consumer){
        this.pumpSize = 10000;
        this.pump = 0;
        synchronized (producer){
        }
        synchronized (consumer){

        }
    }

    int getPumpSize(){
        return pumpSize;
    }

    int getPump(){
        return pump;
    }

    void AddFuel(int fuel){
        if (fuel<pumpSize)
            pump+=fuel;
    }
    void GetFuel(int fuel){
        if (fuel>=pump)
            pump-=fuel;
    }

    @Override
        public void run() {
        synchronized(this){
        }
    }
}