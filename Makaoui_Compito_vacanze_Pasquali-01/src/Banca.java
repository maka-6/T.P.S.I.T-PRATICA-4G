public class Banca {
    public static void main(String[] args) {
        ContoBancario conto = new ContoBancario();

        Socio socio1 = new Socio("Socio1", conto);
        Socio socio2 = new Socio("Socio2", conto);
        Socio socio3 = new Socio("Socio3", conto);

        socio1.start();
        socio2.start();
        socio3.start();

        try {
            socio1.join();
            socio2.join();
            socio3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        conto.stampaMovimenti();
    }
}