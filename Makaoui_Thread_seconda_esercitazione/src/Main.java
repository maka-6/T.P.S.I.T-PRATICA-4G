public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        Thread thread1 = new Thread( new Runnable() {
            @Override
            public void run() {
                System.out.println("Thread name: " + Thread.currentThread().getName() + " with priority: " + Thread.currentThread().getPriority());
            }
        });
        Thread thread2 = new Thread( new Runnable() {
            @Override
            public void run() {
                System.out.println("Thread name: " + Thread.currentThread().getName() + " with priority: " + Thread.currentThread().getPriority());
            }
        });
        thread1.setName("Worker 1");
        thread2.setName("Worker 2");
        thread1.setPriority(3);
        thread2.setPriority(Thread.MAX_PRIORITY);
        thread1.start();
        System.out.println("Thread name: " + Thread.currentThread().getName() + " with priority: " + Thread.currentThread().getPriority());
        thread2.start();
        System.out.println("Thread name: " + Thread.currentThread().getName() + " with priority: " + Thread.currentThread().getPriority());
    }
}