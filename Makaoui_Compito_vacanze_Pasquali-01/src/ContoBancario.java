import java.util.ArrayList;

public class ContoBancario {
    private int saldo;
    private final int MASSIMO = 100000;
    private final ArrayList<String> movimenti = new ArrayList<>();
    private boolean sportelloLibero = true; // per la seconda parte

    public ContoBancario() {
        saldo = 0;
    }

    // Metodo synchronized per accesso esclusivo
    public synchronized void versa(int amount, String socio) throws InterruptedException {
        while (saldo + amount > MASSIMO || !sportelloLibero) {
            System.out.println(socio + " sta provando a versare " + amount + "€. Saldo: " + saldo + "€");
            wait();
        }
        saldo += amount;
        movimenti.add(socio + " ha versato " + amount + "€. Saldo attuale: " + saldo + "€");
        System.out.println(socio + " ha versato " + amount + "€. Saldo: " + saldo + "€");
        notifyAll();
    }

    public synchronized void preleva(int amount, String socio) throws InterruptedException {
        while (saldo - amount < 0 || !sportelloLibero) {
            System.out.println(socio + " sta provando a prelevare " + amount + "€. Saldo: " + saldo + "€");
            wait();
        }
        iniziaOperazione(); // INIZIA L'OPERAZIONE QUI

        saldo -= amount;
        movimenti.add(socio + " ha prelevato " + amount + "€. Saldo attuale: " + saldo + "€");
        System.out.println(socio + " ha prelevato " + amount + "€. Saldo: " + saldo + "€");

        terminaOperazione(); // TERMINA L'OPERAZIONE QUI

        notifyAll();
    }

    // Metodi per gestire lo sportello unico
    public synchronized void iniziaOperazione() throws InterruptedException {
        while (!sportelloLibero) {
            wait();
        }
        sportelloLibero = false;
    }

    public synchronized void terminaOperazione() {
        sportelloLibero = true;
        notifyAll();
    }

    public void stampaMovimenti() {
        System.out.println("\n--- MOVIMENTI BANCARI ---");
        for (String movimento : movimenti) {
            System.out.println(movimento);
        }
    }

    public int getSaldo() {
        return saldo;
    }

    public int getMassimo() {
        return MASSIMO;
    }
}