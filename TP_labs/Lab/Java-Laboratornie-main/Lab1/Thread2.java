public class Thread2 extends Thread {

    @Override
    public void run() {
        System.out.println("����� � �������� - " + (int)Math.pow(Thread1.num,2));
    }
}