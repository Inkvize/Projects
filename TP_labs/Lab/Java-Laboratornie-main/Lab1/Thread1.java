public class Thread1 extends Thread {
    public static int num;

    @Override
    public void run() {
        while (true) {
            num = (int) (Math.random() * 10);
            System.out.println("Число - " + num);
            if (num % 2 == 0) {
                Thread2 thrd2 = new Thread2();
                thrd2.start();
            } else {
                Thread3 thrd3 = new Thread3();
                thrd3.start();
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}