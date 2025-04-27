import java.util.Random;

public class Socio extends Thread {
    private ContoBancario conto;
    private String nome;
    private Random random = new Random();

    public Socio(String nome, ContoBancario conto) {
        this.nome = nome;
        this.conto = conto;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 50; i++) {
                int scelta = random.nextInt(2); // 0 = versa, 1 = preleva
                int cifra = random.nextInt(5000) + 1; // cifra random da 1 a 5000

                System.out.println("Scelta: " + scelta);

                if (scelta == 0) {
                    if (conto.getSaldo() + cifra > conto.getMassimo())
                        continue;
                    conto.versa(cifra, nome);
                } else {
                    // per non rischiare di avere solo versamenti
                    cifra = random.nextInt(1000) + 1;
                    conto.preleva(cifra, nome);
                }

                Thread.sleep(random.nextInt(500)); // Piccola pausa
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}